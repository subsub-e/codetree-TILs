#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    set<int> s;
    int a; cin >> a;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        int b;
        if(str == "add"){
            cin >> b;
            s.insert(b);
        }
        else if(str == "remove"){
            cin >> b;
            s.erase(b);
        }
        else if(str == "find"){
            cin >> b;
            if(s.find(b) != s.end()){
                cout << "true" << '\n';
            }
            else{
                cout << "false" << '\n';
            }
        }
        else if(str == "lower_bound"){
            cin >> b;
            if(s.lower_bound(b) != s.end()){
                cout << *s.lower_bound(b) << '\n';
            }
            else{
                cout << "None" << '\n';
            }
        }
        else if(str == "upper_bound"){
            cin >> b;
            if(s.upper_bound(b) != s.end()){
                cout << *s.upper_bound(b) << '\n';
            }
            else{
                cout << "None" << '\n';
            }
        }
        else if(str == "largest"){
            if(s.size() == 0){
                cout << "None" << '\n';
            }
            else{
                cout << *s.rbegin() << '\n';
            }
        }
        else if(str == "smallest"){
            if(s.size() == 0){
                cout << "None" << '\n';
            }
            else{
                cout << *s.begin() << '\n';
            }
        }
    }
    return 0;
}