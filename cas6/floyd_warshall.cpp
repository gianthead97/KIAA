#include <iostream>
#include <vector>
#include <cstdio>
#include <list>
#include <climits>

#define INF 100000

using namespace std;


class Graf
{
    int V, E;
    int source, destination;
    vector<list<pair<int, int>>> graf;
    vector<vector<int>> matrica;
    vector<vector<int>> P;
    public:
        Graf();
        void floydWarshall();
        void printPath(int i, int j);
};

Graf::Graf()
{
    int m = 0;
    cin >> V >> E;
    graf.resize(V);
    while(E--)
    {
        cout << ++m << ".Unesite dva cvora i razdaljinu izmedju njih: ";
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graf[source].push_back(make_pair(destination, weight));
        graf[destination].push_back(make_pair(source, weight));

    }
    char i, j;
    cout << "Od kog do kog cvora zelite da nadjete putanju(karaktera) ? ";
    cin >> i >> j;
    i -= 'a'; 
    j -= 'a';
    source = i;
    destination = j;
}

void Graf::printPath(int i, int j)
{
    if(i == j)
        printf("%c ", 'a' + i);
    else
    {
        if(P[i][j] == -1)
            cout << "Ne postoji put izmedju dva cvora";
        else
        {
            printPath(i, P[i][j]);
            printf("%c ", 'a' + j);
        }
    }
}

void Graf::floydWarshall()
{
    P.resize(V);
    matrica.resize(V);
    for(int i = 0; i < V; i++)
    {
        matrica[i].resize(V, INF);
        P[i].resize(V, 0);
    }
    for(int i = 0; i < V; i++)
        matrica[i][i] = 0;
    

    for(int i = 0; i < V; i++)
        for(auto it = graf[i].begin(); it != graf[i].end(); it++)
            matrica[i][it->first] = it->second; 

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
        {
            if(i == j || matrica[i][j] == INF)
                P[i][j] = -1;
            else
                P[i][j] = i;
        }

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(matrica[i][j] > matrica[i][k] + matrica[k][j])
                {
                    matrica[i][j] = matrica[i][k] + matrica[k][j];
                    P[i][j] = P[k][j];
                }


    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
            cout << (matrica[i][j] == INF ? -1 : matrica[i][j]) << " ";
        cout << endl;
    }

    printPath(source, destination);
    cout << endl;
}







int main(int argc, char const *argv[])
{
    Graf g = Graf();    
    g.floydWarshall();
    return 0;
}
