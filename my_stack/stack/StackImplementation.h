//
// Created by brinza on 25.03.2022.
//

#ifndef DATASTRUCTURES_ISTACKIMPL_H
#define DATASTRUCTURES_ISTACKIMPL_H

#include <cstddef>


// приходится тянуть ValueType во все места,
using ValueType = double;

// интерфейс для конкретных реализаций контейнера для стека
class IStackImplementation {
public:
    // добавление в хвост
    virtual void push(const ValueType& value) = 0;
    // удаление с хвоста
    virtual void pop() = 0;
    // посмотреть элемент в хвосте
    virtual const ValueType& top() const = 0;
    // проверка на пустоту
    virtual bool isEmpty() const = 0;
    // размер
    virtual size_t size() const = 0;
    // виртуальный деструктор
    virtual ~IStackImplementation() = default;
};


#endif //DATASTRUCTURES_ISTACKIMPL_H
