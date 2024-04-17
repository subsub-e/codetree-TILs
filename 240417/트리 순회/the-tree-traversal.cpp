#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, pair<char, char> > m;
int n;

void preorder(char x){
    cout << x;
    if(m[x].first != '.'){
        preorder(m[x].first);
    }
    if(m[x].second != '.'){
        preorder(m[x].second);
    }
}

void inorder(char x){
    
    if(m[x].first != '.'){
        inorder(m[x].first);
    }
    cout << x;
    if(m[x].second != '.'){
        inorder(m[x].second);
    }
}

void postorder(char x){
    
    if(m[x].first != '.'){
        postorder(m[x].first);
    }
    if(m[x].second != '.'){
        postorder(m[x].second);
    }
    cout << x;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        char a, b, c;
        cin >> a >> b >> c;
        m[a] = make_pair(b, c); 
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');


    return 0;
}