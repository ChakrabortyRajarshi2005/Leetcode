F. Bracket Groups
time limit per test2 seconds
memory limit per test512 megabytes
A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic sequence. For example:

bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)");
bracket sequences ")(", "(" and ")" are not.
You are given n
 bracket sequences s1,s2,…,sn
 (not necessarily regular) and an even integer k
. Your task is to split all of them into groups in such a way that:

every bracket sequence belongs to exactly one group;
for each group, there exists a regular bracket sequence of length exactly k
 such that every bracket sequence assigned to this group is not a substring of it.
What is the smallest number of groups that this can be achieved for? If it's impossible to do for any number of groups, report so. Otherwise, print the groups and any valid regular bracket sequence for each group. If there are multiple answers with the smallest number of groups, print any of them.

Input
The first line contains two integers n
 and k
 (1≤n≤50
; 2≤k≤50
; k
 is even).

The i
-th of the next n
 lines contains a bracket sequence si
 (2≤|si|≤k
). It consists only of characters '(' and ')'.

Output
If it's impossible to split all bracket sequences into groups according to the rules, then print −1
.

Otherwise, print the smallest possible number of groups m
 in the first line. Then, m
 blocks of data should follow:

The first line of each block should contain a regular bracket sequence of length k
.
The second line should contain a single integer g
 — the number of bracket sequences in the current group.
The third line should contain g
 integers from 1
 to n
 — the indices of the bracket sequences that belong to the current group.
None of these bracket sequences should be a substring of the chosen regular bracket sequence. Each index from 1
 to n
 should belong to exactly one group.

If there are multiple answers with the smallest m
, print any of them.

Examples
InputCopy
3 6
)))
(((
(())
OutputCopy
1
(()())
3
1 2 3
InputCopy
4 6
(()
()(
())
((((((
OutputCopy
2
(())()
1
2
()()()
3
1 4 3
InputCopy
2 6
()
)(
OutputCopy
-1
#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
using namespace std;
 
const string al = "()";
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    forn(i, n) cin >> s[i];
    forn(i, n) if (s[i] == "()"){
        cout << -1 << '\n';
        return 0;
    }
 
    vector<string> ac(1, "");
    forn(i, n) forn(j, s[i].size())
        ac.push_back(s[i].substr(0, j + 1));
    sort(ac.begin(), ac.end());
    ac.resize(unique(ac.begin(), ac.end()) - ac.begin());
 
    vector<char> bad(ac.size());
    set<string> tot(s.begin(), s.end());
    vector<vector<int>> go(ac.size(), vector<int>(2));
    forn(i, ac.size()) forn(j, ac[i].size() + 1){
        bad[i] |= tot.count(ac[i].substr(j));
        forn(t, 2) if (go[i][t] == 0){
            string nw = ac[i].substr(j) + al[t];
            auto it = lower_bound(ac.begin(), ac.end(), nw);
            if (it != ac.end() && *it == nw)
                go[i][t] = it - ac.begin();
        }
    }
 
    vector<vector<vector<char>>> dp(k + 1, vector<vector<char>>(ac.size(), vector<char>(k + 1)));
    vector<vector<vector<pair<int, int>>>> p(k + 1, vector<vector<pair<int, int>>>(ac.size(), vector<pair<int, int>>(k + 1)));
    dp[0][0][0] = true;
    forn(i, k) forn(v, ac.size()) forn(bal, i + 1) if (dp[i][v][bal]){
        forn(c, 2){
            int nbal = bal + (c == 0 ? 1 : -1);
            if (nbal < 0) continue;
            int u = go[v][c];
            if (bad[u]) continue;
            dp[i + 1][u][nbal] = true;
            p[i + 1][u][nbal] = {v, c};
        }
    }
    int sv = -1;
    forn(v, ac.size()) if (dp[k][v][0]){
        sv = v;
        break;
    }
    if (sv == -1){
        cout << 2 << '\n';
        vector<string> res(2);
        forn(i, k / 2){
            res[0] += "()";
            res[1] += '(';
        }
        forn(i, k / 2){
            res[1] += ')';
        }
        vector<vector<int>> ans(2);
        forn(i, n){
            bool any = false;
            forn(j, int(s[i].size()) - 1)
                any |= s[i][j] == s[i][j + 1];
            ans[!any].push_back(i);
        }
        forn(i, 2){
            cout << res[i] << '\n';
            cout << ans[i].size() << '\n';
            for (int j : ans[i]) cout << j + 1 << " ";
            cout << '\n';
        }
    }
    else{
        cout << 1 << '\n';
        string res = "";
        int bal = 0, v = sv;
        for (int i = k; i > 0; --i){
            auto [u, c] = p[i][v][bal];
            v = u;
            res += al[c];
            bal -= c == 0 ? 1 : -1;
        }
        reverse(res.begin(), res.end());
        cout << res << '\n';
        cout << n << '\n';
        forn(i, n) cout << i + 1 << " ";
        cout << '\n';
    }
    return 0;
}
