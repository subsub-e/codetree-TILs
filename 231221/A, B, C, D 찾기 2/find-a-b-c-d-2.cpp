#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v1;
vector<int> v2;
vector<int> v3;

bool Possible(int a, int b, int c, int d){
    for(int i = 0; i < 15; i++){
        if(i == a || i == b || i == c || i == d){
            continue;
        }
        else{
            v2.push_back(v1[i]);
        }
    }
    sort(v2.begin(), v2.end());
    v3.push_back(v1[a] + v1[b]);
    v3.push_back(v1[b] + v1[c]);
    v3.push_back(v1[c] + v1[d]);
    v3.push_back(v1[d] + v1[a]);
    v3.push_back(v1[a] + v1[c]);
    v3.push_back(v1[b] + v1[d]);
    v3.push_back(v1[a] + v1[b] + v1[c]);
    v3.push_back(v1[a] + v1[b] + v1[d]);
    v3.push_back(v1[a] + v1[c] + v1[d]);
    v3.push_back(v1[b] + v1[c] + v1[d]);
    v3.push_back(v1[a] + v1[b] + v1[c] + v1[d]);
    sort(v3.begin(), v3.end());
    // for(int i = 0; i < v2.size(); i++){
    //     cout << v2[i] << ' ';
    // }
    // cout << '\n';
    // cout << v1[a] << ' ' << v1[b] << ' ' << v1[c] << ' ' << v1[d] << '\n';
    for(int i = 0; i < 11; i++){
        if(v2[i] != v3[i]){
            v2.clear();
            v3.clear();
            return false;
        }
    }
    v2.clear();
    v3.clear();
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i = 0; i < 15; i++){
        int b; cin >> b;
        v1.push_back(b);
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < 12; i++){
        for(int j = i + 1; j < 13; j++){
            for(int k = j + 1; k < 14; k++){
                for(int l = k + 1; l < 15; l++){
                    if(Possible(i, j, k, l)){
                        cout << v1[i] << ' ' << v1[j] << ' ' << v1[k] << ' ' << v1[l];
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}