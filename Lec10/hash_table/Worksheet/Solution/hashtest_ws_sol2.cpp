// Contains a solution to the final part of the hash table worksheet

#include <iostream>
#include <functional> // to use the C++ built-in string hash method
#include "hash_table_ws_sol.h"
#include "dynarray.h"

// so we don't have to use std:: for everything in the standard namespace
using namespace std;

struct MonsterRecord {
  string name;
  unsigned int AC;
  unsigned int HP;
  unsigned int speed;
  float CR;

  unsigned int hash() const;
  bool operator!=(const MonsterRecord& rhs) const;
};

unsigned int MonsterRecord::hash() const {
  // Have to use std::hash because this function is called "hash"
  // so to use the built-in hash we need to specify we want the one
  // in the standard namespace

  // In C++, hash<string> is a type that overloads the () operator.
  // So we get an instance of the hash type and then call it via ()
  // to actually compute the hash.

  std::hash<string> myHash;

  cout << myHash("hello") << endl;

  return myHash(name);
}

bool MonsterRecord::operator!=(const MonsterRecord& rhs) const {
  return name != rhs.name;
}

void printHashTable(const HashTable<MonsterRecord>& table) {
  DynamicArray<MonsterRecord> array = table.getItemsArray();

  cout << "Size: " << table.size() << endl;
  for (int i = 0; i < array.size(); i++) {
    cout << array[i].name << ' ' << array[i].AC << ' '
         << array[i].HP << ' ' << array[i].speed << ' ' << array[i].CR << endl;
  }
}

int main() {
  HashTable<MonsterRecord> table(10);
  MonsterRecord monsters[] = {
    {"Kobold", 12, 5, 30,  0.125},
    {"Ice Devil", 18, 180, 40, 14}
  };

  table.insert(monsters[0]);
  cout << "Does the table contain " << monsters[0].name << "? ";
  cout << table.contains(monsters[0]) << endl << endl;

  table.remove(monsters[0]);
  table.insert(monsters[1]);

  // Should print "Ice Devil", 18, 180, 40, 14

  printHashTable(table);
}
