#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    unordered_set <int> s1;
    unordered_set <int> s2;
    vector<int> v1;
    vector<int> v2;
    int cnt = 0;

    for(int i = 0; i < a; i++){
        int n; cin >> n;
        s1.insert(n);
        v1.push_back(n);
    }
    
    for(int i = 0; i < b; i++){
        int m; cin >> m;
        s2.insert(m);
        v2.push_back(m);
    }

    for(int i = 0; i < a; i++){
        if(s2.find(v1[i]) == s2.end()){
            cnt++;
        }
    }
    
    for(int i = 0; i < b; i++){
        if(s1.find(v2[i]) == s1.end()){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}