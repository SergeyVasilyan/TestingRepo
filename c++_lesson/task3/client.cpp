#include <iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#include<fstream>
#define PORT 6996

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
		data += '\0';
		str = "";
	}
	file_input.close();
}
int main(int argc,char** argv) {
	if (argc != 5) { // file path, server username, IP, file path
		std::cout<<"Incorrect arguments count."<<std::endl;
	} else {
		std::string c_filename = argv[1];//c_ip uxxarkel petq a??
		std::string s_username = argv[2];
		std::string s_ipaddress = argv[3];
		std::string s_save_filepath = argv[4];
		int sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 0) {
			perror("Error opening socket.");
		}
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(PORT);
		inet_pton(AF_INET, s_ipaddress.c_str(), &hint.sin_addr);
		/*if (bind (sock, (struct sockaddr *)&hint, sizeof(hint)) < 0) {
		  perror("Bind failed.");
		  exit(EXIT_FAILURE);
		  }*/
		if (connect (sock,(sockaddr *)&hint,sizeof(hint)) < 0) {
			perror("Error connecting.");
		}
		std::string s_buffer = "";
		s_buffer += c_filename;
		s_buffer += " ";
		s_buffer += s_username;
		s_buffer += " ";
		s_buffer += s_save_filepath;
		int lenght = s_buffer.length() + 1;
		char *buffer = new char[lenght];
		strcpy(buffer, s_buffer.c_str());
		if (send (sock, buffer, lenght, 0) < 0) {
			perror("Error sending.");
		} else {
			std::string buffer2 = "";
			std::string buffer3 = (std::string)lenght;
			if (send(sock, buffer3.c_str(), buffer3.lenght(), 0) < 0) {
				read_file(c_filename, buffer2);
				if (send(sock, buffer2.c_str(), lenght, 0) < 0) {
					perror("Error sending.");
				}
				char buffer4[1024] = {0};
				if (recv(sock, buffer4, strlen(buffer4), 0) > 0) {
					printf("%s\n", buffer4);
				} else {
					printf("\nError reading.\n");
				}
			} else {
				printf("\nError reading.\n");
			}
		}
		close(sock);
	}
	return 0;
}
