#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main(){
	int sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1)
		return 1;
	int port=54666;
	std::string ipAddress="127.0.0.1";
	sockaddr_in hint;
	hint.sin_family=AF_INET;
	hint.sin_port=htons(port);
	inet_pton(AF_INET,ipAddress.c_str(),&hint.sin_addr);
	int connects=connect(sock,(sockaddr*)&hint,sizeof(hint));
	if(connects==-1)
		return 1;
	char buf[4096];
	std::string userInput;
	while(true){
		getline(std::cin,userInput);
		if(userInput=="exit")
			break;
		int sendRes=send(sock,userInput.c_str(),userInput.size()+1,0);
		if(sendRes==-1){
			std::cout<<"Could not send to server! \r\n";
			continue;
		}
		memset(buf,0,4096);
		int bytesReceived=recv(sock,buf,4096,0);
		if(bytesReceived==-1){
			std::cout<<"Response error \r\n";
		}else
			std::cout<<"Server> "<<std::string(buf,bytesReceived)<<"\r\n";
	}
	close(sock);
return 0;
}
