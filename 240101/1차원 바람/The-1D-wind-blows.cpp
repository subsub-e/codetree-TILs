#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, q; cin >> n >> m >> q;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < q; i++){
        int a;
        char c;
        cin >> a >> c;
        if(c == 'L'){
            int temp = arr[a - 1][m - 1];
            for(int j = m - 1; j > 0; j--){
                arr[a-1][j] = arr[a-1][j - 1];
            }
            arr[a-1][0] = temp;
            for(int j = a - 2; j >= 0; j--){
                for(int k = 0; k < m; k++){
                    if(arr[j][k] == arr[j + 1][k]){
                        if(j % 2 == 1){
                            int temp1 = arr[j][0];
                            for(int l = 0; l < m-1; l++){
                                arr[j][l] = arr[j][l + 1];
                            }
                            arr[j][m-1] = temp1;
                        }
                        else{
                            int temp1 = arr[j][m - 1];
                            for(int l = m - 1; l > 0; l--){
                                arr[j][l] = arr[j][l - 1];
                            }
                            arr[j][0] = temp1;
                        }
                        break;
                    }
                }
            }
            for(int j = a; j < n; j++){
                for(int k = 0; k < m; k++){
                    if(arr[j][k] == arr[j - 1][k]){
                        if(j % 2 == 1){
                            int temp1 = arr[j][0];
                            for(int l = 0; l < m-1; l++){
                                arr[j][l] = arr[j][l + 1];
                            }
                            arr[j][m-1] = temp1;
                        }
                        else{
                            int temp1 = arr[j][m - 1];
                            for(int l = m - 1; l > 0; l--){
                                arr[j][l] = arr[j][l - 1];
                            }
                            arr[j][0] = temp1;
                        }
                        break;
                    }
                }
            }
        }
        else{
            int temp = arr[a - 1][0];
            for(int j = 0; j < m - 1; j++){
                arr[a-1][j] = arr[a-1][j + 1];
            }
            arr[a-1][m - 1] = temp;
            for(int j = a - 2; j >= 0; j--){
                for(int k = 0; k < m; k++){
                    if(arr[j][k] == arr[j + 1][k]){
                        if(j % 2 == 1){
                            int temp1 = arr[j][0];
                            for(int l = 0; l < m-1; l++){
                                arr[j][l] = arr[j][l + 1];
                            }
                            arr[j][m-1] = temp1;
                        }
                        else{
                            int temp1 = arr[j][m - 1];
                            for(int l = m - 1; l > 0; l--){
                                arr[j][l] = arr[j][l - 1];
                            }
                            arr[j][0] = temp1;
                        }
                        break;
                    }
                }
            }
            for(int j = a; j < n; j++){
                for(int k = 0; k < m; k++){
                    if(arr[j][k] == arr[j - 1][k]){
                        if(j % 2 == 1){
                            int temp1 = arr[j][0];
                            for(int l = 0; l < m-1; l++){
                                arr[j][l] = arr[j][l + 1];
                            }
                            arr[j][m-1] = temp1;
                        }
                        else{
                            int temp1 = arr[j][m - 1];
                            for(int l = m - 1; l > 0; l--){
                                arr[j][l] = arr[j][l - 1];
                            }
                            arr[j][0] = temp1;
                        }
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}