#include <iostream>
#include "dynarray.h"

using namespace std;

void dumpArray(DynamicArray<int> &a) {
  cout << "Size is: " << a.size() << endl;
  cout << "Items:";
  for (unsigned int i = 0; i < a.size(); i++) {
    cout << ' ' << a[i];
  }
  cout << endl << endl;
}

int main() {
  DynamicArray<int> a(10);

  cout << "Might be nonsense since entries are not initialized yet" << endl;
  dumpArray(a);

  for (unsigned int i = 0; i < a.size(); i++) {
    a[i] = 2*i;
  }

  cout << "Should be even numbers" << endl;
  dumpArray(a);

  // uncomment each section bellow as you implement it

  // EXERCISE 2: INSERT
  cout << "First we will test the insert function" << endl;
  a.insert(3, 21);
  a.insert(3, 27);
  a.insert(7, 19);
  dumpArray(a);

  // // Expected output: 0 2 4 27 21 6 8 19 10 12 14 16 18


  // EXERCISE 3: ERASE
  cout << "Next we will try to erase some items" << endl;
  a.erase(1);
  a.erase(7);
  a.erase(0);
  dumpArray(a);

  // Expected output: 4 27 21 6 8 19 12 14 16 18

  // EXERCISE 4: POP_BACK
  cout << "Next we will test popBack" << endl;
  int popBackValue = a.popBack();
  cout << "popBackValue value: " << popBackValue << endl;
  dumpArray(a);
  popBackValue = a.popBack();
  cout << "popBackValue value: " << popBackValue << endl;
  dumpArray(a);

  // Should remove the last value in each case

  // EXERCISE 5: FIND
  cout << "Finally we will use the find method" << endl;
  int findValue = a.find(6);
  cout << "findValue for 6: " << findValue << endl;
  dumpArray(a);
  findValue = a.find(103);
  cout << "findValue for 103: " << findValue <<  endl;
  dumpArray(a);

  // findValue for 6 is 3, findValue for 103 is 8


  return 0;
}
