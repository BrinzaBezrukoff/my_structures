#include <iostream>

#include "queue/Queue.h"


void queueCheck(Queue& queue);


int main() {

    std::cout << "VectorQueue: " << std::endl;
    Queue vq = Queue(QueueContainer::Vector);
    queueCheck(vq);

    std::cout << "ListQueue: " << std::endl;
    Queue lq = Queue(QueueContainer::List);
    queueCheck(lq);

    return 0;
}


void queueCheck(Queue& queue) {
    queue.push(10);
    queue.push(20);
    queue.push(30);

    std::cout << "size: " << queue.size() << std::endl;
    std::cout << "empty: " << queue.isEmpty() << std::endl;
    std::cout << "front: " << queue.front() << std::endl;
    queue.pop();
    std::cout << "front: " << queue.front() << std::endl;
    queue.pop();
    queue.pop();
    std::cout << "empty: " << queue.isEmpty() << std::endl;
}
