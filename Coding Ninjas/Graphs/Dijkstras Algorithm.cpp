#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getMin(int *distance,int v,bool *visited){
    int index = -1;
    int min = INT_MAX;
    for(int i=0;i<v;i++){
        if(!visited[i] && distance[i]<min){
            min = distance[i];
            index = i;
        }
    }
    return index;
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **g = new int*[v];
    for(int i=0;i<v;i++){
        g[i] = new int[v];
        for(int j=0;j<v;j++){
			g[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int ei,ej,w;
        cin>>ei>>ej>>w;
        g[ei][ej] = w;
        g[ej][ei] = w;
    }
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    int *distance = new int[v];
    for(int i=1;i<v;i++){
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for(int i=0;i<v-1;i++){
        int currentNode = getMin(distance,v,visited);
        visited[currentNode] = true;
        for(int j=0;j<v;j++){
            if(!visited[j] && g[currentNode][j]!=0){
                if(distance[j] > distance[currentNode]+g[currentNode][j]){
                    distance[j] = distance[currentNode]+g[currentNode][j];
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete[] distance;
    delete[] visited;
    for(int i=0;i<v;i++){
        delete[] g[i];
    }
    delete[] g;
    return 0;
}
