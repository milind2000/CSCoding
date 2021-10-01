#include <bits/stdc++.h>

using namespace std;

void
dfs (int src, vector < int >&visit, vector < int >adj[], int n,
     stack < int >&st)
{
  visit[src] = 1;

for (auto nbr:adj[src])
    {
      if (!visit[nbr])
	{
	  visit[nbr] = 1;
	  dfs (nbr, visit, adj, n, st);
	}
    }
  st.push (src);
}


vector < int >
topoSort (int n, vector < int >adj[])
{
  vector < int >ans;
  stack < int >st;
  vector < int >visit (n + 1, 0);
  for (int i = 0; i < n; i++)
    {
      if (visit[i] == 0)
	{
	  dfs (i, visit, adj, n, st);
	}
    }
  while (!st.empty ())
    {
      ans.push_back (st.top ());
      st.pop ();
    }
  return ans;
}



int
main ()
{
  int n;
  cin >> n;
  int e;
  cin >> e;
  vector < int >adj[n + 1];
  vector<int> indegeree(n+1,0);
  for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back (y);
      indegeree[y]++;
    }
    
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegeree[i]==0)
        q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int src = q.front();
        q.pop();
        ans.push_back(src);
        for(auto x : adj[src]){
            indegeree[x]--;
            if(indegeree[x]==0)q.push(x);
        }
    }
    for(auto x:ans)cout<<x<<" ";
  return 0;
}
