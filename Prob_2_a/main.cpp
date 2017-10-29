#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct text
{
    double frec, l;
    int ind;
};

//functie de compartare pentru sortarea cuvinteleor
bool comp (const text& a, const text& b)
{
    return a.frec / a.l > b.frec / b.l;
}

int main()
{
    //citire
    int n;
    cin >> n;
    text t[n];
    for (int i = 0; i<n; i++)
    {
        cin >> t[i].l >> t[i].frec;
        t[i].ind = i+1;
    }
    //sortare
    sort(t, t+n, comp);
    //afisare
    for (int i = 0; i<n; i++)
        cout << t[i].ind << ' ';
    return 0;
}
