#include <iostream>
#include <algorithm>
#include <vector>
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
    if(a == 2){
        cout << min((v2[0] - v1[0]),(v2[1] - v1[1]));
        return 0;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int length1 = v2[a-1] - v1[1];
    int length2 = v2[a-2] - v1[0];
    cout << min(length1, length2);
    return 0;
}