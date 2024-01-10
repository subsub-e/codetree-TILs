#include <iostream>
#include <algorithm>
using namespace std;

int a;
int answer[1001];
pair<int, int> arr[1001];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 1; i <= a; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    answer[arr[1].second] = 1;
    for(int i = 2; i <= a; i++){
        int start_x = arr[i].first;
        int start_y = arr[i].second;
        for(int j = 1; j < start_x; j++){
            answer[start_y] = max(answer[start_y], answer[j]);
        }
        answer[start_y]++;
    }
    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        ans = max(ans, answer[i]);
    }
    cout << ans;
    return 0;
}