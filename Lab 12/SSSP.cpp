#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//A node to represent each city
struct Node{
    int time;       
    int index;
    Node(int index){
        this -> index = index;      //initialize the shortest time to infinity and give each node an aindex
        this -> time = 99999;       
    }
};
//
class NodeCompare{
    public:
        bool operator()(Node* below, Node* above){
            if(below -> time < above -> time)
                return true;
            return false;
        }
};

void dijkstra(int G[6][6], int n, int src){

    vector<Node*> cities;           //create a vector array of cities

    for(int i= 0; i < n; i++){        
        Node* city = new Node(i);
        cities.push_back(city);
    }
    
    cities[src] -> time = 0;
    priority_queue<Node*, vector<Node*>, NodeCompare> priority_q;
    Node* start = new Node(src);
    priority_q.push(start);


    while(!priority_q.empty()){
     
        Node* node = priority_q.top();
        priority_q.pop();
        int u = node->index;
        for(int v = 0; v < n; v++){
            if(G[u][v] != 0 && cities[u]->time + G[u][v] < cities[v] -> time ){
                cities[v] -> time = cities[u] -> time + G[u][v];
                Node* city = new Node(v);
                priority_q.push(city);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(i != src)
            cout << "distance from the node " << src << " to node " << i << " is " << cities[i] -> time<< endl;
    }
}
int main(){
    int G[6][6] =
        {{0, 10, 0, 0, 15, 5}, 
         {10 ,0, 10, 30, 0, 0}, 
         {0,10, 0, 12, 5, 0}, 
         {0, 30, 12, 0, 0, 20}, 
         {15, 0, 5, 0, 0, 0}, 
         {5, 0, 0, 20, 0, 0}};
    int n = 6;
    int src = 5;
    dijkstra(G,n,src);
    return 0;
}