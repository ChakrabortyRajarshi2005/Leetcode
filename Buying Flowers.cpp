Buying Flowers
Chef wants to buy 
N
N (
N
≥
2
N≥2) flowers.

He can either pay 
4
4 coins and receive 
2
2 flowers, or pay 
5
5 coins and receive 
3
3 flowers.
Both types of transactions can be repeated as many times as he likes.

Find the minimum number of coins Chef needs to pay to buy exactly 
N
N flowers.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of a single line, containing one integer 
N
N — the number of flowers Chef wishes to buy.
Output Format
For each test case, output on a new line the minimum number of coins Chef needs to pay to buy 
N
N flowers.

Constraints
1
≤
T
≤
100
1≤T≤100
2
≤
N
≤
100
2≤N≤100
Sample 1:
Input
Output
4
2
3
5
8
4
5
9
14
Explanation:
Test case 
1
1: The only option is to buy 
2
2 flowers for 
4
4 coins.

Test case 
2
2: The only option is to buy 
3
3 flowers for 
5
5 coins.

Test case 
3
3: Chef can buy 
2
2 flowers for 
4
4 coins and 
3
3 flowers for 
5
5 coins, for a total of 
2
+
3
=
5
2+3=5 flowers at a cost of 
4
+
5
=
9
4+5=9.

Test case 
4
4: There are two options available to Chef:

Buy 
2
2 flowers for 
4
4 coins; four times.
This will result in 
2
+
2
+
2
+
2
=
8
2+2+2+2=8 flowers at a cost of 
4
+
4
+
4
+
4
=
16
4+4+4+4=16.
Buy 
2
2 flowers for 
4
4 coins once, and then buy 
3
3 flowers for 
5
5 coins two times.
This will result in 
2
+
3
+
3
=
8
2+3+3=8 flowers at a cost of 
4
+
5
+
5
=
14
4+5+5=14.
The second option is cheaper, so the answer is 
14
14.


#include <bits/stdc++.h>

using namespace std;



#define int long long

#define pb push_back

#define fr(i,a,b) for(int i = a; i < b; i++)

#define sum(v) accumulate((v).begin(), (v).end(), 0LL)

#define all(x) (x).begin(), (x).end()

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef vector<int> vi;

#define in(v,n) vi v(n); fr(i,0,n) cin>>v[i];



// ==================== Utility Functions ====================



// freq_vec - count frequency of elements in vector

unordered_map<int, int> freq_vec(const vi &v) {

    unordered_map<int, int> freq;

    for (int x : v) freq[x]++;

    return freq;

}



// freq_str - count frequency of characters in string

unordered_map<char, int> freq_str(const string &s) {

    unordered_map<char, int> freq;

    for (char c : s) freq[c]++;

    return freq;

}



// isPrime - checks if a number is prime

bool isPrime(int n) {

    if (n < 2) return false;

    for (int i = 2; i*i <= n; i++)

        if (n % i == 0) return false;

    return true;

}



// sieve - generates prime markings up to n

vi sieve(int n) {

    vi is_prime(n+1, 1);

    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i*i <= n; i++) {

        if (is_prime[i]) {

            for (int j = i*i; j <= n; j += i)

                is_prime[j] = 0;

        }

    }

    return is_prime;

}



// gcd and lcm

int gcd(int a, int b) {

    return b == 0 ? a : gcd(b, a % b);

}

int lcm(int a, int b) {

    return (a * b) / gcd(a, b);

}



// binary_search_custom - returns index or -1

int binary_search_custom(const vi &a, int target) {

    int l = 0, r = a.size() - 1;

    while (l <= r) {

        int mid = (l + r) / 2;

        if (a[mid] == target) return mid;

        else if (a[mid] < target) l = mid + 1;

        else r = mid - 1;

    }

    return -1;

}



//XOR of n numbers

int xor_upto(int n) {

  if (n % 4 == 0) return n;

  if (n % 4 == 1) return 1;

  if (n % 4 == 2) return n + 1;

  return 0;

}



// ==================== Solve Function ====================

void solve(){

    int t; cin >> t;

    while(t--){

        int n; cin>>n;

        int ans;

        if(n%3==0) ans = (n/3) * 5 ;

        else if(n%3==1) ans = ((n/3) * 5 ) - 5 + 8;

        else ans =  (n/3)*5+4 ;

        cout<<ans<<endl;

    }

}



/////////////////////////////////////////////////////////////////////////////////

// Author: ganesh B. KARTHIK

// Institute: IIIT Jabalpur

/////////////////////////////////////////////////////////////////////////////////



int32_t main() {

    fast;

    solve();

    return 0;

}
