#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<pair<int, int>> aaa;
    priority_queue<int> computer;
    int assigned_nums[a];
    for(int i = 0; i < a; i++){
        int x1, x2;
        cin >> x1 >> x2;
        aaa.push_back(make_pair(x1, x2));
    }
    
    for(int i = 1; i <= a; i++){
        computer.push(-i);
    }
    
    vector<tuple<int, int, int>> points;
    for(int i = 0; i < a; i++){
        int x1, x2;
        tie(x1, x2) = aaa[i];
        points.push_back(make_tuple(x1, +1, i));
        points.push_back(make_tuple(x2, -1, i));
    }

    sort(points.begin(), points.end());
    for(int i= 0; i < 2 * a; i++){
        int x, v, index;
        tie(x, v, index) = points[i];

        if(v == +1){
            int computer_num = computer.top();
            computer.pop();

            assigned_nums[index] = -computer_num;
        }
        else{
            int computer_num = assigned_nums[index];
            computer.push(-computer_num);
        }
    }
    int maxans = 0;
    for(int i = 0; i < a; i++){
        maxans = max(maxans, assigned_nums[i]);
    }
    cout << maxans;
    return 0;
}