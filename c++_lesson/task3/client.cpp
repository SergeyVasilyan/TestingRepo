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
	std::ifstream file_input(file_path);
        if ( ! file_input.is_open()) {
                throw std::ifstream::failure {"File isn't open."};
        }
	std::string str = "";
        while (getline(file_input, str)) {
                for (int k = 0; str[k] != '\0'; k++) {
                                data += str[k];
                }
		data += '\0';
        }
        file_input.close();
}
int main(int argc,char** argv) {
	if (argc != 5) {
		std::cout<<"Incorrect arguments count."<<std::endl;
	} else {
		std::string c_filename = argv[1];
		std::string s_username = argv[2];
		std::string s_ipAddress = argv[3];
		std::string s_save_filepath = argv[4];
		int sock=socket(AF_INET,SOCK_STREAM,0);
		if (sock < 0) {
			error("Error opening socket.");
		}
		sockaddr_in hint;
		hint.sin_family=AF_INET;
		hint.sin_port=htons(PORT);
		inet_pton(AF_INET,s_ipAddress.c_str(),&hint.sin_addr);
		if (bind (sock, &hint, sizeof(hint)) < 0) {
			perror("Bind failed.");
			exit(EXIT_FAILURE);
		}
		if (connect(sock,(sockaddr*)&hint,sizeof(hint)) < 0) {
			error("Error connecting.");
		}
		std::string s_buffer = "";
		s_buffer += c_filename;
		s_buffer += " ";
		s_buffer += s_username;
		s_buffer += " ";
		s_buffer += s_ipAddress;
		s_buffer += " ";
		s_buffer += s_save_filepath;
		int lenght = s_buffer.length() + 1;
		char *buffer = new char[lenght];
		strcpy(cstr, s_buffer.c_str());
		if (send(sock, buffer, lenght, 0) < 0) {
			error("Error sending.");
		} else {
			std::string buffer2;
			//berel void*
			read_file(c_filename, buffer2);
			if (send(sock, buffer2, lenght, 0) < 0) {
                        error("Error sending.");
                }
		char buffer3[1024] = {0};
		if (recv(sock, buffer3, 1024, 0) > 0) { // std::string *sp = static_cast<std::string*>(vp);
			//char* ch_buffer3 = (char *)buffer3;
			printf("%s\n", buffer3);
		} else {
			printf("\nError reading.\n");
		}
		}
		close(sock);
	}
	return 0;
}
