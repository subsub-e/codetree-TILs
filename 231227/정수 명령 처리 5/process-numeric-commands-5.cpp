#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        int b;
        if(str == "push_back"){
            cin >> b;
            v.push_back(b);
        }
        else if(str == "get"){
            cin >> b;
            cout << v[b-1] << '\n';
        }
        else if(str == "size"){
            cout << v.size() << '\n';
        }
        else{
            v.pop_back();
        }
    }
    return 0;
}