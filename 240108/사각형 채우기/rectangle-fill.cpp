#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[1001] = {};
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= a; i++){
        arr[i] = arr[i-1] % 10007 + arr[i - 2] % 10007;
    }
    cout << arr[a] % 10007;
    return 0;
}