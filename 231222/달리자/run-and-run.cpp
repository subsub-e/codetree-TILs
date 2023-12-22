#include <iostream>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr1[a];
    int arr2[a];
    for(int i = 0; i < a; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < a; i++){
        cin >> arr2[i];
    }
    int ans;
    for(int i = 0; i < a; i++){
        if(arr1[i] > arr2[i]){
            int num = arr1[i] - arr2[i];
            arr1[i + 1] += num;
            ans += num;
        }
    }
    cout << ans;
    return 0;
}