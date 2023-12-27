#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    sort(arr, arr + a);
    for(int i = 0; i < a; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}