#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    for(int i = 1; i < a; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < a;i++){
        cout << arr[i] << ' ';
    }
    return 0;
}