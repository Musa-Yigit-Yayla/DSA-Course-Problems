//#include <cstddef>

using namespace std;
class Node{
public:
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int data){
        this->data = data;
    }
    ~Node(){
        next = nullptr;
        prev = nullptr;
    }
};
