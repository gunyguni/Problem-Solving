#include <string>
#include <vector>

using namespace std;
vector<vector<int> > answer;

void hanoi(int n, int current, int destination) {
    int via = 0;
    vector<int> result;

    if(n == 1) {
        result.push_back(current);
        result.push_back(destination);
        answer.push_back(result);

        return;
    }

    for(int i = 1; i <= 3; ++i) {
        if(i != current && i != destination) { 
            via = i;
            break;
        }
    }

    hanoi(n-1, current, via);
    
    
    result.push_back(current);
    result.push_back(destination);
    answer.push_back(result);

    hanoi(n-1, via, destination);

    return;
}

vector<vector<int> > solution(int n) {
    hanoi(n, 1, 3);
    
    return answer;
}