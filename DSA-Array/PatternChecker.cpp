#include <bits/stdc++.h>
#include <vector>

using namespace std;

class PatternChecker{
public:
    vector<int> pattern(int N){
        // code here
        if(this->patternInvokeCount == 0){
            this->initialN = N;
        }
        else if(N == this->initialN){
            //pat.push_back(N);
            return pat;
        }
        //else{
            this->patternInvokeCount++;
            this->pat.push_back(N);
            if(N >= 0 && N - 5 < 0){
                this->isDecreasing = !this->isDecreasing;
            }
            else if(N <= 0 && N + 5 > 0){
                this->isDecreasing = !this->isDecreasing;
            }
            if(isDecreasing){
                pattern(N - 5);
            }
            else{
                pattern(N + 5);
            }
        //}
    }
private:
    vector<int> pat;
    int patternInvokeCount = 0;
    int initialN = 0;
    bool isDecreasing = true;
};
