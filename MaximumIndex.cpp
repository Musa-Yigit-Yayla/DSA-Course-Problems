#include <iostream>
#include <vector>
using namespace std;

class MaximumIndex{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    //Brute force
    static int maxIndexDiff(int a[], int n){
        // Your code here
        int lengthiestDiff = 0;
        for(int i = 0; i < n -1; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] <= a[j] && ((j - i) > lengthiestDiff)){
                   lengthiestDiff = j - i;
                }
            }
        }
        return lengthiestDiff;
    }
    static int secondMaxIndex(int a[], int n){
        //find the max
        //Then find the max which is not equal to original max if exists
        //return its index if exists otherwise return -1

        int maxElt = a[0];
        for(int i = 1; i < n; i++){
            if(a[i] > maxElt){
                maxElt = a[i];
            }
        }
        int secondMax = -1000000;
        int secondMaxPos = -1;
        for(int i = 0; i < n; i++){
            if(a[i] > secondMax && a[i] != maxElt){
                secondMax = a[i];
                secondMaxPos = i;
            }
        }
        return secondMaxPos;
    }
    /*
    *Returns the size of the array after removing duplicates
    *no extra array storage used built-in
    */
    static int getDistinctElements(int a[], int n){
        int prev = 0;
        int modifiedSize = n;
        for(int i = 1; i < n; i++, prev++){
            if(a[i] == a[prev]){
                shift(a, modifiedSize, prev);
                modifiedSize--;
            }
        }
        //print array
        printArray(a, modifiedSize);
        return modifiedSize;
    }
    static void shift(int a[], int n, int pos){
        for(int i = pos + 1; i < n; i++, pos++){
            a[pos] = a[i];
        }
    }
    static void printArray(int a[], int n){
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    static void moveZerosToEnd(int arr[], int n){
        int initialN = n;
        for(int i = 0; i < initialN; i++){
            if(arr[i] == 0){
                //move to the end
                //swap with n - 1th element
                if(arr[n - 1] != 0){
                    int temp = arr[i];
                    arr[i] = arr[n - 1];
                    arr[n - 1] = temp;
                    //n--;
                }

                //n--; // may need to remove
            }

        }
    }
    //Function to reverse every sub-array group of size k.
    /*void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        for(int i = 0; i < k; i += n){
            if(i + n > k){
                reverseSubArray(arr, i, k - 1);
            }
            else{
                reverseSubArray(arr, i, i + n);
            }
        }

    }*/
    /*long long erase(int pos, vector<long long>& arr){
        long long returnValue = arr.at(pos);
        for(int i = pos; i < arr.size() - 1; i++){
            arr.insert(pos, arr.at(pos + 1));
        }
        return returnValue;
    }
    void reverseSubArray(vector<long long>& arr, int low, int high){
        //low high inclusive
        while(low < high){

            long long temp = erase(low, arr);
            arr.insert(low, arr.at(high));
            erase(high, arr);
            arr.insert(high, temp);
            low++;
            high--;
        }
    }*/
    static vector<int> getLeaders(int arr[], int n){
        vector<int> leaders; //don't use parantheses for the default constructor
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                if(i == n - 1){
                    leaders.push_back(arr[i]);
                }
                else if(j == n){
                    break;
                }
                else if(arr[j] >= arr[i]){
                    break;
                }
                else if(j == n - 1){
                    leaders.push_back(arr[i]);
                }
            }
        }
        //print leaders
        for(int i = 0; i < leaders.size(); i++){
            cout << leaders.at(i) << ", ";
        }
        cout << endl;
        return leaders;
    }
    static vector<vector<int>> getFrequenciesFromSortedArray(int arr[], int n){
        vector<vector<int>> value;

        int* counter;
        *counter = 1;
        int prev = arr[0];
        vector<int> vec{prev, *counter};
        value.push_back(vec);
        for(int i = 1; i < n; i++){
            if(arr[i] == prev){
                *counter++;
            }
            else{
                prev = arr[i];
                int newCounter = 1;
                counter = &newCounter;
                vector<int> vec{prev, *counter};
                value.push_back(vec);
            }
        }
        return value;
    }
    static void print2DVector(vector<vector<int>> vec){
        for(int i = 0; i < vec.size(); i++){
            vector<int> curr = vec.at(i);
            for(int j = 0; j < curr.size(); j++){
                cout << curr.at(j) << " ";
            }
            cout << endl;
        }
    }
    static int getMaxConsecutiveOnes(bool arr[], int n){
        int maxCount = 0;
        int currCount = 0;
        int prev = arr[0];
        for(int i = 0; i < n; i++){
            if(arr[i] == 1){
                currCount++;
                //check whether currCount is greater than maxCount
                if(currCount > maxCount){
                    maxCount = currCount;
                }
            }
            else if(arr[i] == 0){
                currCount = 0;
            }

            prev = arr[i];
        }
        return maxCount;
    }
};
