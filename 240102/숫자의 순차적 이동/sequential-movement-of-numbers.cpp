#include <iostream>
using namespace std;

int a, b;
int arr[20][20];

bool InRange(int x, int y){
    return 0 <= x && x < a && 0 <= y && y < a;
}

void simulate(){
    int simu[a][a];
    int i = 1;
    while(i <= a * a){
        for(int j = 0; j < a; j++){
            for(int k = 0; k < a; k++){
                if(arr[j][k] == i){
                    int max = 0;
                    int max_x = 0;
                    int max_y = 0;
                    if(InRange(j - 1, k)){
                        if(max < arr[j - 1][k]){
                            max = arr[j - 1][k];
                            max_x = j - 1;
                            max_y = k;
                        }
                    }
                    if(InRange(j - 1, k - 1)){
                        if(max < arr[j - 1][k - 1]){
                            max = arr[j - 1][k - 1];
                            max_x = j - 1;
                            max_y = k - 1;
                        }
                    }
                    if(InRange(j, k - 1)){
                        if(max < arr[j][k - 1]){
                            max = arr[j][k - 1];
                            max_x = j;
                            max_y = k - 1;
                        }
                    }
                    if(InRange(j + 1, k - 1)){
                        if(max < arr[j + 1][k - 1]){
                            max = arr[j + 1][k - 1];
                            max_x = j + 1;
                            max_y = k - 1;
                        }
                    }
                    if(InRange(j + 1, k)){
                        if(max < arr[j + 1][k]){
                            max = arr[j + 1][k];
                            max_x = j + 1;
                            max_y = k;
                        }
                    }
                    if(InRange(j + 1, k + 1)){
                        if(max < arr[j + 1][k + 1]){
                            max = arr[j + 1][k + 1];
                            max_x = j + 1;
                            max_y = k + 1;
                        }
                    }
                    if(InRange(j, k + 1)){
                        if(max < arr[j][k + 1]){
                            max = arr[j][k + 1];
                            max_x = j;
                            max_y = k + 1;
                        }
                    }
                    if(InRange(j - 1, k + 1)){
                        if(max < arr[j - 1][k + 1]){
                            max = arr[j - 1][k + 1];
                            max_x = j - 1;
                            max_y = k + 1;
                        }
                    }
                    int temp = i;
                    arr[j][k] = max;
                    arr[max_x][max_y] = temp;
                    i++;
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < b; i++){
        simulate();
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}