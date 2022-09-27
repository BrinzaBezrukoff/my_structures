//
// Created by brinza on 25.03.2022.
//

#include "Stack.h"
#include "ListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container)
{
    setImplementation(container);
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
{
    setImplementation(container);
    for (size_t idx = 0; idx < arraySize; idx++) {
        push(valueArray[idx]);
    }
}

Stack::Stack(const Stack& copyStack)
        : _containerType(copyStack._containerType)
{
    setImplementation(copyStack);
}

Stack& Stack::operator=(const Stack& copyStack)
{
    if (this != &copyStack) {
        delete _pimpl;
        setImplementation(copyStack);
    }
    return *this;
}

Stack::Stack(Stack&& moveStack) noexcept {
    _containerType = moveStack._containerType;
    _pimpl = moveStack._pimpl;
    moveStack._pimpl = nullptr;
}

Stack& Stack::operator=(Stack&& moveStack) noexcept {
    if (this != &moveStack) {
        delete _pimpl;
        _containerType = moveStack._containerType;
        _pimpl = moveStack._pimpl;
        moveStack._pimpl = nullptr;
    }
    return *this;
}

Stack::~Stack()
{
    delete _pimpl;
}

void Stack::push(const ValueType& value)
{
    _pimpl->push(value);
}

void Stack::pop()
{
    _pimpl->pop();
}

const ValueType& Stack::top() const
{
    return _pimpl->top();
}

bool Stack::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Stack::size() const
{
    return _pimpl->size();
}

void Stack::setImplementation(StackContainer container) {
    switch (container)
    {
        case StackContainer::List: {
            _pimpl = static_cast<IStackImplementation*>(new ListStack());
            break;
        }
        case StackContainer::Vector: {
            _pimpl = static_cast<IStackImplementation*>(new VectorStack());
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    _containerType = container;
}
void Stack::setImplementation(const Stack& copyStack) {
    switch (copyStack._containerType) {
        case StackContainer::List: {
            _pimpl = static_cast<IStackImplementation*>(new ListStack(*dynamic_cast<ListStack*>(copyStack._pimpl)));
            break;
        }
        case StackContainer::Vector: {
            _pimpl = static_cast<IStackImplementation*>(new VectorStack(*dynamic_cast<VectorStack*>(copyStack._pimpl)));
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    _containerType = copyStack._containerType;
}

