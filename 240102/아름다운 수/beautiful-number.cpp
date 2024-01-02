#include <iostream>
#include <vector>
using namespace std;

int a;
vector<int> v;
int cnt = 0;

bool correct(){
    int flag = 0;
    int i = 0;
    while(i < a){
        if(v[i] == 1){
            i++;
        }
        else if(v[i] == 2){
            if(i + 1 >= a || v[i] != 2 || v[i + 1] != 2){
                flag = 1;
            }
            i += 2;
        }
        else if(v[i] == 3){
            if(i + 2 >= a || v[i] != 3 || v[i + 1] != 3 || v[i + 2] != 3){
                flag = 1;
            }
            i += 3;
        }
        else if(v[i] == 4){
            if(i + 3 >= a || v[i] != 4 || v[i + 1] != 4 || v[i + 2] != 4 || v[i + 3] != 4){
                flag = 1;
            }
            i += 4;
        }
    }
    if(flag == 1){
        return false;
    }
    return true;
}

void count(int x){
    if(x == a){
        if(correct()){
            cnt++;
            return;
        }
        else{
            return;
        }
    }

    for(int i = 1; i <= 4; i++){
        v.push_back(i);
        count(x + 1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    count(0);
    cout << cnt;
    return 0;
}