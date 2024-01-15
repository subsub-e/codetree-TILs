#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b;
    cin >> a >> b;
    unordered_map<int, int> m;
    int arr[1000];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
        //m[arr[i]]++;
    }
    int cnt = 0;
    for(int i = 0; i < a; i++){
        
        for(int j = i + 1; j < a; j++){
            int k = b - arr[i] - arr[j];
            cnt += m[k];
        }
        m[arr[i]]++;
    }
    cout << cnt;
    return 0;
}