#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str; cin >> str;
    int size = str.length();
    int arrA[size] = {};
    int arrB[size] = {};
    int cnt = 0;
    for(int i = 0; i < size; i++){
        if(str[i] == '('){
            cnt++;
        }
        else{
            cnt = 0;
        }
        arrA[i] = max(arrA[i-1], cnt);
    }
    cnt = 0;
    for(int i = 0; i < size; i++){
        if(str[i] == ')'){
            arrB[i] = arrB[i-1] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < size; i++){
        if(arrB[i] == 2){
            if(arrA[i] > 1){
                ans += (arrA[i] - 1);
            }
        }
    }
    cout << ans;
    return 0;
}