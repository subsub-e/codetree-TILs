#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    unordered_map<char, int> m;
    string str; cin >> str;
    vector<char> v;
    for(int i = 0; i < str.size(); i++){
        m[str[i]]++;
    }
    //int flag = 0;
    for(int i = 0; i < str.size(); i++){
        if(m[str[i]] == 1){
            cout << str[i];
            return 0;
        }
    }
    cout << "None";
    return 0;
}