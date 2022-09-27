//
// Created by brinza on 29.04.22.
//

#include "ListStack.h"

#include "stdexcept"

ListStack::ListStack(const ValueType* valueArray, const size_t arraySize) {
    _list.insert(_list.begin(), valueArray, valueArray + arraySize);
}

void ListStack::push(const ValueType& value) {
    _list.push_back(value);
}

void ListStack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Can't pop from empty stack!");
    }
    _list.pop_back();
}

const ValueType& ListStack::top() const {
    return _list.back();
}

bool ListStack::isEmpty() const {
    return _list.empty();
}

size_t ListStack::size() const {
    return _list.size();
}
