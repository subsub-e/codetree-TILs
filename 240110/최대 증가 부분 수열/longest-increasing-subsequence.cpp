#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[1001];
    int answer[1001] = {};
    for(int i = 0; i <= a; i++){
        cin >> arr[i];
    }
    answer[0] = 1;
    for(int i = 1; i <= a; i++){
        int maxans = 0;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                maxans = max(maxans, answer[j] + 1);
            }
        }
        answer[i] = maxans;
    }
    int ans = 0;
    for(int i = 0; i <= a; i++){
        ans = max(ans, answer[i]);
    }
    cout << ans;
    return 0;
}