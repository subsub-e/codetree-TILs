#include <iostream>
#include <algorithm>
using namespace std;

int a;
int arr[20][20];

bool InRange(int x, int y) {
    return x >= 0 && x < a && y >= 0 && y < a;
}

int GetNum(int x, int y){
    int num = 0;
    int ox = x;
    int oy = y;
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {1, -1, -1, 1};

    num += arr[x][y];
    for(int i = 0; i < 4; i++){
        if(i == 0){
            while(1){
                x += dx[i];
                y += dy[i];
                if(x < 1 || y > a - 1){
                    x -= dx[i];
                    y -= dy[i];
                    break;
                }
                num += arr[x][y];
            }
        }
        else if(i == 1){
            while(1){
                x += dx[i];
                y += dy[i];
                if(x < 0 || y == 0){
                    x -= dx[i];
                    y -= dy[i];
                    break;
                }
                num += arr[x][y];
            }
        }
        else if(i == 2){
            while(1){
                x += dx[i];
                y += dy[i];
                if(x == a-1 || y < 0){
                    x -= dx[i];
                    y -= dy[i];
                    break;
                }
                num += arr[x][y];
            }
        }
        else if(i == 3){
            while(1){
                x += dx[i];
                y += dy[i];
                if(x == ox || y == oy){
                    break;
                }
                num += arr[x][y];
            }
        }
    }
    return num;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    int maxans = 0;
    for(int i = 2; i < a; i++){
        for(int j = 1; j < a - 1; j++){
            int num_of_Tot = GetNum(i, j);
            maxans = max(maxans, num_of_Tot);
            //cout << i << ' ' << j << ' ' << num_of_Tot << '\n';
        }
    }
    cout << maxans;
    return 0;
}