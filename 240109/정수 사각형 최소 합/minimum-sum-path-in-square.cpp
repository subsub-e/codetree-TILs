#include <iostream>
#include <algorithm>
using namespace std;

int a;
int arr[100][100];
int answer[100][100] = {};

void init(){
    answer[0][a-1] = arr[0][a-1];
    for(int i = a - 2; i >= 0; i--){
        //answer[i][0] = answer[i - 1][0] + arr[i][0];
        answer[0][i] = answer[0][i + 1] + arr[0][i];
    }
    for(int i = 1; i < a; i++){
        answer[i][a - 1] = answer[i - 1][a - 1] + arr[i][a - 1];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    init();
    // for(int i = 0; i < a; i++){
    //     for(int j = 0; j < a; j++){
    //         cout << answer[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = 1; i < a; i++){
        for(int j = a - 2; j >= 0; j--){
            answer[i][j] = min(answer[i - 1][j], answer[i][j + 1]) + arr[i][j];
        }
    }
    cout << answer[a-1][0];
    return 0;
}