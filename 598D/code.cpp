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

void visit(vector<vector<char>> &grid, vector<vector<int>> &vis, int &i, int &ans, int x, int y)
{
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
        return;
    if (grid[x][y] == '*')
    {
        ans++;
        return;
    }
    if (vis[x][y] != 0)
        return;

    vis[x][y] = i;

    visit(grid, vis, i, ans, x + 1, y);
    visit(grid, vis, i, ans, x - 1, y);
    visit(grid, vis, i, ans, x, y + 1);
    visit(grid, vis, i, ans, x, y - 1);
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<char>> grid(m, vector<char>(n));
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<int> p(k + 1, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char val;
            cin >> val;
            grid[i][j] = val;
        }
    }

    for (int i = 1; i <= k; i++)
    {
        int a, b, ans = 0;
        cin >> a >> b;
        if (vis[a - 1][b - 1] != 0)
            ans = p[vis[a - 1][b - 1]];
        else
        {
            visit(grid, vis, i, ans, a - 1, b - 1);
            p[i] = ans;
        }

        cout << ans << endl;
    }

    return 0;
}