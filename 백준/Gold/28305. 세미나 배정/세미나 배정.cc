#include <bits/stdc++.h>
#define ll long long
#define MAX 200000

using namespace std;

int N, T;
int arr[MAX];

bool is_possible(int limit){
    int s_dates[MAX];
    for(int i=0; i<N; i++){
        s_dates[i] = max(1, arr[i]-T+1);
        if(i >= limit) s_dates[i] = max(s_dates[i], s_dates[i-limit]+T);
    }

    for(int i=0; i<N; i++){
        if(arr[i] < s_dates[i] || arr[i] > s_dates[i]+T-1){
            return false;
        }
    }
    return true;
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);

    int left = 1, right = N;
    int mid;
    while(left < right){
        mid = (left+right) / 2;
        if(is_possible(mid)) right = mid;
        else left = mid+1;
    }
    cout << left;
}