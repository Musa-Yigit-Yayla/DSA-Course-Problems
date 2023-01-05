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
                if(arr[i] <= arr[j] && ((j - i) > lengthiestDiff)){
                   lengthiestDiff = j - i;
                }
            }
        }
        return lengthiestDiff;
    }


};
