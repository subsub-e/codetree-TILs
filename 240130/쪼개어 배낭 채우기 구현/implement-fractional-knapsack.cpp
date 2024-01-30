#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    vector<pair<double, int> > v;
    for(int i = 0; i < n; i++){
        double a, b; cin >> a >> b;
        v.push_back(make_pair(b / a, a));
    }
    sort(v.begin(), v.end());
    // for(int i = 0; i < n; i++){
    //     cout << v[i].first << ' ' << v[i].second << '\n';
    // }
    double sum = 0;
    int index = n - 1;
    cout << fixed;
    cout.precision(3);
    while(1){
        for(int i = 0; i < v[index].second; i++){
            sum += v[index].first;
            m--;
            if(m <= 0){
                cout << sum;
                return 0;
            }
        }
        index--;
    }
    //cout << sum;
    return 0;
}