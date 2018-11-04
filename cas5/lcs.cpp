#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void ispisi_lcs_tabelu(string &rec1, string &rec2);
int popuni_polje(char slovo1, char slovo2, int gornje_polje, int levo_polje, int gore_dijagonalno_polje);

int main()
{
    string rec;
    string uzorak;

    cout << "Unesite prvu rec: ";
    cin >> rec;

    cout << "Unesite drugu rec: ";
    cin >> uzorak;

    ispisi_lcs_tabelu(rec, uzorak);

    return 0;
}

void ispisi_lcs_tabelu(string &rec1, string &rec2)
{
    int duzina1 = rec1.length() + 1;
    int duzina2 = rec2.length() + 1;

    vector<vector<int>> matrica(duzina1);
    for(int i = 0; i < duzina1; i++)
        matrica[i].resize(duzina2);



    for(int j = 0; j < duzina2; j++)
        matrica[0][j] = 0;

   
    for(int i = 0; i < duzina1; i++)
        matrica[i][0] = 0;

    //Popunjavanje matrice
    for(int i = 1; i < duzina1; i++)
        for(int j = 1; j < duzina2; j++)
        {
            char slovo1 = rec1.at(i-1);
            char slovo2 = rec2.at(j-1);
            matrica[i][j] = popuni_polje(slovo1, slovo2, matrica[i-1][j], matrica[i][j-1], matrica[i-1][j-1]);
         }
    //Ispis matrice
    for(int i = 0; i < duzina1; i++)
    {
        for(int j = 0; j < duzina2; j++)
            printf("%d ", matrica[i][j]);
        putchar('\n');
     }


}

//Funkcija za popunjavanje trazenog polja
int popuni_polje(char slovo1, char slovo2, int gornje_polje, int levo_polje, int gore_dijagonalno_polje)
{
    if (slovo1 == slovo2)
        gore_dijagonalno_polje++;
    
    int max = gornje_polje;
    if (levo_polje > max)
        max = levo_polje;
    if (gore_dijagonalno_polje > max)
        max = gore_dijagonalno_polje;
    return max;
}
