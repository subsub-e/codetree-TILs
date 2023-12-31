#include <iostream>
#include <vector>
using namespace std;

int a, b;
int arr[100][100];

bool Col(int x){
    vector<int> v1;
    for(int i = 0; i < a - b + 1; i++){
        for(int j = i; j < b + i; j++){
            v1.push_back(arr[x][j]);
        }
        int Colcnt = 0;
        for(int j = 0; j < b; j++){
            if(v1[j] == v1[j + 1]){
                Colcnt++;
            }
        }
        if(Colcnt == b - 1){
            v1.clear();
            return true;
        }
        v1.clear();
    }
    return false;
}

bool Row(int x){
    vector<int> v1;
    for(int i = 0; i < a-b+1; i++){
        for(int j = i; j < b + i; j++){
            v1.push_back(arr[j][x]);
        }
        int Rowcnt = 0;
        for(int j = 0; j < b; j++){
            if(v1[j] == v1[j + 1]){
                Rowcnt++;
            }
        }
        if(Rowcnt == b - 1){
            v1.clear();
            return true;
        }
        v1.clear();
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    if(b == 1){
        cout << a * 2;
        return 0;
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < a; i++){
        if(Col(i)){
            cnt++;
            //cout << i << 1;
        }
    }
    for(int i = 0; i < a; i++){
        if(Row(i)){
            cnt++;
            //cout << i << 2;
        }
    }
    cout << cnt;
    return 0;
}