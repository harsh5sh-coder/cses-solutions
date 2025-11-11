#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O3")
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using st = string;
 
#define For(i, a, b) for (int i = a; i < b; i++)
#define Forl(i, size) for (int i = 0; i < size; i++)
#define Forr(i, size) for (int i = size - 1; i >= 0; i--)
#define ForR(i, a, b) for (int i = a; i >= b; i--)
 
#define cntd continue;
#define pb push_back
#define u_ unordered_
#define contd continue;
#define clr(a) memset(a, 0, sizeof(a));
#define all(c) (c).begin(), (c).end()
 
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ret return 0;
#define NIL -1
 
#define en cout << "\n";
 
#define sqrt sqrtl
 
#define beg begin()
#define rbeg rbegin()
 
#define ram(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define sita(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)
 
#define Bhaag_Milkha_Bhaag            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<ull> vull;
typedef vector<string> vst;
typedef vector<bool> vb;
typedef vector<char> vch;
typedef vector<ld> vld;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
const ld Pi = 3.1415926535;
const long long Mod = 1e9 + 7;
const int N = 2 * 1e5 + 9;
const ll inf = (ll)2e18;
const ll ninf = (ll)-2e18;
const ll sInf = (ll)2e9;
const ll sNinf = (ll)-2e9;
const ld epsilon = (ld)1e-12;
 
ll sum = 0;
string res{};
 
vector<string> vec_splitter(string s)
{
    s += ',';
    vector<string> res;
    while (!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(vector<string> __attribute__((unused)) args, __attribute__((unused)) int idx) { cerr << endl; }
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#define watch(x) cout << (#x) << " is " << (x) << endl;
 
#ifdef JaiShreeRam
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
 
bool mahadev(const pair<int, int> &a,
             const pair<int, int> &b)
{
    if (a.se == b.se)
        return (a.fi < b.fi);
 
    return (a.se < b.se);
}
 
template <class T>
bool ckmin(T &a, T &b)
{
    bool B = a > b;
    a = min(a, b);
    return B;
}
template <class T>
bool ckmax(T &a, T &b)
{
    bool B = a < b;
    a = max(a, b);
    return B;
}
 
ld getDist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
bool isPrime(ll num)
{
    bool flag = true;
    if (num == 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
 
set<ll> fac;
void allFactors(ll n)
{
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            fac.insert(i);
 
            if (i != n / i)
            {
                fac.insert(n / i);
            }
        }
    }
    fac.insert(n);
}
 
ll findSum(ll a[], int l, int r)
{
    ll sum = 0;
    For(i, l, r)
    {
        sum += a[i];
    }
    return sum;
}
 
vector<pair<int, int>> vec1; //Prime Factors along with their exponents
void primeFactors(ll n)
{
    int c1 = 0;
 
    while (n % 2 == 0)
    {
        // printf("%d ", 2);
        n = n / 2;
        c1++;
    }
    if (c1)
        vec1.pb(mp(2, c1));
    c1 = 0;
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        c1 = 0;
        while (n % i == 0)
        {
            // printf("%d ", i);
 
            n = n / i;
            c1++;
        }
        if (c1)
            vec1.pb(mp(i, c1));
    }
    c1 = 0;
    if (n > 2)
        vec1.pb(mp(n, 1));
}
 
ll power(int x, unsigned int y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
 
ll power(ll x, ll y, ll p)
{
    ll res = 1;
 
    x = x % p;
    if (x == 0)
        return 0;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
ull nCr(ll n, ll r)
{
    if (n == 0)
        return (ull)0;
    if (n < r)
        return ull(0);
    if (n == r)
        return (ull)1;
 
    ull p = 1;
    ull k = 1;
    if (n - r < r)
        r = n - r;
 
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m; //Simplifying
            n--;
            r--;
        }
    }
    else
        p = 1;
 
    return p;
}
 
ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}
 
unsigned int countBits(ll n, int specify)
{
    unsigned int count = 0, total = 0;
    if (n == 0)
    {
        if (specify == 1)
            return 0;
        else
            return 1;
    }
    while (n)
    {
        total += 1;
        count += n & 1;
        n >>= 1;
    }
    if (specify == 1)
        return count;
    else
        return (total - count);
}
 
ld angleClock(int hour, int minutes)
{
    long double hourAngle = (ld)((hour % 12) + minutes * (ld)1.0 / (ld)60) * (ld)30;
    long double minutesAngle = (ld)minutes * (ld)6;
    long double a = abs((ld)hourAngle - (ld)minutesAngle);
    long double b = (ld)360 - (ld)a;
    return a < b ? a : b;
}
 
int cntDig(ll n)
{
    return floor(log10(abs(n)) + 1);
}
 
//Seive of Eratosthenes
 
// const ll maxN = 1e7 + 9;
// vector<bool> pr((ll)1e7 + 9, true);
// vector<ll> pp;
 
// void seive()
// {
//     pr[0] = false;
//     pr[1] = false;
//     for (ll p = 2; p * p <= maxN; p++)
//     {
//         if (pr[p])
//         {
//             for (ll i = p * p; i <= maxN; i += p)
//             {
//                 pr[i] = false;
//             }
//         }
//     }
//     for (ll i = 0; i <= maxN; i++)
//     {
//         if (pr[i] == true)
//         {
//             // debug(i);
//             pp.pb(i);
//         }
//     }
// }
 
/*********************************************************************************************************************/
// Function and essential data structures For BFS In A Grid;
// int n, m, k;
 
// string s[509];
// int dr[] = {-1, 1, 0, 0};
// int dc[] = {0, 0, 1, -1};
// queue<int> rq, cq;
// bool vis[509][509] = {false};
 
// int cont = 0;
// bool ok = 0;
 
// void clearQ(std::queue<int> &q)
// {
//     std::queue<int> empty;
//     std::swap(q, empty);
// }
 
// bool valid(int i, int j)
// {
//     return (i >= 0 && i <= n - 1) && (j >= 0 && j <= m - 1);
// }
 
// void explore(int r, int c)
// {
//     int rr, cc;
//     for (int i = 0; i < 4; i++)
//     {   rr = r + dr[i];
//         cc = c + dc[i];
 
//         if (valid(rr, cc) && !vis[rr][cc] && s[rr][cc] == '#')
//         {
//             rq.push(rr);
//             cq.push(cc);
//             vis[rr][cc] = 1;
//         }
//     }
// }
 
// void bfsInGrid(int sr, int sc)
// {
 
//     clearQ(rq);
//     clearQ(cq);
//     clr(vis);
//     rq.push(sr);
//     cq.push(sc);
//     debug(sr, sc);
//     vis[sr][sc] = 1;
//     while (!rq.empty() && !cq.empty())
//     {
 
//         int r = rq.front();
//         rq.pop();
//         int c = cq.front();
//         cq.pop();
//         explore(r, c);
//     }
// }
 
/*******************************************************************************************************************************************/
// #define SIZE 100009
// ll fact[SIZE] = {0};
 
// void factorial()
// {
//     int i;
//     fact[0] = 1;
//     for (i = 1; i <= SIZE; i++)
//     {
 
//         // Calculation of factorial
//         // As fact[i-1] stores the factorial of n-1
//         // so factorial of n is fact[i] = (fact[i-1]*i)
//         fact[i] = (fact[i - 1] * i) % Mod;
//     }
// }
 
void scar(ll a[], int n, int param = 0)
{
    if (param == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
}
 
/*******************************************************************************************************************************************/

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    //Core Logic: The bitwise XOR ensures that as we iterate through cells,
    // the new value i ^ j is fundamentally different from all preceding values in that row and column
    // due to the nature of bitwise arithmetic, making it the required MEX.
    for(int i = 0; i < n; i++) {
        int m;
        for(int j = 0; j < n; j++) {
            m = i ^ j;
            cout<<m<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
 
//*********************** PAY ATTENTION **********************************//
/*
ALWAYS REMEMBER:
 
1.SPAGHETTI Code is the worst thing you can ever come up with!
2.To use 0ll(and not simple zero) in accumulate function to avoid overflow.
------------
Even If You PASS The PRETESTS, Don't Be HAPPY (Don't even SMILE)!!
Your solution might fail in SYSTEM TESTS..!!
.
.
. 
Surprise MADAFAKA !!
-------------
 
 
*/
//*************************************************************************//
