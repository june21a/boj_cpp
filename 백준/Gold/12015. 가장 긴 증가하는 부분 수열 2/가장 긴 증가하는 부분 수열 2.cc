#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int arr[1000001];
    int idx = 1, num;
    
    cin >> N;
    cin >> arr[0];
    for(int i=1; i<N; i++){
        cin >> num;
        if(num > arr[idx-1]){
            arr[idx] = num;
            idx++;
        }
        else *lower_bound(arr, arr+idx, num) = num;
    }
    cout << idx;
}
