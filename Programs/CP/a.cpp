#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define in insert
#define fo(i, n) for (i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
//============================================================================================
// costum comparator
struct myComp {
    constexpr bool operator()(pair<ll, pl> const& a,
                              pair<ll, pl> const& b) const noexcept {
        if ((a.F) != b.F)
            return (((a).F) > (b).F);
        else
            return a.S < b.S;
    }
};
//=================================================================================
// debugger

#ifndef ONLINE_JUDGE
#define dbg(x)         \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define dbg(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T>
void _print(unordered_set<T> v);
template <class T>
void _print(multiset<T, greater<T>> v);
template <class T>
void _print(multiset<T, myComp> v);
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(set<T, myComp> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}
template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T, greater<T>> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T, myComp> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T, myComp> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(unordered_set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
//=================================================================================================
/*  some useful code snippets!
  1>  Getprime - to get prime till a number limit. !!!
  2>  Primefactorize - to get all prime factors in sorted order of a number n by
  using seive. !!! 3>  Power_exponentiation  - gives power function to get a^n
  in log (n) time. !!! 4>  inverse_modulo - gives inverse modulo of a number wrt
  md.  !!! 5>  nCr_modulo_md - gives nCr % md in log (md) time.  !!!
*/

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

//===============================================================================================================
void local() {
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
//===================================================================================================================

ll inf = 1e18;
ll md = 1e9 + 7;  // 998244353;

//=============================================

vi par;

int find(int u) {
    if (par[u] == u) return u;

    return par[u] = find(par[u]);
}

void unio(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    par[u] = v;
}

void yes() {cout<<"YES"<<endl;}
void no() {cout<<"NO"<<endl;}

int helper(int a, int b, int c) {
    if(a==b && b==c) return a;
    if(a==b) return c;
    if(b==c) return a;

    if(a<b && b<c) return a + c-b;
    if(a<b && b>c) return a - (b-c);
    if(a>b && b<c) return a + (c-b);
    return a - (b-c);
}

void solve() {
    int n;
    cin>>n;
    vi a(n);
    int i;
    fo(i,n) cin>>a[i];

    i=1;
    int prev = a[0];
    while(i < n) {
        int next = -1;
        if(i<n-1) next = a[i+1];
        if(next == -1) {
            if(a[i] >= prev) yes();
            else no();
            return;
        }
        prev = helper(prev, a[i], next);
        i += 2;
    }

    yes();
}

/*
5 4 1 - 2 2 2
1 4 3 - 0 0 0
2 1 4 - 5 5 5
    p*q = a
    p*r = b
    p*(q+r) >= a+b
    q+r+p min

    p-1 + a/p + b/p
    p-1 + (a+b)/p
*/

//==================================================================================================
int main() {
    // local ();
    fastio();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
         << " ms\n";
#endif
}

/*
10 45
 1 1
 0 2
 1 0
 0 1
 1 2
 0 0
 1 1
*/