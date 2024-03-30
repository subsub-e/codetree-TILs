#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    pair<int, int> arr[100001];
    for(int i = 1; i <= n; i++){
        int cnt, x;
        cin >> cnt >> x;
        arr[i] = make_pair(x, cnt);
    }
    sort(arr + 1, arr + n + 1);

    int sum = 0;
    int maxans = 0;
    int en = 0;
    for(int st = 1; st <= n; st++){
        while(en + 1 <= n && arr[en + 1].first - arr[st].first <= 2 * m){
            sum += arr[en + 1].second;
            en++;
        }

        maxans = max(maxans, sum);
        sum -= arr[st].second;
    }
    cout << maxans;
    return 0;
}