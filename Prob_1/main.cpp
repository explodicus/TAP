#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct cub
{
    int l, c, ind;
};

//functia de comparare pentru sortat
bool compare(const cub& a, const cub& b)
{
    return a.l > b.l;
}

int main()
{
    //citire
    int n, p;
    cin >> n >> p;
    cub c[n];
    for (int i = 0; i<n; i++)
    {
        cin >> c[i].l >> c[i].c;
        c[i].ind = i;
    }
    //sortare
    sort(c,c+n,compare);
    int k = 0, sum = 0;
    int curent_col = 0;
    int result[n];
    //selectarea cuburilor potrivite
    for (int i = 0; i<n; i++)
    {
        if (curent_col != c[i].c)
        {
            curent_col = c[i].c;
            result[k] = c[i].ind+1;
            k++;
            sum += c[i].l;
        }
    }
    //afisarea rezultatelor
    cout << sum << '\n';
    for (int i = 0; i<k; i++)
    {
        cout << result[i] << ' ';
    }
}
