#include <queue>
#include <vector>
#include <math>

using namespace std;
class Graph{
private:
    vector<int>* adjList;
    int nodeCount;
public:
    //Grid is expected to be not ragged matrix and non empty
    Graph(vector<vector<int>>& grid){
        //create an adjList of the grid elemenets
        this->nodeCount = grid.size() * grid.at(0).size();
        adjList = new vector<int>[this->nodeCount];

        int currIndex = 0;
        for(int i = 0; i < i < grid.size(); i++){
            for(int j = 0; j < grid.at(i).size(); j++){
                vector<int> adj; //adjacency list for the current element
                //we will store the binary values of the adjacent nodes
                //diagonal nodes are not considered to be adjacent
                if(j - 1 >= 0){
                    adj.push_back(grid.at(i).at(j - 1));
                }
                if(j + 1 < grid.at(i).size()){
                    adj.push_back(grid.at(i).at(j + 1));
                }
                if(i - 1 >= 0){
                    adj.push_back(grid.at(i - 1).at(j));
                }
                if(i + 1 < grid.size()){
                    adj.push_back(grid.at(i + 1).at(j));
                }
                adjList[currIndex] = adj;
                currIndex++;
            }
        }
    }
    ~Graph(){
        delete[] adjList;
    }
     // BFS function to find minimum distance
    void bfs(bool visit[], vector<vector<int>>& dist, queue<int>& q){
        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            for (int i = 0; i < this->adjList[temp].size(); i++) {
                if (visit[this->adjList[temp][i]] != 1) {
                    this->adjList[temp][i]] = min(dist[this->adjList[temp]][i]);
                    dist[this->adjList[temp][i], dist[temp] + 1);

                    q.push(this->adjList[temp][i]);
                    visit[this->adjList[temp][i]] = 1;
                }
            }
        }
    }
};

class GridDistance{
public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    //Construct a graph where each vertex has adjacency between their adjacent grid elements in
	    //the grid

	    Graph myGraph(grid);

	    queue<int> q;

	    int currIndex = 0;
	    for(int i = 0; i < grid.size(); i++){
	        for(int j = 0; j < grid.at(i).size(); j++){
	            int curr = grid.at(i).at(j);
	            if(curr == 1){
	                q.push(currIndex);
	            }
	            currIndex++;
	        }
	    }

	    vector<vector<int>> result(grid.size(), vector<int>(grid.at(0).size(), 0));
	    bool visit[currIndex];
	    for(int i = 0; i < currIndex; i++){
	        visit[i] = false;
	    }

	    //push the first element into the queue before breadth first traversal
	    q.push(grid.at(0).at(0));
	    bfs(visit, result, q);
	    return result;
	}
};
