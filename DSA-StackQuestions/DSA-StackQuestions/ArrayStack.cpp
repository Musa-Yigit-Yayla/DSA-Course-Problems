//Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop(){
        if(this->top == -1){
            return -1;
        }
        else{
            int value = this->arr[--top];
            //top--;
            return value;
        }
    }
    void push(int x){
        if(this->top != 999){
            this->arr[top++] = x;
        }
    }
};

