#include <vector>
#include <algorithm>

using namespace std;
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(double* a, double* b){
        return a[1] < b[1];
    }

class FractionalKnapsack{
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        //sort indexes wrt value weight ratio in descending order
        vector<double*> indexRatio;
        for(int i = 0; i < n; i++){
            Item curr = arr[i];
            double ratio = ((double)(curr.value)) / curr.weight;
            double* newArr = new double[2];
            newArr[0] = i;
            newArr[1] = ratio;
            indexRatio.push_back(newArr);
        }

        sort(indexRatio.begin(), indexRatio.end(), comp);

        double value = 0;
        double currWeight = 0;
        int currIndex = n - 1;
        //greedy choice is to select as much as we can from the most valuable item and proceed
        while(currWeight < w && currIndex >= 0){
            double availW = w - currWeight;
            int entryIndex = indexRatio.at(currIndex)[0];
            if(availW >= arr[entryIndex].weight){
                currWeight += arr[entryIndex].weight;
                value += arr[entryIndex].value;
                currIndex--;
            }
            else{
                //take as much as we can
                currWeight += availW;
                value += availW * indexRatio.at(currIndex)[1];
            }
        }
        return value;

    }
};

