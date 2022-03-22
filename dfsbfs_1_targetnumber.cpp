#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int answer = 0;

void bfs(int sum, vector<int> numbers, int pos, int target) {
        if (pos >= numbers.size()) {
            return;
        } 
        cout << "curr num: " << numbers[pos] << " curr sum: " << sum << endl;
        
        int addsum = sum + numbers[pos];
        int subsum = sum - numbers[pos];

        if (pos == numbers.size() - 1) {
            if (addsum == target) answer++;
            
            if (subsum == target) answer++;
            
            return;
        }

        bfs(addsum, numbers, pos+1, target);
        bfs(subsum, numbers, pos+1, target);
}

int solution(vector<int> numbers, int target) {

    bfs(0, numbers, 0, target);
    
    return answer;
}

int main() {
    vector<int> array {4, 1, 2, 1};

    int ans = solution(array, 4);
    cout << ans << endl;
}