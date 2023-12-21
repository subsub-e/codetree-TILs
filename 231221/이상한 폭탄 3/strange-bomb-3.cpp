#include <iostream>
#include <algorithm>
using namespace std;

int a, b; 
int arr[10000001];

bool InRange(int x){
    if(x >= 0 && x < a){
        return true;
    }
    else{
        return false;
    }
}

int Maxarr(int x){
    int cnt = 0;
    int ans = arr[x];
    for(int i = x - b; i < x + b; i++){
        if(!InRange(i)){
            continue;
        }
        if(arr[i] == ans){
            cnt++;
        }
    }
    if(cnt == 1){
        return 0;
    }
    else{
        return cnt;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    int max1 = 0;
    int ans1 = 0;
    for(int i = 0; i < a; i++){
        int maxarr = Maxarr(i);
        if(max1 < maxarr){
            max1 = maxarr;
            ans1 = max(ans1, arr[i]);
        }
    }
    cout << ans1;
    return 0;
}