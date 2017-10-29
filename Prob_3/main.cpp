#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct activ
{
    int p, t, ind;
    //functie de sortare pentru heap
    bool operator < (const activ& a) const
    {
        return p < a.p;
    }
};

//functie de comparare pentru sortarea initiala
bool comp (const activ& a, const activ& b)
{
    return a.t > b.t;
}

int main()
{
    //citire
    int n;
    cin >> n;
    activ a[n];
    for (int i = 0; i<n; i++)
    {
        cin >> a[i].p >> a[i].t;
        a[i].ind = i+1;
    }
    //sortare
    sort(a, a+n, comp);
    //selectare + crearea/adaugarea in heap
    priority_queue <activ> heap;
    heap.push(a[0]);
    int t = a[0].t;
    int profit = 0;
    int result[n];
    int i = 1;
    int k = 0;
    while (t > 0 && k<n)
    {
        while (t <= a[i].t && i < n)
        {
            heap.push(a[i]);
            i++;
        }
        if (!heap.empty())
        {
            profit += heap.top().p;
            result[k] = heap.top().ind;
            k++;
            heap.pop();
            t--;
        }
        else
            t = a[i].t;
    }
    //afisare
    cout << profit << '\n';
    for (int j = k-1; j>=0; j--)
        cout << result[j] << ' ';
    return 0;
}
