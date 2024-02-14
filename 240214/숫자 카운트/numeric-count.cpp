#include <iostream>
#include <string>
using namespace std;

int arr[11][3];

bool game(int x, int index){
    int cnt1 = 0;
    int cnt2 = 0;

    string str1 = to_string(x);
    string str2 = to_string(arr[index][0]);


    for(int i = 0; i < str1.length(); i++){
        if(str1[i] == str2[i]){
            cnt1++;
        }
        else{
            for(int j = 0; j < str1.length(); j++){
                if(i == j){
                    continue;
                }
                else{
                    if(str1[i] == str2[j]){
                        cnt2++;
                    }
                }
            }
        }
    }
    if(cnt1 == arr[index][1] && cnt2 == arr[index][2]){
        return true;
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int cnt = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 111; i <= 999; i++){
        int flag1 = 0;
        string str = to_string(i);
        for(int i = 0; i < 3; i++){
            if(str[i] == '0'){
                flag1 = 1;
            }
        }
        for(int i = 1; i < 3; i++){
            if(str[i] == str[i-1]){
                flag1 = 1;
            }
        }
        if(str[2] == str[0]){
            flag1 = 1;
        }
        if(flag1 == 1){
            continue;
        }
        int flag = 0;
        for(int j = 0; j < a; j++){
            if(!game(i, j)){
                flag = 1;
            }
        }
        if(flag == 0){
            //cout << i << '\n';
            cnt++;
        }    
    }
    cout << cnt;
    return 0;
}