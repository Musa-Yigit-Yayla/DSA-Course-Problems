#include "Node.cpp"

class IntersectionYShaped{
public:
    Node* contains(Node* list, int data){
    Node* currNode = list;
    while(currNode != NULL){
        if(currNode->data == data){
            return currNode;
        }
        currNode = currNode->next;
    }
    return nullptr;
}
bool containsRest(Node* curr1, Node* intersectionNode){
    Node* curr = curr1;
    while(curr1 != NULL && intersectionNode != NULL){
        if(curr1->data != intersectionNode->data){
            return false;
        }
        curr1 = curr1->next;
        intersectionNode = intersectionNode->next;
    }
    return curr1 == NULL && (intersectionNode == NULL);

}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* curr1 = head1;
    while(curr1 != NULL){
        Node* intersectionNode = contains(head2, curr1->data);
        if(intersectionNode != NULL){
            if(containsRest(curr1, intersectionNode)){
                return curr1->data;
            }
        }
        curr1 = curr1->next;
    }
    return -1;
}


};
