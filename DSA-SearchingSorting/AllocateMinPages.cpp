#include <iostream>

using namespace std;

class AllocateMinPages{
public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        //code here
        //if we have more students than the books then return -1
        if(N < M){
            return -1;
        }
        //sum the pages
        int sum = 0;
        int minPages = A[0]; // minimum of the pages
        for(int i = 0; i < N; i++){
            sum += A[i];
            if(A[i] < minPages){
                minPages = A[i];
            }
        }

        int start = 0, end = sum;
        int result = INT_MAX;
        while(start <= end){
            int mid = (start + end) / 2;

            if(this->isValid(A, N, M, mid)){
                result = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return result;
    }
    bool isValid(int A[], int N, int M, int curr_min){
        int studentsRequired = 1;
        int curr_sum = 0;

        for(int i = 0; i < N; i++){

            if(A[i] > curr_min){
                return false;
            }

            //curr_sum += A[i];
            if(curr_sum + A[i] > curr_min){
                studentsRequired++;

                //update curr_sum
                curr_sum = A[i];

                if(studentsRequired > M){
                    return false;
                }
            }
            else{
                curr_sum += A[i];
            }
        }
        return true;
    }
};
