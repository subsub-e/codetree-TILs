#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    unordered_map<int, int> m;
    int arr[100000];
    int arr1[100000];
    for(int i = 0; i < a; i++){
        cin >> arr[i] >> arr1[i];
        if(m.count(arr[i]) == 0){
            m[arr[i]] = arr1[i];
        }
        else{
            if(m[arr[i]] > arr1[i]){
                m[arr[i]] = arr1[i];
            }
        }
    }
    int ans = 0;
    for(auto i : m){
        ans += i.second;
    }
    cout << ans;
    return 0;
}