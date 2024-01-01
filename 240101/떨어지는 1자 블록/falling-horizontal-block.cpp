#include <iostream>
using namespace std;

int a, b, c; 
int arr[100][100];


int find(){
    int index = 0;
    for(int i = 0; i < a; i++){
        for(int j = c; j < b + c; j++){
            if(arr[i][j] == 1){
                return index;
            }
            else{
                index = i;
            }
        }
    }
    return index;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b >> c;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    c--;
    int index_i = find();
    for(int i = c; i < c+b; i++){
        arr[index_i][i] = 1;
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}