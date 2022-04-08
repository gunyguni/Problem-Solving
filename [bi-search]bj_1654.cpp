#include <iostream>

using namespace std;

long long n, k;
long long wire[10001];

int main() {
    cin >> n >> k;

    long long input;
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> wire[i];
        sum += input;
    }


    long long front = 0, back = sum/k + 1;

    long long max = 0;

    while (front < back) {
        long long mid = (front+back)/2;
        long long pieces = 0;

        for (int i = 0; i < n; i++) {
            pieces += wire[i] / mid;

            if (pieces >= k) break;
        }

        if (pieces >= k) {
            if (mid > max) max = mid;
            front = mid + 1;
        } else {
            back = mid;
        }

    }

    cout << max << endl;

    return 0;
}