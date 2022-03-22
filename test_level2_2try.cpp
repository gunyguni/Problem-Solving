#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());

    int start = 0, end = people.size() - 1;

    while (start <= end) {
        if (start == end) {
            answer++;
            break;
        }

        if (people[end] + people[start] > limit) {
            end--;
        } else {
            start++;
            end--;
        }

        answer++;
    }


    
    return answer;
}