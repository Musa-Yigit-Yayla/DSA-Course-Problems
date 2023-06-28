class TwoStacks
{
    int *arr;
    int size;
    int top1, top2;
    public:

    TwoStacks(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    ~TwoStacks(){
        delete[] this->arr;
    }
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(this->top1 + 1 < this->top2){
            this->arr[++this->top1] = x;
        }
    }

    //Function to push an integer into the stack2.
    void push2(int x)
    {
       if(this->top1 < this->top2 - 1){
            this->arr[--this->top2] = x;
        }
    }

    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(this->top1 >= 0){
            int value = this->arr[top1];
            this->top1--;
            return value;
        }
        else{
            return -1;
        }
    }

    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(this->top2 < this->size){
            int value = this->arr[top2];
            this->top2++;
            return value;
        }
        else{
            return -1;
        }
    }
};

