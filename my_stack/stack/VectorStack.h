//
// Created by brinza on 29.04.22.
//

#ifndef DATASTRUCTURES_VECTORSTACK_H
#define DATASTRUCTURES_VECTORSTACK_H

#include "StackImplementation.h"
#include "vector"


class VectorStack : public IStackImplementation {
public:
    VectorStack() = default;
    VectorStack(const ValueType* valueArray, const size_t arraySize);

    void push(const ValueType& value) override;
    void pop() override;
    const ValueType& top() const override;
    bool isEmpty() const override;
    size_t size() const override;

private:
    std::vector<ValueType> _vector;
};


#endif //DATASTRUCTURES_VECTORSTACK_H
