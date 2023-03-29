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
  int idx;

  /* TODO: While '\n' is not read from the pipe,
    read data, one character at a time, from the pipe
    and store it in msg, starting from msg[0].
    Upon reading '\n', print the full line to stdout 
    and start populating msg from index 0 again
    Continue until the received msg is "quit"
  */

  // close pipe from the write end 
  close(fd);

  return 0;
}