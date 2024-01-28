#include <iostream>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {

    int n, q;
    cin >> n >> q;

    int tmp;
    set<int> s;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }

    int idx = 1;
    for(auto iter=s.begin(); iter!=s.end(); iter++)
    {
        m[*iter] = idx++;
    }

    int x1, x2;
    for(int i=0; i<q; i++)
    {
        cin >> x1 >> x2;
        auto iter1 = s.lower_bound(x1);
        auto iter2 = --s.upper_bound(x2);
        //cout << "iter test " << *iter1 << " " << *iter2 << endl;

        if(*iter2 < x1) cout << 0 << '\n';
        else if(*iter1 > x2) cout << 0 << '\n';
        else
        {
            cout << m[*iter2] - m[*iter1] + 1 <<'\n';
        }


    }

    return 0;
}