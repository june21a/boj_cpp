#include <bits/stdc++.h>
#define ll long long

using namespace std;

int arr[5000];
int N, M;
int ans = INT_MAX;

bool score_validation(int target){
    int mv=arr[0], Mv=arr[0];
    int cnt = 1;

    for(int i=1; i<N; i++){
        Mv = max(Mv, arr[i]);
        mv = min(mv, arr[i]);

        if(Mv-mv > target){
            cnt++;
            mv = arr[i]; Mv = arr[i];
        }
    }

    return cnt <= M;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int left=0, right= 10000;
    while(left <= right){
        int mid = (left+right) / 2;
        if(score_validation(mid)){
            ans = min(ans, mid);
            right = mid-1;
        }
        else left=mid+1;
    }
    cout << ans;
}