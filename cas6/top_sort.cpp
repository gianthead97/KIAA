#include <iostream>
#include <vector>
#include <list>


using namespace std;

int globalni_RB = 0;

struct Graf
{
    vector<bool> oznaceni;
    vector<list<int>> lista;
    vector<int> Ul_stepen;
    vector<int> poredak;
    
    void ucitaj_graf(int n)
    {
        if(n <= 0)
        {
            cerr << "Neispravna dimenzija";
            exit(EXIT_FAILURE);
        }
        // inicijalizacija
        lista.resize(n);
        oznaceni.resize(n);
        Ul_stepen.resize(n);
        poredak.resize(n);

        for(int i = 0; i < n; i++)
        {
            Ul_stepen[i] = 0;
            lista[i].clear();
        }
        

        for(int i = 0; i < n; i++)
        {
            oznaceni[i] = false;

            int m;
            cout << "Broj suseda cvora " << i << ": ";
            cin >> m;
            cout << "Susedi cvora " << i << ":";
            for(int j = 0; j < m; j++)
            {
                int sused;
                cin >> sused;
                if(sused < 0 || sused >= n)
                {
                    cerr << "Neispravna grana";
                    exit(EXIT_FAILURE);
                }

                lista[i].push_back(sused);
            }
            cout << endl;
        }
    }

    void topolosko_sortiranje(int n)
    {
        list<int> tmp;
        for(int i = 0; i < n; i++)
            if(Ul_stepen[i] == 0)
                tmp.push_back(i);


        while(!tmp.empty())
        {
            auto i = tmp.front();
            globalni_RB++;
            tmp.pop_front();
            poredak[*i] = globalni_RB;
            for(auto it = lista[*i].begin(); it != lista[*i].end(); it++)
            {
                Ul_stepen[*it]--;
                if(Ul_stepen[*it] == 0)
                    tmp.push_back(*it);
            }
        }
    }

    void DFS(int cvor)
    {
        int n = oznaceni.size();
        if(cvor < 0 || cvor >= n)
        {
            cerr << "Neispravan pocetni cvor";
            exit(EXIT_FAILURE);
        }
        oznaci(cvor);
        for(auto it = lista[cvor].begin(); it != lista[cvor].end(); it++)
        {
            Ul_stepen[*it]++;
            if(neozancen(*it))
                DFS(*it);
        }

    }
    

    void oznaci(int cvor)
    {
        oznaceni[cvor] = true;
    }

    bool neozancen(int cvor)
    {
        return !oznaceni[cvor];
    }
};

int main()
{
    Graf g;
    int n;
    cout << "Broj cvorova u grafu: ";
    cin >> n;

    g.ucitaj_graf(n);


    for(int j = 0; j < n; j++)
        if(g.neozancen(j))
            g.DFS(j);
    
    return 0;
}