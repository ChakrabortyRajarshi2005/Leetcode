D1. Max Sum OR (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes

This is the easy version of the problem. The difference between the versions is that in this version, l=0
, and r<2⋅105
. You can hack only if you solved all versions of this problem.

You are given two integers l
 and r
 (l≤r
).

Let n=r−l+1
. We will create two arrays a
 and b
, both consisting of n
 integers. Initially, both a
 and b
 are equal to [l,l+1,…,r]
. You have to reorder the array a
 arbitrarily to maximize the following value:

∑i=1n(ai|bi).

Here, |
 denotes the bitwise OR operation.

You also need to construct a possible way to reorder the array a
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The only line of each test case contains two integers l
 and r
 (0=l≤r<2⋅105
) — the minimum and maximum elements in a
.

Let n=r−l+1
. It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer in the first line of output — the maximum value of ∑i=1n(ai|bi)
.

Then, print n
 distinct integers a1,a2,…,an
 in the second line — the array a
 after reordering.

If there are multiple answers, you may print any of them.

Example
InputCopy
3
0 3
0 9
0 15
OutputCopy
12
3 2 1 0 
90
7 8 5 4 3 2 9 0 1 6
240
15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 
Note
In the first test case, the reordered array a
 is [3,2,1,0]
. The value of the expression is (3|0)+(2|1)+(1|2)+(0|3)=3+3+3+3=12
. It can be proved that this is the maximum possible value of the expression.

In the second test case, the reordered array a
 is [7,8,5,4,3,2,9,0,1,6]
. The value of the expression is 90
. It can be proved that this is the maximum possible value of the expression.



Codeforces (c) Copdef solve():
    l, r = map(int, input().split())
    pw = 1
    ans = 0
    while pw < r:
        pw = pw << 1 | 1
    s = set()
    for i in range(l, r + 1):
        s.add(i)
    a = [0] * (r + 1)
    for i in range(r, l - 1, -1):
        while pw - i not in s:
            pw >>= 1
        a[i] = pw - i
        ans += i | a[i]
        s.remove(pw - i)
    print(ans)
    print(*a[l : r + 1])
    return


t = int(input())
for _ in range(t):
    solve()
