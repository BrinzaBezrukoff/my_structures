//
// Created by brinza on 22.05.22.
//

#ifndef MY_QUEUE_LISTQUEUE_H
#define MY_QUEUE_LISTQUEUE_H

#include "QueueImplementation.h"
#include "../list/List.h"


class ListQueue : public IQueueImplementation {
public:
    ListQueue() = default;
    ListQueue(const ValueType* valueArray, const size_t arraySize);

    void push(const ValueType& value) override;
    void pop() override;

    const ValueType& front() const override;

    bool isEmpty() const override;
    size_t size() const override;

private:
    List _list;

};


#endif //MY_QUEUE_LISTQUEUE_H
