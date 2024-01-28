#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    char arr[a];
    char al[3] = {'P', 'H', 'S'};
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    int left[a + 1] = {};
    int right[a + 1] = {};

    for(int i = 0; i < 3; i++){
        int cnt = 0;
        for(int j = 1; j <= a; j++){
            if(al[i] == arr[j - 1]){
                cnt += 1;
            }
            left[j] = max(left[j], cnt);
        }
    }

    for(int i = 0; i < 3; i++){
        int cnt = 0;
        for(int j = a-1; j >= 0; j--){
            if(al[i] == arr[j - 1]){
                cnt += 1;
            }
            right[j] = max(right[j], cnt);
        }
    }

    // for(int i = 0; i <= a; i++){
    //     cout << left[i] << ' ';
    // }
    // cout << '\n';

    // for(int i = 0; i <= a; i++){
    //     cout << right[i] << ' ';
    // }
    // cout << '\n';

    int maxans = 0;
    for(int i = 0; i <= a; i++){
        int ans = left[i - 1] + right[i-1];
        maxans = max(maxans, ans);
    }
    cout << maxans;
    return 0;
}