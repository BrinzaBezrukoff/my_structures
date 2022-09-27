//
// Created by brinza on 25.03.2022.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <cstddef>

using ValueType = double;


enum class QueueContainer {
    Vector = 0,
    List,
};


class IQueueImplementation;


class Queue
{
public:
    Queue(QueueContainer container = QueueContainer::Vector);
    Queue(const ValueType* valueArray, const size_t arraySize,
          QueueContainer container = QueueContainer::Vector);

    explicit Queue(const Queue& copyQueue);
    Queue& operator=(const Queue& copyQueue);

    Queue(Queue&& moveStack) noexcept;
    Queue& operator=(Queue&& moveStack) noexcept;

    ~Queue();

    void push(const ValueType& value);
    void pop();
    const ValueType& front() const;
    bool isEmpty() const;
    size_t size() const;
private:
    IQueueImplementation* _pimpl = nullptr;
    QueueContainer _containerType;

    void setImplementation(QueueContainer container);
    void setImplementation(const Queue& queue);
};


#endif //DATASTRUCTURES_STACK_H
