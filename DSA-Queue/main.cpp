#include <iostream>
#include <vector>
#include <string>
#include "MyQueue.cpp"
#include "SearchSuggestionHeap.cpp"

using namespace std;

void test0();

int main(){
    test0();
    /*MyQueue mq;
    mq.push(2);
    //mq.push(3);
    cout << mq.pop() << endl;
    //mq.push(4);
    cout << mq.pop() << endl;
    cout << mq.pop() << endl;*/
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";
    vector<string> arr = {"a", "b", "c", "d", "e"};
    SearchSuggestionHeap sgh;
    sgh.suggestedProducts(arr, "a");
    vector<vector<string>> result = sgh.suggestedProducts(products, searchWord);
    return 0;
}
void test0(){
    cout << endl;
    cout << endl;
}
