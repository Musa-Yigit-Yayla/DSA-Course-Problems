#include <vector>
#include <list>

using namespace std;
class PartitionThreeWay{
public:
    //Function to partition the array around the range such
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int leftInsertion = -1;
        list<int> myList;
        for(int i = 0; i < array.size(); i++){
            myList.push_back(array.at(i));
        }
        // code here

        list<int>::iterator it = myList.begin();
        for(int i = 0; i < array.size(); i++ ){
            int curr = *it;
            if(curr < a){
                //place at the very beginning
                list<int>::iterator next = std::next(it, 1);
                myList.erase(it);
                myList.push_front(curr);
                it = next;
            }
            else if(curr > b){
                list<int>::iterator next = std::next(it, 1);
                myList.erase(it);
                myList.push_back(curr);
                it = next;
            }
            else{
                it++;
            }
        }
        /*for(list<int>::iterator it = myList.begin(); it != myList.end(); it++){
            cout << *it;
        }*/
        array.clear();
        for(list<int>::iterator it = myList.begin(); it != myList.end(); it++){
            array.push_back(*it);
        }
    }
};
