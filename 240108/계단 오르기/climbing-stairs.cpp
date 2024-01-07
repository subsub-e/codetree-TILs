#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[1001] = {};
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 1;
    for(int i = 5; i <= a; i++){
        arr[i] = arr[i - 2] % 10007 + arr[i - 3] % 10007;
    }
    if(arr[a] == 0){
        cout << 0;
        return 0;
    }
    cout << arr[a] % 10007;
    return 0;
}