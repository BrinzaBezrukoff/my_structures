//
// Created by brinza on 29.04.22.
//

#ifndef DATASTRUCTURES_LISTSTACK_H
#define DATASTRUCTURES_LISTSTACK_H

#include "list"

#include "StackImplementation.h"


class ListStack : public IStackImplementation {
public:
    ListStack() = default;
    ListStack(const ValueType* valueArray, const size_t arraySize);

    void push(const ValueType& value) override;
    void pop() override;
    const ValueType& top() const override;
    bool isEmpty() const override;
    size_t size() const override;

private:
    std::list<ValueType> _list;

};


#endif //DATASTRUCTURES_LISTSTACK_H
