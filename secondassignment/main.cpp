#include <iostream>
#include <vector>
#include <numeric> // For accumulate function

class Stack {
private:
    std::vector<int> data;

public:
    // Push element onto stack
    void push(int value) {
        data.push_back(value);
    }

    // Pop element from stack
    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    // Get top element of stack
    int top() const {
        if (!data.empty()) {
            return data.back();
        }
        throw std::out_of_range("Stack is empty");
    }

    // Check if stack is empty
    bool isEmpty() const {
        return data.empty();
    }

    // Find average value of stack
    double findAverage() const {
        if (data.empty()) return 0.0;
        return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    }
};

int main() {
    Stack myStack;

    // Push some integers onto stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    // Check if stack is empty
    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    // Find top of stack
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Pop element from stack
    myStack.pop();
    std::cout << "After pop, top element: " << myStack.top() << std::endl;

    // Find average of stack elements
    std::cout << "Average of stack elements: " << myStack.findAverage() << std::endl;

    return 0;
}