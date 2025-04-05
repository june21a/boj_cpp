#include <iostream>
#include <string>
#define ll long long

using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, F;
    cin >> N >> F;

    for(int i=0; i<100; i++){
        int num = (N/100)*100 + i;
        if(num % F == 0){
            string s = to_string(num%100);
            if(s.length() == 1) s = '0' + s;
            cout << s;
            break;
        }
    }
}