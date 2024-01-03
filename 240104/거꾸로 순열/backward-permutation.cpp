#include <iostream>
#include <vector>
using namespace std;

int a;
bool visited[9];
vector<int> v;

void simulate(int count){
    if(count == a){
        for(int i = 0; i < a; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    for(int i = a; i > 0; i--){
        if(visited[i] == true){
            continue;
        }

        visited[i] = true;
        v.push_back(i);
        simulate(count + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    simulate(0);
    return 0;
}