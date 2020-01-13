#include <iostream>
using namespace std;

class FixedMultiStack {
public:
    //Create 3 stacks, each stack is of size stackCapacity.
    FixedMultiStack(int stackCapacity);
    virtual ~FixedMultiStack();

    // Push an element onto stack stackNum, where stackNum is from 0 to 2.
    void push(int stackNum, int value);

    // Pop the top element from stack stackNum, where stackNum
    void pop(int stackNum);

    // Return the top element on stack stackNum, where stackNum is from 0 to 2
    int top (int stackNum) const;

    bool isEmpty(int stackNum) const;
    bool isFull(int stackNum) const;

private:
    int numOfStack = 3;
    int stackCapacity;
    int *stackArray;
    int *stackCapacityUsed;

    // Return the top index of stack stackNum, where stackNum is from 0 to 2
    int indexOfTop(int stackNum) const;
};

FixedMultiStack::FixedMultiStack(int stackCapacity) {
    this->stackCapacity = stackCapacity;
    stackArray = new int[numOfStack * stackCapacity]();
    stackCapacityUsed = new int[numOfStack]();
}

FixedMultiStack::~FixedMultiStack() {
    delete [] stackArray;
    delete [] stackCapacityUsed;
}

void FixedMultiStack::pop(int stackNum) {
    if (isEmpty(stackNum))
        cout << "Stack " << stackNum << " is empty.\n";
    else {
        int topIndex = indexOfTop(stackNum);
        stackArray[topIndex] = 0;
        stackCapacityUsed[stackNum]--;
    }
}

int FixedMultiStack::top(int stackNum) const {
    if (isEmpty(stackNum)) {
        cout << "Stack " << stackNum << " is empty.\n";
    }
    else
        return stackArray[indexOfTop(stackNum)];
}

bool FixedMultiStack::isEmpty(int stackNum) const {
    return (stackCapacityUsed[stackNum] == 0);
}

bool FixedMultiStack::isFull(int stackNum) const {
    return (stackCapacityUsed[stackNum] == stackCapacity);
}

int FixedMultiStack::indexOfTop(int stackNum) const {
    int startIndex = stackNum * stackCapacity;
    int capacity = stackCapacityUsed[stackNum];
    return (startIndex + capacity - 1);
}

using namespace std;
int main () {

    return 0;
}