
#include<bits/stdc++.h>
using namespace std;
void dfs(int s, vector<int> g[], bool vis[])
{   
vector<int>::iterator i;
    if(vis[s]==0){
        cout<<s<<" ";
        vis[s]=1;
        for(i=g[s].begin();i!=g[s].end();i++){
            if(vis[s]!=0){
                dfs(*i,g,vis);
            }
        }
    }
    
}
int main()
{
    
        int N, E;//number of vertices and number of edges
        cin>>N>>E;
        
        vector<int> g[N+1];
        bool vis[N+1]={false};
        
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int startVertex;
        cout<<"\nEnter the starting vertex from where you want to do dfs = ";
        cin>>startVertex;
        cout<<"\n";
        dfs(startVertex,g,vis);
        
        cout<<endl;
}



