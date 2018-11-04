#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

struct Predmeti
{
	int C;
	int L;
};

void ispisi_tablu(vector<int> &tezine, vector<int> &vrednosti, int K);

int main()
{
	int n;
	cout << "Unesite broj predmeta: ";
	cin >> n;
	if(n < 0)
		throw("Greska");

	// cout << "Unesite tezine " << n << " predmeta: ";
	vector<int> tezine(n+1);
	vector<int> vrednosti(n+1);
	for(int i = 1; i < n+1; i++)
	{
		cout << "Unesite tezinu i vrednost predmeta broj " << i << ": ";
		cin >> tezine[i];
		cin >> vrednosti[i];
	}
	int K;
	cout << "Unesite nosivost ranca: ";
	cin >> K;
	if(K < 0)
		throw("Greska");


	ispisi_tablu(tezine, vrednosti, K);

	return 0;
}

void ispisi_tablu(vector<int> &tezine, vector<int> &vrednosti, int K)
{
	int n = tezine.size();
	vector<vector<Predmeti>> P(n+1);
	for(int i = 0; i <= n; i++)
		P[i].resize(K+1);

	for(int k = 0; k <= n; k++)
		P[k][0].C = P[k][0].L = 0;

	for(int k = 0; k <= K; k++)
		P[0][k].C = P[0][k].L = 0;


// Popunjavanje matrice
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= K; j++)
		{
			P[i][j].C = P[i-1][j].C;
			P[i][j].L = 0;
			if(j >= tezine[i] &&
				(P[i][j-tezine[i]].C > 0 || j - tezine[i] == 0) &&
				(P[i][j-tezine[i]].C + vrednosti[i] > P[i][j].C ))
				{
					P[i][j].C = P[i][j-tezine[i]].C + vrednosti[i];
					P[i][j].L = P[i][j-tezine[i]].L + 1;
				}

		}

	}
	// Rekonstrukcija
	int re_value;
	cout << "Unesite tezinu za koju zelite da izvrsite rekonstrukciju: ";
	cin >> re_value;
	stack<int> stek;

	for(int i = n; i >= 0; i--)
	{
		if(0 == P[i][re_value].C)
			break;
		if(0 == P[i][re_value].L)
			continue;


		re_value -= tezine[i];
		stek.push(i++);
	}
	cout << "Potrebno je uzeti sledece predmete: ";
	while(!stek.empty())
    {
		cout << "k" << stek.top() << " ";
	    stek.pop();
	}
    cout << endl;

// Ispis matrice
	for(int i = 0; i < n; i++)
	{
		if(i != 0)
			printf("k%d = %3d ", i, tezine[i]);
		else
			printf("         ");
		for(int k = 0; k <= K; k++)
			printf("%2d/%2d ",P[i][k].C, P[i][k].L);

		cout << endl;
	}
}
