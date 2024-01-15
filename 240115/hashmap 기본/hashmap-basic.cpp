#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;



int main() {
    // 여기에 코드를 작성해주세요.
    unordered_map<int, int> m;
    int a; cin >> a;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        if(str == "add"){
            int b, c;
            cin >> b >> c;
            m[b] = c;
        }
        else if(str == "find"){
            int d; cin >> d;
            if(m.find(d) != m.end()){
                cout << m[d] << '\n';
            }
            else{
                cout << "None" << '\n';
            }
        }
        else if(str == "remove"){
            int e; cin >> e;
            m.erase(e);
        }
    }
    return 0;
}