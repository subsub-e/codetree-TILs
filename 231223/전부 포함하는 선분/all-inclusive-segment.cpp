#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v1;
    vector<int> v2;
    for(int i= 0; i < a * 2; i++){
        int b; cin >> b;
        if(i % 2 == 0){
            v1.push_back(b);
        }
        else{
            v2.push_back(b);
        }
    }
    int min_ans = INT_MAX;
    for(int i = 0; i < a; i++){
        int min_x = INT_MAX;
        int max_y = 0;
        for(int j = 0; j < a; j++){
            if(i == j){
                continue;
            }
            min_x = min(min_x, v1[j]);
            max_y = max(max_y, v2[j]);
        }
        min_ans = min(min_ans, (max_y - min_x));
    }
    cout << min_ans;
    return 0;
}