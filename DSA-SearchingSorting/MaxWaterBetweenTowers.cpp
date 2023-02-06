#include <iostream>

using namespace std;

class MaxWaterBetweenTowers{
public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n)
    {
        //Your code here
        int l = 0, h = n - 1;
        int maxTrappedWater = 0;
        while(l < n){
            maxTrappedWater = max(maxTrappedWater, this->calculateTrappedWater(height, n, l, h));
            if(height[l] < height[h]){
                //maxTrappedWater = max(maxTrappedWater, calculateTrappedWater(height, n, l, h));
                l++;
            }
            else{

                h--;
            }
        }
        return maxTrappedWater;
    }
    int calculateTrappedWater(int height[], int n, int l, int h){
        return min(height[l], height[h]) * (h - l - 1);
    }
};
