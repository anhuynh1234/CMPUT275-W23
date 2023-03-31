#include <iostream> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <cstring>      // strerrno
#include <errno.h>      // errno

#define _MSG_MAX_LENGTH 100

using namespace std;

int main() {

  const char * pipename = "./pipe";

  // pipe is persumably created on the sender side, 
  // so we just open it here for read-only access
  int fd = open(pipename, O_RDONLY);
  if ( fd == -1 ) {
    // errno is set so we can check it
    cout << "Pipe open failed" << endl;
    cout << errno << ": " << strerror(errno) << endl << flush;
    exit(1);
  }
  cout << "Named pipe opened for reading..." << endl;

  char msg[_MSG_MAX_LENGTH];
  char current;
  int idx = 0;

  // write your code here

  while(true) {
    read(fd, &current, 1);
    msg[idx++] = current;

    // jump out of the loop after reading null
    if(current == '\0') break;
  }

  // convert a c-string to int
  cout << atoi(msg)/2 << endl;

  // close pipe from the write end 
  close(fd);

  return 0;
}