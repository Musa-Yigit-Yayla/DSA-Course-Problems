#include <unordered_map>
#include <string>
#include <iostream>

struct MinHeapNode
    {
        char data;
        int freq;
        MinHeapNode *left, *right;
    };

using namespace std;
class Huffman{
private:
    unordered_map<string, char> charEncodings;

public:
    void preorder(struct MinHeapNode* curr, string currEncode){
        if(curr->left == NULL && curr->right == NULL){
            //we have a leaf node
            charEncodings.insert(make_pair(currEncode, curr->data));
            return;
        }
        preorder(curr->left, currEncode + "0");
        preorder(curr->right, currEncode + "1");
    }

    //Function to return the decoded string.
    string decodeHuffmanData(struct MinHeapNode* root, string binaryString){
        // Code here
        //we will traverse the leaves of root in preorder fashion and obtain a mapcontaining
        //encoding matches
        preorder(root, "");
        string result = "";

        int i = 0;
        while(i < binaryString.size()){
            bool broken = false;
            for(int j = 1; j <= binaryString.size() - i; j++){
                string currStr = binaryString.substr(i, j);
                if(charEncodings.find(currStr) != charEncodings.end()){
                    result += charEncodings.at(currStr);
                    i += j;
                    broken = true;
                    break;
                }
            }
            if(!broken){
                break;
            }
        }
        return result;
    }
};
