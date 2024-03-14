#include <vector>

using namespace std;
class FindShiftAmt{
public:
    int findShift(vector<int>& arr){
        if(arr.size() <= 1){
            return 0;
        }
        int prev = arr[0];
        for(int i = 1; i < arr.size(); i++){
            int curr = arr[i];
            if(prev > curr){
                return i;
            }
        }
        return 0;
    }
};
