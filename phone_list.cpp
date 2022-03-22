#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> substring;
    set<string> fullstring;

    for(string number : phone_book) {
        if(substring.find(number) != substring.end()) {
            return false;
        }
        
        fullstring.insert(number);
        
        for (int i = 1; i < number.size(); i++) {
            string curr_substring = number.substr(0, i);

            if (fullstring.find(curr_substring) != fullstring.end()) {
                return false;
            }
            
            substring.insert(curr_substring);
        }

    }
    
    return true;
}