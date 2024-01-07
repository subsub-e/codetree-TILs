#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[1001] = {};
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 7;
    for(int i = 3; i <= a; i++){
        arr[i] = 3 * arr[i-1] + arr[i-2] - arr[i - 3];
    }
    cout << arr[a] % 1000000007;
    return 0;
}