#include <vector>
#include <queue>

using namespace std;
class MotherVertex{
public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int v, vector<int>adj[]){
	    //Finding any mother vertex would be adequate, namely a vertex which we can traverse the whole graph
	    int result = -1;
	    for(int i = 0; i < v; i++){
	        int possibleMother = i;
	        vector<bool> visit(v, false);
	        this->bfs(possibleMother, visit, adj);
	        bool broken = false;
	        for(bool x: visit){
	            if(!x){
	                broken = true;
	                break;
	            }
	        }
	        if(!broken){
	            result = possibleMother;
	            break;
	        }
	    }
	    return result;
	}
	void bfs(int label, vector<bool>& visit, vector<int> adj[]){
	    queue<int> q;

	    //enqueue the given label and mark it as visited
	    q.push(label);
	    visit.at(label) = true;

	    while(!q.empty()){
	        //dequeue the front element and use bfs approach to its unvisited adjacent labels
	        int currLabel = q.front();
	        q.pop();

	        vector<int> currAdj = adj[currLabel];
	        for(int i = 0; i < currAdj.size(); i++){
	            int adjLabel = currAdj.at(i);
	            if(!visit.at(adjLabel)){
	                q.push(adjLabel);
	                visit.at(adjLabel) = true;
	            }
	        }
	    }
	}
};
