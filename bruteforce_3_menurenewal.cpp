#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string, int> combination[11];
int maxMenu[11] = {0,};

void dfs(string order, string partial, int index) {
    if(index >= order.length()) 
        return;

    dfs(order, partial, index+1);

    partial += order[index];
    combination[partial.length()][partial]++;

    if (combination[partial.length()][partial] > maxMenu[partial.length()]) {
        maxMenu[partial.length()] = combination[partial.length()][partial];
    }

    dfs(order, partial, index+1);
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 각 주문마다 루프 돌려
    for(string order : orders) {
        sort(order.begin(), order.end());
        //정렬된 주문의 첫번째 메뉴로 init한다.
        
        dfs(order, "", 0);
    }

    for (int num : course) {
        for(auto comb : combination[num]) {
            if (maxMenu[num] >= 2 && comb.second == maxMenu[num]) {
                answer.push_back(comb.first);
            }   
        }
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}