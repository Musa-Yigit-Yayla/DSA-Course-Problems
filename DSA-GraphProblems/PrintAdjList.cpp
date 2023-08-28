#include <pair>
#include <vector>
#include <utility>

using namespace std;
class PrintAdjList{
public:
   vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> result;
        /*set<int> values;
        //count the number of vertices
        for(int i = 0; i < edges.size(); i++){
            int curr = edges.at(i).first;
            values.insert(curr);
        }*/
        //initialize the result vector with empty int vectors
        for(int i = 0; i < V; i++){
            vector<int> newVec;
            result.push_back(newVec);
        }
        for(int i = 0; i < edges.size(); i++){
            pair<int, int> currPair = edges.at(i);
            int first = currPair.first;
            int second = currPair.second;
            result.at(first).push_back(second);
            result.at(second).push_back(first);
        }
        return result;
    }
};


