#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    cin >> a >> b;
    int arr[a];
    unordered_map<int, int> m;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
        m[arr[i]] = i + 1;
    }
    for(int i = 0; i < b; i++){
        int c; cin >> c;
        cout << m[c] << ' ';
    }
    return 0;
}