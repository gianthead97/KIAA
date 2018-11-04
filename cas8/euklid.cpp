#include <iostream>
#include <cstdlib>
#include <list>
#include <climits>

using namespace std;

int min_el(list<int> niz, int* min_indeks)
{
	int tmp = INT_MAX;
	*min_indeks = 0;
	int i = 0;
	for(auto it = niz.begin(); it != niz.end(); it++, i++)
	{
			if(tmp > (*it))
			{
			        *min_indeks = i;
			        tmp = (*it);
	        }
	}
	return tmp;
}


int main()
{
	int n, min_indeks = -1;
	cin >> n;
	list<int> niz;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		niz.push_back(tmp);
	}
	
	while(niz.size() != 1)
	{
		int tmp_min = min_el(niz, &min_indeks);
		int i = 0;
		for(auto it = niz.begin(); it != niz.end(); it++, i++)
		{
		    if(i != min_indeks)
		      *it %= tmp_min;
		}	
		niz.remove(0);
		
		if(niz.size() == 0)
		{
		    cout << tmp_min << endl;
		    return 0;
		}
	}
	
	cout << niz.front() << endl;

	
	return 0;
}
