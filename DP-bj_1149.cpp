#include <iostream>
#include <queue>

using namespace std;

int cost[3][1001];
int dp[3][1001];
int n = 0;

int main() {    
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[j][i];
        }
    }

    dp[0][0] = cost[0][0];
    dp[1][0] = cost[1][0];
    dp[2][0] = cost[2][0];


    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int min = 999999999;

            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    min = dp[k][i-1] < min ? dp[k][i-1] : min;
                }
            }
            dp[j][i] = cost[j][i] + min;
        }
    }

    int answer = 999999999;
    
    for (int i = 0; i < 3; i++) {
        answer = dp[i][n-1] < answer ? dp[i][n-1] : answer;
    }

    cout << answer << endl;

    return 0;
}