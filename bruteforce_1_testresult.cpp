#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int correct1 = 0, correct2 = 0, correct3 = 0;

    int student2[8] = {2,1,2,3,2,4,2,5};
    int student3[5] = {3,1,2,4,5};

    for (int i = 0; i < answers.size(); i++) {
        if(answers[i] == (i % 5 + 1)) {
            correct1++;
        }

        int index2 = i % 8;
        if (answers[i] == student2[index2]) correct2++;
        

        int index3 = i % 10;
        index3 /= 2;
        if (answers[i] == student3[index3]) correct3++;
    }
    
    int max = correct1;

    if (correct2 > max) {
        max = correct2;
    }
    if (correct3 > max) {
        max = correct3;
    }
    vector<int> answer;
    if (max == correct1) answer.push_back(1);
    if (max == correct2) answer.push_back(2);
    if (max == correct3) answer.push_back(3);

    return answer;
}