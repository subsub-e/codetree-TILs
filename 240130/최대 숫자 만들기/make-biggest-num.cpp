#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(string a, string b){
    long long num1 = stoi(a);
    long long num2 = stoi(b);
    int len = min(a.length(), b.length());
    for(int i = 0; i < len; i++){
        if(a[i] == b[i]){
            continue;
        }
        else if(a[i] > b[i]){
            return true;
        }
        else{
            return false;
        }
    }
    if(a.length() < b.length()){
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