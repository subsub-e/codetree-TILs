#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int arr[1001] = {};
int coin[3] = {1, 2, 5};

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    arr[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            arr[i] = (arr[i] + arr[i - coin[j]]) % 10007;
        }
    }
    cout << arr[n];
    return 0;
}