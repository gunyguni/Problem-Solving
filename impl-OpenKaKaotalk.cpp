#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> final_name;

    for(string talk_log : record) {
        vector<string> words = split(talk_log, ' '); 

        if (words[0] != "Leave") {
            final_name[words[1]] = words[2];
        }

    }

    for(string talk_log : record) {
        vector<string> words = split(talk_log, ' '); 
        string temp = final_name[words[1]];

        temp += "님이 ";

        if (words[0] == "Enter") {
            temp += "들어왔습니다.";
        } else if (words[0] == "Leave") {
            temp += "나갔습니다.";
        } else {
            continue;
        }
        answer.push_back(temp);
    }

    return answer;
}