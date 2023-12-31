#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int arr[201][201] = {};

int MaxNum1(int x, int y){
    if(x + 1 > a || y + 1 > b){
        return 0;
    }
    return arr[x][y] + arr[x + 1][y] + arr[x][y + 1];
}

int MaxNum2(int x, int y){
    if(x + 1 > a || y + 1 > b){
        return 0;
    }
    return arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1];
}

int MaxNum3(int x, int y){
    if(x + 1 > a || y + 1 > b){
        return 0;
    }
    return arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1];
}

int MaxNum4(int x, int y){
    if(x + 1 > a || y - 1 < 0){
        return 0;
    }
    return arr[x][y] + arr[x + 1][y] + arr[x + 1][y - 1];
}

int MaxNum5(int x, int y){
    if(y - 2 < 0){
        return 0;
    }
    return arr[x][y] + arr[x][y-1] + arr[x][y-2];
}

int MaxNum6(int x, int y){
    if(y + 2 > b){
        return 0;
    }
    return arr[x][y] + arr[x][y+1] + arr[x][y+2];
}

int MaxNum7(int x, int y){
    if(x - 2 < 0){
        return 0;
    }
    return arr[x][y] + arr[x-1][y] + arr[x-2][y];
}

int MaxNum8(int x, int y){
    if(x + 2 > a){
        return 0;
    }
    return arr[x][y] + arr[x+1][y] + arr[x+2][y];
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cin >> arr[i][j];
        }
    }
    int maxans = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            maxans = max(maxans, MaxNum1(i, j));
            maxans = max(maxans, MaxNum2(i, j));
            maxans = max(maxans, MaxNum3(i, j));
            maxans = max(maxans, MaxNum4(i, j));
            maxans = max(maxans, MaxNum5(i, j));
            maxans = max(maxans, MaxNum6(i, j));
            maxans = max(maxans, MaxNum7(i, j));
            maxans = max(maxans, MaxNum8(i, j));
            //cout << maxans << '\n';
        }
    }
    cout << maxans;
    return 0;
}