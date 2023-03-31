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
struct myComp
{
    constexpr bool operator()(pair<ll, pl> const &a,
                              pair<ll, pl> const &b) const noexcept
    {
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

void _print(ll t)
{
    cerr << t;
}
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
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T, greater<T>> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T, myComp> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T, myComp> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(unordered_set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
//=================================================================================================
/*  some useful code snippets!
  1>  Getprime - to get prime till a number limit. !!!
  2>  Primefactorize - to get all prime factors in sorted order of a number n by using seive. !!!
  3>  Power_exponentiation  - gives power function to get a^n in log (n) time. !!!
  4>  inverse_modulo - gives inverse modulo of a number wrt md.  !!!
  5>  nCr_modulo_md - gives nCr % md in log (md) time.  !!!
*/
//===============================================================================================================
void local()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
//===================================================================================================================

ll inf = 1e18;
ll md = 1e9 + 7; // 998244353;

ll gcd(ll a, ll b) {
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a/gcd(a,b)*b;
}

//=============================================

vi par;

int find(int u) {
    if(par[u] == u) return u;

    return par[u] = find(par[u]);
}

void unio(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;

    par[u] = v;
}

ll repeat(int n, int count) {
    ll ans = 0;
    for(int i=0; i<count; ++i) {
        ans = ans*10 + n;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    

    vi ans(n+1);

    vi a(n+1);
    for(int i=0; i<=n; ++i) a[i] = i;
    int val = n;
    for(int i=0; i<n-1; ++i) {
        cout<<"? ";
        for(int j=1; j<=n; ++j) cout<<a[j]<<" ";
        cout<<endl;
        int k;
        cin>>k;
        vi ind(k);
        for(int k1=0; k1<k; ++k1) cin>>ind[k1];

        // swap
        ans[a[ind[k-1-i]]] = val--;
        int temp = a[ind[k-1-i]];
        a[ind[k-1-i]] = a[n-i];
        a[n-i] = temp;
    }

    cout<<"! ";
    for(int i=1; i<=n; ++i) {
        if(ans[i]==0) cout<<1<<" ";
        else cout<<ans[i]<<" ";
    }
    cout<<endl;

    int verdict;
    cin>>verdict;
}

// 1 2 3 4 - 2 4 3 1 = 1 2
// 2 3 4 1 - 4 3 1 2 = 1 
// 3 4 1 2 - 3 1 4 2 = 1 3
// 1 3 4 2 - 2 3 1 4 = 1 2 4
// 1 4 3 2 - 2 1 3 4 = 1 3 4

//==================================================================================================
int main()
{

    // local ();
    fastio();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << " ms\n";
#endif
}

/*
 1 1
 0 2
 1 0
 0 1
 1 2
 0 0
 1 1
*/