#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#include<fstream>
#include<csignal>
#define PORT 6113

/*
   Reads the content of the file and stores it into variable.
   First argument - file path.
   Second argument - content variable.
 */
void get_file_data(std::string file_path, std::string& data)
{
	std::string str = "";
	std::ifstream file_input(file_path);
	if ( ! file_input.is_open()) {
		throw std::ifstream::failure {"File isn't open."};
	}
	while (getline(file_input, str)) {
		for (int k = 0; str[k] != '\0'; k++) {
			data += str[k];
		}
		data += "\n";
		str = "";
	}
	file_input.close();
}

/*
   Gets file name from file path.
   First argument - file path.
*/
std::string get_filename(const std::string& str)
{
	if (str.length() == 0) {
		std::cerr << "No string\n";
		return "";
	}
	int len = str.length();
	int i = len - 1;
	while (i >= 0 && str[i] != '/') {
		i--;
	}
	std::string last_word;
	for (int j = i + 1; j < len; j++) {
		last_word += str[j];
	}
	return last_word;
}

/*
   Creates corresponding string data containing file name and save location absolute path.
   First argument - server side username.
   Second argument - server side file path.
   Third argument -client side file path.
*/
std::string create_file_information_string(std::string username, std::string sr_filepath, std::string cl_filepath)
{
	std::string absolute_filepath = "";
	std::string cl_filename = get_filename(cl_filepath);
	absolute_filepath += cl_filename;
	absolute_filepath += " ";
	if (sr_filepath[0] == '~' && sr_filepath[1] == '/') {
		absolute_filepath += "/home/";
		absolute_filepath += username;
		sr_filepath.erase(0, 1);
	}
	absolute_filepath += sr_filepath;
	return absolute_filepath;
}
/*
   Receives response from the server.
   First argument - socket descriptor.
*/
void get_response(int socket)
{
	int chrlen = 101;
	char answer[chrlen] = {0};
	if (recv(socket, answer, chrlen, 0) < 0) {
		perror("Error reading.");
		exit(1);
	}
	printf("%s\n", answer);
}

/*
  Configures communication between client and server.//???
  First argument - connection structure.
  Second argument - server IP address.
*/
void configure_comunication(struct sockaddr_in& hint, std::string s_ipaddress)
{
	hint.sin_family = AF_INET;
	hint.sin_port = htons(PORT);
	inet_pton(AF_INET, s_ipaddress.c_str(), &hint.sin_addr);
}

/*
   Sends data to server.
   First argument - socket descriptor.
   Second argument - client side file path.
   Third argument - server side username.
   Forth argument - server side file path.
*/
bool send_data(int sock, std::string cl_filepath, std::string s_username, std::string s_save_filepath)
{
	std::string buffer = create_file_information_string(s_username, s_save_filepath, cl_filepath);
	if (send (sock, buffer.c_str(), buffer.length(), 0) < 0) {
		perror("Error sending.");
		return false;
	} else {
		get_response(sock);
		std::string buffer_data = "";
		get_file_data(cl_filepath, buffer_data);
		std::string buffer_len = std::to_string(buffer_data.length());
		if (send(sock, buffer_len.c_str(), buffer_len.length(), 0) > 0) {
		get_response(sock);
			if (send(sock, buffer_data.c_str(), buffer_data.length(), 0) < 0) {
				perror("Error sending.");
				return false;
			}
		get_response(sock);
		get_response(sock);
		} else {
			perror("Error sending.");
			return false;
		}
	}
	return true;
}

void signal_handle(int signum)
{
        std::cout << "Aborting application." << std::endl;
        exit(signum);
}

// Programs execution start point.
int main(int argc,char** argv)
{
	signal(SIGABRT, signal_handle);
	signal(SIGINT, signal_handle);
	if (argc != 5) { // file path, server IP, server side username, server side file path.
		std::cout<<"Incorrect arguments count."<<std::endl;
	} else {
		std::string cl_filepath = argv[1];
		std::string s_ipaddress = argv[2];
		std::string s_username = argv[3];
		std::string s_save_filepath = argv[4];
		int sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 0) {
			perror("Error opening socket.");
			return 1;
		}
		struct sockaddr_in hint;
		configure_comunication(hint, s_ipaddress);
		if (connect (sock,(sockaddr *)&hint,sizeof(hint)) < 0) {
			perror("Error connecting.");
			return 1;
		}
		if (send_data(sock, cl_filepath, s_username, s_save_filepath) == false) {
			return 1;
		}
		close(sock);
	}
	return 0;
}
