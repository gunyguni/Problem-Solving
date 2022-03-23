#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    set<int> numbers_int;

    int len = numbers.length();
    sort(numbers.begin(), numbers.end());
    
    for (int i = 1; i <= len; i++) {
        vector<bool> numberlength(len - i, false);
        numberlength.insert(numberlength.end(), i, true);
        
        do {
            string temp = "";
            for(int j = 0; j < len; j++) {
                if(numberlength[j]) temp += numbers[j];
            }

            do {
                numbers_int.insert(stoi(temp));
            } while (next_permutation(temp.begin(), temp.end()));
            
            cout << temp << endl;
        } while (next_permutation(numberlength.begin(), numberlength.end()));
    }

    for (int number: numbers_int) {
        bool isPrime = true;


        for(int i = 2; i < number; i++) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) answer++;
    }
    
    return answer;
}