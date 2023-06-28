#include <cstddef>
using namespace std;

#include "MyStack.h"

//Function to push an integer into the stack.
void MyStack ::push(int x)
{
    StackNode* newNode = new StackNode(x);
    /*if(invokeCount == 0){
        top = newNode;
        bottom = newNode;
    }
    else{
        top->next = newNode;
        top = top->next;
    }
    invokeCount++;*/
    if(this->top == NULL){
        this->top = newNode;
    }
    else{
        newNode->next = this->top;
        this->top = newNode;
    }
}

//Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    /*if(this->top != NULL){
        int x = this->top->data;
        delete this->top;
        return x;
    }
    else{
        invokeCount = 0;
        return -1;
    }*/
    if(this->top == NULL){
        return -1;
    }
    else{
        int returnValue = this->top->data;
        StackNode* next = this->top->next;
        delete this->top;
        this->top = next;
        return returnValue;
    }
}

