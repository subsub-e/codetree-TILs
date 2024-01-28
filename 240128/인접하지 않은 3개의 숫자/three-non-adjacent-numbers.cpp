#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
int arr[MAX_N];

int L[MAX_N], R[MAX_N];
int ans;

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // L 배열을 채워줍니다.
    // L[i] = 0번부터 i번 원소 중 최댓값
    L[0] = arr[0];
    for(int i = 1; i < n; i++)
        L[i] = max(L[i - 1], arr[i]);

    // R 배열을 채워줍니다.
    // R[i] = i번부터 n - 1번 원소 중 최댓값
    R[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
        R[i] = max(R[i + 1], arr[i]);

    // i번째 숫자가 세 숫자 중 가운데 숫자라고 했을 때
    // 가능한 최대 합 중 최댓값을 갱신해줍니다.

    // for(int i = 0; i < n; i++){
    //     cout << L[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << R[i] << ' ';
    // }
    // cout << '\n';

    for(int i = 2; i < n - 2; i++)
        ans = max(ans, L[i - 2] + arr[i] + R[i + 2]);

    cout << ans;
    return 0;
}