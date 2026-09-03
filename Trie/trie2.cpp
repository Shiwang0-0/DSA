// LINK: https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM


#include<bits/stdc++.h>
using namespace std;


class Node{

    Node* references[26];
    int ew; // ending With
    int sw; // starting with

    // the SW and EW are always stored in the reference node for the current node
    // that means first traverse to the reference node, 
    // then increment the count of sw
    // you do this, because suppose we save the info of root node at the root node itself
    // and there can be 26 different ways to start at the root node
    // how will you tell that this info belongs to this reference (say A and not B)
    // thats why we sav it in the reference, because reference of A and B will differ for sure

    // dont need isEnd, because we have EW, and we dont need to tell in boolean


    public:
        Node(){
            ew=0,sw=0;
        }

        void incrementSW(){
            sw++;
        }
        void incrementEW(){
            ew++;
        }
        void decrementSW(){
            sw--;
        }
        void decrementEW(){
            ew--;
        }

        int getSW(){
            return sw;
        }
        int getEW(){
            return ew;
        }

        bool containsKey(char ch){
            return (references[ch-'a']!=NULL); // if reference is not null, that it contains key
        }

        void put(char ch, Node* newNode){
            references[ch-'a']=newNode;
        }

        Node* getReferenceNode(char ch){
            return references[ch-'a'];
        }

};

class Trie{

private: Node* root;


    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        int n=word.length();

        Node* node=root; // iterator
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){ // if doesnt contain, insert it
                Node* newNode=new Node();
                node->put(word[i], newNode); // add the reference node
            }
            node=node->getReferenceNode(word[i]); // move the iterator to the reference node
            node->incrementSW(); // In the reference node: increment the prefix count
        }
        
        node->incrementEW(); // increment ending with, once you reach the end of the word

    }

    int countWordsEqualTo(string &word){
        int n=word.length();

        Node* node=root; // iterator
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                return 0; // doesnt even match the whole word
            }
            node=node->getReferenceNode(word[i]); // move the iterator to the reference node
        }

        // when the whole word was matched
        return node->getEW();
    }

    int countWordsStartingWith(string &word){
        int n=word.length();

        Node* node=root; // iterator
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                return 0; // doesnt even match the whole word
            }
            node=node->getReferenceNode(word[i]); // move the iterator to the reference node
        }

        // when the whole word was matched
        return node->getSW();
    }

    void erase(string &word){
        // Write your code here.
        //If erase(WORD) function is called then it is guaranteed that the WORD is present in the TRIE.
        // this condition is important to prevent from SW,EW goes -ve

        // another way is to iteratre thorugh the trie and first check whether the word actually exist in the tree or not
        // only it it exist then do the erase functionality

        int n=word.length();

        Node* node=root; // iterator
        for(int i=0;i<n;i++){

            // it is made sure that the word exist in trie, so no need for this check
            // if(!containsKey(word[i])){
            //     return; // doesnt even match the whole word
            // }

            //decrement the sw count
            node=node->getReferenceNode(word[i]); // move the iterator to the reference node
            node->decrementSW(); // from the reference node: decrement the sw
        }

        node->decrementEW();
    }
};
