#include <iostream> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <string.h>

#define _MSG_MAX_LENGTH 100

using namespace std;

int main() {

  const char * pipename = "./sharedch";

  // pipe is persumably created on the sender side, 
  // so we just open it here
  int fd = open(pipename, O_RDONLY); // open for read-only access

  char msg[_MSG_MAX_LENGTH];
  char current;
  int idx = 0;

  if(fd == -1){
    std::cerr << "Error: cannot open anmed pipe:" << std::endl;
    unlink(pipename);
  }
  /* TODO: While '\n' is not read from the pipe,
    read data, one character at a time, from the pipe
    and store it in msg, starting from msg[0].
    Upon reading '\n', print the full line to stdout 
    and start populating msg from index 0 again
    Continue until the received msg is "quit"
  */
  while(true){
    memset(msg, 0, _MSG_MAX_LENGTH);

    read(fd, &current, 1);

    if(current != '\n'){
      msg[idx] = current;
      idx++;
    }else if(current == '\n'){
      idx = 0;
      cout << msg << endl;
    }

    if(!strcmp(msg, "quit")){
      break;
    }
  }
  
  // close pipe from the write end 
  close(fd);

  return 0;
}