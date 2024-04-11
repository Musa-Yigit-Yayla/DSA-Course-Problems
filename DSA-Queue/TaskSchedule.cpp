#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class TaskSchedule{
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> occurenceMap;
        for(char instruction: tasks){
            cout << "hey1" << endl;
            if(occurenceMap.find(instruction) == occurenceMap.end()){
                //make new pair for insertion
                occurenceMap.insert(make_pair(instruction, 1));
            }
            else{
                occurenceMap.at(instruction)++;
            }
        }
        string sequence = "";
        while(!tasks.empty()){
            char instruction = this->fetchInstruction(occurenceMap, sequence, n);
            if(instruction != ' '){
                cout << "hey2" << endl;
                occurenceMap.at(instruction)--;
                //remove one entry from tasks with the current instruction
                for(int i = 0; i < tasks.size(); i++){
                    char ch = tasks.at(i);
                    if(ch == instruction){
                        tasks.erase(tasks.begin() + i);
                        break;
                    }
                }
            }
            sequence += instruction;
        }
        return sequence.size();
    }
    //fetch the instruction which does not occur in sequence's n length suffix and has the most occurence count in the given map
    //if no sutch instruction is found return ' '
    char fetchInstruction(unordered_map<char, int>& occurenceMap, string& sequence, int n){
        string suffix = sequence;
        if(sequence.size() > n){
            suffix = sequence.substr(sequence.size() - n);
        }
        char instruction = ' ';
        int maxCount = 0;
        for(auto& it: occurenceMap){
            if(count(suffix.begin(), suffix.end(), it.first) == 0){ //not in the suffix
                int currCount = it.second;
                if(currCount > maxCount){
                    instruction = it.first;
                    maxCount = currCount;
                }
            }
        }
        return instruction;
    }
};
