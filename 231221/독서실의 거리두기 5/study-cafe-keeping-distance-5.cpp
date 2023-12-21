#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v;
    string str; cin >> str;
    for(int i = 0; i < a; i++){
        int b = str[i];
        b = b - 48;
        v.push_back(b);
    }
    int max1 = 0;
    int cnt = 0;
    for(int i = 0; i < a; i++){
        if(v[i] == 1){
            cnt = 0;
        }
        else{
            cnt++;
            if(i == a-1){
                max1 = max(max1, cnt);
                break;
            }
            for(int j = 1; j < cnt; j++){
                if(v[i + j] == 1){
                    cnt = 0;
                    break;
                }
            }
            max1 = max(max1, cnt);
        }
    }
    cout << max1;
    return 0;
}