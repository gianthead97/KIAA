#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

struct komparator
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.second - b.second;
    }

};

vector<int> dijkstra(vector<list<pair<int,int>>> &graf, int source)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, komparator> hip;
    vector<int> distance(graf.size(), INT_MAX);
    vector<bool> posecen(graf.size(), false);
    distance[source] = 0;
    hip.push(make_pair(source, 0));
    while(!hip.empty())
    {
        pair<int,int> tmp = hip.top();
        hip.pop();
        if(!posecen[tmp.first])
        {
            posecen[tmp.first] = true;
            for(auto it = graf[tmp.first].begin(); it != graf[tmp.first].end(); it++)
            {
                if(tmp.second + it->second > distance[it->first])
                {
                    distance[it->first] = tmp.second + it->second;
                    hip.push(make_pair(it->first, distance[it->first]));
                }
            }
        }

    }

    return distance;
}

int main()
{
    vector<list<pair<int, int>>> graf;
    int V, E, source, destination, weight;
    // cout << "Unesite broj cvorova i grana: ";
    cin >> V >> E;
    graf.resize(V);
    int i = 0;
    while(E--)
    { 
        // cout << ++i << ".Unesite dva cvora i razdaljinu izmedju njih: ";
        cin >> source >> destination >> weight;
        graf[source].push_back(make_pair(destination, weight));
    }
    // cout << "Unesite cvor iz kog zelite da saznate najkraci put: ";
    cin >> source;
    vector<int> distances = dijkstra(graf, 0);
    for(auto it = distances.begin(); it != distances.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}