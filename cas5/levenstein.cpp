#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void ispisi_levenstein_tabelu(string &rec1, string &rec2);
int popuni_polje(char slovo1, char slovo2, int gornje_polje, int levo_polje, int gore_dijagonalno_polje);
void rekonstrukcija(vector<vector<int>> matrica, string &rec1, string &rec2);
int min3(int desno, int dole, int dijagonalno, int* indeks);    
int main()
{
    string rec;
    string uzorak;

    cout << "Unesite prvu rec: ";
    cin >> rec;

    cout << "Unesite drugu rec: ";
    cin >> uzorak;

    ispisi_levenstein_tabelu(rec, uzorak);

    return 0;
}

void ispisi_levenstein_tabelu(string &rec1, string &rec2)
{
    int duzina1 = rec1.length() + 1;
    int duzina2 = rec2.length() + 1;

    vector<vector<int>> matrica(duzina1);
    for(int i = 0; i < duzina1; i++)
        matrica[i].resize(duzina2);


    //Popunjavamo prvi red matrice redom brojevima 0 1 2 3 4 5...
    for(int j = 0; j < duzina2; j++)
        matrica[0][j] = j;

    //Popunjavamo prvu kolonu matrice redom brojevima 0 1 2 3 4 5...
    for(int i = 0; i < duzina1; i++)
        matrica[i][0] = i;

    //Popunjavanje matrice
    for(int i = 1; i < duzina1; i++)
        for(int j = 1; j < duzina2; j++)
        {
            char slovo1 = rec1.at(i-1);
            char slovo2 = rec2.at(j-1);
            matrica[i][j] =
             popuni_polje(slovo1, slovo2, matrica[i-1][j], matrica[i][j-1], matrica[i-1][j-1]);
         }
    //Ispis matrice
    for(int i = 0; i < duzina1; i++)
    {
        for(int j = 0; j < duzina2; j++)
            printf("%d ", matrica[i][j]);
        putchar('\n');
    }

    // Rekonstrukcija
    rekonstrukcija(matrica, rec1, rec2);


}

//Funkcija za popunjavanje trazenog polja
int popuni_polje(char slovo1, char slovo2, int gornje_polje, int levo_polje, int gore_dijagonalno_polje)
{
    if (slovo1 != slovo2)
        gore_dijagonalno_polje++;
    gornje_polje++;
    levo_polje++;
    int min = gornje_polje;
    if (levo_polje < min)
        min = levo_polje;
    if (gore_dijagonalno_polje < min)
        min = gore_dijagonalno_polje;
    return min;
}

void rekonstrukcija(vector<vector<int>> matrica, string &rec1, string &rec2)
{
    
    int n = matrica.size();
    int m = matrica[0].size();
    int i = 0, j = 0;
    while(i != n && j != m)
    {
        int min, indeks = 0;
        int desno = INT_MAX, dole = INT_MAX, dijagonalno = INT_MAX;
        if(j != m)
            desno = matrica[i][j+1];
        if(i != n)
            dole = matrica[i+1][j];
        if(i != n && j != m)
            dijagonalno = matrica[i+1][j+1];

        min = min3(desno, dole, dijagonalno, &indeks);

        switch(indeks)
        {
            case 1:
                if(matrica[i][j] != dijagonalno)
                    cout << "Zamenjena su slova " << rec1.at(i) << " i " << rec2.at(j) << endl;
                i++; j++;
                break;
            case 2:
                if(matrica[i][j] != dole)
                    cout << "Obrisano je slovo " << rec1.at(i) << endl;
                i++;
                break;    
            case 3:
                if(matrica[i][j] != desno)
                    cout << "Dodato je slovo " << rec2.at(j) << endl; 
                j++;
                break;
        }


    }
        
}

int min3(int desno, int dole, int dijagonalno, int* indeks)
{
    *indeks = 1;
    int min = dijagonalno;
    if(min > dole)
    {
        *indeks = 2;
        dole = min;
    }
    if(min > desno)
    {
        *indeks = 3;
        min = desno;
    }
    return min;
}