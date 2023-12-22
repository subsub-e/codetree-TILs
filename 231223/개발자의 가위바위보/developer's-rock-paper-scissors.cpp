#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr1[a];
    int arr2[a];
    for(int i= 0; i < a; i++){
        cin >> arr1[i] >> arr2[i];
    }
    int maxans = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < a; i++){
        if((arr1[i] == 1 &&  arr2[i] == 2) || (arr1[i] == 2 && arr2[i] == 3) || (arr1[i] == 3 && arr2[i] == 1)){
            cnt1++;
        }
    }
    maxans = max(maxans, cnt1);
    for(int i = 0; i < a; i++){
        if((arr1[i] == 2 &&  arr2[i] == 1) || (arr1[i] == 3 && arr2[i] == 2) || (arr1[i] == 1 && arr2[i] == 3)){
            cnt2++;
        }
    }
    maxans = max(maxans, cnt2);
    cout << maxans;
    return 0;
}