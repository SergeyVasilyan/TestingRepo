#include<iostream>

void aa () {

	std::cout << "fggf";


}
int main(){

	freopen( "output.txt", "w", stdout );
	aa();
	return 0;
}
void log_add(char* filename)
{
        std::string now = get_current_datetime();
        log_file << "DATE: " << std::endl;
        log_file << now << std::endl;
        log_file << "Started test" << std::endl;
        log_file << "Program output: " << std::endl;
        //en cragri outputy tpel
        log_file << "If fail print reason- " << std::endl;
        //inchvor stugumner vor jongnvi error exela te xhe
        log_file << "Test result - " << std::endl;

}

