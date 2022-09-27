//
// Created by brinza on 25.03.2022.
//

#include "Queue.h"
#include "ListQueue.h"
#include "VectorQueue.h"
#include "QueueImplementation.h"

#include <stdexcept>

Queue::Queue(QueueContainer container)
{
    setImplementation(container);
}

Queue::Queue(const ValueType* valueArray, const size_t arraySize, QueueContainer container)
{
    setImplementation(container);
    for (size_t idx = 0; idx < arraySize; idx++) {
        push(valueArray[idx]);
    }
}

Queue::Queue(const Queue& copyQueue)
        : _containerType(copyQueue._containerType)
{
    setImplementation(copyQueue);
}

Queue& Queue::operator=(const Queue& copyQueue)
{
    if (this != &copyQueue) {
        delete _pimpl;
        setImplementation(copyQueue);
    }
    return *this;
}

Queue::Queue(Queue&& moveQueue) noexcept {
    _containerType = moveQueue._containerType;
    _pimpl = moveQueue._pimpl;
    moveQueue._pimpl = nullptr;
}

Queue& Queue::operator=(Queue&& moveQueue) noexcept {
    if (this != &moveQueue) {
        delete _pimpl;
        _containerType = moveQueue._containerType;
        _pimpl = moveQueue._pimpl;
        moveQueue._pimpl = nullptr;
    }
    return *this;
}

Queue::~Queue()
{
    delete _pimpl;
}

void Queue::push(const ValueType& value)
{
    _pimpl->push(value);
}

void Queue::pop()
{
    _pimpl->pop();
}

const ValueType& Queue::front() const
{
    return _pimpl->front();
}

bool Queue::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Queue::size() const
{
    return _pimpl->size();
}

void Queue::setImplementation(QueueContainer container) {
    switch (container)
    {
        case QueueContainer::List: {
            _pimpl = static_cast<IQueueImplementation*>(new ListQueue());
            break;
        }
        case QueueContainer::Vector: {
            _pimpl = static_cast<IQueueImplementation*>(new VectorQueue());
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    _containerType = container;
}
void Queue::setImplementation(const Queue& copyQueue) {
    switch (copyQueue._containerType) {
        case QueueContainer::List: {
            _pimpl = static_cast<IQueueImplementation*>(new ListQueue(*dynamic_cast<ListQueue*>(copyQueue._pimpl)));
            break;
        }
        case QueueContainer::Vector: {
            _pimpl = static_cast<IQueueImplementation*>(new VectorQueue(*dynamic_cast<VectorQueue*>(copyQueue._pimpl)));
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    _containerType = copyQueue._containerType;
}

