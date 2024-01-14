#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int a;
int arr[101];
vector<int> v;

void init(){
    for(int i = 0; i <= a; i++){
        arr[i] = INT_MIN;
    }
    arr[0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    v.push_back(0);
    for(int i = 0; i < a; i++){
        int num; cin >> num;
        v.push_back(num);
    }
    init();
    for(int i = 1; i <= a; i++){
        int q = INT_MIN;
        for(int j = 1; j <= i; j++){
            q = max(q, v[j] + arr[i - j]);
        }
        arr[i] = q;
    }
    // for(int i = 0; i <= a; i++){
    //     cout << arr[i] << ' ';
    // }
    cout << arr[a];
    return 0;
}