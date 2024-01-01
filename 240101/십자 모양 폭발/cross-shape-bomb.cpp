#include <iostream>
using namespace std;

int a;
int arr[200][200];

void cutArr(int x, int y){
    int num = arr[x][y];
    arr[x][y] = 0;
    for(int i = 1; i < num; i++){
        arr[x - i][y] = 0;
        arr[x + i][y] = 0;
        arr[x][y - i] = 0;
        arr[x][y + i] = 0;
    }
    int temp[a][a] = {};
    for(int i = 0; i < a; i++){
        int temp_row = a - 1;
        for(int j = a - 1; j >= 0; j--){
            if(arr[j][i] != 0){
                temp[temp_row][i] = arr[j][i];
                temp_row--;
            }
        }
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            arr[i][j] = temp[i][j];
        }
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
    int b, c;
    cin >> b >> c;
    b--;
    c--;
    cutArr(b, c);
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}