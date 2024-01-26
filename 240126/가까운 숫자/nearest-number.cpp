#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
int queries[MAX_N];
set<int> s;

int ans = INT_MAX;

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> queries[i];

    // x = 0 위치에 점을 놓고 시작합니다.
    s.insert(0);

    for(int i = 0; i < n; i++) {
        // 가장 근처에 있는 오른쪽 점을 찾습니다.
        set<int>::iterator it = s.upper_bound(queries[i]);
        // 존재한다면, 거리 중 최솟값을 갱신합니다.
        if(it != s.end())
            ans = min(ans, *it - queries[i]);
        
        // 가장 근처에 있는 왼쪽 점을 찾습니다.
        it--;
        // 거리 중 최솟값을 갱신합니다.
        ans = min(ans, queries[i] - *it);

        // 해당 점을 treeset에 추가합니다.
        s.insert(queries[i]);
        cout << ans << endl;
    }
    return 0;
}