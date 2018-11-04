#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <stack>

using	namespace std;

struct Predmeti
{
	bool postoji;
	bool pripada;
};

bool da_li_postoji(vector<int> &S, int K)
{
    int n = S.size();
    vector<vector<Predmeti>> P(n+1);
    for(int i = )
	
  // Ispis matrice
	for(int i = 0; i < n; i++)
	{

		if(i != 0)
			printf("k%d = %3d ", i, S[i]);
		else
			printf("         ");
		for(int k = 0; k <= K; k++)
			printf("%3s/%s ", P[i][k].postoji ? "1" : "0", P[i][k].pripada ? "1" : "0");
			cout << endl;
	}

  // Punjenje steka za ispis stvari iz ranca koje ucestvuju u resenju
	// stack<int> stek;
	// if(P[n][K].postoji)
	// {
	// 	int tmp = K;
	// 	for(int i = 0; i < n; i++)
	// 		if(P[i][K].pripada)
	// 		{
	// 			stek.push(i);
	// 			tmp -= S[i];
	// 		}
	// 	while(tmp != 0)
	// 	{
	// 		for(int i = 0; i < n; i++)
	// 			if(P[i][tmp].pripada)
	// 				stek.push(i);
	// 	}
  //
	// 	cout << "Predmeti su:" << endl;
	// }
  //
	// while(!stek.empty())
	// {
	// 	cout << "k" << stek.top() << " ";
	// }
	// cout << endl;
	return P[n][K].postoji;
}

int main()
{
	int n;
	cout << "Unesite broj predmeta: ";
	cin >> n;
	if(n < 0)
		throw("Greska");

	cout << "Unesite tezine " << n << " predmeta: ";
	vector<int> tezine(n+1);
	for(int i = 1; i < n+1; i++)
		cin >> tezine[i];

	int K;
	cout << "Unesite kapacitet ranca:";
	cin >> K;
	if(K < 0)
		throw("Greska");
	printf("Resenje %s\n", da_li_postoji(tezine, K) ? "postoji" : "ne postoji" );
	return 0;
}
