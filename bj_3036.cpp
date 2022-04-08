#include <iostream>
#include <vector>

using namespace std;

int n;
int radius;

int main() {
    cin >> n >> radius;

    int circle;
    for(int i = 1; i < n; i++) {
        cin >> circle;

        int min = radius < circle ? radius : circle;

        for(int j = min; j > 0; j--) {
            if (radius % j == 0 && circle % j == 0) {
                cout << radius/j << "/" << circle/j << endl;
                break;
            }
        }


    }

    return 0;
}