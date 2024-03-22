#include <vector>

using namespace std;
class CoveredIntervals{
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //brute force approach
        for(int i = 0; i < intervals.size(); i++){
            vector<int> currInterval = intervals.at(i);
            for(vector<int> otherInterval: intervals){
                if(otherInterval == currInterval){
                    continue;
                }
                int a = currInterval.at(0), b = currInterval.at(1);
                int c = otherInterval.at(0), d = otherInterval.at(1);
                if(a >= c && b <= d){
                    cout << "a and b are " << a << ", " << b << "and c and d are " << c << ", " << d;
                    intervals.erase(intervals.begin() + i);
                    //decrement i by one for not skipping the next element of i
                    i--;
                    break;
                }
            }
        }
        return intervals.size();
    }
};
