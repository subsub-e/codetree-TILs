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
    int sum = arr[a-1];
    priority_queue<int> pq;
    pq.push(-arr[a-1]);
    double maxans = 0;
    for(int i = a-2; i > 0; i--){
        //arr[i] = 0;
        sum += arr[i];
        pq.push(-arr[i]);
        double avg = (double) (sum - (-pq.top())) / (a - i - 1);
        //cout << avg << '\n';
        maxans = max(maxans, avg);
    }
    cout << fixed;
    cout.precision(2);
    cout << maxans;
    return 0;
}