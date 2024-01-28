#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, q;
    cin >> n >> q;
    int arr[n];
    int sumA[n + 1] = {};
    int sumB[n + 1] = {};
    int sumC[n + 1] = {};

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        if(arr[i-1] == 1){
            sumA[i] = sumA[i-1] + 1;
            sumB[i] = sumB[i-1];
            sumC[i] = sumC[i-1];
        }
        else if(arr[i-1] == 2){
            sumA[i] = sumA[i-1];
            sumB[i] = sumB[i-1] + 1;
            sumC[i] = sumC[i-1];
        }
        else if(arr[i-1] == 3){
            sumA[i] = sumA[i-1];
            sumB[i] = sumB[i-1];
            sumC[i] = sumC[i-1] + 1;
        }
    }
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        int a = sumA[y] - sumA[x-1];
        int b = sumB[y] - sumB[x-1];
        int c = sumC[y] - sumC[x-1];
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}