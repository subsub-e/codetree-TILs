#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>

#define MAX_NUM 100000

using namespace std;

// 변수 선언
int n, q;
int arr[MAX_NUM];
pair<int, int> queries[MAX_NUM];

set<int> nums;
unordered_map<int, int> mapper;

int main() {
    // 입력:
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries[i] = make_pair(a, b);
    }

    // 주어진 x좌표값들을 전부 treeset에 넣어줍니다.
    for(int i = 0; i < n; i++)
        nums.insert(arr[i]);
    
    // treeset에서 정점을 작은 번호부터 뽑으면서
    // 각 정점별로 1번부터 순서대로 매칭하여
    // 그 결과를 hashmap에 넣어줍니다.
    int cnt = 1;
    for(set<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        mapper[*it] = cnt;
        cnt++;
    }
    
    // 질의에 대해
    // 각 [a, b]에 해당하는 번호를
    // mapper를 통해 구해
    // 두 번호 사이의 점의 수를 출력합니다.
    for(int i = 0; i < q; i++) {
        int a, b;
        tie(a, b) = queries[i];

        int new_a = mapper[a];
        int new_b = mapper[b];

        cout << new_b - new_a + 1 << endl;
    }
    return 0;
}