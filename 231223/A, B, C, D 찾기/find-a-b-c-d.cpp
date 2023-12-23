#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[15];
    for(int i = 0; i < 15; i++){
        cin >> arr[i];
    }
    sort(arr, arr+15);
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int idx;
    if(a + b != arr[3]){
        idx = 3;
    }
    else if(a + c != arr[4]){
        idx = 4;
    }
    else if(b + c != arr[5]){
        idx = 5;
    }
    if(a + b + c != arr[6]){
        idx = 6;
    }
    cout << a << ' ' << b << ' ' << c << ' ' << arr[idx];
    return 0;
}