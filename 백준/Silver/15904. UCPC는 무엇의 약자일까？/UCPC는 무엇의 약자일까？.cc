#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string success = "I love UCPC";
    string fail = "I hate UCPC";
    string s; 
    getline(cin, s);

    char targets[4] = {'U', 'C', 'P', 'C'};
    int idx = 0;
    for(auto i : s){
        if(idx == 4) break;
        if(i == targets[idx]) idx++;
    }

    if(idx == 4) cout << success;
    else cout << fail;
}