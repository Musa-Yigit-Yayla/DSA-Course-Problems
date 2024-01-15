#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node* left = nullptr;
    struct Node* right = nullptr;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int getSmallerOnRight(int* arr, int n);
int optimizedSmallerOnRight(int* arr, int n);
int subArrHelper(int* arr, int n);
bool insert(Node* head, int data);
void deleteTree(Node* currNode);

int main() {

    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int n;
        cin >> n;

        int* arr = new int[n];
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        cout << optimizedSmallerOnRight(arr, n) << endl;
        delete[] arr;
    }
	return 0;
}

int subArrHelper(int* arr, int n){
    //create a BST from the given sub-array with root arr[0]
    //count the total elements inserted at the left subtree
    int leftInsertionCount = 0;

    Node* head = new Node(arr[0]);
    for(int i = 1; i < n; i++){
        int curr = arr[i];
        if(curr < head->data && insert(head, curr)){
            leftInsertionCount++;
        }
    }
    deleteTree(head);
    return leftInsertionCount;
}
//inserts only the smaller elements than head
bool insert(Node* head, int data){
    Node* newNode = new Node(data);
    Node* currNode = head;
    Node* prevNode = head;

    bool isRight = false;
    while(currNode != NULL){
        if(newNode->data < currNode->data){
            prevNode = currNode;
            currNode = currNode->left;
            isRight = false;
        }
        else if(newNode->data > currNode->data){
            prevNode = currNode;
            currNode = currNode->right;
            isRight = true;
        }
        else{
            return false; //insertion unsuccessful
        }
    }
    if(isRight){
        prevNode->right = newNode;
    }
    else{
        prevNode->left = newNode;
    }
    return true;
}
void deleteTree(Node* currNode){
    //simply post-order traverse the given tree and deallocate each node
    if(currNode != NULL){
        deleteTree(currNode->left);
        deleteTree(currNode->right);
        delete currNode;
    }
}
int optimizedSmallerOnRight(int* arr, int n){
    int maxResult = 0;

    for(int i = 0; i < n - 1; i++){
        int currResult = subArrHelper(arr + i, n - i);
        if(currResult > maxResult){
            maxResult = currResult;
        }
    }
    return maxResult;
}
int getSmallerOnRight(int* arr, int n){
    int result = 0;
    for(int i = 0; i < n - 1; i++){
        vector<int> checkedList;
        int currRoot = arr[i];
        int currResult = 0;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < currRoot && count(checkedList.begin(), checkedList.end(), arr[j]) == 0){
                checkedList.push_back(arr[j]);
                currResult++;
            }
        }
        if(currResult > result){
            result = currResult;
        }
    }
    return result;
}

