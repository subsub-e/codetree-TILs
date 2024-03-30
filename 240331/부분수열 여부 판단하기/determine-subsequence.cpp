#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<int> part;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        part.push_back(x);
    }

    int flag = 0;
    int index = 0;
    for(int i = 0; i < m; i++){
        while(index < n && v[index] != v[i]){
            index++;
        }
        if(index == n){
            cout << "No";
            return 0;
        }
        else{
            index++;
        }
    }
    cout << "Yes";
    return 0;
}