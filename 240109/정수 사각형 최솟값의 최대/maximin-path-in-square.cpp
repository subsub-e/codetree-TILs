#include <iostream>
#include <algorithm>
using namespace std;

int a;
int arr[100][100];
int answer[100][100];

void init(){
    answer[0][0] = arr[0][0];
    for(int i = 1; i < a; i++){
        answer[i][0] = min(arr[i][0], answer[i-1][0]);
        answer[0][i] = min(arr[0][i], answer[0][i-1]);
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
    
    for(int i = 1; i < a; i++){
        for(int j = 1; j < a; j++){
            int m = max(answer[i - 1][j], answer[i][j - 1]);
            answer[i][j] = min(m, arr[i][j]);
        }
    }
    // for(int i = 0; i < a; i++){
    //     for(int j = 0; j < a; j++){
    //         cout << answer[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // int ans_m = max(arr[a-2][a-1], arr[a-1][a-2]);
    // if(ans_m <= arr[a-1][a-1]){
    //     answer[a-1][a-1] = ans_m;
    // }
    // else{
    //     answer[a-1][a-1] = arr[a-1][a-1];
    // }
    cout <<answer[a-1][a-1];
    return 0;
}