#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a;
int arr[101];

int Maxarr(){
    int min1 = 1000000;
    for(int i = 0; i < a; i++){
        if(arr[i] == 1){
            int cnt = 0;
            for(int j = i + 1; j < a; j++){
                if(arr[j] == 0){
                    cnt++;
                }
                else{
                    min1 = min(min1, cnt);
                    cnt = 0;
                    break;
                }
            }
        }
    }
    return min1 + 1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    string str; cin >> str;

    for(int i = 0; i < a; i++){
        arr[i] = str[i] - 48;
    }

    int maxans = 0;

    for(int i = 0; i < a; i++){
        if(arr[i] == 0){
            arr[i] = 1;
            for(int j = i + 1; j < a; j++){
                if(arr[j] == 0){
                    arr[j] = 1;
                    int maxarr = Maxarr();
                    maxans = max(maxarr, maxans);
                    arr[j] = 0;
                }
            }
            arr[i] = 0;
        }
    }
    cout << maxans;
    return 0;
}