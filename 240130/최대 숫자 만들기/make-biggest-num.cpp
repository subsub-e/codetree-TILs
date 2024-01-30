#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(string a, string b){
    string str1 = a + b;
    string str2 = b + a;
    if((int) str1 > (int) str2){
        return true;
    }
    else{
        return false;
    }
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