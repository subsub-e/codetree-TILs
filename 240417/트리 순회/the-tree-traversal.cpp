#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, int> m;
unordered_map<int, char> m1;
int n;

void preorder(int x){
    if(m1[x] == '.'){
        return;
    }
    cout << m1[x];
    preorder(x * 2);
    preorder(x * 2 + 1);
}

void inorder(int x){
    if(m1[x] == '.'){
        return;
    }
    inorder(x * 2);
    cout << m1[x];
    inorder(x * 2 + 1);
}

void postorder(int x){
    if(m1[x] == '.'){
        return;
    }
    postorder(x * 2);
    postorder(x * 2 + 1);
    cout << m1[x];
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    m['A'] = 1;
    m1[1] = 'A';
    for(int i = 0; i < n; i++){
        char a, b, c;
        cin >> a >> b >> c;
        int index = m[a];
        m[b] = index * 2;
        m1[index * 2] = b;
        m[c] = index * 2 + 1;
        m1[index * 2 + 1] = c;  
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);


    return 0;
}