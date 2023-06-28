#ifndef MYSTACK_H
#define MYSTACK_H
#include <cstddef>

struct StackNode{
  int data;
  StackNode* next;
  StackNode(int a){
    data = a;
    next = nullptr;
  }
};

class MyStack{
private:
    StackNode* top = nullptr;
public:
    void push(int);
    int pop();
    MyStack();
};
#endif // MYSTACK_H
