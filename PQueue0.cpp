#include "PQueue0.h"

PQueue::PQueue() {
    _size = 0;
}

PQueue::PQueue(int* items, int size) {
    _size = 0;

    for (int i = 0; i < size; i++) {
        insert(items[i]);
    }
}

void PQueue::insert(T val) {
    if (_size == 0) {
        _array[1] = val;
        _size++;
    } else if (_size < (MAX_SIZE)) {
        _array[_size + 1] = val;
        _size++;
        moveUp();   // Fix heap since heap property likely violated.
    } else {    // Heap is full, nothing can be inserted.
        return;
    }
}


// Start with last non-leaf node, and call moveDown().
// Continue with each index to the left, stopping after moveDown() is called on root.
void PQueue::buildHeap() {
    int floydIndex = _size / 2;
    while (floydIndex >= 1) {
        moveDown(floydIndex);
        floydIndex--;
    }
    return;
}


// If a child is less than its parent, swap positions since min heap property is violated.
void PQueue::moveUp() {
    int childIndex = _size;
    int parentIndex = _size / 2;   // int division finds parent index since flooring occurs.
    int tempVal;
    while (_array[childIndex] < _array[parentIndex]) {
        tempVal = _array[parentIndex];
        _array[parentIndex] = _array[childIndex];
        _array[childIndex] = tempVal;
        childIndex = parentIndex;
        parentIndex = parentIndex / 2;
        if (parentIndex == 0) {
            return;
        }
    }
    return;
}


void PQueue::moveDown(int i) {
    if ((i * 2) + 1 > _size) {  // No children, return.
        return;
    }

    int parentIndex = i;
    int childLeftIndex = parentIndex * 2;
    int childRightIndex = (parentIndex * 2) + 1;
    int tempVal;

    while ((_array[parentIndex] < _array[childLeftIndex] || _array[parentIndex] < _array[childRightIndex]) && (childRightIndex <= _size)) {
        if (_array[childLeftIndex] <= _array[childRightIndex]) {
            tempVal = _array[childLeftIndex];
            _array[childLeftIndex] = _array[parentIndex];
            _array[parentIndex] = tempVal;
            parentIndex = childLeftIndex;
        } else {
            tempVal = _array[childRightIndex];
            _array[childRightIndex] = _array[parentIndex];
            _array[parentIndex] = tempVal;
            parentIndex = childRightIndex;
        }
        childLeftIndex = parentIndex * 2;
        childRightIndex = (parentIndex * 2) + 1;
    }

    return;
}


T PQueue::findMin() {
    return _array[1];
}


// Replace root element with last element, then call moveDown() on it.
void PQueue::deleteMin() {
    if (isEmpty() == true) {
        return;
    }
    _array[1] = _array[_size];
    _size--;
    moveDown(1);
}


bool PQueue::isEmpty() {
    if (size() == 0) {
        return true;
    } else {
        return false;
    }
}


int PQueue::size() {
    return _size;
}