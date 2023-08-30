#include <queue>
#include <vector>

using namespace std;
class NodeLevel{
public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X)
	{
	    // code here
	    //the idea is we use a bfs approach but we have an int visit matrix of row length number of vertices
	    //and we have either 0 or 1 representing visit status at the first column, for the second column
	    //we have the level which is initially set to -1
	    //Also we can initially make a regular dfs traversal to see whether the given node is contained

	    if(X >= V){
	        return -1;
	    }
	    int** visit = new int*[V];
	    for(int i = 0; i < V; i++){
	        int* currArr = new int[2];
	        currArr[0] = 0;
	        currArr[1] = -1;
	        visit[i] = currArr;
	    }
	    //after we have completed the bfs traversal we can return the visited elements value
	    bfsLevel(adj, V, visit);
	    int returnValue = visit[X][1];
	    //deallocate the visit
	    for(int i = 0; i < V; i++){
	        delete[] visit[i];
	    }
	    delete[] visit;
	    return returnValue;
	}
	void bfsLevel(vector<int> adj[], int v, int** visit){
	    //start from the root vertex which is assumed to be 0
	    int startVertex = 0;
	    int currLevel = 0;
	    queue<int> s;
	    visit[0][0] = 1; //mark as visited
	    visit[0][1] = currLevel; //level is 0
	    s.push(startVertex);
	    while(!s.empty()){
	        int top = s.front();
	        s.pop();
	        currLevel = visit[top][1];
	        //no need to mark the top as visited since it already has been
	        //retrieve the unvisited current adjacent nodes of the recently popped element
	        vector<int> unvisitedAdj;
	        for(int i: adj[top]){
	            if(!visit[i][0]){
	                //add it to the unvisitedAdj vector
	                unvisitedAdj.push_back(i);
	            }
	        }
	        for(int i = 0; i < unvisitedAdj.size(); i++){
	            int currAdj = unvisitedAdj.at(i);
	            //set the level to currLevel + 1 since there is no self loops
	            visit[currAdj][0] = 1;
	            visit[currAdj][1] = currLevel + 1;
	            //enqueue the recently visited element
	            s.push(currAdj);
	        }
	    }
	}
};
