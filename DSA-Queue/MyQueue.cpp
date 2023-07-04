#include <queue>

using namespace std;
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue(){
        this->front = 0;
        rear=0;
    }
        void push(int x){

        static bool invoked = false;
        // Your Code
        if(!invoked){
           this->front = 100004;
           this->rear =0;
           invoked = true;
        }
        /*
        if(this->rear < 100005){
            this->arr[this->front - this->rear] = x;
            this->rear++;
        }

        if(!invoked){
            invoked = true;
        }*/

        if(this->front < 100004){
            this->arr[front - rear] = x;
        }
        else{
            this->arr[this->front - this->rear] = x;
            this->rear++;
        }
    }
    void push1(int x){
        if(this->front < 100004){
            this->arr[++this->front] = x;
        }
        if(this->rear == 0){
            this->rear++;
        }
    }
    int pop1(){
        int result = -1;
        if(this->rear > 0){
            result = this->arr[front];
            this->arr[front--] = 0;
            this->rear--;
        }
        return result;
    }
    //Function to pop an element from queue and return that element.
    int pop()
    {
        // Your Code
        int result = -1;
        if(this->rear > 0){
            result = arr[this->front];
            arr[this->front] = 0;
            this->front--;
            this->rear--;
        }
        return result;
    }
};
