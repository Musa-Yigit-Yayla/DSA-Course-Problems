#include <iostream>
#include <vector>
#include "NumberOfIslands.cpp"
using namespace std;

int main()
{
    NumberOfIslands noi;
    vector<vector<char>> input{{{0,1},{1,0},{1,1},{1,0}}};
    int result = noi.numIslands(input);
    cout << result << endl;
    return 0;
}
