#include <vector>
#include <exception>
#include <algorithm>


template<typename T, typename Container = std::vector<T>>
class priority_queue {
    Container _cont;
    
    int _leftChildIndex(int parentIndex) {
        int left = 2 * parentIndex + 1;
        if (_isValidIndex(left))
            return left;
        return -1;  // -1 if not exists
    }
    
    int _rightChildIndex(int parentIndex) {
        int right = 2 * parentIndex + 2;
        if (_isValidIndex(right))
            return right;
        return -1;  // -1 if not exists
    }
    
    int _parentIndex(int childIndex) {
        return (childIndex + childIndex % 2) / 2 - 1;
    }

    bool _isValidIndex(int index) {
        return index >= 0 && index < size();
    }
    
    void _siftUp(int index) {
        if (index == 0) return;
        int parent = _parentIndex(index);
        if (_cont[parent] < _cont[index]) {
            std::swap(_cont[index], _cont[parent]);
            _siftUp(parent);
        }
    }
    
    void _siftDown(int index) {
        int left = _leftChildIndex(index);
        int right = _rightChildIndex(index);
        int mx;
        if (left < 0 && right < 0) {
            return;  // no child, stop recursion
        }
        if (left < 0) {
            mx = right;  // only one right child
        }
        else if (right < 0) {
            mx = left;  // only one left child
        }
        else {  // two children, choose one with max value
            mx = std::max(left, right, [=](int a, int b) { return _cont[a] < _cont[b]; });
        }
        if (_cont[index] < _cont[mx]) {
            std::swap(_cont[mx], _cont[index]);
            _siftDown(mx);
        }
    }

public:
    void push(const T& value) {
        _cont.push_back(value);
        _siftUp(size() - 1);
    }
    
    const T& top() const {
        return _cont[0];
    }
    
    void pop() {
        if (empty()) {
            throw std::invalid_argument("Can't pop from empty priority_queue");
        }
        std::swap(_cont[0], _cont[size() - 1]);
        _cont.pop_back();
        _siftDown(0);
    }
    
    bool empty() const {
        return size() == 0;
    }
    
    int size() const {
        return _cont.size();
    }

    template<class priority_queue>
    friend std::ostream& operator<<(std::ostream& stream, priority_queue pq) {
        for (T el: pq._cont) {
            stream << el << " ";
        }
        stream << std::endl;
    }
};
