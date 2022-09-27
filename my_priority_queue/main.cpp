#include <iostream>
#include "prioirty_queue.h"


int main(int argc, char* argv[]) {
    
    priority_queue<int> pq;

    pq.push(12);
    pq.push(20);
    pq.push(20);
    pq.push(5);
    pq.push(9);
    pq.push(17);
    pq.push(0);
    pq.push(50);
    pq.push(20);

    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

     // pq.pop();  // generate exception
    
    return 0;
}

