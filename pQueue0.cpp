#include "PQueue0.h"

PQueue::PQueue() {
    _size = 0;
}

void PQueue::insert(T val) {
    if (_size == 0) {
        _array[1] == val;
        _size++;
    } else if (_size < (MAX_SIZE)) {
        _array[_size + 1] = val;
        _size++;
        moveUp();   // Fix heap since heap property likely violated.
    } else {    // Heap is full, nothing can be inserted.
        return;
    }
}

// If a child is less than its parent, swap positions since min heap property is violated.
void PQueue::moveUp() {
    int childIndex = _size;
    int parentIndex = _size / 2;   // int division finds parent index since flooring occurs
    int childVal = _array[childIndex];
    int parentVal = _array[parentIndex];
    int tempVal;
    int tempIndex;
    while (childVal < parentVal) {
        tempVal = parentVal;
        parentVal = childVal;
        childVal = tempVal;
        childIndex = parentIndex;
        parentIndex = parentIndex / 2;
        childVal = _array[childIndex];
        parentVal = _array[parentIndex];
        if (parentIndex == 0) {
            return;
        }
    }
    return;
}

/*
T PQueue::findMin() {
    if (_size != 0) {
        return _array[1];
    } else {
        return;
    }
}
*/