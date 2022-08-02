#include <iostream>
#include <map>
using namespace std;
const int sizeofGraph = 9;

void dijkstra(int graph[sizeofGraph][sizeofGraph],int size, int target);
void readout(map<int, int>prev, map<int, int>dist, int target);

int main()
{
    
    /*int graph[sizeofGraph][sizeofGraph] = { {0,5,0,7},
                                            {5,0,1,0},
                                            {0,1,0,1},
                                            {7,0,1,0} };*/
    int graph2[sizeofGraph][sizeofGraph] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


    cout << "The shortest path found through Dijkstra's algorithm is ";
    //dijkstra(graph, sizeofGraph, 3);
    dijkstra(graph2, sizeofGraph, 4);
}

void dijkstra(int graph[sizeofGraph][sizeofGraph], int size, int target) {
    //init
    int inf = INT_MAX;
    //dist
    map<int,int>dist;
    //prev
    map<int, int>prev;
    //hasVisited
    map<int, bool>hasVisited;

    for (int i = 0; i < size; i++) {
        dist[i] = inf;
        prev[i] = -1;
        hasVisited[i] = false;
    }

    dist[0] = 0;

    //for loop iterating through the graph
    for (int i = 0; i < size; i++) {
        //finding u
        int u = -1;
        for (int k = 0; k < size; k++) {
            if (!hasVisited[k]) {
                if (u == -1 || dist[k] < dist[u] ) {
                    u = k;
                }
            }
        }
        //found u
        hasVisited[u] = true;
        // check the distances and compare
        for (int j = 0; j < size; j++) {
            if (!hasVisited[j] && graph[u][j] != 0) {
                int alt = dist[u] + graph[u][j];
                if (alt < dist[j] && dist[u] != inf) {
                    dist[j] = alt;
                    prev[j] = u;
                }
            }
        }
    }
    readout(prev, dist, target);
}
void readout(map<int, int>prev, map<int, int>dist,int target) {
    int u = target;
    
    cout << dist[target] << " long and went through these nodes:";

    if (prev[u] != -1) {
        while (u != -1) {
            
            cout << " " << u;
            u = prev[u];
        }
        cout << endl;
    }
}