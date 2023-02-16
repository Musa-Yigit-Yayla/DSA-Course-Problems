class GeeksIslandProblem{
private:
    int rowSize;
    int columnSize;

public:
    //return the number of islands(ceels) that water can flow to both seas
    int water_flow(vector<vector<int>>& mat,int N,int M){

        int counter = 0;

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat.at(0).size(); j++){
                if(calculate(mat, i, j)){
                    counter++;
                }
            }
        }
        return counter;
    }
    //i represents row index, whereas j represents column index
    //
    bool calculate(vector<vector<int>>& mat, int i, int j){
        return calculateHelper(mat, i, j);
    }
    //Recursive helper method
    bool calculateHelper(vector<vector<int>>& mat, int i, int j){
        //base case is out of bounds or both seas reached
        static bool indianReached = false;
        static bool arabicReached = false;
        if(i < 0 || j < 0){
            //reached the indian sea
            indianReached = true;
        }
        if(i > rowSize || j > columnSize){
            arabicReached = true;
        }
        if(indianReached && arabicReached){
            arabicReached = false;
            indianReached = false;

            return true;
        }
        if(calculateHelper(mat, i + 1, j)){
            arabicReached = false;
            indianReached = false;

            return true;
        }
        else if(calculateHelper(mat, i, j + 1)){
            arabicReached = false;
            indianReached = false;

            return true;
        }
        else if(calculateHelper(mat, i - 1, j)){
            arabicReached = false;
            indianReached = false;

            return true;
        }
        else if(calculateHelper(mat, i, j - 1)){
            arabicReached = false;
            indianReached = false;

            return true;
        }
        //eventually return false
        return false;
    }
};
