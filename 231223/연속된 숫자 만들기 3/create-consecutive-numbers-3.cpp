#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, c; cin >> a >> b >> c;
    int cnt = 0;
    int arr[3];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    sort(arr, arr + 3);
    if(c == 1,000,000,000){
        cout << arr[1] - arr[0];
    }
    else{
        while(((arr[2] - arr[1]) + (arr[1] - arr[0])) != 2){
            if(arr[2] - arr[1] > arr[1] - arr[0]){
                arr[0] = arr[1] + 1;
                sort(arr, arr + 3);
                cnt++;
            }
            else{
                arr[2] = arr[1] - 1;
                sort(arr, arr + 3);
                cnt++;
            }
        }
        cout << cnt;
    }
    
    return 0;
}