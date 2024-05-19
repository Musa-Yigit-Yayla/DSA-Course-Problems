class Solution {
public:
    vector<int> solve(int n, vector<int>& a) {
       //since we are asked the input for each entry, we will construct a bottom up approach
       vector<int> result;

       int arrTemp[n] = {0};

       for(int i = 0; i < n; i++){
           if(i == 0){
               arrTemp[0] = a.at(i);
               continue;
           }
           int curr = a.at(i);
           int maxRes = curr;
           if(i == 1 && n > 1){
               maxRes = max(a.at(0), a.at(1));
           }
           else if(i > 1){
               maxRes = curr + arrTemp[0];
           }
           for(int j = 1; j < i - 1; j++){
               int currMax = arrTemp[j];
               int prevRes = arrTemp[j - 1];
               //track the prev results sum curr entry
               if(curr + currMax > maxRes){
                   maxRes = curr + currMax;
               }
           }
           arrTemp[i] = maxRes;
       }
       for(int i = 0; i < n; i++){
           result.push_back(arrTemp[i]);
       }
       return result;
    }
    //Other question
    int maxValue(string s)
    {
        //We apply a greedy algorithm. The greedy choice is to choose max(a + b, a * b) where a and b are
        //sequential digits in the given string
        int sum = stoi(s.at(0) + "");
        for(int i = 1; i < s.size(); i++){
            int curr = stoi(s.at(i) + "");
            int maxVal = max(sum + curr, sum * curr);
            sum = maxVal;
        }
        return sum;
    }
};
