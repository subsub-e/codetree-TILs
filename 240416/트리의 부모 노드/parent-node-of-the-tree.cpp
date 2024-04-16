#include <iostream>
#include <vector>
using namespace std;

int arr[100001];
int n;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >>x2;
        arr[x2] = x1;
    }

    for(int i = 2; i <= n; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}