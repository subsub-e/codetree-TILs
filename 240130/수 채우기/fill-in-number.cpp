#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int cnt = 0;
    int a; cin >> a;
    while(a > 0){
        //cout << a << '\n';
        if(a % 5 == 0){
            cnt++;
            a -= 5;
        }
        else{
            cnt++;
            a -= 2;
        }
    }
    if(a == 0){
        cout << cnt;
    }
    else{
        cout << -1;
    }
    return 0;
}