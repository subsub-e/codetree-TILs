#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str; 

int Strlen(string str){
    int cnt = 1;
    for(int i = 1; i < str.length(); i++){
        if(str[i] != str[i - 1]){
            cnt += 2;
        }
    }
    return cnt + 1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str;
    int minans = 100;
    if(str.length() == 1){
        cout << 2;
        return 0;
    }
    if(str.length() == 10){
        int flag = 1;
        for(int i = 1; i < str.length(); i++){
            if(str[i] != str[i-1]){
                flag = 0;
            }
        }
        if(flag == 1){
            cout << 3;
            return 0;
        }
    }
    for(int i = 0; i < str.length(); i++){
        char temp = str[str.length() - 1];
        for(int j = str.length() - 1; j > 0; j--){
            str[j] = str[j-1];
        }
        str[0] = temp;
        minans = min(minans, Strlen(str));
    }
    cout << minans;
    return 0;
}