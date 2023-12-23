#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a * 2];
    for(int i = 0; i < a*2; i++){
        cin >> arr[i];
    }
    sort(arr, arr + a * 2);
    int minans = INT_MAX;
    for(int i = 0; i < a; i++){
        minans = min(minans, (arr[i + a] - arr[i]));
    }
    cout << minans;
    return 0;
}