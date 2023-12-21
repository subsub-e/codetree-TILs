#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    int arr[b][2];
    for(int i = 0; i < b; i++){
        int c, d; cin >> c >> d;
        if(c > d){
            arr[i][0] = d;
            arr[i][1] = c;
        }
        else{
            arr[i][0] = c;
            arr[i][1] = d;
        }
    }
    int max1 = 0;
    for(int i = 1; i < a; i++){
        for(int j = i + 1; j <= a; j++){
            int cnt = 0;
            for(int k = 0; k < b; k++){
                if(i == arr[k][0]){
                    if(j == arr[k][1]){
                        cnt++;
                    }
                }
            }
            max1 = max(max1, cnt);
        }
    }
    cout << max1;
    return 0;
}