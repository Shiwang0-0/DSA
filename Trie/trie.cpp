// if the word is present, go to its reference
// if not then mark it present, and create a reference of it (with a false)
// for the last character reference (not the last character iteself, but its reference) (which is marked false), left mark it true.this will tell whether certain string ends with this specific character or not

// CHILDS are reference nodes
// if a is at root, it reference node will be the child (not the root itself)
// therefore for last character there will be an additional reference node


// a string exist if you traverse the tree and the last node you reach is the reference node with TRUE and at the same time the string to be searched also ends
// if only the string ends and the node doesnt have reference true, that means the searched string was prefix of some string because we didnt find the end reference node (true)

#include<bits/stdc++.h>
using namespace std;

class Node{ // trie node
    Node* references [26]; // contains an array of references to reference node of this particular node
    bool isEnd; // is this node the end of the tree ( would be used to determine whether the searched string is a prefix or an exact match)

    public: 

    // there might be TLE, even if you implement Trie in some IDE,
    // The TLE is happening because of undefined behavior in your Trie node.

    // You never initialize preferences[26], so they contain garbage values.
    // Then containsKey() may randomly return true, causing invalid pointer traversal and huge slowdowns/crashes.

    // so always create the constructor and initialize the things first hand

    Node(){
        isEnd = false;

        for(int i = 0; i < 26; i++){
            references[i] = NULL;
        }
    }

    // sometimes you might even get MLE ebcause of each node being skewed, make destructor for Node and Solution class
    ~Node(){
        for(int i=0;i<26;i++)
            delete references[i];
    }


    bool containsKey(char ch){
        return (references[ch-'a']!=NULL);
    }

    void put (char ch, Node* newNode){
        // whethere a character exist in current Trie Node or not is known whether its reference is NULL or not
        references[ch-'a']=newNode;
    }

    Node* getReferenceNode(char ch){
        return references[ch-'a'];
    }

    void setEnd(){
        isEnd=true;
    }

    bool isEndReference(){
        return isEnd;
    }
};


class Trie {

private:
    Node* root;

public:
    Trie() {
        root=new Node();
        root->setEnd(); // default node end is false
    }

    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        int n=word.length();

        Node* node=root; // node is the iterator of the tree
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){ // if character doesnt exist
                Node* newNode=new Node();
                node->put(word[i],newNode); // create new reference node
            }
            node=node->getReferenceNode(word[i]); // move to the reference node
        }
        node->setEnd();
    }
    
    bool search(string word) {
        int n=word.length();

        Node* node=root; // iterator of Trie
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i]))
                return false; // the word is not part of the trie
            node=node->getReferenceNode(word[i]);
        }

        if(node->isEndReference()) // only if we reached at end node upon itearting thorough the whole word, then we can say exact word is matched
            return true;
        return false; // otherwise some prefix was matched
    }
    
    bool startsWith(string prefix) {
        int n=prefix.length();

        Node* node=root;
        for(int i=0;i<n;i++){
            if(!node->containsKey(prefix[i]))
                return false; // only if word is missing then it is not a prefix
            node=node->getReferenceNode(prefix[i]);
        }

        return true; // if we completed the string, it is sure a prefix
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */