#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    stack<int> s;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            s.push(str[i]);
        }
        else{
            s.pop();
        }
    }
    if(s.size() == 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}