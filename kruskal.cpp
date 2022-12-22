#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e6-1;
int root[MAX];
int nodes, edges;
vector<pair <long long, pair<int, int> > > p;
vector<pair<int,int> >T;
int parent(int a)                                                       
{
    while(root[a] != a)
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_find(int a, int b)  
{
    int d = parent(a);
    int e = parent(b);
    root[d] = root[e];
}

long long kruskal()
{
    int a, b;
    long long cost, minCost = 0;
    for(int i = 0 ; i < edges ; ++i)
    {
        a = p[i].second.first;
        b = p[i].second.second;
        cost = p[i].first;
        if(parent(a) != parent(b))  
        {
        	minCost += cost;
            union_find(a, b);
            T.push_back(make_pair(a,b));
        }
    }
    return minCost;
}

int main()
{
    long long minCost;
    for(int i = 0;i < MAX;i++)   
    {
        root[i] = i;
    }
    
    cin >> nodes >> edges;
    for(int i = 0;i < edges;i++)  
    {
        int w,s,d;
        cin >> w >> s >> d;
        p.push_back(make_pair(w, make_pair(s, d)));
    }
    
    sort(p.begin(), p.end());    
    minCost = kruskal();
    
    cout << "Minimum cost is: "<< minCost << endl;
    
    cout << "MST is: ";
    for(int i = 0; i < T.size();i++)
    {
    	cout <<"("<< T[i].first << ","<< T[i].second << ")"<< " ";
	}
    return 0;
}
