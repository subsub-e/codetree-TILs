#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a][2];
    for(int i = 0; i < a; i++){
        for(int j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }
    int minans = INT_MAX;
    for(int i = 1; i < a - 1; i++){
        int sum = 0;
        for(int j = 1; j < a; j++){
            if(i == j){
                sum += abs(arr[j+1][0] - arr[j-1][0]) + abs(arr[j+1][1] - arr[j-1][1]);
                j += 1;
                continue;
            }
            sum += abs(arr[j][0] - arr[j-1][0]) + abs(arr[j][1] - arr[j-1][1]);
        }
        //cout << sum << '\n';
        minans = min(minans, sum);
    }
    cout << minans;
    return 0;
}