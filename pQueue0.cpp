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
    int parentIndex = _size / 2;   // int division finds parent index since flooring occurs.
    int childVal = _array[childIndex];
    int parentVal = _array[parentIndex];
    int tempVal;
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


void PQueue::moveDown(int i) {
    if ((i * 2) + 1 > _size) {  // No children, return.
        return;
    }

    int parentVal;
    int parentIndex = i;
    int childLeftIndex = parentIndex * 2;
    int childRightIndex = (parentIndex * 2) + 1;
    int childLeftVal;
    int childRightVal;
    int tempVal;

    while ((_array[parentIndex] < _array[childLeftIndex] || _array[parentIndex] < _array[childRightIndex]) && (childRightIndex <= _size)) {
        parentVal = _array[parentIndex];
        childLeftVal = _array[childLeftIndex];
        childRightVal = _array[childRightIndex];
        if (childLeftVal <= childRightVal) {
            tempVal = childLeftVal;
            childLeftVal = parentVal;
            parentVal = tempVal;
            parentIndex = childLeftIndex;
        } else {
            tempVal = childRightVal;
            childRightVal = parentVal;
            parentVal = tempVal;
            parentIndex = childRightIndex;
        }
        childLeftIndex = parentIndex * 2;
        childRightIndex = (parentIndex * 2) + 1;
    }

    return;
}


T PQueue::findMin() {
    if (_size != 0) {
        return _array[1];
    } else {
        return;
    }
}