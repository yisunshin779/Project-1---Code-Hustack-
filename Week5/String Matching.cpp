#include <bits/stdc++.h>
using namespace std;
const int base = 337;
const int MOD = 1e9 + 7;
vector<long long> power_arr;
vector<long long> HshS; 
long long Hash(int i, int j) {
    return (HshS[j] - (HshS[i-1] * power_arr[j-i+1]) % MOD + MOD) % MOD;
}
int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string SH, SS;
    getline(cin, SH); 
    getline(cin, SS); 
    int Sz = SS.size();
    int Hz = SH.size();
    SS = " " + SS;
    SH = " " + SH;
    power_arr.assign(Sz + 1, 0);
    HshS.assign(Sz + 1, 0);
    power_arr[0] = 1;
    for (int i = 1; i <= Sz; i++) {
        power_arr[i] = (power_arr[i-1] * base) % MOD;
    }
    for (int i = 1; i <= Sz; i++) {
        HshS[i] = (HshS[i-1] * base + SS[i]) % MOD; 
    }
    long long HshH = 0;
    for (int i = 1; i <= Hz; i++) {
        HshH = (HshH * base + SH[i]) % MOD;
    }
    int ans = 0;
    if (Hz <= Sz) {
        for (int i = 1; i <= Sz - Hz + 1; i++) {
            if (HshH == Hash(i, i + Hz - 1)) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}