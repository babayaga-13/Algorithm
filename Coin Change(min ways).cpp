#include <bits/stdc++.h>
using namespace std;

int coin_change_ways(int n, int a[], int X)
{
    int total[n+1][X+1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= X; j++) {
            if (i == 0 && j == 0){
                total[i][j] = 1;
            }
            else if(i==0) 
                 total[i][j] = 0;
            else{
                if (a[i-1] > j)
                    total[i][j] = total[i-1][j];
                else{
                    total[i][j] = total[i -1][j] + total[i][j - a[i-1]];
                }
            }
        }
    }
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= X; j++){
            cout << total[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"TOTAL POSSIBLE WAYS: "<<total[n][X];
}
int main()
{
    int n, X;
    cout << "COIN TYPE: ";
    cin >> n;
    int a[n];
    cout << "ENTER COIN VALUES: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "TOTAL AMOUNT: ";
    cin >> X;
    coin_change_ways(n, a, X);
}
