#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct text
{
    int l;
    int ind;
};

//functie de compartare pentru sortarea cuvinteleor
bool comp (const text& a, const text& b)
{
    return a.l < b.l;
}

int main()
{
    //citire
    int n, p;
    cin >> n >> p;
    text t[n];
    for (int i = 0; i<n; i++)
    {
        cin >> t[i].l;
        t[i].ind = i+1;
    }
    //sortare
    sort(t, t+n, comp);
    vector <int> banda[p];
    int k = 0;
    //selectare text pe fiecare banda
    while (k < n)
        for (int i = 0; i<p && k<n; i++)
        {
            banda[i].push_back(t[k].ind);
            k++;
        }
    //afisare
    for (int i = 0; i<p; i++)
    {
        for (k = 0; k<banda[i].size(); k++)
            cout << banda[i][k] << ' ';
        cout << '\n';
    }
    return 0;
}
