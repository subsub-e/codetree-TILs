#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a-1];
    vector<int> v;
    for(int i = 0; i < a-1; i++){
        cin >> arr[i];
    }
    int ans = arr[0] - 1;
    v.push_back(ans);
    for(int i = 0; i < a-1; i++){
        int b = arr[i] - ans;
        v.push_back(b);
        ans = b;
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    return 0;
}