#include <vector>
#include <iostream>

using namespace std;

class Solution
{
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>>& matrix){
        int i = 0, j = 0;
        int rows = matrix.size();
        int columns = matrix.at(0).size();
        int hitColumn = 0; // represents the column that we will start the next iteration. Update inside the loops properly.

        while(i < rows){
            while(i < rows && j < columns){
               int curr = matrix.at(i).at(j);
               if(curr == 1){
                   turnIntoOne(matrix, i, j);
                   i++;
                   j++;
                   hitColumn = j;
                   continue;
               }
               else{
                   if(j == columns - 1){
                       //switch to the next row
                       i++;
                       j = hitColumn;
                       break;
                   }
                   else{
                       j++;
                   }
               }
            }

        }
    }
    /*
    *Function to turn ith row and jth column elements all into 1
    *Receives a binary matrix consisting of only ones and zeros
    *Returns true if function performed correctly, otherwise returns false
    */
    bool turnIntoOne(vector<vector<int>>& matrix, int i, int j){
        //traverse the row first
        bool returnValue = false;
        for(int k = 0; k < matrix.at(i).size(); i++){
            matrix.at(i).at(k) = 1;
            returnValue = true;
        }
        //Then traverse column if possible
        for(int k = 0; k < matrix.size(); k++){
            matrix.at(k).at(j) = 1;
            returnValue = true;
        }
        return returnValue;
    }
};
