#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100001];

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    int maxans = 0;
    int en = 0;
    for(int st = 0; st < n; st++){
        while(!visited[v[en]] && en < n){
            visited[v[en]] = 1;
            maxans = max(maxans, en - st + 1);
            en++;
        }
        visited[v[st]] = 0;
    }
    cout << maxans;
    return 0;
}