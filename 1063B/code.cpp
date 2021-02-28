#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
// #define OJ
#define ll long long

bool vis[2001][2001];
char grid[2001][2001];

struct node
{
    ll x, y, l, r;
};

bool isvalid(ll r, ll c, ll n, ll m)
{
    return (r >= 0 && c >= 0 && r < n && c < m);
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    ll m, n, si, sj, lm, rm, ans = 1;
    cin >> n >> m >> si >> sj >> lm >> rm;
    si--, sj--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            vis[i][j] = false;
        }

    deque<node> q;
    q.push_front(node{si, sj, lm, rm});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto cell = q.front();
        q.pop_front();

        ll r = cell.r, l = cell.l, x = cell.x, y = cell.y;
        // grid[cell.x][cell.y] = '+';

        if (isvalid(x + 1, y, n, m) && grid[x + 1][y] != '*' && vis[x + 1][y] == false)
            vis[x + 1][y] = true, q.push_front({x + 1, y, l, r}), ans++;

        if (isvalid(x - 1, y, n, m) && grid[x - 1][y] != '*' && vis[x - 1][y] == false)
            vis[x - 1][y] = true, q.push_front({x - 1, y, l, r}), ans++;

        if (isvalid(x, y + 1, n, m) && grid[x][y + 1] != '*' && vis[x][y + 1] == false && r > 0)
            vis[x][y + 1] = true, q.push_back({x, y + 1, l, r - 1}), ans++;

        if (isvalid(x, y - 1, n, m) && grid[x][y - 1] != '*' && vis[x][y - 1] == false && l > 0)
            vis[x][y - 1] = true, q.push_back({x, y - 1, l - 1, r}), ans++;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;

    return 0;
}