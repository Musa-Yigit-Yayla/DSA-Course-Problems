class{
public:
    //Function to print the list of integers denoting spiral traversal of matrix.
    void spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        int left = 0, top = 0, bottom = r - 1, right = c - 1;

        while(left <= right && bottom >= top){
            //print top row
            vector<int> currRow = matrix.at(top);
            for(int i = left; i <= right; i++){
                cout << currRow[i] << " ";
            }
            top++;
            //print right column
            for(int j = top; j <= bottom; j++){
                cout << matrix[j][right] << " ";
            }
            right--;
            //print bottom row in reverse order
            for(int i = right; i >= 0; i--){
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
            //print left column from bottom to top (top inclusive)
            for(int i = bottom; i >= top; i--){
                cout << matrix[i][left];
            }
            left++;
        }
    }
};
