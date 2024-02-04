#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) // first 값이 같다면?
    {
        return a.second > b.second; 
    }
    return a.first < b.first; // first 값이 같지 않다면 더 큰 값이 뒤로 가게 해라!
}

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<pair<int, int> > v;
    for(int i = 0; i < a; i++){
        int x, y; cin >> x >> y;
        v.push_back(make_pair(y, x));
    }
    sort(v.begin(), v.end(), cmp);
    int sum = 0;
    int index = 0;
    for(int i = 0; i < a; i++){
        if(index < v[i].first){
            index = v[i].first + 1;
            sum += v[i].second;
        }
        else{
            continue;
        }
    }
    cout << sum;
    return 0;
}