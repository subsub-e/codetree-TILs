#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    sort(arr, arr + a);
    int disc = arr[a-1] - arr[0];
    int cnt = 0;
    while(disc > 17){
        arr[0]++;
        arr[a-1]--;
        cnt++;
        disc = arr[a-1] - arr[0];
    }
    cout << cnt*cnt*2;
    return 0;
}