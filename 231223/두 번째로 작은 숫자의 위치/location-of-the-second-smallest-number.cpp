#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr1[a];
    int arr2[a];
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        arr1[i] = b;
        arr2[i] = b;
    }
    sort(arr2, arr2 + a);
    int ans;
    int ans1;
    int cnt = 0;
    if(a == 1){
        cout << -1;
        return 0;
    }
    else{
        for(int i = 1; i < a; i++){
            if(arr2[i] > arr2[0]){
                ans = arr2[i];
                break;
            }
        }
        for(int i = 0; i < a; i++){
            if(arr1[i] == ans){
                cnt++;
                ans1 = i;
            }
        }
    }
    if(cnt == 1){
        cout << ans1+1;
        return 0;
    }
    else{
        cout << -1;
    }
    return 0;
}