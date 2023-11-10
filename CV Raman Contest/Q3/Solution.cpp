//[C++]
#include <bits/stdc++.h>
using namespace std;

class clss
{
    public:

    int n, logN;
    int tmr;
    vector<int> ti, to;
    vector<vector<int>> up;
    vector<int> ht;

    clss(vector<vector<int>> &tree, int N)
    {
        logN = ceil(log2(N));
        ti.resize(N);
        to.resize(N);
        up.resize(N);
        ht.resize(N);

        for(int i=0; i<N; i++)
            up[i].resize(logN+1, 0);

        DFS(tree, 0, 0);
    }

    void DFS(vector<vector<int>> &tree, int v, int p)
    {
        ti[v] = ++tmr;
        up[v][0] = p;

        for(int i=1; i<=logN; i++)
            up[v][i] = up[up[v][i-1]][i-1];

        for(auto c: tree[v])
        {
            if(c == p)         continue;

            ht[c] = 1+ht[v];
            DFS(tree, c, v);
        }

        to[v] = ++tmr;
    }

    bool ances(int p, int c)
    {
        return (ti[p]<=ti[c] && to[p]>=to[c]);
    }

    int getclss(int u, int v)
    {
        if(ances(u, v))       return u;
        if(ances(v, u))       return v;

        for(int i=logN; i>=0; i--)
        {
            if(!ances(up[u][i], v))
                u = up[u][i];
        }

        return up[u][0];
    }

    int _par(int u, int val)
    {
        int p = u;

        while(val > 0 &&  p>0)
        {
            for(int i=0; i<=logN; i++)
            {
                if((1ll<<(i+1)) > val)
                {
                    p = up[p][i];
                    val -= (1ll<<i);
                    break;
                }
            }
        }

        return p;
    }
};

int main()
{
    int test;
    cin>>test;

    assert(test>=1 && test<=1e5);

    int totalN = 0;
    int totalM = 0;

    while(test--)
    {
        int N;
        cin>>N;

        assert(N>=3 && N<=2e5);
        totalN += N;

        vector<vector<int>> tree(N);
        for(int i=0; i<N-1; i++)
        {
            int u, v;
            cin>>u>>v;

            assert(u>=1 && u<=N);
            assert(v>=1 && v<=N);

            u--, v--;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        clss obj(tree, N);

        int M;
        cin>>M;

        assert(M>=1 && M<=2e5);
        totalM += M;

        vector<int> ver;

        while(M--)
        {
            int A, B, C;
            cin>>A>>B>>C;

            assert(A>=1 && A<=N);
            assert(B>=1 && B<=N);
            assert(C>=1 && C<=N);
            assert(A!=B && A!=C && B!=C);

            A--, B--, C--;

            ver = {A, B, C};
            sort(ver.begin(), ver.end());

            int possible = 0;

            do{
                if(obj.ances(ver[1], ver[0]))
                {
                    if(!obj.ances(obj._par(ver[0], obj.ht[ver[0]]-obj.ht[ver[1]]-1), ver[2]))
                    {
                        possible = 1;
                        break;
                    }
                }
            }while(next_permutation(ver.begin(), ver.end()));

            if(possible)        cout<<"Yes\n";
            else                cout<<"No\n";
        }
    }

    assert(totalN<=2e5);
    assert(totalM<=2e5);
}