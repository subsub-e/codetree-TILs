#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    char arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    int left[a] = {};
    int right[a] = {};

    if(arr[0] == 'C'){
        left[0] = 1;
    }
    if(arr[a-1] == 'W'){
        right[a-1] = 1;
    }

    for(int i = 1; i < a; i++){
        left[i] = left[i-1];
        if(arr[i] == 'C'){
            left[i]++;
        }
    }

    for(int i = a-2; i >= 0; i--){
        right[i] = right[i + 1];
        if(arr[i] == 'W'){
            right[i]++;
        }
    }

    // for(int i = 0; i < a; i++){
    //     cout << left[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < a; i++){
    //     cout << right[i] << ' ';
    // }
    // cout << '\n';

    long long cnt = 0;
    for(int i = 1; i < a-1; i++){
        if(arr[i] == 'O'){
            cnt += (left[i] * right[i]);
        }
    }
    cout << cnt;
    return 0;
}