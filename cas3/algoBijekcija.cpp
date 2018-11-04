#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>

using namespace std;

int main()
{
		
		cout << "Unesite kardinalnost skupa S:" << endl;
		int n;
		cin >> n;
		if(n < 0)
			throw("Neispravna vrednost");

		vector<int> f(n);
		vector<int> c(n, 0);
		int tmp;

		for(int i = 0; i < n; i++)
		{
			cout << "Unesite sliku " << i << ". tacke " << endl;
			cin >> tmp;
			if(tmp < 0 || tmp >= n)
				throw("Greska");
			f[i] = tmp;
		}

		for(int i = 0; i < n; i++)
			c[f[i]]++;

		vector<bool> pripada(n, true);
		list<int> Lista;
		for(int i = 0; i < n; i++)
			if(0 == c[i])
			 Lista.push_back(i);

		while(!Lista.empty())
		{
			int i = Lista.front();
			pripada[i] = false;
			Lista.pop_front();
			c[f[i]]--;
			if(0 == c[f[i]])
				Lista.push_back(f[i]);
		}
		cout << "Maksimalan podskup S izgleda:" << endl;
		for(int i = 0; i < n; i++)
			if(pripada[i])
				cout << i << " ";
		cout << endl;
		return 0;
}
