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

  // create a pipe that can be opened by all users
  // for read/write operations
  mkfifo(pipename, 0666);
  int fd = open(pipename, O_WRONLY); // open for write-only access

  char msg[_MSG_MAX_LENGTH];
  char delimiter = '\n';

  while(true){
    // zero out the buffer at first
    memset(msg, 0, _MSG_MAX_LENGTH);

    // getline extracts characters from istream until
    // the delimiting character (\n) is extracter or the
    // max number of characters are written to the buffer 
    // (including the terminating null character)
    // note: delim is discarded and not written to msg
    cin.getline(msg, _MSG_MAX_LENGTH); 

    // message is written to pipe
    // strlen(msg) returns the length of msg because
    // the remaining characters are set to null (memset)
    write(fd, msg, strlen(msg));

    // we also write delimiter to pipe so the receiver 
    // knows when a line ends and can interpret the message
    // this is part of the protocol used for communication
    write(fd, &delimiter, 1);

    // continue reading from stdin until the message is "quit"
    if( strcmp(msg, "quit") == 0 ){
      break;
    }
  }  

  // close pipe from the write end 
  close(fd);

  // reclaim the backing file 
  unlink(pipename);

  return 0;
}