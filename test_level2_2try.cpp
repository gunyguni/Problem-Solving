#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long nll = n;
    int row = 0, col = 0;

    for (long long i = left; i < right; i++) {
        row = i % nll;
        col = i / nll;

        if (row > col) {
            answer.push_back(row + 1);
        } else {
            answer.push_back(col + 1);
        }
    }
    
    return answer;
}