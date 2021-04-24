//
// Created by marco on 4/19/2021.
//
//Used this to figure out how to use priority queue with objects:
//https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
//

#ifndef PROJECT1_TREE_H
#define PROJECT1_TREE_H

#include "node.h"
#include <queue>
using namespace std;

struct smallerheuristic{
    bool operator()(Node* one, Node* two){
        return ((one->g()+one->h())>(two->g()+two->h()));
    }
};

class Tree {
private:
    int nodescurrinqueue;
    int maxnodesinqueue;
    priority_queue<Node*, vector<Node*>, smallerheuristic> frontier; //FIX
    vector<Node*>exploredlist;
    Node* root;
public:
    Tree();
    Tree(Node*);
    bool hasbeenexplored(Node*);
    void addtoexplored(Node*);
    priority_queue<Node*, vector<Node*>, smallerheuristic> getfrontier();
    void addtofrontier(Node*);
    Node* popfromfrontier();
    int getmaxnodesinqueue();
    void testtree();



};


#endif //PROJECT1_TREE_H
