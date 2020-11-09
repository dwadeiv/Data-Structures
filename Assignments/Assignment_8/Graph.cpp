#include "Graph.hpp"
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

static void DFTraversal(vertex *n);

using namespace std;

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

void Graph::addEdge(string v1, string v2){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){

            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex newV1;
                    newV1.v = vertices[j];
                    vertices[i]->adj.push_back(newV1);
                    adjVertex newV2;
                    newV2.v = vertices[i];
                    vertices[j]->adj.push_back(newV2);
                    return;
                }
            }
        }
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

void Graph::breadthFirstTraverse(string sourceVertex){
    // Find source vertex
    vertex *vStart;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == sourceVertex){
            vStart = vertices[i];
        }
    }

    vStart->visited = true;
    cout << "Starting vertex (root): " << vStart->name << "-> ";
    queue<vertex*> q;
    q.push(vStart);
    vertex *n;

    // Basic BFS
    while(!q.empty()){
        n = q.front();
        q.pop();
        for(int j = 0; j < n->adj.size(); j++ ){
            if(!n->adj[j].v->visited){
                q.push(n->adj[j].v);
                n->adj[j].v->visited = true;
                n->adj[j].v->distance = (n->distance + 1);
                cout << n->adj[j].v->name << "(" << n->adj[j].v->distance << ") ";
            }
        }
    }
}

static void DFTraversal(vertex *n)
{
    n->visited = true;

    for(int i = 0; i < n->adj.size(); i++ ){
        if(!n->adj[i].v->visited){
            DFTraversal(n->adj[i].v);
        }
    }
}

int Graph::getConnectedComponents(){

    int number_of_components = 0;

    for(int i = 0; i < vertices.size(); i ++){
        if(!vertices[i]->visited){
            DFTraversal(vertices[i]);
            number_of_components++;
        }
    }
    return number_of_components;
}