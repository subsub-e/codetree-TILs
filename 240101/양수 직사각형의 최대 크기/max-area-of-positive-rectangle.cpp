#include <iostream>
#include <algorithm>
using namespace std;


int a, b;
int arr[20][20];

bool Rect(int x, int y){
    for(int i = 0; i < a - x + 1; i++){
        for(int j = 0; j < b - y + 1; j++){
            int flag = 0;
            for(int k = i; k < i + x; k++){
                for(int l = j; l < j + y; l++){
                    if(arr[k][l] < 1){
                        flag = 1;
                    }
                }
            }
            if(flag == 0){
                return true;
            }
        }
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cin >> arr[i][j];
        }
    }
    int maxans = -1;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            int rect = -1;
            if(Rect(i, j)){
                rect = i * j;
                maxans = max(maxans, rect);
            }
        }
    }
    cout << maxans;
    return 0;
}