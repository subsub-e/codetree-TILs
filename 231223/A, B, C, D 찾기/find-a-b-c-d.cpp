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
    int d = arr[14] - a - b - c;
    cout << a << ' ' << b << ' ' << c << ' ' << d;
    return 0;
}