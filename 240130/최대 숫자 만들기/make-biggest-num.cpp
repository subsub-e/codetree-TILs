#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(string a, string b){
    string str1 = a + b;
    string str2 = b + a;
    int len = str1.length();
    for(int i = 0; i < len; i++){
        if((int) str1[i] == (int) str2[i]){
            continue;
        }
        else if((int) str1[i] > (int) str2[i]){
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<string> v;
    for(int i = 0; i < a; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < a; i++){
        cout << v[i];
    }
    return 0;
}