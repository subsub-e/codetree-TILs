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

    for(int i = arr[i] - 1; i > 0; i--){
        int ans = i;
        v.push_back(ans);
        for(int j = 0; j < a - 1; j++){
            if(ans < 1){
                v.clear();
                break;
            }
            int b = arr[j] - ans;
            v.push_back(b);
            ans = b;
        }
        if(v.size() == a){
            break;
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    return 0;
}