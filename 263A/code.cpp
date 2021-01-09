#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int data;
    for (int m = 1; m <= 5; m++)
    {
        for (int n = 1; n <= 5; n++)
        {
            cin >> data;
            if (data)
            {
                cout << abs(3 - m) + abs(3 - n);
                return 0;
            }
        }
    }

    return 0;
}
