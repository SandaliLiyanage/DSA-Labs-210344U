#include <iostream>
using namespace std;

int minKey(int key[], bool mst_set[], int V){
    
    int min = INT_MAX;          //initialize the minimum values.
    int min_index;

    //find the minimum weight edge that connects to a vertex that is not yet included in the mst_set.
    for(int i = 0; i < V; i++ ){
        if(!mst_set[i] && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}
void MST(int graph[6][6], int V){

    int parent[V];      //a list to store the parent vertex.
    int key[V];         //a list to update the minimum
    bool mst_set[V];

    for(int i = 0; i < V; i++){         //initialize the lists key and mst_set
        key[i] = INT_MAX;               
        mst_set[i] = false;             //No verteces in the MST at the beginning
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V-1; i++){

        int u = minKey(key,mst_set, V);     //find the minimum edge.
        mst_set[u] = true;                  //add the vertex connected to the minimum edge into the mstSet.

        for(int v = 0; v < V; v++){
            if(graph[u][v] && mst_set[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];       //update the key value if the values in the graph in relevent to u is greater than zero and less than the existing value
            }
        }
    }
    for (int i = 0; i < V; i++)
        if(parent[i]!=-1){
            cout << parent[i] << " - " << i << " \t"<< graph[i][parent[i]] << " \n";
        }
}
int main(){
    int V = 6;          //number of verteces.
    int G[6][6]  = {{0, 3, 0, 0, 0, 1},
                   {3, 0, 2, 1, 10, 0},
                   {0, 2, 0, 3, 0, 5},
                   {0, 1, 3, 0, 5, 0},
                   {0, 10, 0, 5, 0, 4},
                   {1, 0, 5, 0, 4, 0}};
                   

    MST(G, V);
}