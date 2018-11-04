#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

struct Pravuagonik
{
	double a;
	double b;
};

double max_(double a, double b)
{
	return (a > b) ? a : b;
}

int main()
{
	int n;
	cout << "Unesite broj pravugaonika: ";
	cin >> n;
	if(n < 0)
		throw("Greska");

	vector<Pravuagonik> niz(n);
	vector<double> f(n);
	vector<double> g(n);
	for(int i = 0; i < n; i++)
		cin >> niz[i].a >> niz[i].b;

	f[0] = niz[0].a;
	g[0] = niz[0].b;
	for(int i = 1; i < n; i++)
	{
		f[i] = niz[i].a + max_(f[i-1]+abs(niz[i-1].b-niz[i].b), g[i-1]+abs(niz[i-1].a-niz[i].b));
		g[i] = niz[i].b + max_(f[i-1]+abs(niz[i-1].b-niz[i].a), g[i-1]+abs(niz[i-1].a-niz[i].a));
	}
	printf("%.2lf\n", max_(f[n-1], g[n-1]));
	return 0;
}
