#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    unordered_map<int, int> first;
    unordered_map<int, int> second;
    int arr[4][a];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            first[arr[0][i] + arr[1][j]]++;
            second[arr[2][i] + arr[3][j]]++;
        }
    }
    int cnt = 0;
    for(unordered_map<int, int>::iterator it=first.begin(); it != first.end(); it++){
        int diff = -(it->first); // 0-(A+B)
        if(second.find(diff) != second.end()) // 만약 그 차이가 C+D에 있다면
            cnt += second[diff]; // (해당 A+B 값의 freq) * (C+D 값의 freq) 를 ans에 더하기
    }
    // 출력
    cout << cnt;
    return 0;
}