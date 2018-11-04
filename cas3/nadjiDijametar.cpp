#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Cvor{
	Cvor(int n):vrednost(n){};
	int vrednost;
	Cvor* levo = nullptr;
	Cvor* desno = nullptr;
};


Cvor* dodaj_u_stablo(Cvor* s, int n)
{
	if(!s)
		return new Cvor(n);

	if(s->vrednost >= n)
		s->levo = dodaj_u_stablo(s->levo, n);
	else
		s->desno = dodaj_u_stablo(s->desno, n);

	return s;
}

int dijametar = 0;
int nadjiDijametar(Cvor* koren)
{
	int dim = 0;
	int levo_visina = 0;
	int desno_visina = 0;

	if(!koren)
		return 0;

	levo_visina = nadjiDijametar(koren->levo);
	desno_visina = nadjiDijametar(koren->desno);

  // Racunamo razdaljinu najdaljeg cvora u oba podstabla
	int tmp = 0;
	if(koren->levo)
		tmp++;
	if(koren->desno)
		tmp++;
	dim = levo_visina + desno_visina + tmp;

  // Ako je ova vrednost veca od trenutne vrednosti
  // dijameta, azuriramo promenljivu
	if(dim > dijametar)
		dijametar = dim;


  // Kao rezultat vracamo dubinu stabla, kao vecu
  // od dubina dva podstabla, uvecanu za jedan
	return max(levo_visina, desno_visina) + 1;
}

int main()
{
	Cvor* koren = nullptr;
	int x;
	cout << "Unesite cvorove stabla" << endl;
  // Ucitavanje stabla
	while(cin >> x)
		koren = dodaj_u_stablo(koren, x);

	cout << "Dijametar za stablo S je: " << nadjiDijametar(koren) << endl;
	return 0;
}
