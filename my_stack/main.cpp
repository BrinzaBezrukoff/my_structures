#include <iostream>

#include "stack/Stack.h"


int main() {

    Stack s;
    s.push(12);

    Stack v (s);

    std::cout << s.top() << std::endl;
    std::cout << s.size() << std::endl;

    std::cout << v.top() << std::endl;
    std::cout << v.size() << std::endl;

    return 0;
}
