#include"matrix.h"
#include<iostream>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fstream>
#include<cstring> 
#define PORT 6996

void input_file(std::string& buffer1)
{
	buffer1 = "";
	std::string data1 = "";
	std::string str = "";
	std::string file_name = "";
	std::cin >> file_name; // file path.
	std::ifstream file_input(file_name);
	if ( ! file_input.is_open()) {
		throw std::ifstream::failure {"File isn't open."};
	}
	while (getline(file_input, str)) {
		for (int k = 0; str[k] != '\0'; k++) {
			if (! isspace(str[k])) {
				data1 += str[k];
			} else {
				if(data1 != "") {
					buffer1 += data1;
					buffer1 += " ";
				}
			}
		}
		if (data1 != "") {
			buffer1 += data1;
			buffer1 += " ";
		}
	}
	file_input.close();
}
int main()
{
	int sock = 0;
	std::string s_buffer1 = "";
	std::string s_buffer2 = "";
	std::string s_rows = "";
	std::string s_cols = "";
	struct sockaddr_in serv_addr;
	if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error.\n");
		return -1;
	}
	serv_addr.sin_family = AF_UNIX;
	serv_addr.sin_port = htons(PORT);
	/*if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
		printf("\nInvalid address/ Address not supported.\n");
		return -1;
	}*/
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("\nConnection Failed.\n");
		return -1;
	}
	std::cin >> s_rows;
	std::cin >> s_cols;
	s_buffer1 += s_rows;
	s_buffer1 += " ";
    s_buffer1 += s_cols;
	input_file(s_buffer2);
	const void * buffer1 = s_buffer1.c_str();
	const void * buffer2 = s_buffer2.c_str();
	void* buffer3;
	send(sock, buffer1, 1024, 0);
	send(sock, buffer2, 1024, 0);
        if (recv(sock, buffer3, 1024, 0) > 0) { // std::string *sp = static_cast<std::string*>(vp);
			char* ch_buffer3 = (char *)buffer3;
			printf("%s\n", ch_buffer3);
	} else {
		printf("\nServer don't work.\n");
	}
	close(sock);
	return 0;
}
