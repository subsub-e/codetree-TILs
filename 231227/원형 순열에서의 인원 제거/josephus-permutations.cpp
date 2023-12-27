#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    queue<int> q;
    for(int i = 1; i <= a; i++){
        q.push(i);
    }
    int j = 1;
    while(q.size() != 0){
        if(j % b == 0){
            cout << q.front() << ' ';
            q.pop();
            j++;
        }
        else{
            q.push(q.front());
            q.pop();
            j++;
        }
    }
    return 0;
}