#include <iostream>
#include <vector>
#include "NumberOfIslands.cpp"
#include "FindPath.cpp"
using namespace std;

int main()
{
    NumberOfIslands noi;
    //vector<vector<char>> input{{{0,1},{1,0},{1,1},{1,0}}};
    /*vector<vector<char>> input{{0, 1, 0},
                                {0, 1, 0},
                                {0, 0, 0},
                                {1, 1, 0},
                                {1, 0, 1},
                                {0, 1, 1},
                                {1, 1, 1},
                                {0, 1, 1},
                                {1, 0, 1}};
    int result = noi.numIslands(input);
    cout << result << endl;*/
    vector<vector<int>> input1{{3, 0, 3, 0, 0},
                                {3, 0, 0, 0, 3},
                                {3, 3, 3, 3, 3},
                                {0, 2, 3, 0, 0},
                                {3, 0, 0, 1, 3}};
    vector<vector<int>> input2{{1, 3},
                                {3, 2}};
                                vector<vector<int>> input3{{1, 3},
                                                            {3, 3},
                                                            {3,0},
                                                            {0, 2}};
    vector<vector<int>> input4{{1, 3},
                                                            {3, 3},
                                                            {3, 0},
                                                            {3, 2}};
    FindPath fp;
    cout << fp.is_Possible(input1) << endl;
    cout << fp.is_Possible(input2) << endl;
    cout  << fp.is_Possible(input3) << endl;
    cout << fp.is_Possible(input4) << endl;
    return 0;
}
