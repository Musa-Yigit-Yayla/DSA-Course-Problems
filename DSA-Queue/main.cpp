#include <iostream>
#include "MyQueue.cpp"

using namespace std;

int main()
{
    MyQueue mq;
    mq.push(2);
    mq.push(3);
    cout << mq.pop() << endl;
    mq.push(4);
    cout << mq.pop() << endl;
    cout << mq.pop() << endl;
    return 0;
}
