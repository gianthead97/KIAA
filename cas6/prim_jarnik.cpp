#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <set>

using namespace std;



struct komparator
{
    operator()(const Edge &a, const Edge &b)
    {
        return a->weight - b->weight;
    }
};


struct Edge
{
    int source, destination, weight;
    Edge(int source, int destination, int weight)
    {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

set<pair<int,int>> MCST(vector<list<pair<int,int>>> graf,
                             priority_queue<Edge, vector<Edge>, komparator<Edge>> &hip)
{
    set<pair<int,int>> T;
    vector<bool> oznaka(graf.size(), false);
    vector<int> cena(graf.size(), INT_MAX);
    
    
    return T;
}

int main()
{
    vector<list<pair<int, int>>> graf;
    int V, E, source, destination, weight;
    cout << "Unesite broj cvorova i grana: ";
    cin >> V >> E;
    graf.resize(V);
    priority_queue<Edge, vector<Edge>, komparator<Edge> > hip;
    while(E--)
    { 
        cout << ++i << ".Unesite dva cvora i razdaljinu izmedju njih: ";
        cin >> source >> destination >> weight;
        graf[source].push_back(make_pair(destination, weight));
        hip.push(Edge(source, destination, weight));
        graf[destination].push_back(make_pair(source, weight));
    }
    set<pair<int,int>> T = MCST(graf);
    for(auto it = T.begin(); it != T.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}