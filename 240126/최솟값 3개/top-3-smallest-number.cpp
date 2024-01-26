#include <iostream>
#include <queue>
#include <algorithm>

int main() {
    int a; 
    std::cin >> a;
    std::priority_queue<int> pq;

    for (int i = 0; i < a; i++) {
        int b; 
        std::cin >> b;
        pq.push(-b);

        if (pq.size() < 3) {
            std::cout << -1 << '\n';
        }
        else {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int t = pq.top();
            pq.pop();

            long long ans = static_cast<long long>(f) * s * t;
            std::cout << -ans << '\n';

            pq.push(f);
            pq.push(s);
            pq.push(t);
        }
    }
    return 0;
}