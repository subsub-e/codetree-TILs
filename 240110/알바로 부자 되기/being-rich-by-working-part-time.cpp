#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int answer[a][2] = {};
    for(int i = 0; i < a; i++){
        int s, e, p;
        cin >> s >> e >> p;
        if(i == 0){
            answer[0][0] = e;
            answer[0][1] = p;
            continue;
        }
        
        for(int j = 0; j < i; j++){
            if(s <= answer[j][0]){
                answer[i][0] = e;
                answer[i][1] = max(answer[i][1], p);
            }
            else{
                answer[i][0] = e;
                answer[i][1] = max(answer[i][1], p + answer[j][1]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < a; i++){
        // for(int j = 0; j < 2; j++){
        //     cout << answer[i][j] << ' ';
        // }
        ans = max(answer[i][1], ans);
        //cout << '\n';
    }
    cout << ans;
    return 0;
}