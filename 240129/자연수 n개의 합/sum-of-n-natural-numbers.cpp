#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    long long a; cin >> a;
    long long left = 1;
    long long right = 2000000000;
    long long min_num = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(mid * (mid + 1) / 2 <= a){
            left = mid + 1;
            min_num = max(min_num, mid);
        }
        else{
            right = mid - 1;
            //min_num = max(min_num, mid);
        }
        //cout << mid << ' ';
    }
    //cout << '\n';
    cout << min_num;
    return 0;
}