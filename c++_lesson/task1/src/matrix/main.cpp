#include"matrix.h"
#include<iostream>
#include<csignal>
#include<pthread.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fstream>
#include<cstring> 
#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD -12
#define SUCCESS 0
#define PORT 6996
void signal_handel(int signum)
{
	std::cout << "Interrupt signal (" << signum <<") received." << std::endl;
	exit(signum);
}

void check_assignment_operator()
{
	Matrix mat1(3,2);
	std::cin >> mat1;
	mat1 = mat1;
	std::cout << mat1 << std::endl;
}

void check_equality_operator()
{
	Matrix mat1(3,2);
	Matrix mat2(5,9);
	if (mat1 == mat2) {
		std::cout << " Matrices are equal. " <<std::endl;
	}
	std::cout << " Matrices aren't equal. " <<std::endl;
}

void bad_check_sum_operator()
{
	Matrix mat1(3,2);
	std::cin >> mat1;
	Matrix mat2(5,9);
	Matrix mat3 = mat1 + mat2;
	std::cout << mat3 << std::endl;
}

void check_sub_operator()
{
	Matrix mat1(3,2);
	std::cin >> mat1;
	Matrix mat2(3,2);
	mat2[0][0] = 3;
	mat2[2][1] = 5.222;
	Matrix mat3 = mat1 - mat2;
	std::cout << mat3 << std::endl;
}

void bad_check_scalar_with_assignment_operator()
{
	Matrix mat1(3,2);
	std::cin >> mat1;
	mat1 *= mat1;
	std::cout << mat1 << std::endl;
}

void check_scalar_with_assignment_operator()
{
	Matrix mat1(2,2);
	mat1[0][0] = 5;
	mat1[0][1] = 1;
	mat1[1][0] = 2;
	mat1[1][1] = 7;
	mat1 *= mat1;
	std::cout << mat1 << std::endl;
}
void check_multiplication_number()
{
	/*	
		Matrix mat1(2,2);
		mat1[0][0] = 1;
		mat1[0][1] = 1;
		mat1[1][0] = 1;
		mat1[1][1] = 1;
		mat1 = 3 * mat1;
		mat1 = mat1 * 6;
		std::cout << mat1 << std::endl;
	/*
	 */
	Matrix mat1(2,2);
	mat1[0][0] = 1;
	mat1[0][1] = 1;
	mat1[1][0] = 1;
	mat1[1][1] = 1;
	double a;
	std::cin >> a;
	mat1 = a * mat1;
	std::cout << mat1 << std::endl;

}
void check_cin_operator()
{
	Matrix mat1(3,3); // stugel chaperi anpatasxanutyuny ev convert chlinely 
	std::cout << "object created." << std::endl;
	std::cin >> mat1;
}
bool check_double(const std::string& str)
{
        try {
                double result = std::stod(str);
		return true;
        } catch (const std::invalid_argument& ia) {
                return false;
        }
}
bool check_data(std::string str, bool flag)
{
	std::string row = "";
	int count = 1;
	std::string word = "";
	for (auto x : str) {
		if (x == ' ') {
			if(check_double(word)) {
				if(count == 1) {
					row = word;
					count++;
				}
				word = "";
			} else {
				return false;
			}
		} else {
			word = word + x;
		}
	}
	if(word != "") {
		if( ! check_double(word)) {
			return false;
		}
	}
	if (flag == true) {
		return row == word;
	}
}
void* server(void *args)
{
	int server_fd, new_socket, new1_socket;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	if ((server_fd = socket (AF_UNIX, SOCK_STREAM, 0)) == 0) {
		perror("Socket failed.");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_UNIX;
	address.sin_addr.s_addr = INADDR_ANY; //INADDE_ANY соответствует адресу локального компьютера.
	address.sin_port = htons(PORT);

	if (bind (server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("Bind failed.");
		exit(EXIT_FAILURE);
	}
	if (listen (server_fd, 1) < 0) {
		perror("Listen failed.");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept (server_fd, (struct sockaddr *)&address,
				  (socklen_t*)&addrlen)) < 0) {
		perror("Accept failed.");
		exit(EXIT_FAILURE);
	}
	if (recv (new_socket, buffer, strlen(buffer) > 0) {///sxal mxal banner kaa
		if (check_data(buffer, true)) {
			if (recv (new_socket, buffer, strlen(buffer) > 0) {
				if (check_data(buffer, false)) {
					buffer = 'True';
					send(new_socket, buffer, strlen(buffer), 0);
					return SUCCESS;
				} else {
					buffer = 'True';
                                	send(new_socket, buffer, strlen(buffer), 0);
                                	return SUCCESS;
				}
			} else {
				printf("\nServer don't work.\n");
				return;
			}
		} else {
			buffer = 'True';
                        send(new_socket, buffer, strlen(buffer), 0);
                        return SUCCESS;
		}
	} else {
		printf("\nServer don't work.\n");
		return -1;
	}
}
int main()
{
	signal(SIGABRT, signal_handel);
	pthread_t thread;
	int status = 0;
	int status_addr = 0;
	status = pthread_create(&thread, NULL, server, NULL);
	if (status != 0) {
		printf("Main error: can't create thread, status = %d\n", status);
		exit(ERROR_CREATE_THREAD);
	}
	status = pthread_join(thread, (void**)&status_addr);
	if (status != SUCCESS) {
		printf("Main error: can't join thread, status = %d\n", status);
		exit(ERROR_JOIN_THREAD);
	}
	//  check_assignment_operator();
	//  check_equality_operator();
	//  bad_check_sum_operator();
	check_sub_operator();
	//  bad_check_scalar_with_assignment_operator();
	//  check_scalar_with_assignment_operator();
	//  check_multiplication_number();
	//  check_cin_operator();
	return 0;
}
