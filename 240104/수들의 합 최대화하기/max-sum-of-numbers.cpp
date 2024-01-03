#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a;
int arr[10][10];
bool visited_row[100001];
bool visited_col[100001];
int ans;
vector<int> v;

void simulate(int count){
    if(count == a){
        int v_max = 0;
        // for(int i = 0; i < a; i++){
        //     cout << v[i] << ' ';
        // }
        // cout << '\n';
        for(int i = 0; i < a; i++){
            v_max += v[i];
        }
        ans = max(ans, v_max);
        return;
    }
    
    for(int i = 0; i < a; i++){
        if(visited_row[i] == true){
              continue;
        }
        for(int j = 0; j < a; j++){

            if(visited_col[j] == true){
                continue;
            }
            
            visited_row[i] = true;
            visited_col[j] = true;
            v.push_back(arr[i][j]);
            simulate(count + 1);
            v.pop_back();
            visited_row[i] = false;
            visited_col[j] = false;
        }
    }


}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    simulate(0);
    cout << ans;
    return 0;
}