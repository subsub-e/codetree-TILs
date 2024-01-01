#include <iostream>
using namespace std;

int a, b; 
int arr[100];

void Bomb(){
    int temp[a] = {};
    // for(int i = 0; i < a; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';
    int index1 = 0;
    for(int i = 0; i < a; i++){
        if(arr[i] != 0){
            temp[index1] = arr[i];
            index1++;
        }
    }
    for(int i = 0; i < a; i++){
        arr[i] = temp[i];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    if(b == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    // int endp = 0;
    // for(int i = 1; i < a; i++){
    //     if(arr[i-1] != arr[i]){
    //         endp = 1;
    //     }
    // }
    // if(endp == 0){
    //     cout << 0;
    //     return 0;
    // }
    int flag = 1;
    while(1){
        if(flag == 0){
            break;
        }
        flag = 0;
        int cnt1 = 1;
        int index = 0;
        for(int i = 1; i < a; i++){
            if(arr[i - 1] == arr[i] && arr[i] != 0){
                cnt1++;
            }
            else{
                if(cnt1 >= b){
                    for(int k = index; k < cnt1 + index; k++){
                        arr[k] = 0;
                    }
                    flag = 1;
                }
                index = i;
                cnt1 = 1;
            }
        }
        if(cnt1 >= b){
            for(int k = index; k < cnt1 + index; k++){
                arr[k] = 0;
            }
            flag = 1;
        }
        Bomb();
    }
    int cnt = 0;
    for(int i = 0; i < a; i++){
        if(arr[i] != 0){
            cnt++;
        }
    }
    cout << cnt << '\n';
    for(int i = 0; i < a; i++){
        if(arr[i] == 0){
            continue;
        }
        cout << arr[i] << '\n';
    }
    return 0;
}