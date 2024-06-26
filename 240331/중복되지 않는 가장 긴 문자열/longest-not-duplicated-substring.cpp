#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool visited[30];

int main() {
    // 여기에 코드를 작성해주세요.
    string str; cin >> str;
    int n = str.length();
    int st = 0;
    int en = 0;
    int maxans = 0;
    while(st < n){
        while(en < n && !visited[(int)str[en] - 97]){
            visited[(int)str[en] - 97] = 1;
            maxans = max(maxans, en - st + 1);
            en++;
        }
        
        visited[(int)str[st] - 97] = 0;
        st++;
    }
    cout << maxans;
    return 0;
}