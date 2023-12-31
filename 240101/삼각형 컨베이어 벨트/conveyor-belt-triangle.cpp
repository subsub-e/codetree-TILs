#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, t; cin >> n >> t;
    int arr1[n];
    int arr2[n];
    int arr3[n];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    for(int i = 0; i < n; i++){
        cin >> arr3[i];
    }
    while(t--){
        int temp1 = arr1[n-1];
        int temp2 = arr2[n-1];
        int temp3 = arr3[n-1];
        for(int i = n-1; i > 0; i--){
            arr1[i] = arr1[i-1];
            arr2[i] = arr2[i-1];
            arr3[i] = arr3[i-1];
        }
        arr1[0] = temp3;
        arr2[0] = temp1;
        arr3[0] = temp2;
    }
    for(int i = 0; i < n; i++){
        cout << arr1[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << arr2[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << arr3[i] << ' ';
    }
    return 0;
}