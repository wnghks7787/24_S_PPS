#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 15000

class stack{
    vector<int> values;
    int stack_size;

public:
    stack();

    void push(int x);
    int pop();
    int size();
    int empty();
    int top();
};

int main()
{
    stack myStack;
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        string operation;
        int val;
        cin >> operation;
        

        if(operation == "push")
        {
            cin >> val;
            
            myStack.push(val);
            continue;
        }
        
        if(operation == "pop")
        {
            cout << myStack.pop() << endl;
            continue;
        }
        
        if(operation == "size")
        {
            cout << myStack.size() << endl;
            continue;
        }

        if(operation == "empty")
        {
            cout << myStack.empty() << endl;
            continue;
        }

        if(operation == "top")
        {
            cout << myStack.top() << endl;
            continue;
        }
    }
    return 0;
}

stack::stack()
{
    values.assign(MAX_SIZE, 0);
    stack_size = 0;
}

void stack::push(int x)
{
    values[stack_size] = x;
    stack_size++;
}

int stack::pop()
{
    if(stack_size == 0)
        return -1;

    int tmp = values[stack_size-1];
    stack_size--;

    return tmp;
}

int stack::size()
{
    return stack_size;
}

int stack::empty()
{
    return stack_size == 0 ? 1 : 0;
}

int stack::top()
{
    return stack_size == 0 ? -1 : values[stack_size - 1];
}