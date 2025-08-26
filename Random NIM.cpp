Random NIM
There are 
N
N piles numbered 
1
,
2
,
…
,
N
1,2,…,N. The 
i
i-th pile initially has 
A
i
A 
i
​
  stones. Alice and Bob are playing a Nim game on these piles, but there is a twist.

As per the usual rules of Nim, Alice and Bob take turns alternately choosing a pile and removing some stones from the pile, with Alice going first. The player unable to make a move loses.

However, the twist is that instead of choosing how many stones to remove from the pile, they have to use a random number generator. If there are 
X
X stones left in the pile, they will randomly generate an integer 
R
R between 
1
1 and 
X
X (inclusive, and equiprobable) and then remove exactly 
R
R stones from the pile.

In this game, find the probability that Alice wins modulo 
998244353
998244353, when both players play optimally.

Formally, it can be shown that the answer can be represented as 
P
Q
Q
P
​
  where 
Q
m
o
d
 
 
998244353
≠
0
Qmod998244353=0, and you should print the unique integer 
R
R in 
[
0
,
998244353
)
[0,998244353) such that 
R
⋅
Q
=
P
m
o
d
 
 
998244353
R⋅Q=Pmod998244353.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
1
1 integer - 
N
N, the number of piles.
The second line contains 
N
N integers - 
A
1
,
A
2
,
…
,
A
N
A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 .
Output Format
For each test case, output on a new line the probability that Alice wins modulo 
998244353
998244353.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
≤
1000
1≤N≤1000
1
≤
A
i
≤
1000
1≤A 
i
​
 ≤1000
The sum of 
N
N over all test cases does not exceed 
1000
1000.
Sample 1:
Input
Output
2
1
2
2
1 1
499122177
0
Explanation:
Test Case 1 : There are 
2
2 possible ways the game can play out:

Alice chooses pile 
1
1, and the random number 
R
=
2
R=2. Alice wins because Bob has no move.
Alice chooses pile 
1
1, and the random number 
R
=
1
R=1. Bob chooses pile 
1
1, and the random number 
R
R must be 
1
1. Alice loses as she has no move.
Thus, the probability is 
1
2
2
1
​
 , and we print 
499122177
499122177 because 
2
⋅
499122177
=
1
m
o
d
 
 
998244353
2⋅499122177=1mod998244353.
#include <bits/stdc++.h>
#define lil long long int
// #define sort(xyz) sort(xyz.begin(),xyz.end())
const int MOD = 1e9 + 7;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int test;cin>>test;
	while(test--)
	{
	    lil n;cin>>n;
	    lil a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int mod=998244353;
	    int o=0;
	   for(int i=0;i<n;i++)
	   {
	       if(a[i]!=1) o++;
	   }
	   if(o==0){
	       cout<<(n%2)<<endl;
	   }
	   else{
	       cout<<mod/2+1<<endl;
	       
	   }
	}

}
