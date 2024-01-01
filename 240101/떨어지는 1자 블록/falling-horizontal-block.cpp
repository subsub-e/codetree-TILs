#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b, c; cin >> a >> b >> c;
    int arr[a][a];
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    c--;
    for(int i = a - 1; i >= 0; i--){
        int flag = 0;
        for(int j = c; j < b; j++){
            if(arr[i][j] == 1){
                flag = 1;
            }
        }
        if(flag == 0){
            for(int j = c; j < b; j++){
                arr[i][j] = 1;
            }
            break;
        }
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}