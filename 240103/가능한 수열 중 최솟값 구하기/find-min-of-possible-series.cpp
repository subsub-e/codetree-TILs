#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int a;
vector<int> v;
unordered_set<string> visited;

bool possible() {
    for (int i = 1; i < a; i++) {
        if (v[i - 1] == v[i]) {
            return false;
        }
    }
    return true;
}

string getSequenceString() {
    string sequence;
    for (int i = 0; i < a; i++) {
        sequence += to_string(v[i]);
    }
    return sequence;
}

void simulate(int len, int start) {
    if (len == a) {
        if (possible()) {
            for (int i = 0; i < a; i++) {
                cout << v[i];
            }
            cout << '\n';
            exit(0);  // 프로그램 종료 추가
            
        }
        return;
    }   

    for (int i = start; i <= 6; i++) {
        v.push_back(i);
        simulate(len + 1, i + 1);
        v.pop_back();
    }
}

int main() {
    cin >> a;
    simulate(0, 4);
    return 0;
}