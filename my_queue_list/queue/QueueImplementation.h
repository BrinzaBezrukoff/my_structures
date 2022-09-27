//
// Created by brinza on 25.03.2022.
//

#ifndef DATASTRUCTURES_ISTACKIMPL_H
#define DATASTRUCTURES_ISTACKIMPL_H

#include <cstddef>


using ValueType = double;


class IQueueImplementation {
public:
    virtual void push(const ValueType& value) = 0;
    virtual void pop() = 0;

    virtual const ValueType& front() const = 0;

    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;

    virtual ~IQueueImplementation() = default;
};


#endif //DATASTRUCTURES_ISTACKIMPL_H
