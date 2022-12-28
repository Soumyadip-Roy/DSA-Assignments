#include <bits/stdc++.h>
using namespace std;

#define INF 9999
const int N = 1e3;

int graph[N][N];

void Dijkstra(int src, int v)
{
    int dist[v];
    int vis[v];

    for (int i = 0; i < v; i++)
    {
        dist[i] = INF;
        vis[i] = 0;
    }

    dist[src] = 0;
    int u = src;

    for (int it = 0; it < v; it++)
    {
        vis[u] = 1;
        int mn = INF;

        for (int i = 0; i < v; i++)
        {
            // dist of all the vertex connected to u are updated if they are visited
            if (!vis[i] and dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
            cout << dist[i] << " ";
        }
        cout << endl;

        // finding the minimum distance
        for (int i = 0; i < v; i++)
        {
            if (!vis[i] and dist[i] < mn)
            {
                mn = dist[i];
                u = i;
            }
        }
        cout << u << endl;
    }

    for (int i = 0; i < v; i++)
    {
        if (i != src)
            cout << src << "--> " << i << " : " << dist[i] << "\n";
    }
}

int main()
{

    while (true)
    {
        cout << "1 - Add a New Graph\n";
        cout << "2 - Calculate Shortest Distance\n";
        cout << "0 - EXIT\n";
        cout << "Enter your choice :  ";

        int v, op = 0, op1 = 1, src = 0, dest = 0, weight = 0;

        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Enter the number of vertices : ";
            cin >> v;

            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    graph[i][j] = INF;
                }
            }

            while (op1)
            {
                cout << "1. Add Edges" << endl;
                cout << "2. Delete Edge" << endl;
                cout << "0. Main Menu" << endl;
                cout << "Enter your choice : ";

                cin >> op1;

                switch (op1)
                {
                case 1:
                    cout << "Enter the number of edges you want to add : ";
                    int op2;
                    cin >> op2;
                    for (int i = 0; i < op2; i++)
                    {
                        cout << "Enter the first vertex : ";
                        cin >> src;
                        cout << "Enter the second vertex : ";
                        cin >> dest;
                        cout << "Enter the weight of the edge : ";
                        cin >> weight;

                        graph[src][dest] = weight;
                        graph[dest][src] = weight;
                    }
                    break;
                case 2:
                    cout << "Enter the first vertex : ";
                    cin >> src;
                    cout << "Enter the second vertex : ";
                    cin >> dest;

                    graph[src][dest] = INF;
                    graph[dest][src] = INF;
                    break;
                default:
                    op1 = 0;
                    break;
                }
            }
            // for (int i = 0; i < v; i++)
            // {
            //     for (int j = 0; j < v; j++)
            //     {
            //         cout << graph[i][j];
            //     }
            //     cout << endl;
            // }
            break;
        case 2:
            cout << "Enter the source vertex : ";
            cin >> src;

            Dijkstra(src, v);
            break;

        case 0:
            break;
        default:
            cout << "Invalid Choice !";
        }
    }
}
