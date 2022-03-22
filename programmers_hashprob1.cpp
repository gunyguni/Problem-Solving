#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    bool completed = true;
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i = 0; i < completion.size(); i++) {
        if(participant[i].compare(completion[i]) != 0) {
                completed = false;
                answer = participant[i];
                break;
            
        }
    }

    if (completed) {
        answer = participant.back();
    }
    
    return answer;
}

