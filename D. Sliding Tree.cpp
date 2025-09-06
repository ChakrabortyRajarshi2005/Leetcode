D. Sliding Tree
time limit per test2 seconds
memory limit per test256 megabytes

You are given a tree∗
 with n
 vertices numbered from 1
 to n
. You can modify its structure using the following multi-step operation, called a sliding operation:

Choose three distinct vertices a
, b
, and c
 such that b
 is directly connected to both a
 and c
.
Then, for every neighbor d
 of b
 (excluding a
 and c
), remove the edge between b
 and d
, and instead connect d
 directly to c
.
For example, the figure below illustrates this operation with a=4
, b=3
, and c=5
 in the leftmost tree.


It can be proved that after a sliding operation, the resulting graph is still a tree.

Your task is to find a sequence of sliding operations that transforms the tree into a path graph†
, while minimizing the total number of operations. You only need to output the first sliding operation in an optimal sequence if at least one operation is required. It can be proved that it is possible to transform the tree into a path graph using a finite number of operations.

∗
A tree is a connected graph without cycles.

†
A path graph is a tree where every vertex has a degree of at most 2
. Note that a graph with only 1
 vertex and no edges is also a path graph.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of vertices in the tree.

The i
-th of the following n−1
 lines contains two integers ui
 and vi
 (1≤ui,vi≤n
, ui≠vi
) — the ends of the i
-th edge.

It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case:

If no operations are required (that is, the input tree is already a path graph), output −1
.
Otherwise, output three distinct integers a
, b
, and c
 (1≤a,b,c≤n
) — the chosen vertices for the first sliding operation in an optimal sequence.
If there are multiple valid choices for the first operation, you can output any of them.

Example
InputCopy
4
6
4 3
3 5
3 1
1 2
3 6
1
2
1 2
5
5 4
2 3
4 2
1 4
OutputCopy
4 3 5
-1
-1
2 4 1
Note
The first test case matches the example provided in the problem statement. It can be proved that we cannot transform the given tree into a path graph using less than 2
 operations.

However, we can transform the given tree into a path graph using 2
 operations: Initially, we perform an operation with a=4
, b=3
, and c=5
, as shown in the example. Next, we apply an operation with a=3
, b=5
, and c=6
. After this, the tree becomes a path graph. The second operation is illustrated in the figure below.


Thus, we obtain a sequence of sliding operations with the total number of operations minimized. Note, however, that only the first operation must be in the output; the number of operations and the second operation should not appear in the output.

In the second and third test cases, the tree is already a path graph, so no operations are required.


Codeforces Round 1045 (Div. 2)
Finished
Practice
Add to favourites
→ Virtual participation
Virtual contest is a way to take part in past contest, as close as possible to participation on time. It is supported only ICPC mode for virtual contests. If you've seen these problems, a virtual contest is not for you - solve these problems in the archive. If you just want to solve some problem from a contest, a virtual contest is not for you - solve this problem in the archive. Never use someone else's code, read the tutorials or communicate with other person during a virtual contest.
→ Clone Contest to Mashup
You can clone this contest to a mashup.

→ Submit?
Language:	
GNU G++23 14.2 (64 bit, msys2)
Choose file:	No file chosen
→ Last submissions
Submission	Time	Verdict
337182258	Sep/06/2025 21:04	Accepted
→ Problem tags
constructive algorithmsdfs and similargreedyimplementationtrees*2300
No tag edit access
→ Contest materials
Announcement (en)
Tutorial (en)

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    vector<int> dist(n), p(n);
    function<void(int, int)> dfs = [&](int now, int par) {
      p[now] = par;
      for (int i : G[now]) {
        if (i != par) {
          dist[i] = dist[now] + 1;
          dfs(i, now);
        }
      }
    };

    dist[0] = 0;
    dfs(0, -1);
    int x = max_element(dist.begin(), dist.end()) - dist.begin();
    dist[x] = 0;
    dfs(x, -1);
    int y = max_element(dist.begin(), dist.end()) - dist.begin();

    if (dist[y] == n - 1) {
      cout << -1 << '\n';
    } else {
      vector<int> on_diameter(n);
      int now = y;
      while (now != -1) {
        on_diameter[now] = 1;
        now = p[now];
      }
      int a = -1, b = -1, c = -1;
      for (int u = 0; u < n; u++) {
        for (int v : G[u]) {
          if (on_diameter[u] && !on_diameter[v]) {
            a = p[u], b = u, c = v;
            break;
          }
        }
        if (a != -1)
          break;
      }
      cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
    }
  }
}
