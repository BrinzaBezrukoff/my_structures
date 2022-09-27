//
// Created by brinza on 22.05.22.
//

#include <stdexcept>

#include "ListQueue.h"


ListQueue::ListQueue(const ValueType* valueArray, const size_t arraySize) {
    _list.insert(0, valueArray, arraySize);
}

void ListQueue::push(const ValueType& value) {
    _list.pushBack(value);
}

void ListQueue::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Can't pop from empty queue");
    }
    _list.popFront();
}

const ValueType& ListQueue::front() const {
    return _list.front();
}

bool ListQueue::isEmpty() const {
    return size() == 0;
}

size_t ListQueue::size() const {
    return _list.size();
}
