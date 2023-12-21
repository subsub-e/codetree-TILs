#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    sort(arr, arr+a);
    int maxans = 0;
    for(int i = 0; i <= arr[a-1]; i++){
        int cnt = 0;
        for(int j = 0; j < a; j++){
            if(arr[j] >= i && arr[j] <= i + b){
                cnt++;
            }
        }
        maxans = max(maxans, cnt);
    }
    cout << maxans;
    return 0;
}