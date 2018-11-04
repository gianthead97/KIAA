#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

struct Graf
{
    vector<bool> oznaceni;
    vector<list<int>> lista;
    stack<int> topoloski_poredak;
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

        for(int i = 0; i < n; i++)
            lista[i].clear();

        

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
            if(neozancen(*it))
                DFS(*it);
        }
        topoloski_poredak.push(cvor);

    }
    

    void oznaci(int cvor)
    {
        oznaceni[cvor] = true;
    }

    bool neozancen(int cvor)
    {
        return !oznaceni[cvor];
    }
    void print_top_poredak()
    {
        while(!topoloski_poredak.empty())
        {
            cout << topoloski_poredak.top() << " ";
            topoloski_poredak.pop();
        }
        cout << endl;
    }
};

int main()
{
    Graf g;
    int n;
    cout << "Broj cvorova u grafu: ";
    cin >> n;

    g.ucitaj_graf(n);


    while(g.topoloski_poredak.size() != n)
    {
        for(int j = 0; j < n; j++)
            if(g.neozancen(j))
                g.DFS(j);
    }
    g.print_top_poredak();
    return 0;
}