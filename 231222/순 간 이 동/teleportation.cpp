#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int minans = INT_MAX;
    minans = min(minans, abs(b-a));
    minans = min(minans, abs(x-a)+abs(b-y));
    minans = min(minans, abs(y-a) + abs(b-x));
    cout << minans;
    return 0;
}