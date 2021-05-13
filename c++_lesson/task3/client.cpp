#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#include<fstream>
#define PORT 3113

void read_file(std::string file_path, std::string& data)
{
	std::cout << "111" << std::endl;
	std::string str = "";
	std::ifstream file_input(file_path);
	if ( ! file_input.is_open()) {
		throw std::ifstream::failure {"File isn't open."};
	}
	std::cout << "22" << std::endl;
	while (getline(file_input, str)) {
		for (int k = 0; str[k] != '\0'; k++) {
			data += str[k];
		}
		std::cout << "33" << std::endl;
		data += "\0";
		str = "";
	}
	std::cout << "44" << std::endl;
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
int main(int argc,char** argv) {
	if (argc != 4) { // file path, IP, server file path
		std::cout<<"Incorrect arguments count."<<std::endl;
	} else {
		std::string c_filename = argv[1];
		//char* berel string
		std::string s_ipaddress = argv[2];
		std::string s_save_filepath = argv[3];
		int sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 0) {
			perror("Error opening socket.");
		}
		std::cout << "66" << std::endl;
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(PORT);
		inet_pton(AF_INET, s_ipaddress.c_str(), &hint.sin_addr);
		/*if (bind (sock, (struct sockaddr *)&hint, sizeof(hint)) < 0) {
		  perror("Bind failed.");
		  exit(EXIT_FAILURE);
		  }*/
		std::cout << "77" << std::endl;
		if (connect (sock,(sockaddr *)&hint,sizeof(hint)) < 0) {
			perror("Error connecting.");
		}
		std::cout << "88" << std::endl;
		std::string s_buffer = "";
		std::string word = "";
		word = get_last_word(c_filename);
		s_buffer += word;
		s_buffer += " ";
		s_buffer += s_save_filepath;
		std::cout << "10" << std::endl;
		if (send (sock, s_buffer.c_str(), s_buffer.length(), 0) < 0) {
			perror("Error sending.");
		} else {
			char answer[1024] = {0};
			if (recv(sock, answer, 1024, 0) > 0) {
				printf("\nError reading.\n");
			}
			printf("%s\n", answer);
			std::cout << "11" << std::endl;
			std::string buffer2 = "";
			read_file(c_filename, buffer2);
			std::string buffer3 = std::to_string(buffer2.length());
			if (send(sock, buffer3.c_str(), buffer3.length(), 0) > 0) {
				if (recv(sock, answer, strlen(answer), 0) > 0) {
					printf("\nError reading.\n");
				}
				printf("%s\n", answer);
				std::cout << "12" << std::endl;
				if (send(sock, buffer2.c_str(), buffer2.length(), 0) < 0) {
					perror("Error sending.");
				}
				if (recv(sock, answer, 1024, 0) > 0) {
					printf("\nError reading.\n");
				}
				printf("%s\n", answer);
				std::cout << "13" << std::endl;
				char buffer4[1024] = {0};
				if (recv(sock, buffer4, 1024, 0) > 0) {
					printf("%s\n", buffer4);
				} else {
					std::cout << "14" << std::endl;
					printf("\nError reading.\n");
				}
				std::cout << "15" << std::endl;
			} else {
				printf("\nError sending.\n");
			}
		}
		std::cout << "16" << std::endl;
		close(sock);
	}
	return 0;
}
