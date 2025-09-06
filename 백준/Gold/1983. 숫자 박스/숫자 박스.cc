#include <bits/stdc++.h>
#define ll long long
#define MIN_VALUE -40001

using namespace std;

int DP[401][401][401]; // 위쪽 i번째, 아래쪽 j번째 숫자가 k열+에 위치했을 때 최대값

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&DP[0][0][0], &DP[0][0][0] + 401*401*401, MIN_VALUE);
    int n;
    vector<int> v[2];
    cin >> n;
    for(int i=0; i<2; i++){
        v[i].push_back(0);
        for(int j=0; j<n; j++){
            int num; cin >> num;
            if(num) v[i].push_back(num);
        }
    }

    if(v[0].size() == 1 || v[1].size() == 1){
        cout << 0;
        return 0;
    }

    for(int i=1; i<v[0].size(); i++){
        for(int j=1; j<v[1].size(); j++){
            int limit = n - max(v[0].size() - (i+1), v[1].size() - (j+1));
            for(int k=max(i,j); k<=limit; k++){
                DP[i][j][k] = max(DP[i][j][k], DP[i-1][j][k-1]);
                DP[i][j][k] = max(DP[i][j][k], DP[i][j-1][k-1]);
                if((k > i || k > j) && DP[i][j][k] == MIN_VALUE) DP[i][j][k] = 0;
                DP[i][j][k] = max(DP[i][j][k], v[0][i]*v[1][j] + DP[i-1][j-1][k-1]*(DP[i-1][j-1][k-1]!=MIN_VALUE));
            }
        }
    }
    cout << DP[v[0].size()-1][v[1].size()-1][n];
}