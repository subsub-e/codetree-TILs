#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, c;
    cin >> a >> b >> c;
    int arr[3];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    sort(arr, arr + 3);
    int cnt = 0;
    while(1){
        if((arr[1] - arr[0] == 1) && (arr[2] - arr[1] == 1)){
            break;
        }
        else if((arr[1] - arr[0] == 2) || (arr[2] - arr[1] == 2)){
            cnt = 1;
            break;
        }
        else{
            cnt = 2;
            break;
        }
    }
    cout << cnt;
    return 0;
}