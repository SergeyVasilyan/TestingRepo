#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#define PORT 6996

std::string file_path(std::string str)
{
	struct data {
		std::string cl_filepath;
		std::string sr_username;
		std::string sr_filepath;
	}
	data aa;//heto kpoxem anuny
	std::string word = "";
	int count = 1;
	for (int k = 0; str[k] != '\0'; k++) { //sa arandzin funkcia kara lini 
            if (! isspace(str[k])) {
                word += str[k];
            } else {
				switch (count) {
				case 1:
					aa.cl_filepath = word;
					count++;
					break;
				case 2:
					aa.sr_username = word;
					count++;
					break;
				case 3:
					aa.sr_filepath = word;
					count++;
					break;
			}
				word = "";
           }
    }
	for (int k = str.lenght; str[k] != '/'; k--) {
            word += str[k];
	}
	aa.sr_username += "/";
	aa.sr_username += aa.sr_filepath;
	aa.sr_username += "/";
	aa.sr_username += word;
	return aa.sr_username;

}
int main() {
	int sock = socket (AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		printf ("ERROR: Failed to obtain Socket Descriptor.\n");
		return (0);
	}
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
	if (listen (sock, SOMAXCONN) < 0) {
		printf ("ERROR: Failed to listen Port %d.\n", PORT);
		return (0);
	}
	int success = 0;
	while (success == 0) {
		if ((int new_sock = accept(sockfd, (struct sockaddr *)&addr_remote, sizeof(struct sockaddr_in))) == -1) {
			printf ("ERROR: Obtain new socket descriptor error.\n");
		} else {
			if (!fork()) {
				char buffer[4096] = {0};
				if (recv(new_sock, buffer, strlen(buffer), 0) < 0) {
					perror("Error sending.");
				} else {
					std::string s_data(buffer);
					std::string file_path = file_path(s_data);
					//file open .....
					// file-i parunakutyunnenq stanum 
					//bufferi pahy....
					if (recv (new_sock, buffer, strlen(buffer), 0) < 0) {
						perror("Error sending.");
					} else {
						//stananq parunakutyuny ev save anenq
						//ev patasxany uxarkenq , vor ameninch ok a
					}
					success = 1;
					close(new_sock);
				}
			}

		}
	}
	close(sock);
	return 0;
}
