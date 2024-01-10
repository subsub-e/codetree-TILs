#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int a;
int arr[1000];
int answer[1000];

void init(){
    for(int i = 0; i < a; i++){
        answer[i] = INT_MIN;
    }
    answer[0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    init();
    for(int i = 1; i < a; i++){
        for(int j = 0; j < i; j++){
            if(j + arr[j] >= i){
                answer[i] = max(answer[i], answer[j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < a; i++){
        ans = max(ans, answer[i]);
    }
    cout << ans;
    return 0;
}