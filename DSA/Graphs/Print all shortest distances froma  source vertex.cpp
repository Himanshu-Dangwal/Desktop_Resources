#include<bits/stdc++.h>
using namespace std;

#define PII pair<int,int>

class Triplet{
    public:
        int src;
        string psf;
        int weight;
        
        Triplet(int sr,string s,int w){
            this->src = sr;
            this->psf = s;
            this->weight = w;
        }
};

// struct compare{
// 	bool operator()(const Triplet &a,const Triplet &b){
// 		return a.weight < b.weight;
// 	}
// };
struct compareWeight {
    bool operator()(Triplet const& p1, Triplet const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        
        if(p1.weight == p2.weight){
            string s1 = p1.psf;
            string s2 = p2.psf;
            
            return s1.length() < s2.length();
        }
        
        return p1.weight > p2.weight;
    }
};

int main(){
    int v,e;
    cin>>v>>e;
    
    vector<vector<PII>> adj(v+1);
    
    for(int i=0;i<e;i++){
//    	cout<<"Inside"<<endl;
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z}); 
        adj[y].push_back({x,z});
    }
    
    int osrc;
    cin>>osrc;
    
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    
    Triplet t(osrc,to_string(osrc) + "",0);
    priority_queue<Triplet,vector<Triplet>,compareWeight> p;
    p.push(t);
    
    while(!p.empty()){
        Triplet curr = p.top();
        p.pop();
        if(visited[curr.src]){
            continue;
        }
        visited[curr.src] = true;
        cout<<curr.src<<" via "<<curr.psf<<" @ "<<curr.weight<<endl;
        
//        cout<<p.size()<<endl;
        
        for(auto x : adj[curr.src]){
        	if(!visited[x.first]){
        		Triplet t(x.first,curr.psf + to_string(x.first),curr.weight + x.second);
            	p.push(t);
			}
        }
    }
}























