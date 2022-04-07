#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int line[1001], sum[1001];
bool visited[1001];
int n = 0;


int main() {
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> line[i];
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        
        visited[i] = true;
        int index = line[i]; 
        // cout << "nextIndex = " << line[i] << endl;
        int count = 1;
        
        while (!visited[index]) {
            // cout << "curr index / next index : " << index << ", " << line[index] << endl;
            visited[index] = true;
            count++;
            index = line[index];
        }
        // cout << "count = " << count << endl;
        sum[i] = count;
    }

    int max = 0, answer = 0;

    for (int i = 1; i <= n; i++) {
        // cout << sum[i];
        if(sum[i] > max) {
            max = sum[i];
            answer = i;
        }
    }
    // cout << endl;
    cout << answer << endl;

    return 0;
}