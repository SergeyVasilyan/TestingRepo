#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include<fstream>
#define PORT 4113

bool check_exist_file(std::string str)
{
	std::ifstream test(str);
	if( ! test) {
		return false;
	}
	return true;
}

std::string create_file_path(std::string str)
{
	std::string cl_filepath = "";
	std::string sr_filepath = "";
	std::string word = "";
	for (int k = 0; str[k] != '\0'; k++) {
		if (! isspace(str[k])) {
			word += str[k];
		} else {
			cl_filepath = word;
			word = "";
		}
	}
	sr_filepath = word;
	if (check_exist_file(sr_filepath)) {
		sr_filepath += "/";
		sr_filepath += cl_filepath;
		return sr_filepath;
	} else {
		return "";
	}
}

int main()
{
	int chrlen = 101;
	int sock = socket (AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror ("ERROR: Failed to obtain Socket Descriptor.\n");
		return 1;
	}
	struct sockaddr_in addr_local;
	struct sockaddr_in addr_remote;
	addr_local.sin_family = AF_INET;
	addr_local.sin_port = htons(PORT);
	addr_local.sin_addr.s_addr = INADDR_ANY;
	bzero(&(addr_local.sin_zero), 8);
	if (bind (sock, (struct sockaddr*)&addr_local, sizeof(struct sockaddr)) == -1 ) {
		perror ("ERROR: Failed to bind Port");
		return 1;
	}
	if (listen (sock, SOMAXCONN) < 0) {
		perror ("ERROR: Failed to listen Port");
		return 1;
	}
	int success = 0;
	while (success == 0) {
		int addrlen = sizeof(addr_remote);
		int new_sock = accept(sock, (struct sockaddr *)&addr_remote, (socklen_t*)&addrlen);
		if (new_sock == -1) {
			perror ("ERROR: Obtain new socket descriptor error.");
			return 1;
		} else {
			if ( ! fork()) {
				char buffer[1024] = {0};
				if (recv(new_sock, buffer, 1024, 0) < 0) {
					perror("Error reading.");
					return 1;
				} else {
					char answer[chrlen] = "Server got path file.)";
					if (send(new_sock, answer, chrlen, 0) < 0) {
						perror("Error sending.");
						return 1;
					}
					std::string s_data(buffer);
					std::string file_path = create_file_path(s_data);
					if (file_path == "") {
						perror("Path incorrect.");
						return 1; //kpoxes heto
					}
					buffer[1024] = {0};
					if (recv(new_sock, buffer, 1024, 0) < 0) {//buffer- file-i data-i chapy
						perror("Error reading.");
						return 1;
					} else {
						strcpy(answer, "Server got file size.)");
						if (send(new_sock, answer, chrlen, 0) < 0) {
							perror("Error sending.");
							return 1;
						}
						int lenght = atoi(buffer) + 1;
						char buffer_data[lenght] = {0};
						if (recv (new_sock, buffer_data, lenght, 0) < 0) {
							perror("Error reading.");
							return 1;
						} else {
							strcpy(answer, "Server got file data.)");
							if (send(new_sock, answer, chrlen, 0) < 0) {
								perror("Error sending.");
								return 1;
							}
							std::ofstream outfile (file_path);
							for (int k = 0; buffer_data[k] != '\0'; k++) {
								outfile << buffer_data[k];
							}
							outfile.close();
							std::string messenge = "Everything is done well:)";
							if (send(new_sock, messenge.c_str(), messenge.length(), 0) < 0) {
								perror("Error sending.");
								return 1;
							}
						}
						success = 1;
						close(new_sock);
					}
				}

			}
		}
	}
	close(sock);
	return 0;
}
