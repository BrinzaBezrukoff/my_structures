//
// Created by brinza on 22.05.22.
//

#ifndef MY_QUEUE_VECTORQUEUE_H
#define MY_QUEUE_VECTORQUEUE_H

#include <vector>

#include "QueueImplementation.h"


class VectorQueue : public IQueueImplementation {
public:
    VectorQueue() = default;
    VectorQueue(const ValueType* valueArray, const size_t arraySize);

    void push(const ValueType& value) override;
    void pop() override;

    const ValueType& front() const override;

    bool isEmpty() const override;
    size_t size() const override;

private:
    std::vector<ValueType> _vector;
    size_t _first = 0;
};


#endif //MY_QUEUE_VECTORQUEUE_H
