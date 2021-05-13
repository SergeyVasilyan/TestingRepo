#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include<fstream>
#define PORT 3113

bool check_exist_file(std::string str)
{
	std::ifstream test(str);
	if( ! test) {
		return false;
	}
	std::cout << "1" << std::endl;
	return true;
}

std::string create_file_path(std::string str)
{
	std::string cl_filepath = "";
	std::string sr_filepath = "";
	std::string word = "";
	int count = 1;
	std::cout << "2" << std::endl;
	for (int k = 0; str[k] != '\0'; k++) { //sa arandzin funkcia kara lini 
		if (! isspace(str[k])) {
			word += str[k];
		} else {
			std::cout << word << std::endl;
			cl_filepath = word;
			word = "";
			std::cout << "4" << std::endl;
		}
	}
	sr_filepath = word;
	if (check_exist_file(sr_filepath)) {
		sr_filepath += "/";
		sr_filepath += cl_filepath;
		return sr_filepath;
	} else {
		// tralala
		return "";
	}
}

int main()
{
	int sock = socket (AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		printf ("ERROR: Failed to obtain Socket Descriptor.\n");
		return (0);
	}
	std::cout << "5" << std::endl;
	struct sockaddr_in addr_local;
	struct sockaddr_in addr_remote;
	addr_local.sin_family = AF_INET;
	addr_local.sin_port = htons(PORT);
	addr_local.sin_addr.s_addr = INADDR_ANY;
	bzero(&(addr_local.sin_zero), 8); // Flush the rest of struct
	if (bind (sock, (struct sockaddr*)&addr_local, sizeof(struct sockaddr)) == -1 ) {
		printf ("ERROR: Failed to bind Port %d.\n",PORT);
		return (0);
	}
	std::cout << "6" << std::endl;
	if (listen (sock, SOMAXCONN) < 0) {
		printf ("ERROR: Failed to listen Port %d.\n", PORT);
		return (0);
	}
	std::cout << "7" << std::endl;
	int success = 0;
	while (success == 0) {
		int addrlen = sizeof(addr_remote);
		int new_sock = accept(sock, (struct sockaddr *)&addr_remote, (socklen_t*)&addrlen);
		if (new_sock == -1) {
			printf ("ERROR: Obtain new socket descriptor error.\n");
		} else {
			std::cout << "8" << std::endl;
			if ( ! fork()) {
				char buffer[1024] = {0};
				if (recv(new_sock, buffer, 1024, 0) < 0) {
					perror("Error reading.");
				} else {
					char answer[1024] = "OK";
					if (send(new_sock, answer, strlen(answer), 0) < 0) {
						printf("\nError sending.\n");
					}
					std::cout << "9" << std::endl;
					std::string s_data(buffer);
					std::string file_path = create_file_path(s_data);
					buffer[1024] = {0};
					if (recv(new_sock, buffer, 1024, 0) < 0) {//buffer fili chapy
						perror("Error reading.");
					} else {
						if (send(new_sock, answer, strlen(answer), 0) < 0) {
							printf("\nError sending.\n");
						}
						std::cout << "10" << std::endl;
						int lenght = atoi(buffer);
						char buffer_data[lenght] = {0};
						if (recv (new_sock, buffer_data, lenght, 0) < 0) {
							perror("Error reading.");
						} else {//buffer_data-n berel stringi
							if (send(new_sock, answer, strlen(answer), 0) < 0) {
								printf("\nError sending.\n");
							}
							std::cout << "11" << std::endl;
							std::ofstream outfile (file_path);
							for (int k = 0; buffer_data[k] != '\0'; k++) {
								outfile << buffer_data[k];//lav sxala es masy
							}
							std::cout << "12" << std::endl;
							outfile.close();
							//ev patasxany uxarkenq , vor ameninch ok a
							std::string messenge = "OK";
							if (send(new_sock, messenge.c_str(), messenge.length(), 0) < 0) {
								printf("\nError sending.\n");
							}
							std::cout << "13" << std::endl;
						}
						success = 1;
						close(new_sock);
						std::cout << "14" << std::endl;
					}
				}

			}
		}
	}
	close(sock);
	return 0;
}
