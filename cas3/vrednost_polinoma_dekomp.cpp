#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

double vrednost_polinoma(double x, vector<double> &polinom)
{
	int n = polinom.size();
	if(n == 1)
		return polinom[0];
	else
	{
		double x_novo = x * x;
		vector<double> a_parno;
		vector<double> a_neparno;
		for(int i = 0; i < n; i++)
		{
			if(i % 2)
				a_neparno.push_back(polinom[i]);
			else
				a_parno.push_back(polinom[i]);
		}

		double pp = vrednost_polinoma(x_novo, a_parno);
		double pn = vrednost_polinoma(x_novo, a_neparno);
		return pp + x * pn;
	}
}


int main()
{
	int n;
	cout << "Unesi najveci stepen polinoma:" << endl;
	cin >> n;
	if (n < 0)
		throw("Neispravna dimenzija");

	cout << "Unesi " << n+1 << " koeficijenta:" << endl;
	vector<double> polinom(n + 1);
	for(int i = 0; i <= n; i++)
		cin >> polinom[i];

	double x;
	cout << "Unesi vrednost x:" << endl;
	cin >> x;

	cout << "Vrednost polinoma u tacki x = " << x << " je: " << vrednost_polinoma(x, polinom) << endl;

	return 0;
}
