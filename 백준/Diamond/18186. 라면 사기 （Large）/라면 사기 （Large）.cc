#include <iostream>
#define MAX 1000001
#define ll long long

using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, B, C;
    ll arr[MAX];
    ll sum = 0;
    
    cin >> N >> B >> C;
    ll cost[4] = {0, B, B+C, B+2*C};
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    if(B <= C){
        ll cnt = 0;
        for(int i=0; i<N; i++) cnt += arr[i];
        cout << cnt*B;
    }
    else{
        for(int i=3; i>0; i--){
            for(int j=0; j<N-i+1; j++){
                ll num = MAX;
                for(int k=0; k<i; k++) num = min(num, arr[j+k]);
                if(i == 3) {
                    while(num && arr[j] + arr[j+2] < arr[j+1] + num) num--;
                }
                
                for(int k=0; k<i; k++) arr[j+k] -= num;
                sum += num * cost[i];
            }
        }
        
        cout << sum;
    }
}
