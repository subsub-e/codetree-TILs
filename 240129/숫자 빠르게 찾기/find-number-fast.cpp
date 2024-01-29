#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int a, b;

int bin(int x){
    int left = 0;
    int right = v.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] == x){
            return mid + 1;
        }
        else if(v[mid] < x){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        int c; cin >> c;
        v.push_back(c);
    }
    for(int i = 0; i < b; i++){
        int d; cin >> d;
        int ans = bin(d);
        cout << ans << '\n';
    }
    return 0;
}