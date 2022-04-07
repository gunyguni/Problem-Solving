#include <iostream>
#include <queue>

using namespace std;

int target_number = 0;
int min_count = 1000001;
bool visited[1000001] = {false,};

void bfs() {
    queue<pair<int, int>> q;

    q.push(make_pair(1,0));

    int num = 0, count = 0;
    while (!q.empty()) {
        num = q.front().first;
        count = q.front().second;
        q.pop();

        if (count > min_count || num > target_number || visited[num]) {
            continue;
        }

        if (num == target_number) {
            min_count = count;
            continue;
        }

        q.push(make_pair(num+1, count+1));
        q.push(make_pair(num*2, count+1));
        q.push(make_pair(num*3, count+1));

        visited[num] = true;

    }
}

int main() {
    cin >> target_number;

    bfs();

    cout << min_count << endl;

    return 0;
}