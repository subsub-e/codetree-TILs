#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a];
    int answer[a] = {};
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    answer[0] = 1;
    for(int i = 1; i < a; i++){
        int minans = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j]){
                minans = max(minans, answer[j] + 1);
            }
        }
        answer[i] = minans;
    }

    int ans = 1;
    for(int i = 0; i < a; i++){
        ans = max(ans, answer[i]);
    }
    cout << ans;
    return 0;
}