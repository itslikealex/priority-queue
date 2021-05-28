#include "PQueue0.h"

PQueue::PQueue() {
    _size = 0;
}

// Remember to call buildHeap() after insertion
void PQueue::insert(T val) {
    if (_size == 0) {
        _array[1] == val;
        _size++;
    } else if (_size < (MAX_SIZE)) {
        _array[_size + 1] = val;
        _size++;
    } else {    // Heap is full, nothing can be inserted.
        return;
    }
}

T PQueue::findMin() {
    if (_size != 0) {
        return _array[1];
    } else {
        return;
    }
}