#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    string arr[a];
    unordered_map<string, int> m;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
        m[arr[i]] = i + 1;
    }
    for(int i = 0; i < b; i++){
        string str1; cin >> str1;
        if(str1[0] > '0' && str1[0] < '9'){
            for(int j = 0; j < a; j++){
                if(m[arr[j]] == stoi(str1)){
                    cout << arr[j] << '\n';
                }
            }
        }
        else{
            cout << m[str1] << '\n';
        }
    }
    return 0;
}