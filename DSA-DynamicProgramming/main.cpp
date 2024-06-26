#include <iostream>
#include <string>
#include <vector>
#include "LongestPalindromicSubstring.cpp"
#include "GenerateParantheses.cpp"
#include "Kadane.cpp"
#include "LCS.cpp"
#include "ActivitySelect.cpp"
#include "Climber.cpp"
#include "PlayerSelect.cpp"
#include "Huffman.cpp"

using namespace std;


MinHeapNode* createNode(char data, int freq) {
    MinHeapNode* node = new MinHeapNode();
    node->data = data;
    node->freq = freq;
    return node;
}


int main(){
    //LongestPalindromicSubstring lps;

    //cout << lps.longestPalindrome("aaaaa") << endl;
    //GenerateParantheses gp;
    //vector<string> vec = gp.generateParenthesis(5);
    //int x = gp.longestValidParentheses("()");
    int arr[6] = {5, -2, -3, 32, -5, 65};
    int arr2[5] = {-9, -8, 8, 11, 7};
    int arr3[5] = {-9,-8,8,3,-4};
    //Kadane k;
    //cout << k.maximumSum(arr, 6) <<endl;
    //cout << k.maximumSum(arr2, 5) <<endl;
    //cout << k.maximumSum(arr3, 5) <<endl;

    //LCS lcs;
    //cout << lcs.lcs(6, 13, "CECDBB", "CAACDDABBDACA") << endl;
    /*ActivitySelect as;
    vector<int> start = {2, 1};
    vector<int> end = {2, 2};
    int z = as.activitySelection(start, end, 2);*/
    /*Climber c;
    int* grid[1] = {};
    grid[0] = new int[2]{3, 5};

    int* grid2[4] = {};
    grid2[0] = new int[5]{2, 8, 9, 5, 8};
    grid2[1] = new int[5]{4, 4, 6, 2, 3};
    grid2[2] = new int[5]{5, 7, 5, 6, 1};
    grid2[3] = new int[5]{3, 2, 5, 4, 8};
    cout << c.getSafestPath(grid, 1, 2) << endl;
    cout << c.getSafestPath(grid2, 4, 5) << endl;*/

    //PlayerSelect ps;
    //ps.printTest();
    Huffman h;

    MinHeapNode* root = createNode('$', 20);

    root->left = createNode('$', 8);
    root->right = createNode('$', 12);

    root->left->left = createNode('$', 3);
    root->left->right = createNode('E', 5);

    root->left->left->left = createNode('B', 1);
    root->left->left->right = createNode('D', 2);

    root->right->left = createNode('C', 6);
    root->right->right = createNode('A', 6);

    string binaryStr = "1111111111110001010101010100010010101010101";
    cout << "Result: " << h.decodeHuffmanData(root, binaryStr) << endl;

    return 0;
}
