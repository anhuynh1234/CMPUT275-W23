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
  int idx = 0;
  char current;
  // write your code here
  while(true){
    read(fd, &current, 1);

    if(current == '\0'){
      msg[idx] = '\0';
      break;
    }else{
      msg[idx] = current;
      idx++;
    }
  }
string number(msg);
int numb = stoi(number);
std::cout << numb/2 << std::endl;
  // close pipe from the write end 
  close(fd);

  return 0;
}