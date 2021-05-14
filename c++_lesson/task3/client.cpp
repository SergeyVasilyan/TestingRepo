#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#include<fstream>
#define PORT 4113

void read_file(std::string file_path, std::string& data)
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
std::string get_last_word(const std::string& str)
{
    if (str.length() == 0)
    {
        std::cerr << "No string\n";
        return "";
    }
    int len = str.length();
    int i = len - 1;
    while (i >= 0 && str[i] != '/')
    {
        i--;
    }
    std::string last_word;
    for (int j = i + 1; j < len; j++)
    {
        last_word += str[j];
	}
	return last_word;
}
std::string get_server_filepaths (std::string str1, std::string str2)
{
	std::string cl_filename = get_last_word(str1);
	std::string buffer = "";
	buffer += cl_filename;
	buffer += " ";
	buffer += str2;
	return buffer;
}
void messenge(int socket)
{
	int chrlen = 101;
	char answer[chrlen] = {0};
	if (recv(socket, answer, chrlen, 0) < 0) {
		perror("Error reading.");
		exit(1);//heto poxell;
	}
	printf("%s\n", answer);
}
int main(int argc,char** argv) {
	if (argc != 4) { // file path, IP, server file path
		std::cout<<"Incorrect arguments count."<<std::endl;
	} else {
		std::string cl_filepath = argv[1];
		std::string s_ipaddress = argv[2];
		std::string s_save_filepath = argv[3];
		std::cout << s_save_filepath << std::endl;
		int sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 0) {
			perror("Error opening socket.");
			return 1;
		}
		// fill_value(hint);
		struct sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(PORT);
		inet_pton(AF_INET, s_ipaddress.c_str(), &hint.sin_addr);
		if (connect (sock,(sockaddr *)&hint,sizeof(hint)) < 0) {
			perror("Error connecting.");
			return 1;
		}
		std::string buffer = get_server_filepaths(cl_filepath, s_save_filepath);
		if (send (sock, buffer.c_str(), buffer.length(), 0) < 0) {
			perror("Error sending.");
			 return 1;
		} else {
			messenge(sock);
			std::string buffer_data = "";
			read_file(cl_filepath, buffer_data);
			std::string buffer_len = std::to_string(buffer_data.length());
			if (send(sock, buffer_len.c_str(), buffer_len.length(), 0) > 0) {
				messenge(sock);
				if (send(sock, buffer_data.c_str(), buffer_data.length(), 0) < 0) {
					perror("Error sending.");
					return 1;
				}
				messenge(sock);
				messenge(sock);
			} else {
				perror("Error sending.");
				return 1;
			}
		}
		close(sock);
	}
	return 0;
}
