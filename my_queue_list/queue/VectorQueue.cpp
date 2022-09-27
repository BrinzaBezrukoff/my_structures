//
// Created by brinza on 22.05.22.
//

#include <stdexcept>

#include "VectorQueue.h"


VectorQueue::VectorQueue(const ValueType* valueArray, const size_t arraySize) {
    _vector.insert(_vector.begin(), valueArray, valueArray + arraySize);
}

void VectorQueue::push(const ValueType& value) {
    _vector.push_back(value);
}

void VectorQueue::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Can't pop from empty queue");
    }
    _first++;
}

const ValueType& VectorQueue::front() const {
    return _vector[_first];
}

bool VectorQueue::isEmpty() const {
    return size() == 0;
}

size_t VectorQueue::size() const {
    return _vector.size() - _first;
}
