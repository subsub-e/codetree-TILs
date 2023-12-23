#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a];
    int sum = 0;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + a);
    int avg = sum / a;

    int block = 0;
    for(int i = 0; i < a; i++){
        if(arr[i] > avg){
            block += arr[i] - avg;
        }
    }
    cout << block;
    return 0;
}