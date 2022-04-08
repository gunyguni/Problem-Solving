#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int n;

int date[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

vector<pair<int, int>> v;
vector<string> year;
vector<string> mmdd;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string duedate = "", dueMM = "", dueDD = "", dueYY = "";
        string mydate = "", myMM = "", myDD = "", myYY = "";

        int duedate_int = 0, mydate_int = 0;

        cin >> duedate;
        stringstream ss(duedate);
        getline(ss, dueMM, '/');
        getline(ss, dueDD, '/');
        getline(ss, dueYY, '\n');

        duedate_int = date[stoi(dueMM)] + stoi(dueDD);

        cin >> mydate;
        mmdd.push_back(mydate);
        stringstream ss2(mydate);
        getline(ss2, myMM, '/');
        getline(ss2, myDD, '\n');

        mydate_int = date[stoi(myMM)] + stoi(myDD);

        if (stoi(dueMM) == 12 && stoi(myMM) == 1) {
            mydate_int += 365;
            year.push_back(to_string(stoi(dueYY) + 1));
        } else if (stoi(dueMM) == 1 && stoi(myMM) == 12) {
            duedate_int += 365;
            year.push_back(to_string(stoi(dueYY) - 1));
        } else {
            if ((stoi(dueYY) % 400) == 0 || ((stoi(dueYY) % 100) != 0 && (stoi(dueYY) % 4) == 0)) {
                if (stoi(dueMM) > 2) duedate_int++; 
                if (stoi(myMM) > 2) mydate_int++;
            }
            year.push_back(dueYY);
        }
        
        v.push_back(make_pair(duedate_int, mydate_int));
    }

    for(int i = 0; i < n; i++) {
        // cout << pair.first << " : " << pair.second << endl;
        int diff = v[i].first - v[i].second;

        if (abs(diff) > 7) {
            cout << "OUT OF RANGE" << endl;
        } else if (diff == 0) {
            cout << "SAME DAY" << endl;
        } else {
            cout << mmdd[i] << "/" << year[i] << " IS ";
            if (diff > 0) {
                cout << diff;
            } else {
                cout << -diff;
            }
            if (abs(diff) == 1) {
                cout << " DAY ";
            } else {
                cout << " DAYS ";
            }
            if (diff > 0) {
                cout << "PRIOR";
            } else {
                cout << "AFTER";
            }
            cout << endl;
        }
    }
    return 0;
}
