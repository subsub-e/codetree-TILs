#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// 변수 선언
int n, k;
int ans;

vector<pair<int, int> > segments;
vector<pair<int, int> > points;

int main() {
    // 입력:
    cin >> n >> k;
    
    // n개의 선분을 만들어줍니다.
    int x = 0;
    for(int i = 0; i < n; i++) {
        int dist; char c_dir;
        cin >> dist >> c_dir;
        if(c_dir == 'L') {
            segments.push_back(make_pair(x - dist, x));
            x -= dist;
        }
        else {
            segments.push_back(make_pair(x, x + dist));
            x += dist;
        }
    }
    // 주어진 좌표의 범위가 큰 경우에는
    // 각 선분을 두 지점으로 나눠서
    // +1, -1로 담은 뒤,
    // 정렬해줍니다.
    for(int i = 0; i < n; i++) {
        int x1, x2;
        tie(x1, x2) = segments[i];
        points.push_back(make_pair(x1, +1)); // 시작점
        points.push_back(make_pair(x2, -1)); // 끝점
    }

    // 정렬을 진행합니다.
    sort(points.begin(), points.end());

    // 각 위치에 적혀있는 숫자들의 합을 구하면
    // 매 순간마다 겹치는 구간의 횟수가 구해집니다.
    // 이 때 k 이상인 경우에 대해 구간의 합을 구하면 됩니다.
    int sum_val = 0;
    for(int i = 0; i < 2 * n; i++) {
        int x, v;
        tie(x, v) = points[i];

        // k개 이상 겹치는 구간이라면
        // 해당 구간의 길이를 더해줍니다.
        if(sum_val >= k) {
            int prev_x;
            tie(prev_x, ignore) = points[i - 1];
            ans += x - prev_x;
        }

        // 적혀있는 가중치를 전부 더해줍니다.
        sum_val += v;
    }
    
    cout << ans;
    return 0;
}