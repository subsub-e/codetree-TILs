#include <iostream>
#include <string>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n;
string str;
int R[MAX_N];

int main() {
    // 입력:
    cin >> str;
    n = (int) str.size();
    
    // R 배열을 채워줍니다.
    // Ri = i번지부터 N - 1번지 까지 있는 문자열중에 
    //      연속하여 ))가 나오는 횟수
    R[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--) {
        // i, i + 1로 )) 조합이 만들어진다면
        // i번부터 만들 수 있는 조합 수가 1만큼 더 늘어납니다.
        if(str[i] == ')' && str[i + 1] == ')')
            R[i] = R[i + 1] + 1;
        // 그렇지 않다면, i + 1번부터 만들 수 있는 조합 수와 같습니다.
        else
            R[i] = R[i + 1];
    }

    // for(int i = 0; i < n; i++){
    //     cout << R[i] << ' ';
    // }
    // cout << '\n';
    // 답을 구해줍니다.
    // 현재 i, i + 1 조합과
    // 쌍을 이루는 서로 다른 가짓수를 세어
    // 답에 더해줍니다.
    long long ans = 0;
    for(int i = 0; i < n - 2; i++) {
        if(str[i] == '(' && str[i + 1] == '(')
            ans += R[i + 2];
    }
    
    cout << ans;
    return 0;
}