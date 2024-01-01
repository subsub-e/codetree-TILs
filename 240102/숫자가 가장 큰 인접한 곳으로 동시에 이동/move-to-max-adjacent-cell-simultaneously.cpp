#include <iostream>
using namespace std;

int n, m, t;
int arr[20][20];
int count[20][20];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void simulate(){
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int NewCount[n][n] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(count[i][j] == 1){
                int max_x;
                int max_y;
                int max = 0;
                for(int k = 0; k < 4; k++){
                    int po_x = i + dx[k];
                    int po_y = j + dy[k];
                    
                    if(InRange(po_x, po_y)){
                        if(max < arr[po_x][po_y]){
                            max = arr[po_x][po_y];
                            max_x = po_x;
                            max_y = po_y;
                        }
                    }
                }
                NewCount[max_x][max_y]++;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << NewCount[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(NewCount[i][j] > 1){
                count[i][j] = 0;
            }
            else{
                count[i][j] = NewCount[i][j];
            }   
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t;
    count[n][n] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        count[x][y] = 1;
    }
    for(int i = 0; i < t; i++){
        simulate();
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(count[i][j] == 1){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}