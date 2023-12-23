#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[7];
    for(int i = 0; i < 7; i++){
        cin >> arr[i];
    }
    sort(arr, arr + 7);
    if(arr[0] + arr[1] == arr[2]){
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[3];
    }
    else{
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
    }
    return 0;
}