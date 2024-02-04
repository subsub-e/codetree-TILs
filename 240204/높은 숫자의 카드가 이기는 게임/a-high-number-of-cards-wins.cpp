#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v;
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    int cnt = 0;
    for(int i = 0; i < a; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int index = 0;
    for(int i = 1; i <= 2 * a; i++){
        if(i == v[index]){
            pq1.push(i);
            index++;
        }
        else{
            pq2.push(i);
        }
    }
    for(int i = 0; i < a; i++){
        if(pq1.top() > pq2.top()){
            pq1.pop();
        }
        else{
            pq1.pop();
            pq2.pop();
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}