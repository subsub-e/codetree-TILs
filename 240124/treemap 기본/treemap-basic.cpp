#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    map<int, int> m;
    map<int, int>:: iterator it;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        int b, c;
        if(str == "add"){
            cin >> b >> c;
            m[b] = c;
            //m.insert(make_pair(b, c));
        }
        else if(str == "remove"){
            cin >> b;
            m.erase(b);
        }
        else if(str == "find"){
            cin >> b;
            if(m.find(b) != m.end()){
                cout << m[b] << '\n';
            }
            else{
                cout << "None" << '\n';
            }
        }
        else if(str == "print_list"){
            if(m.size() == 0){
                cout << "None" << '\n';
            }
            else{
                for(it = m.begin(); it != m.end(); it++){
                    cout << (it -> second) << ' ';
                }
                cout << '\n';
            }  
        }
    }
    return 0;
}