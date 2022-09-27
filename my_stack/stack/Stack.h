//
// Created by brinza on 25.03.2022.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <cstddef>

// тип значений в стеке
using ValueType = double;

// на основе какого контейнера работает стек
enum class StackContainer {
    Vector = 0,
    List,
};

// декларация интерфейса реализации
class IStackImplementation;

class Stack
{
public:
    // Большая пятерка
    Stack(StackContainer container = StackContainer::Vector);
    // элементы массива последовательно подкладываются в стек
    Stack(const ValueType* valueArray, const size_t arraySize,
          StackContainer container = StackContainer::Vector);

    explicit Stack(const Stack& copyStack);
    Stack& operator=(const Stack& copyStack);

     Stack(Stack&& moveStack) noexcept;
     Stack& operator=(Stack&& moveStack) noexcept;

    ~Stack();

    // добавление в хвост
    void push(const ValueType& value);
    // удаление с хвоста
    void pop();
    // посмотреть элемент в хвосте
    const ValueType& top() const;
    // проверка на пустоту
    bool isEmpty() const;
    // размер
    size_t size() const;
private:
    // указатель на имплементацию (уровень реализации)
    IStackImplementation* _pimpl = nullptr;
    // тип контейнера, наверняка понадобится
    StackContainer _containerType;

    void setImplementation(StackContainer container);
    void setImplementation(const Stack& stack);
};


#endif //DATASTRUCTURES_STACK_H
