// Tests only the worksheet solutions.

#include <iostream>
#include "worksheet_sol.h"

using namespace std;


// Checks the linked list for proper structure.
// Uses asserts
void checkList(LinkedList<int>& list) {
  ListNode<int> *first = list.getFirst(), *last = list.getLast();

  if (list.size() == 0) {
    // if the list has size zero, the first and last better be null
    assert(first == NULL && last == NULL);
    return;
  }

  // otherwise, assert the first and last pointers behave properly
  assert(first != NULL && last != NULL);
  assert(first->prev == NULL && last->next == NULL);
  if (list.size() == 1) {
    assert(first == last);
    return;
  }

  // if we get here, the list has size >= 2, presumably
  ListNode<int> *node = first;
  unsigned int nodeCount = 0; // number of nodes we have iterated past
  while (node != last) {
    // as long as we are not at the last node, this "node"" should point ahead to another
    // list node and that node should point back to this "node"
    assert(node->next != NULL && node->next->prev == node);
    node = node->next;
    ++nodeCount;

    assert(nodeCount < list.size());
  }

  assert(nodeCount+1 == list.size());

}


void checkAndPrint(LinkedList<int>& list) {
  checkList(list);

  cout << "List size: " << list.size() << endl;
  cout << "Contents:";

  for (ListNode<int> *node = list.getFirst(); node != NULL; node = node->next) {
    cout << ' ' << node->item;
  }

  cout << endl << endl;
}

void checkFindLast() {
  // checks finding the last 2 in the list
  cout << "*** BEGIN checkFindLast ***" << endl;
  LinkedList<int> list;
  int vals[] = {3, 2, -1, 2, 1, 3, 5, 2, 1};
  for (int i = 0; i < 9; i++) {
    list.insertBack(vals[i]);
  }
  checkAndPrint(list);
  ListNode<int>* node = list.findLast(2);
  cout << node->item << endl;
  list.removeNode(node);
  checkAndPrint(list);

  // now checks on a list with only size 1
  // (is also testing that remove works on a list with size 1)
  list.clear();
  list.insertBack(17);
  checkAndPrint(list);
  node = list.findLast(17);
  list.removeNode(node);
  checkAndPrint(list);
  cout << "*** END checkFindLast ***" << endl << endl << endl;

}

void checkRemoveAllButOne() {
  cout << "*** BEGIN checkRemoveAllButOne ***" << endl;
  LinkedList<int> list;
  int vals[] = {3, 2, -1, 2, 1, 3, 5, 2, 1};
  for (int i = 0; i < 9; i++) {
    list.insertBack(vals[i]);
  }

  list.removeAllButOne(2);
  checkAndPrint(list);
  list.removeAllButOne(1);
  checkAndPrint(list);
  list.removeAllButOne(5);
  checkAndPrint(list);
  list.removeAllButOne(0);
  checkAndPrint(list);

  cout << "*** END checkRemoveAllButOne ***" << endl << endl;
}

void checkReverse() {
  cout << "*** BEGIN checkReverse ***" << endl;
  LinkedList<int> list;
  int vals[] = {3, 2, -1, 2, 1, 3, 5, 2, 1};
  for (int i = 0; i < 9; i++) {
    list.insertBack(vals[i]);
  }

  checkAndPrint(list);
  list.reverse();
  checkAndPrint(list);

  list.clear();
  list.insertBack(17);
  list.reverse();
  checkAndPrint(list);

  list.clear();
  list.reverse();
  checkAndPrint(list);

  cout << "*** END checkReverse ***" << endl << endl;
}
int main() {
  checkFindLast();
  checkRemoveAllButOne();
  checkReverse();

  return 0;
}
