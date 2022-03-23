#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<pair<int,int>> graph[201];
int price[201][201];
int dist1[201], dist2[201], dist3[201];

void dijkstra(int start, int dist[]) {
    for(int i = 0; i < 201; i++) {
        dist[i] = 9999999;
    }

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[curr].size(); i++) {
            int nextcost = graph[curr][i].first;
            int next = graph[curr][i].second;

            // cout << "curr node : " << curr << " , next node : " << next << " , prev distance : " << dist[next] << " new dist : " << cost + nextcost << endl;

            if (dist[next] > cost + nextcost) {
                dist[next] = cost + nextcost;
                pq.push(make_pair(-dist[next], next));
            }

        }
    }

    // for(int i = 1; i <= 10; i++) {
    //     cout << i << " : " << dist[i]<< ", ";
    // }
    // cout << endl;
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    // convert input into adjacency graph
    for (auto info : fares) {
        // info[0] = x, info[1] = y, info[2] = fare
        graph[info[0]].push_back(make_pair(info[2],info[1]));
        graph[info[1]].push_back(make_pair(info[2],info[0]));

    }

    dijkstra(s, dist1);
    dijkstra(a, dist2);
    dijkstra(b, dist3);
    
    
    int min = 999999999;

    for(int i = 1; i <= n; i++) {
         int total = dist1[i] + dist2[i] + dist3[i];

         if(total < min) {
             min = total;
         }
    }

    return min;
}

int main() {
    vector<vector<int>> testcase = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    int ans = solution(6,4,6,2, testcase);

    cout << ans << endl;

}