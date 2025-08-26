C1. Interactive RBS (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes
This is an interactive problem.

This is the easy version of the problem. The only difference is the limit on the number of queries. You can make hacks only if all versions of the problem are solved.

There is a hidden bracket sequence s
 of length n
, where s
 only contains '('
 and ')'
. It is guaranteed that s
 contains at least one '('
 and one ')'
.

To find this bracket sequence, you can ask queries. Each query has the following form: you pick an integer k
 and arbitrary indices i1,i2,…,ik
 (1≤k≤1000
, 1≤i1,i2,…,ik≤n
). Note that the indices can be equal. Next, you receive an integer f(si1si2…sik)
 calculated by the jury.

For a bracket sequence t
, f(t)
 is the number of non-empty regular bracket substrings in t
 (the substrings must be contiguous). For example, f("()())")=3
.

A bracket sequence is called regular if it can be constructed in the following way.

The empty sequence ∅
 is regular.
If the bracket sequence A
 is regular, then (A)
 is also regular.
If the bracket sequences A
 and B
 are regular, then the concatenated sequence AB
 is also regular.
For example, the sequences "(())()"
, "()"
 are regular, while "(()"
 and "())("
 are not.

Find the sequence s
 using no more than 550
 queries.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤20
). The description of the test cases follows.

Interaction
The first line of each test case contains one integer n
 (2≤n≤1000
). At this moment, the bracket sequence s
 is chosen. The interactor in this task is not adaptive. In other words, the bracket sequence s
 is fixed in every test case and does not change during the interaction.

To ask a query, you need to pick an integer k
 and arbitrary indices i1
, i2…ik
 (1≤k≤1000
, 1≤i1,i2,…,ik≤n
) and print the line of the following form (without quotes):

"? k i1 i2…ik
"
After that, you receive an integer f(si1si2…sik)
.

You can ask at most 550
 queries of this form.

Next, if your program has found the bracket sequence s
, print a line with the following format (without quotes):

"! s1s2…sn
"
Note that this line is not considered a query and is not taken into account when counting the number of queries asked.

After this, proceed to the next test case.

If you ask more than 550
 queries during an interaction, your program must terminate immediately, and you will receive the Wrong Answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

After printing a query or the answer for a test case, do not forget to output the end of the line and flush the output. Otherwise, you will get the verdict Idleness Limit Exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see the documentation for other languages.
Hacks

To hack, follow the test format below.

The first line contains the number of test cases t
 (1≤t≤20
). The description of the test cases follows.

The first line of each test case contains one integer n
 (2≤n≤1000
).

The second line of each test case contains a bracket sequence s1s2…sn
, where si='('
 or ')'
.

The bracket sequence s
 must contain at least one '('
 and one ')'
.

Example
InputCopy
2
3

0

1

1

2

3

OutputCopy


? 4 1 2 3 3

? 2 2 1

? 2 3 1

! )((

? 4 1 2 1 2

! ()


Note
In the first test case, the hidden bracket sequence is s=")(("
.

For the query "? 4 1 2 3 3", the jury returns 0
 because f(s1s2s3s3)=f(")(((")=0
.

For the query "? 2 2 1", the jury returns 1
 because f(s2s1)=f("()")=1
.

For the query "? 2 3 1", the jury returns 1
 because f(s3s1)=f("()")=1
.

In the second test case, the hidden bracket sequence is s="()"
.

For the query "? 4 1 2 1 2", the jury returns 3
 because f(s1s2s1s2)=f("()()")=3
.

Note that the example is only for understanding the statement and does not guarantee finding the unique bracket sequence s
.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;

#define T(x, i) get<i>(x)
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define forn(i, n) for (int i = 0; i < n; i++)

template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.F >> p.S; }
template<class T, class U> inline ostream& operator<<(ostream& str, const pair<T, U> &p) { str << p.F << ' ' << p.S << ' '; return str; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline ostream& operator<<(ostream& str, const vector<T> &a) { for (auto &i : a) str << i << ' '; return str; }

void flush() { cout << flush; }
void flushln() { cout << endl; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U&... u) { read(x); read(u...); }
template<class T> void print(const T &x) { cout << x; }
template<class T, class ...U> void print(const T &x, const U&... u) { print(x); print(u...); }
template<class ...T> void println(const T&... u) { print(u..., '\n'); }
template<class T> void eprint(const T &x) { cerr << x; }
template<class T, class ...U> void eprint(const T &x, const U&... u) { eprint(x); eprint(u...); }
template<class ...T> void eprintln(const T&... u) { eprint(u..., '\n'); }

#ifdef DEBUG
	mt19937 rng(1033);
	#define var(x) cerr << #x << ": " << x << '\n';
	#define range(a, b) cerr << #a << ", " << #b << ": "; for (auto _it = a; _it != b; ++_it) cerr << *_it << ' '; cerr << '\n';
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	#define cerr if (false) cerr
	#define var(x)
	#define range(a, b)
	#define eprintln if(false)eprintln
	#define eprint if(false)eprint
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


int n;

map<vector<int>, int> mem;

int ask(vector<int> ind) {
	if (!mem.count(ind)) {
		cout << "? ";
		cout << ind.size() << ' ';
		for (auto i : ind)
			cout << i + 1 << ' ';
		cout << endl;

		int res;
		cin >> res;
		mem[ind] = res;
	}

	return mem[ind];
}


bool same(vector<int> ind) {
	if (ask(ind))
		return false;
	ind.push_back(ind[0]);
	ind.erase(ind.begin());
	if (ask(ind))
		return false;
	return true;
}

pii search(vector<int> ind) {
	if (ind.size() == 2) {
		if (ask(ind))
			return {ind[0], ind[1]};
		return {ind[1], ind[0]};
	}

	vector<int> inda, indb;
	int sz = (ind.size() + 1) / 2;
	for (int i = 0; i < sz; i++) {
		inda.push_back(ind[i]);
		indb.push_back(ind[ind.size() - 1 - i]);
	}

	if (!same(inda))
		return search(inda);
	if (!same(indb))
		return search(indb);
	inda.push_back(indb[0]);
	return search(inda);
}

pii find_reg2() {
	vector<int> ind(n);
	iota(all(ind), 0);
	shuffle(all(ind), rng);
	return search(ind);
}

void solve() {
	mem.clear();
	auto [po, pc] = find_reg2();

	vector<int> to_ask(n);
	iota(all(to_ask), 0);
	if (to_ask.size() & 1)
		to_ask.push_back(0);


	string ans = string(n, '.');
	ans[po] = '(';
	ans[pc] = ')';
		
	for (int i = 0; i < to_ask.size(); i += 2) {
		int a = to_ask[i], b = to_ask[i + 1];

		vector<int> q = {po, pc, po, a, b, pc};
		int res = ask(q);

		// ()(ab) - x ab
		// ()(()) - 4 ()
		// ()((() - 2 ((
		// ()())) - 3 ))
		// ()()() - 6 )(
		map<int, pair<char, char>> results = {
			{4, {'(', ')'}},
			{2, {'(', '('}},
			{3, {')', ')'}},
			{6, {')', '('}},
		};

		assert(results.count(res));
		auto [resa, resb] = results[res];
		ans[a] = resa;
		ans[b] = resb;
	}

	cout << "! " << ans << endl;
}

signed main() {
	#ifdef DEBUG
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(20);
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		solve();
	}
	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}


/*


()(ab)
()(()) - 4 ()
()((() - 2 ((
()())) - 3 ))
()()() - 6 )(

2
3
)((
2
()


*/

