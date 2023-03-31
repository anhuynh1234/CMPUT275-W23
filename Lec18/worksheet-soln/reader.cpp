#include <iostream> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <cstring>      // strerrno
#include <string>       // to_string
#include <errno.h>      // errno

using namespace std;

int main() {

  const char * pipename = "./pipe";

  // create a pipe that can be opened by all users
  // for read/write operations
  mkfifo(pipename, 0666);

  // open for write-only access
  int fd = open(pipename, O_WRONLY);
  
  if ( fd == -1 ) {
    // errno is set so we can check it
    cout << "Pipe open failed" << endl;
    cout << errno << ": " << strerror(errno) << endl << flush;
    exit(1);
  }
  cout << "Named pipe opened for reading..." << endl;

  char n = '\0';
  int number;
  string mystr;

  // cin reads an integer from stdin
  cin >> number;

  // std::to_string converts int to string
  mystr = to_string(number);

  // using range based for loop
  for( char c : mystr ) {
    // note: null character won't be included
    write(fd, &c, 1);
  }

  // let's write null to pipe to signal end of message
  write(fd, &n, 1); 

  // let this process sleep for 5s
  sleep(5);

  // close pipe from the write end 
  close(fd);

  // reclaim the backing file 
  unlink(pipename);

  return 0;
}