#include <iostream>
using namespace std;

//int arr[5][4] = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};

int* arr;
int noOfColumns, noOfRows;
void fun2(int, int);
void function1( int rows, int columns){
    //check each row for whether that row contains one, if it does call fun2 on that row
    for(int k = 0; k < rows; k++){
        for(int j = 0; j < columns; j++){
            if(*(arr + (k * noOfColumns + j) * sizeof(int)) == 1){
                fun2(k, columns);
                break;
            }
        }
    }

}
void fun2( int rowIndex, int columns){
    for(int j = 0; j < columns; j++){
        *(arr + (rowIndex * noOfColumns + j) * sizeof(int)) = 1;

    }
}
bool fun3(int arr[], int n, int x){
    //find the sum of each pair and compare it with x
    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            if(arr[i] + arr[j] == x){
                return true,
            }
        }
    }
    return false;
}

int main() {
	//code
	int T;
	int m, n; // m rows, n columns
	cin >> T;

	while(T >= 0){
	    cin >> m;
	    cin >> n;
	    int a[m][n];
	    arr = &a[0][0];
	    noOfRows = m;
	    noOfColumns = n;
	    int nextValue;
	    for(int j = 0; j < m; j++){


	        for(int i = 0; i < n; i++){
	            cin >> nextValue;
	            //place in the array
	            a[j][i] = nextValue;
	            //cout << nextValue;
	        }
	        //cout << endl;
	    }
	    function1(m, n);
	    T--;
	}
	//function(m, n);
	for(int i = 0; i < noOfRows; i++){
	    //cout << "hey2";
	    for(int j = 0; j < noOfColumns; j++){
	        //cout << "hey1";
	        cout << *(arr + (i * noOfColumns + j) * sizeof(int));
	    }
	    cout << endl;
	}
	return 0;
}
