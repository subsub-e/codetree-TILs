#include <iostream>

#define MAX_N 100

using namespace std;

int n;

char name[MAX_N];
int value[MAX_N];

int score_a = 0, score_b = 0, score_c = 0;

int Status(int score1, int score2, int score3) {
    // 1. A만 명예의 전당에 올라가 있는 경우
    if(score1 > score2 && score1 > score3)
        return 1;
    // 2. B만 명예의 전당에 올라가 있는 경우
    else if(score2 > score1 && score2 > score3)
        return 2;
    // 3. A, B 둘 다 명예의 전당에 올라가 있는 경우
    else if(score3 > score1 && score3 > score2)
        return 3;

    else if(score2 == score1 && score1 > score3)
        return 4;

    else if(score1 == score3 && score1 > score2)
        return 5;

    else if(score2 == score3 && score2 > score1)
        return 6;

    else{
        return 7;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> name[i] >> value[i];
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(name[i] == 'A') {
            if(Status(score_a, score_b, score_c) != Status(score_a + value[i], score_b, score_c))
                ans++;
            score_a += value[i];
        }
        else if(name[i] == 'B') {
            if(Status(score_a, score_b, score_c) != Status(score_a, score_b + value[i], score_c))
                ans++;
            score_b += value[i];
        }
        else{
            if(Status(score_a, score_b, score_c) != Status(score_a, score_b, score_c + value[i]))
                ans++;
            score_c += value[i];
        }
    }
    cout << ans;
    return 0;
}