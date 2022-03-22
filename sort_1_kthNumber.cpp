#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(auto ijk : commands) {
        vector<int> subarray(array.begin()+ijk[0]-1, array.begin()+ijk[1]);
        sort(subarray.begin(), subarray.end());

        answer.push_back(subarray[ijk[2]-1]);
    }


    return answer;
}