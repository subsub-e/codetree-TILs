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
    int st = 0;
    for(int en = 0; en < n; en++){
        if(visited[v[en]]){
            visited[v[st]] = 0;
            st++;
            maxans = max(maxans, en - st + 1);
        }
        visited[v[en]] = 1;
    }
    cout << maxans;
    return 0;
}