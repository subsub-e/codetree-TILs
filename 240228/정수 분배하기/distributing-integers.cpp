#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;


bool solve(int answer){
    //cout << answer << '\n';
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        cnt += v[i] / answer;
        //cout << cnt << '\n';
    }

    return cnt >= m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int left = 1;
    int right = 100001;
    while(left < right){
        int mid = (left + right + 1) / 2;
        if(solve(mid)){
            left = mid;
            
        }
        else{
            right = mid - 1;
        }
    }
    cout << left;
    return 0;
}