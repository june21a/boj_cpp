#include <iostream>

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    for(int i=0; i<8; i++){
        string s; cin >> s;
        for(int j=0; j<s.length(); j++) if((i+j)%2 == 0 && s[j] == 'F') ans++;
    }
    cout << ans;
}