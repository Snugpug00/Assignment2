#include <iostream>
#include <vector>

using namespace std;

class Stack { // declare stack class
private: // following memebers are private:
    vector<int> elements; // private variable named elements.

public: // following members are public
    bool isEmpty() { // defines func isEmpty that doesn't take any arguments. and returns bool values.
        return elements.empty(); // returns empty func called on the elements vector. The empty func returns true if the vector has no elements and false otherwise.
    }

    void push(int value) { // punsh func takes an int value as its argument and returns void which doesn't return anything
        elements.push_back(value); // uses push_back() of elements vector to add the value to the end of the vector. this add value to the top of the stack.
    }

    void pop() { // removes top element from the stack.
        if (!isEmpty()) { // checks if the stack is not empty by calling the isEmpty func. The ! operater is used to negate the result, so the condition is true if the stack is not empty.
            elements.pop_back(); // if the stack is not empty this line removes the last element from the elemenst vector using the pop back func. This removes the top element from the stack.
        }
    }

    int top() { // func top takes no arguments and returns an int, which is the top element of the stack.
        if (!isEmpty()) { // checks if the stack is not empty by calling hte isEmpty func. ! is used to negate result, so the condition is true if the stack is not empty.
            return elements.back(); // if the stack is not empty, this line returns the last element of elements vector using the back func. top element of the stack.
        }
        return -1; // Assuming stack contains only positive integers
    }

    double average() { // calcs the avg value of all elements in the stack. takes no arguments and returns a double.
        if (!isEmpty()) { // checks if the stack is not empty by calling is empty func. ! to negate result, if the condition is true if the stack is not empty.
            int sum = 0; // initializes a var sum to store the sum of all elements in the stack.
            for (int element : elements) { // starts a loop that iterates over each element in the elements vector using a range - based for loop.
                sum += element; // in the loop each element is added to the sum variable.
            }
            return static_cast<double>(sum) / elements.size(); // if the stack is empty it returns a 0 as the avg. Avg calcs the avg value of all elements
        }
        return 0; // Assuming stack contains only positive integers
    }
};

int main() {
    Stack stack;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    stack.push(2);
    stack.push(4);
    stack.push(6);

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    cout << "Top of stack: " << stack.top() << endl;

    cout << "Removing an element from the stack." << endl;
    stack.pop();

    cout << "Top of stack after pop: " << stack.top() << endl;

    cout << "Average value of stack elements: " << stack.average() << endl;

    return 0;
}