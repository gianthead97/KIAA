#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int NZS(vector<int> niz);
int NZD(int a, int b);

int main(int argc, char const *argv[])
{
    vector<int> niz;
    int x;
    while(cin >> x)
        niz.push_back(x);

    cout << NZS(niz) << endl;    

    return 0;
}

int NZS(vector<int> niz)
{

    vector<int> tmp_niz(niz);
    if(niz.begin() + 2 == niz.end())
        return niz[0] * niz[1] / NZD(niz[0], niz[1]);
    else
    {
        int kraj = tmp_niz.back();
        tmp_niz.pop_back();
        int nzs_m = NZS(tmp_niz);
        return  kraj * nzs_m / NZD(kraj, nzs_m);
    }
}

int NZD(int a, int b)
{
    int m = max(a, b);
    int n = min(a, b);
    int r = 1;
    while(r > 0)
    {
        r = m % n;
        m = n;
        n = r;
    }

    return m;
}