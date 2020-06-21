/* CCC '02 S4 - Bridge Crossing */
#include <bits/stdc++.h>

using namespace std;

/*
For editorial refer to https://github.com/sjay05/CCC-Solutions/tree/master/2002/S4/editorial.pdf
*/

#define INF INT_MAX

int main() {
    int m, q; cin >> m >> q;
    vector<int> dp(q + 1, INF), g(q + 1);
    vector<int> time(q + 1);
    vector<string> name(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> name[i] >> time[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= q; i++) {
        int ma = time[i];
        for (int j = 1; j <= m; j++) {
            if (i - j < 0)
                break;
            if (dp[i] > dp[i - j] + ma) {
                dp[i] = dp[i - j] + ma;
                g[i] = i - j;
            }
            ma = max(ma, time[i - j]);
        }
    }
    vector<vector<string>> groups;
    int i = q;
    while (i > 0) {
        int c = g[i];
        vector<string> a;
        for (int x = (c + 1); x < (i + 1); x++) 
            a.push_back(name[x]);
        
        groups.push_back(a);
        i = c;
    }
    reverse(groups.begin(), groups.end());
    cout << "Total Time: " << dp[q] << endl;
    for (auto u : groups) {
        string s = "";
        for (auto x : u)
            s += x + " ";

        cout << s << endl;
    }
}