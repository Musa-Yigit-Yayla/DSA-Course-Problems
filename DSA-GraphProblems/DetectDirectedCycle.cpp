#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;
class DetectDirectedCycle{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        //During our traversal, if at any time we observe that a label is adjacent to itself or
        //another already visited label then we reckon that there is a cycle
        bool totalVisit[v]; //total number of visited nodes
        for(int i = 0; i < v; i++){
            totalVisit[i] = false;
        }
        bool result = false;
        while(!this->isTraversed(totalVisit, v)){
            //retrieve an unvisited vertex and start the traversal from there
            int currLabel = this->getUnvisitedLabel(totalVisit, v);
            //cout << currLabel << endl;
            if(currLabel != -1 && this->dfsCycleCheck(adj, v, currLabel, totalVisit)){
                result = true;
                break;
            }
            else if(currLabel == -1){
                break;
            }

        }
        return result;
    }
    //We are obliged to update the total visit in here as well
    bool dfsCycleCheck(vector<int> adj[], int v, int givenLabel, bool totalVisit[]){
        stack<int> s;
        bool visit[v];
        for(int i = 0; i < v; i++){
            visit[i] = false;
        }

        //mark the given label as visited in both visit arrays after having pushed it into the stack
        s.push(givenLabel);
        totalVisit[givenLabel] = true;
        visit[givenLabel] = true;

        while(!s.empty()){
            //pop the top
            int top = s.top();
            s.pop();

            //if we have the current vertex on its own adjacency list or any other visited vertex
            //on the local visit array then we immediately return true
            vector<int> currAdj = adj[top];
            if(count(currAdj.begin(), currAdj.end(), top) != 0){
                return true; //self loop
            }

            for(int i = 0; i < currAdj.size(); i++){
                int adjLabel = currAdj.at(i);
                if(visit[adjLabel]){
                    return true;
                }
                else{
                    //push into the stack and mark as visited
                    s.push(adjLabel);
                    visit[adjLabel] = true;
                    totalVisit[adjLabel] = true;
                }
            }
        }
        return false;
    }
    bool isTraversed(bool visit[], int n){
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
    //return the first unvisited label
    int getUnvisitedLabel(bool visit[], int n){
        int result = -1;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                result = i;
                break;
            }
        }
        return result;
    }
};
