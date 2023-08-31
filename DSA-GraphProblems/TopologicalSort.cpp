#include <vector>

using namespace std;
class TopologicalSort{
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int v, vector<int> adj[]) {
	    //any topological order would be fine
	    vector<int> result;
	    while(result.size() != v){
	        int endNode = this->getEndNode(adj, v, result);
	        result.insert(result.begin(), endNode);
	    }
	    return result;
	}
	//Result contains nodes which we will disregard when finding a terminating node
	int getEndNode(vector<int> adj[], int v, vector<int> result){
	    int endNode = -1;
	    for(int i = 0; i < v; i++){
	        vector<int> currAdj = adj[i];
	        if(currAdj.size() == 0){
	            endNode = i;
	            break;
	        }
	        else{
	            bool broken = false;
	            for(int j = 0; j < currAdj.size(); j++){
	                int adjLabel = currAdj.at(j);
	                if(count(result.begin(), result.end(), adjLabel) == 0){
	                    broken = true;
	                    break;
	                }
	            }
	            if(!broken){
	                endNode = i;
	                break;
	            }
	        }
	    }
	    return endNode;
	}

};
