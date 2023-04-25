#include <cstddef>
using namespace std;
class Node{
public:
    int data;
    Node* next = NULL;
    Node* prev = NULL;

    Node(int data){
        this->data = data;
    }
};
