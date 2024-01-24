#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k; cin >> n >> k;
    unordered_set<int> s[n];
    vector<pair<int, int>> v;
    int arr[n];
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        v.push_back({a, b});
    }
    for(int i = 0; i < n; i++){
        arr[i] = i;
        s[i].insert(i);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < k; j++){
            int temp = arr[v[j].first];
            arr[v[j].first] = arr[v[j].second];
            arr[v[j].second] = temp;
            s[arr[v[j].first]].insert(v[j].second);
            s[arr[v[j].second]].insert(v[j].first);
        }
    }
    for(int i = 0; i < n; i++){
        cout << s[i].size() << '\n';
    }
    return 0;
}