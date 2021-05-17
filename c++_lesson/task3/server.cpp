#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include<fstream>
#define PORT 6113

// Check path validity.
bool check_path_validity(std::string str)
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
	if (check_path_validity(sr_filepath)) {
		if (sr_filepath[sr_filepath.length() - 1] != '/') {
			sr_filepath += '/';
		}
		sr_filepath += cl_filepath;
		return sr_filepath;
	} else {
		return "";
	}
}

// Struct sockaddr_in object fills value.???( localiny )
void configure_comunication(struct sockaddr_in& addr_local )
{
	addr_local.sin_family = AF_INET;
	addr_local.sin_port = htons(PORT);
	addr_local.sin_addr.s_addr = INADDR_ANY;
	bzero(&(addr_local.sin_zero), 8);
}

// Sends a message to the client.
void send_response(int new_sock, char* answer, int chrlen)
{
	if (send(new_sock, answer, chrlen, 0) < 0) {
		perror("Error sending.");
		exit(1);
	}
}

// Saves data in file.
void save_file(std::string file_path, char* buffer_data)
{
	std::ofstream outfile (file_path);
	for (int k = 0; buffer_data[k] != '\0'; k++) {
		outfile << buffer_data[k];
	}
	outfile.close();
}

void receive_file_path(int new_sock,std::string& file_path)
{
	char buffer[1024] = {0};
	if (recv(new_sock, buffer, 1024, 0) < 0) {
		perror("Error reading.");
		exit(1);
	} else {
		int chrlen = 101;
		char answer[chrlen] = "Server got path file.)";
		send_response(new_sock, answer, chrlen);
		std::cout << "Got file info." << std::endl;
		std::string s_data(buffer);
		file_path = create_file_path(s_data);
		if (file_path == "") {
			perror("Path incorrect.");
			exit(1);
		}
	}
}

void receive_file_data(int new_sock, std::string file_path)
{
	char buffer[1024] = {0};
	if (recv(new_sock, buffer, 1024, 0) < 0) {//buffer- file-i data-i chapy
		perror("Error reading.");
		exit(1);
	} else {
		int chrlen = 101;
		char answer[chrlen] = "Server got file size.)";
		send_response(new_sock, answer, chrlen);
		std::cout << "Got file size." << std::endl;
		int lenght = atoi(buffer) + 1;
		char buffer_data[lenght] = {0};
		if (recv (new_sock, buffer_data, lenght, 0) < 0) {
			perror("Error reading.");
			exit(1);
		} else {
			strcpy(answer, "Server got file data.)");
			std::cout << "Got file data." << std::endl;
			send_response(new_sock, answer, chrlen);
			save_file(file_path, buffer_data);
		}
	}
}

void communicate_with_client(int new_sock, struct sockaddr_in addr_remote, int& success)
{
	std::cout << "Client IP- " << addr_remote.sin_addr.s_addr << std::endl; //inch-vor convert petqa arvi 
	int chrlen = 101;
	std::string file_path = "";
	receive_file_path(new_sock,file_path);
	receive_file_data(new_sock, file_path);
	char messenge[chrlen] = "Everything is done well:)";
	send_response(new_sock, messenge, chrlen);
	std::cout << "Client connection ended." << std::endl;
	success = 1;
}

// ???
int main()
{
	int sock = socket (AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror ("ERROR: Failed to obtain Socket Descriptor.\n");
		return 1;
	}
	struct sockaddr_in addr_local;
	struct sockaddr_in addr_remote;
	configure_comunication(addr_local);
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
				communicate_with_client(new_sock, addr_remote, success);
				close(new_sock);

			}
		}
	}
	close(sock);
	return 0;
}
