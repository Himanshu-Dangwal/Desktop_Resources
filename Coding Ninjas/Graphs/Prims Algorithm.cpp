#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int findMin(int *weight,int v,bool *visited){
    int index = -1;
    int min = INT_MAX;
    for(int i=0;i<v;i++){
        // if(weight[i+1]<min){
        //     min = weight[i+1];
        //     index = i+1;
        // }
        if(weight[i]<min && !visited[i]){
            min = weight[i];
            index = i;
        }
    }
    return index;
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    //Creating an adjacency matrix::
    int **g = new int*[v];
    //Making an adjacency list ans initialising it
    for(int i=0;i<v;i++){
        g[i] = new int[v];
        for(int j=0;j<v;j++){
            g[i][j] = 0;
        }
    }
    //Taking input in the adjacency matrix::
    for(int i=0;i<e;i++){
        int ei,ej,w;
        cin>>ei>>ej>>w;
        g[ei][ej] = w;
        g[ej][ei] = w;
    }
    //Initialising visited array
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    //Initialising weight array for any node
    int *weight = new int[v];
    weight[0] = 0;
    for(int i=1;i<v;i++){
        weight[i] = INT_MAX;
    }
    //Initialising parent for every node
    int *parent = new int[v];
    parent[0] = -1;
    for(int i=1;i<v;i++){
        parent[i] = INT_MIN;
    }
    for(int i=0;i<v-1;i++){
		int currentNode = findMin(weight,v,visited);//Use priority queue instead::
        visited[currentNode] = true;
        for(int j=0;j<v;j++){
            if(g[currentNode][j]>0 && !visited[j]){
                // if(currentNode==3){
                //     cout<<"Himanshu";
                // }
                if(weight[j]>g[currentNode][j]){
                    // cout<<j<<endl;
                    weight[j] = g[currentNode][j];
                    parent[j] = currentNode;
                }
            }
        }
    }
    for(int i=1;i<v;i++){
		if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }  
    delete[] parent;
    delete[] weight;
    delete[] visited;
    for(int i=0;i<v;i++){
        delete[] g[i];
    }
    delete[] g;
    return 0;
}














