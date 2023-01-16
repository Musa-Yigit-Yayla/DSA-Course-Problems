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
        int secondMax = INT_MIN;
        int secondMaxPos = -1;
        for(int i = 0; i < n; i++){
            if(a[i] > secondMax && a[i] != maxElt){
                secondMax = a[i];
                secondMaxPos = i;
            }
        }
        return secondMaxPos;
    }

};
