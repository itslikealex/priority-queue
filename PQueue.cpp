template< class T, int MAX_SIZE >
PQueue<T, MAX_SIZE>::PQueue() {
    _size = 0;
}

template< class T, int MAX_SIZE >
PQueue<T, MAX_SIZE>::PQueue(T* items, int size) {
    _size = 0;

    for (int i = 0; i < size; i++) {
        insert(items[i]);
    }
}

template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::insert(T val) {
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
template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::buildHeap() {
    int floydIndex = _size / 2;
    while (floydIndex >= 1) {
        moveDown(floydIndex);
        floydIndex--;
    }
    return;
}


// If a child is less than its parent, swap positions since min heap property is violated.
template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::moveUp() {
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


template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::moveDown(int i) {
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


template< class T, int MAX_SIZE >
T PQueue<T, MAX_SIZE>::findMin() {
    return _array[1];
}


// Replace root element with last element, then call moveDown() on it.
template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::deleteMin() {
    if (isEmpty() == true) {
        return;
    }
    _array[1] = _array[_size];
    _size--;
    moveDown(1);
}


template< class T, int MAX_SIZE >
bool PQueue<T, MAX_SIZE>::isEmpty() {
    if (size() == 0) {
        return true;
    } else {
        return false;
    }
}


template< class T, int MAX_SIZE >
int PQueue<T, MAX_SIZE>::size() {
    return _size;
}