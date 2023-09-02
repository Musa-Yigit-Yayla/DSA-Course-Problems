#include <iostream>
#include <vector>
#include "NumberOfIslands.cpp"
#include "FindPath.cpp"
#include "GraphCounter.cpp"
#include "DetectCycle.cpp"
#include "DetectDirectedCycle.cpp"
#include "LargestArea.cpp"
#include "Dijkstra.cpp"
using namespace std;

int main()
{
    //NumberOfIslands noi;
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
    /*vector<vector<int>> input1{{3, 0, 3, 0, 0},
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
    cout << fp.is_Possible(input4) << endl;*/
    /*GraphCounter gc;
    vector<vector<char>> grid = {{'X', 'O', 'X'},
                                  {'O', 'X', 'O'},
                                  {'X', 'X', 'X'}};
    cout << gc.xShape(grid) << endl;*/
    /*int v = 5;
    vector<int> adjArr[] = {{0, 1},
                            {1, 2},
                            {1, 4},
                            {2, 3},
                            {3, 4}};
    DetectCycle dc;
    cout << dc.isCycle(v, adjArr) << endl;*/
    /*DetectDirectedCycle ddc;
    vector<int> adj[] = {{1},
                         {2},
                          {3},
                          {3}
                           };
    cout << ddc.isCyclic(4, adj) << endl;*/
    /*LargestArea la;
    vector<vector<int>> grid = {{1, 1, 1, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1}};
    cout << la.findMaxArea(grid) << endl;*/
    Dijkstra d;
    int v = 4;
    vector<vector<int>> input[] =  {{{0, 1, 9}, {0, 2, 1}, {0, 3, 1}},
{{1, 3, 3}},
{{2, 3, 2}}};
    int s = 0;
    vector<int> output = d.dijkstra(v, input, s);
    for(int i: output){
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
