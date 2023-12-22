#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    char arr1[a];
    char arr2[a];
    for(int i = 0; i < a; i++){
        char c; cin >> c;
        arr1[i] = c;
        arr2[i] = c;
    }
    sort(arr2, arr2 + a);
    int cnt = 0;
    int flag = 0;
    // for(int i = 0; i < a; i++){
    //     cout << arr2[i] << ' ';
    // }
    // cout << '\n';
    while(1){
        for(int i = 0; i < a; i++){
            if(arr1[i] != arr2[i]){
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
        flag = 0;
        for(int i = 1; i < a; i++){
            if(arr1[i-1] > arr1[i]){
                swap(arr1[i-1], arr1[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}