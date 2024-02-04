#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

// 변수 선언
int n;
vector<pair<int, int> > nums;

int ans;

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        nums.push_back(make_pair(y, x));
    }

    // y 기준으로 오름차순 정렬을 진행합니다.
    sort(nums.begin(), nums.end());

    // 최선의 전략을 오름차순 정렬 뒤
    // 가장 작은 수와 큰 수를 하나씩 매칭해주는 것입니다.
    int li = 0, ri = n - 1;
    while(li <= ri) {
        int ly, lx;
        tie(ly, lx) = nums[li];
        int ry, rx;
        tie(ry, rx) = nums[ri];

        // 답을 갱신합니다.
        ans = max(ans, ly + ry);

        // 왼쪽 개수가 더 적다면
        // 왼쪽을 전부 매칭시켜줍니다.
        if(lx < rx) {
            // 오른쪽은 lx만큼 개수를 줄여줍니다.
            nums[ri] = make_pair(ry, rx - lx);

            // 왼쪽 위치를 한칸 뒤로 옮겨줍니다.
            li++;
        }
        // 오른쪽 개수가 더 적다면
        // 오른쪽을 전부 매칭시켜줍니다.
        else if(lx > rx) {
            // 왼쪽은 rx만큼 개수를 줄여줍니다.
            nums[li] = make_pair(ly, lx - rx);

            // 오른쪽 위치를 한칸 앞으로 옮겨줍니다.
            ri--;
        }
        // 개수가 동일하다면
        // li, ri 위치 모두 옮겨줍니다.
        else {
            li++;
            ri--;
        }
    }
    cout << ans;
    return 0;
}