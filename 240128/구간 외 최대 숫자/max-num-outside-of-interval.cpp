#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    int arr[a];
    int left[a];
    int right[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    left[0] = arr[0];
    right[a-1] = arr[a-1];

    for(int i = 1; i < a; i++){
        left[i] = max(left[i-1], arr[i]);
    }
    for(int i = a - 2; i >= 0; i--){
        right[i] = max(right[i + 1], arr[i]);
    }

    // for(int i = 0; i < a; i++){
    //     cout << left[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < a; i++){
    //     cout << right[i] << ' ';
    // }
    // cout << '\n';
    for(int i = 0; i < b; i++){
        int x1, x2; cin >> x1 >> x2;
        x1--;
        x2--;
        cout << max(left[x1 - 1], right[x2 + 1]) << '\n';
    }
    return 0;
}