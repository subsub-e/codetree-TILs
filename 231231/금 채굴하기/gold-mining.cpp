#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int arr[20][20];

bool InRange(int x, int y) {
    return x >= 0 && x < a && y >= 0 && y < a;
}

int Gold(int x, int y, int size){
    int gold = 0;
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {-1, 1, 1, -1};

    gold += arr[x][y];

    for(int i = 1; i <= size; i++){
        int curr_x = x - i, curr_y = y;

        for(int j = 0; j <4; j++){
            if(InRange(curr_x, curr_y)){
                gold += arr[curr_x][curr_y];
            }
            curr_x = curr_x + dx[j];
            curr_y = curr_y + dy[j];
        }
    }
    return gold;
}

int GetArea(int k) {
    return k * k + (k+1) * (k+1); 
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    int maxans = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            for(int k = 0; k < a; k++){
                int num_of_gold = Gold(i, j, k);

                if(num_of_gold * b >= GetArea(k)){
                    maxans = max(maxans, num_of_gold);
                }
            }
        }
    }
    cout << maxans;
    return 0;
}