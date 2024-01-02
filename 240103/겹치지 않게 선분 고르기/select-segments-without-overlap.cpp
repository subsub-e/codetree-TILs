#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int a;
pair<int, int> segments[15];
int ans;
vector<pair<int, int>> v;

bool Overlapped(pair<int, int> seg1, pair<int, int> seg2) {
    int ax1, ax2;
    tie(ax1, ax2) = seg1;

    int bx1, bx2;
    tie(bx1, bx2) = seg2;

    // 두 선분이 겹치는지 여부는
    // 한 점이 다른 선분에 포함되는 경우로 판단 가능합니다. 
    return (ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) ||
           (bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2);
}

bool Possible() {
    // 단 한쌍이라도 선분끼리 겹치면 안됩니다.
	for(int i = 0; i < (int)v.size(); i++)
		for(int j = i + 1; j < (int)v.size(); j++)
            if(Overlapped(v[i], v[j]))
                return false;

	return true;
}

void simulate(int cnt){

    if(cnt == a){
        if(Possible()){
            ans = max(ans, (int) v.size());
        }
        return;
    }

    v.push_back(segments[cnt]);
    simulate(cnt + 1);
    v.pop_back();

    simulate(cnt + 1);

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;

    for(int i = 0; i < a; i++){
        int x1, x2;
        cin >> x1 >> x2;
        segments[i] = make_pair(x1, x2);
    }

    simulate(0);
    cout << ans;
    return 0;
}