#include <bits/stdc++.h>
using namespace std;

vector<long long> pf[200001];
long long dp[200001];
bool cmp[200001];

void pre(){
    for(long long i  =2; i <= 200000; i++){
        if(!cmp[i]){
            cmp[i] = true;
            for(long long j = 2*i; j <= 200000;  j+=i){
                pf[j].push_back(i);
                cmp[j] = true;
            }
            pf[i].push_back(i);
        }
    }
}
void solve(){
    long long n, k; cin >> n >> k;
    long long aa = 0;
    vector<long long> dp(n+1, 1e18);
    for(long long i=1; i<= n; i++){
        if(i <= k) dp[i] = 0;
        for(auto x : pf[i]) dp[i] = min(dp[i], dp[i/x] * x + 1);
    }
    for(long long i = 0; i<n; i++){
        long long a; cin >> a;
        aa += dp[a];
    }
    cout << aa << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pre();
    long long t; cin >> t;
    while(t--) solve();
}
    