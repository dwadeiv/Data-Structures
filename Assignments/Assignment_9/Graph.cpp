#include "Graph.hpp"
#include <stack>
#include <queue>

using namespace std;

void Graph::addEdge(string v1, string v2, int num){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){

            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex newV1;
                    newV1.weight = num;
                    newV1.v = vertices[j];
                    vertices[i]->adj.push_back(newV1);
                    adjVertex newV2;
                    newV2.weight = num;
                    newV2.v = vertices[i];
                    vertices[j]->adj.push_back(newV2);
                    return;
                }
            }
        }
    }
}

void Graph::addVertex(string n){
    bool exists = false;

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n){
            exists = true;
            return;
        }
    }

    if(exists == false){
        vertex * v = new vertex;
        v->name = n;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i]->name << " --> ";
        for(int j = 0; j < vertices[i]->adj.size(); j ++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
    }
}

void DFTraversal(vertex *n){
    n->visited = true;
    cout << n->name << " -> ";

    for(int i = 0; i < n->adj.size(); i++){
        if(!n->adj[i].v->visited){
            DFTraversal(n->adj[i].v);
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex){

    vertex *n;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == sourceVertex){
            n = vertices[i];
        }
    }

    DFTraversal(n);
    cout << "DONE";
}


void Graph::dijkstraTraverse(string start){

    vertex *vStart;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == start){
            vStart = vertices[i];
        }
    }

    vStart->distance = 0;
    vStart->visited = true;

    // Create a list to store the solved vertices
    // and append vStart
    vector<vertex*> visited_list;
    visited_list.push_back(vStart);

    // Set a boolean variable to let us know
    // when Dijkstra's is completed on
    // entire  graph

    bool graph_solved = false;

    while(!graph_solved){
        int minDist = INT_MAX;
        // pointer to keep track of solved node
        vertex *currNode = NULL;
        graph_solved = true;
        // iterate across list of visited vertices
        for(int i = 0; i < visited_list.size(); i++){
            vertex *n = visited_list[i];
            // now iterate s's adj list
            for(int j = 0; j<n->adj.size(); j++){
                if(!n->adj[j].v->visited){
                    // calculate the distance from vStart
                    int dist = n->distance + n->adj[j].weight;
                    // check if the distance is less than 
                    // smallest distance thus far
                    if(dist < minDist){
                        currNode = n->adj[j].v;
                        minDist = dist;
                        currNode->pred = visited_list.back();
                    }
                    
                    graph_solved = false;
                }
            }
        }

        if(!graph_solved){
            // Mark vertex as solved
            currNode->visited = true;
            // Update the new vertex shortest path
            currNode->distance = minDist;

            // Append the solved vertex to "visited list"
            visited_list.push_back(currNode);
        }
    }

}

void Graph::shortestPath(string start, string end){
    
    vertex* currVertex;
    int index = 0;
    
    dijkstraTraverse(start);
    
    while(index < vertices.size()){
        if(vertices[index]->name == end){
            currVertex = vertices[index];
        }
        index++;
    }
    
    vector<vertex*> path;
    int distance = currVertex->distance;
    
    while(currVertex->pred){
        path.insert(path.begin(), currVertex);
        currVertex = currVertex->pred;
    }

    cout << start << " -> ";
    while(path.size() > 0){
        cout << path.front()->name << " -> ";
        path.erase(path.begin());
    }

    cout << "DONE [" << distance << "]" << endl;
}


