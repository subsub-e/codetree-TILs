#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
int arr[101][101];
vector<pair<int, int> > v;
int ans[101][101];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                v.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        ans[v[i].first][v[i].second] = 1;
    }

    for(int i = 1; i <= n; i++){
        ans[i][i] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(ans[i][k] && ans[k][j]){
                    ans[i][j] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}