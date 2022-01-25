#include <iostream>
using namespace std;

class Stack
{
private:
    int top = -1;
    int arraySize = 100;
    int array[arraySize];

public:
    void push(int value)
    {
        if (top == arraySize - 1)
        {
            throw invalid_argument("Stack overflow!");
        }
        top += 1;
        array[top] = value;
    };
    void pop()
    {
        if (top == -1)
        {
            throw invalid_argument("Stack is already empty.");
        }
        top -= 1;
    };
    int getTop()
    {
        return array[top];
    };
};

int main()
{
    Stack my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.pop();
    cout << my_stack.getTop() << endl;
}