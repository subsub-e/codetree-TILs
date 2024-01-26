#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    double maxans = 0;
    for(int i = 0; i < a-2; i++){
        //arr[i] = 0;
        priority_queue<int> pq;
        for(int j = i + 1; j < a; j++){
            pq.push(-arr[j]);
        }
        pq.pop();
        double sum = 0;
        int si =pq.size();
        for(int j = 0; j < si; j++){
            sum += -(pq.top());
            pq.pop();
        }
        //cout << sum << '\n';
        maxans = max(maxans, sum / (a-i-2));
    }
    cout << fixed;
    cout.precision(2);
    cout << maxans;
    return 0;
}