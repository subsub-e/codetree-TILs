#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[4][2];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }
    int min_x = INT_MAX;
    int min_y = INT_MAX;
    int max_x = 0;
    int max_y = 0;
    for(int i = 0; i < 4; i++){
        if(min_x > arr[i][0]){
            min_x = arr[i][0];
        }
        if(max_x < arr[i][0]){
            max_x = arr[i][0];
        }
        if(min_y > arr[i][1]){
            min_y = arr[i][1];
        }
        if(max_y < arr[i][1]){
            max_y = arr[i][1];
        }
    }
    if((max_x - min_x) > (max_y - min_y)){
        cout << (max_x - min_x) * (max_x - min_x);
    }
    else{
        cout << (max_y - min_y) * (max_y - min_y);
    }
    return 0;
}