#include <string>
#include <vector>
#include <iostream>

using namespace std;



int solution(vector<vector<int>> triangle) {
    int max = 0;

    if (triangle.size() == 1) {
        return triangle[0][0];
    }

    for(int depth = 1; depth < triangle.size(); depth++) {
        for(int choice = 0; choice <= depth; choice++) {
            if (choice == 0) {
                triangle[depth][choice] += triangle[depth-1][choice];
            } else if (choice == depth) {
                triangle[depth][choice] += triangle[depth-1][choice-1];
            } else {
                if (triangle[depth-1][choice] > triangle[depth-1][choice-1]) {
                    triangle[depth][choice] += triangle[depth-1][choice];
                } else {
                    triangle[depth][choice] += triangle[depth-1][choice-1];
                }

                

                if (triangle[depth][choice] > max) {
                    max = triangle[depth][choice];
                }

            }

            cout << depth  << ", " << choice << ": "  << triangle[depth][choice] << endl;
            
        }

    }    

    return max;
}


int main() {
    vector<vector<int>> array {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
     

    int ans = solution(array);
    
    cout << ans << endl;
}