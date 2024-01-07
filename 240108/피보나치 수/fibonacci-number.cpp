#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[45] = {};
    int ans = 0;
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < a; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[a-1];
    return 0;
}