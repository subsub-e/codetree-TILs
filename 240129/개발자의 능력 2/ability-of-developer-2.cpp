#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> v;
    vector<int> v2;
    for(int i = 0; i < 6; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int sumA = v[0] + v[5];
    int sumB = v[1] + v[4];
    int sumC = v[2] + v[3];

    v2.push_back(sumA);
    v2.push_back(sumB);
    v2.push_back(sumC);

    sort(v2.begin(), v2.end());
    cout << v2[2] - v2[0];
    return 0;
}