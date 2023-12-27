#include <iostream>
#include <deque>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    deque<int> d;
    for(int i = 1; i <= a; i++){
        d.push_back(i);
    }
    while(d.size() != 1){
        d.pop_front();
        d.push_back(d.front());
        d.pop_front();
    }
    cout << d.front();
    return 0;
}