#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, d, s;
int record[1001][3];
int sick[51][2];
int trash[51];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> d >> s;
    for(int i = 0; i < d; i++){
        for(int j = 0; j < 3; j++){
            cin >> record[i][j];
        }
    }

    for(int i = 0; i < s; i++){
        for(int j = 0; j < 2; j++){
            cin >> sick[i][j];
        }
    }

    for(int i = 0; i < s; i++){
        int people = sick[i][0];
        int timeo = sick[i][1];
        for(int j = 0; j < d; j++){
            if(record[j][2] < timeo && people == record[j][0]){
                trash[record[j][1]]++;
            }
        }
    }


    int maxans = 0;
    vector<int> v;
    for(int i = 1; i <= m; i++){
        if(trash[i] >= s){
            v.push_back(i);
        }
    }

    for(int i = 0; i < v.size(); i++){
        int cnt = 0;
        for(int j = 0; j < d; j++){
            if(record[j][1] == v[i]){
                cnt++;
            }
        }
        maxans = max(maxans, cnt);
    }

    cout << maxans;
    return 0;
}