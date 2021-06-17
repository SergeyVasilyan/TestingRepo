#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  // unbuffered system-call level write() access:
  ::fclose(stderr);
  if (::dup2(STDOUT_FILENO, STDERR_FILENO) == -1) {
    cout << "dup2() failed!" << endl;
    return -1;
  }
  char msg_err[] = "write(STDERR_FILENO) OK.\n";
  char msg_out[] = "write(STDOUT_FILENO) still OK.\n";
  write(STDERR_FILENO, msg_err, strlen(msg_err));
  write(STDOUT_FILENO, msg_out, strlen(msg_out));

  // buffered C-style access: (ordering may be weird w/o fflush())
  stderr = ::fdopen(STDOUT_FILENO, "a");
  fprintf(stderr, "fprintf(stderr) OK.\n");
  fprintf(stdout, "fprintf(stdout) still OK.\n");

  // buffered C++ access:
  std::cerr.rdbuf(std::cout.rdbuf());
  cerr << "cerr << OK.\n";
  cout << "cout << still OK.\n";
}
