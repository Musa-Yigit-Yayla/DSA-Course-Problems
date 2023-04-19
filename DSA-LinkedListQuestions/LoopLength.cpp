#include <vector>
#include <unordered_map>


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

using namespace std;
class LoopLength{
public:
    //Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head){
        // Code here

        //count linkedlist's length
        /*struct Node* initialHead = head;
        int length = 0;
        while(head != NULL){
            length++;
            head = head->next;
        }
        head = initialHead;*/

        int loopBeginIndex = -1;
        // {nodeValue, [nodeIndex, occurenceCount] valuePairs (nodeIndex represents the first occurence)
        unordered_map<int , vector<int>> map;
        int i = 0;
        while(head != NULL){
            int currData = head->data;
            if(map.find(currData) == map.end()){
                vector<int> vec;
                vec.push_back(i);
                vec.push_back(1);
                map.insert({currData, vec});
            }
            else{
                loopBeginIndex = map.at(currData).at(0);
                break;
            }
            head = head->next;
            i++;
        }
        if(loopBeginIndex != -1){
            return i - loopBeginIndex;
        }
        else{
            return 0;
        }
    }
};
