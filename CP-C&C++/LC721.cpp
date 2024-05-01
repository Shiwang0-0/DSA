/*

class Solution {

private:

    int findUltParent(int node,vector<int>&parent)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUltParent(parent[node],parent);
    }

    void connect(int u,int v,vector<int>&size,vector<int>&parent)
    {
        int ultU=findUltParent(u,parent);
        int ultV=findUltParent(v,parent);
        if(ultU==ultV)
        {
            return;
        }
            
        if(size[ultU]>size[ultV])
        {
            parent[ultV]=ultU;
            size[ultU]=size[ultU]+size[ultV];
        }
        else
        {
            parent[ultU]=ultV;
            size[ultV]=size[ultU]+size[ultV];
        }
    }

public:

    // we need to have atleast 1 mail in common, means then the users are same,even if in accounts matrix they are kept on different indexs.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();
        vector<int>size(n,1);
        vector<int>parent(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        // we need map.
        // why? 
        // to store the user with their "many associated accounts" which are distributed across the whole
        // accounts matrix.
        // map will help in keeping them collectively and will also associate a unique number for the user.
        unordered_map<string,int>um;  // <mails,index>

        // going thorugh all the mails of different (or maybe same/repeated) user
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++) // skiping the first one because it holds users name.
            {
                string mail=accounts[i][j];
                if(um.find(mail)!=um.end()) // if mail is in map,means it is not fresh,means it has a connection.
                {
                    connect(i,um[mail],size,parent);
                }
                else
                {
                    um[mail]=i; // no connection, therefore add to map.
                }   
            }
        }
        vector<string>emailList[n];  // bonds different user with their connected mails.
        for(auto it:um)
        {
            string mail=it.first;
            int index=it.second;
            int ultParent=findUltParent(index,parent); // remember to bond with the ult parent.
            emailList[ultParent].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        { 
            if(emailList[i].size()==0) // see first example, jhon of index 2 will be empty.
            // as all its elements are now connected to jhon of index 1. so skip the repeated jhon.
                continue;
            sort(emailList[i].begin(),emailList[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]); // pushing name as name of email holder should be the first.
            for(auto it:emailList[i])
            {
                temp.push_back(it); // pushing respective and connected mails
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

*/