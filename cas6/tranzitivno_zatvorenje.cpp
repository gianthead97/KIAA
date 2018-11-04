#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Graf
{
    vector<vector<bool>> matrica;
    int V;

    public:
        Graf();
        void tranzitivno();

};

void Graf::tranzitivno()
{
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            if(matrica[i][k])
                for(int j = 0; j < V; j++)
                    if(matrica[k][j])
                        matrica[i][j] = true;

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            printf("%d ", matrica[i][j] ? 1 : 0);
        putchar('\n');
    }
}

Graf::Graf()
{
    cout << "Koliki je broj cvorova: ";
    cin >> V;
    matrica.resize(V);
    for(int i = 0; i < V; i++)
        matrica[i].resize(V, false);

    int E;
    cout << "Unesi broj grana: ";
    cin >> E;
    int m = 1;
    while(E--)
    {
        int source, destination;
        cout << "Unesi " << m++ << ".granu (pocetni i krajnji cvor):  ";
        cin >> source >> destination;
        matrica[source][destination] = true;
    }
}


int main(int argc, char const *argv[])
{
    Graf g = Graf();
    g.tranzitivno();
    return 0;
}
