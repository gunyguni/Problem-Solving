#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    set<int> numbers_int;
    
    sort(numbers.begin(), numbers.end());

    do {
        for(int i = 1; i <= numbers.length(); i++) {
            numbers_int.insert(stoi(numbers.substr(0,i)));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    

    for (int number: numbers_int) {
        cout << number << endl;
        bool isPrime = true;

        if (number <= 1) continue;

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

