#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int a;
int arr[100][100];
int answer[100][100];
int ans = INT_MAX;

void init(){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            answer[i][j] = INT_MAX;
        }
    }

    answer[0][0] = arr[0][0];
    for(int i = 1; i < a; i++){
        answer[i][0] = max(arr[i][0], answer[i - 1][0]);
        answer[0][i] = max(arr[0][i], answer[0][i - 1]);
    }
}

int solve(int x){
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(arr[i][j] < x){
                arr[i][j] = INT_MAX;
            }
        }
    }

    init();

    for(int i = 1; i < a; i++){
        for(int j = 1; j < a; j++){
            answer[i][j] = max(min(answer[i-1][j], answer[i][j-1]), arr[i][j]);
        }
    }

    return answer[a-1][a-1];
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    init();
    for(int i = 1; i <= 100; i++){
        int maxans = solve(i);

        if(maxans == INT_MAX){
            continue;
        }
        ans = min(ans, maxans - i);
    }
    cout << ans;
    return 0;
}