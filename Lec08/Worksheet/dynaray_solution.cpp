// NOTE: make sure you change dynarraytesttwo to include the solution
#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_

#include <cassert>
#include <cstdlib>

using namespace std;

// A dynamic array that can be resized when desired.
template <typename T>
class DynamicArray {
public:
  // create a new array with the given size
  DynamicArray(unsigned int size = 0);
  ~DynamicArray();

  // copy constructor
  DynamicArray(const DynamicArray& copy);

  // assignment operator overload
  DynamicArray& operator=(const DynamicArray& rhs);

  // add a new entry to the end of the array
  void pushBack(const T& item);

  // resize the array, keeping the items in the current array
  // except for ones that are indexed >= size (if any)
  void resize(unsigned int newSize);

  T& operator[](unsigned int index);

  // just return the # of slots allocated to the array
  unsigned int size() const;

  // this is what you will implement in exercise 2
  void insert(unsigned int index, const T& item);

  // this is what you will implement in exercise 3
  void erase(unsigned int index);

  // this is what you will implement in exercise 4
  T popBack();

  // this is what you will implement in exercise 5
  int find(const T& item);

private:
  T *array; // the actual array allocated in the heap
  unsigned int numItems;  // number of items in the array, for the user
  unsigned int arraySize; // size of the underlying array in the heap
};

template <typename T>
DynamicArray<T>::DynamicArray(unsigned int size) {
  // just point array to NULL and let resize do the work
  array = NULL;
  resize(size);
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  delete[] array;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& copy) {
  // first get an array of the appropriate size,
  // since this is a constructor, we treat it as if the array pointer
  // was not initialized at all
  // FURTHER STUDY FOR THE CURIOUS: constructor delegation
  array = NULL;
  resize(numItems);

  // now the array has the proper size, so just copy the contents of the other
  // array into this array
  for (unsigned int i = 0; i < numItems; i++) {
    array[i] = copy.array[i];
  }
}

// different than the copy constructor, see the lecture slides for a discussion
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& rhs) {
  resize(rhs.numItems);

  for (unsigned int i = 0; i < numItems; i++) {
    array[i] = rhs.array[i];
  }

  return *this;
}

template <typename T>
void DynamicArray<T>::resize(unsigned int newSize) {
  // get an array from the heap with twice the new user array size
  // (or 10, if the new size is really small)
  unsigned int newArraySize = max(newSize*2, 10u);

  // get the new array
  T *newArray = new T[newArraySize];

  // if we had an old array (i.e. this was not called from the constructor),
  // copy the contents over to the new array and then delete this array
  if (array != NULL) {
    // copy the old array over until we fill the new array (according to user size)
    // or we copied all contents from the old array
    for (unsigned int i = 0; i < min(numItems, newSize); i++) {
      newArray[i] = array[i];
    }
    delete[] array;
  }

  // update the class members for this new array and point to it now
  numItems = newSize;
  arraySize = newArraySize;
  array = newArray;
}

template <typename T>
unsigned int DynamicArray<T>::size() const {
  return numItems;
}

template <typename T>
void DynamicArray<T>::pushBack(const T& item) {
  // we can rewrite this to call the more general insert() method
  insert(numItems, item);
}

template <typename T>
T& DynamicArray<T>::operator[](unsigned int index) {
  assert(index < numItems);
  return array[index];
}

// EXERCISE 2: Finish implementing the following
template <typename T>
void DynamicArray<T>::insert(unsigned int index, const T& item) {
  // first thing we want to do is make sure we have a valid index
  // you should allow inserting "after" the last item as well

  assert(index <= numItems);
  // next, we should ensure there is actually room for our array to hold another item
  if (numItems == arraySize) {
    resize(numItems+1);
    // remember that after resizing we still haven't added the new item yet
    numItems--;
  }

  // next we want to shift everything in our array one item to the right
  for (int i = numItems; i >= index; i--) {
    array[i] = array[i-1];
  }

  // finally, we can add our new element
  array[index] = item;
  numItems++;
}

// EXERCISE 3: Finish implementing the following
template <typename T>
void DynamicArray<T>::erase(unsigned int index) {
  // first lets make sure the index they gave us is in range of our array
  assert(index < numItems);

  // now that we know we are able to get rid of an item, we just have to shift everything left and overwrite the old values
  for (int i = index; i < numItems - 1; i++) {
    array[i] = array[i+1];
  }

  // finally we can reduce the number of items
  numItems--;

  // check to see if the user's array is much smaller than the array in the heap
  if (numItems < arraySize && arraySize > 10) {
    resize(numItems);
  }
}

// EXERCISE 4: Finish implementing the following
template <typename T>
T DynamicArray<T>::popBack() {
  // first thing we want to do is ensure there are actually items in the array
  assert(numItems > 0);
  // we should copy the item we want so that it can be returned
  T item = array[numItems - 1];

  // new get rid of the item: can you reuse any code?
  erase(numItems - 1);

  // finally, return the item that you created before
  return item;
}

// EXERCISE 6: Finish implementing the following
template <typename T>
int DynamicArray<T>::find(const T& item) {
  // lets first just look for the item in the array
  for (int i = 0; i < numItems; i++) {
    // if we find it, then we should return that index
    if (item == array[i]) {
      return i;
    }
  }
  // if we haven't found it, we should return -1
  return -1;
}


/*
  Exercise 1 solutions
  1. A dynamic array is one that can be resized automatically to hold more or less items
  2. The size of our dynamic array is not fixed, it will grow or shrink as needed
  3. You can add items to the end, find the size of it, change the size of it, and retrieve values from it
  4. first it ensures there is room for a new item. If there isn't then it creates some. Next it adds the item to the end.
  5. Because we are using operator overloading.
  6. Part of our dynamic array stores a variable that keeps track of how many items are in it. The function just returns this value
*/

/*
  Exercise 5 solutions
  Look how the erase() method will reallocate space if the user's array size shrinks
  to < 1/4 of the array size in the heap (unless the array size is already 10).
*/


#endif
