// UNION BY RANK & SIZE


#include<iostream>
#include<vector>
using namespace std;

class Disjoint{
        vector<int> rank;
        vector<int> parent;
        vector<int>size;
    public:
        Disjoint(int n)
        {
            rank.resize(n,0);
            parent.resize(n,0);
            size.resize(n,0);
            for (int i = 0; i < n; i++)
            {
                parent[i]=i;
            }
        }

        int findUltParent(int node)
        {   
            if(node==parent[node])
            {
                return node;
            }
            return parent[node] = findUltParent(parent[node]);
        }

        void unionByRank(int u,int v)
        {
            int ultU=findUltParent(u);
            int ultV=findUltParent(v);
            if(ultU==ultV)
                return;
            if(rank[ultU]>rank[ultV])
            {
                parent[ultV]=ultU;
            }
            else if(rank[ultU]<rank[ultV])
            {
                parent[ultU]=ultV;
            }
            else
            {
                parent[ultU]=ultV;
                rank[ultV]++;
            }
        }

        void unionBySize(int u,int v)
        {
            int ultU=findUltParent(u);
            int ultV=findUltParent(v);
            if(ultU==ultV)
                return;
            if(size[ultU]>size[ultV])
            {
                parent[ultV]=ultU;
                size[ultU]=size[ultV]+size[ultU];
            }
            else
            {
                parent[ultU]=ultV;
                size[ultV]=size[ultU]+size[ultV];
            }
        }
};


int main()
{
    Disjoint obj1(7);
    obj1.unionByRank(0, 1);
    obj1.unionByRank(1, 2);
    obj1.unionByRank(3, 4);
    obj1.unionByRank(5, 6);
    obj1.unionByRank(4, 5);
    
    if (obj1.findUltParent(2) == obj1.findUltParent(6)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    obj1.unionByRank(2, 6);

    if (obj1.findUltParent(2) == obj1.findUltParent(6)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    // ------------------------------------------------------------------------------------------------

    Disjoint obj2(7);
    obj2.unionBySize(0, 1);
    obj2.unionBySize(1, 2);
    obj2.unionBySize(3, 4);
    obj2.unionBySize(5, 6);
    obj2.unionBySize(4, 5);
    
    if (obj2.findUltParent(2) == obj2.findUltParent(6)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    obj2.unionBySize(2, 6);

    if (obj2.findUltParent(2) == obj2.findUltParent(6)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    return 0;
}
