#include <iostream>

using namespace std;


void findNum(int dist) {

    int sum = 0, answer = 0, next_sum = 0;
    
    for(int j = 1; j < dist; j++) {
        sum += j;
        dist -= j;
        next_sum = sum + j + 1;

        if (next_sum < dist) {
            continue;
        } else if (next_sum == dist) {
            answer = 2*j + 1;
            break;
        } else {
            if (sum < dist) {
                answer = 2*j + 1;
                break;
            } else {
                answer = 2*j;
                break;
            }
        }     
    }

    cout << answer << endl;
}

int main() {
    int n;

    cin >> n;

    int start, end;

    for (int i = 0; i < n; i++) {
        cin >> start >> end;

        int diff = end - start;
        
        if (diff == 1) {
            cout << 1 << endl;
        } else {
            findNum(diff);
        }
        
    }
    return 0;
}