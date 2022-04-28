#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isNetwork[201] = {false, };

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < computers.size(); i++) {
        if (isNetwork[i]) {
            continue;
        } 
        
        queue<int> q;
        
        q.push(i);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            isNetwork[curr] = true;
            
            for(int j = 0; j < computers[curr].size(); j++) {
                if (computers[curr][j] == 1 && !isNetwork[j]) q.push(j);
            }
        }
        
        answer++;
    }
    
    return answer;
}