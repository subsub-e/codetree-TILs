#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    unordered_set<int> s;
    int a; cin >> a;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        int b;
        if(str == "find"){
            cin >> b;
            if(s.find(b) != s.end()){
                cout << "true" << '\n'; 
            }
            else{
                cout << "false" << '\n';
            }
        }
        else if(str == "add"){
            cin >> b;
            s.insert(b);
        }
        else if(str == "remove"){
            cin >> b;
            s.erase(b);
        }
    }
    return 0;
}