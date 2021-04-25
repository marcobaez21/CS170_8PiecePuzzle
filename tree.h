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

struct smallerheuristic{ //Honestly still not sure how or why this works, but i got this code from the link above
    bool operator()(Node* one, Node* two){
        return ((one->g()+one->h())>(two->g()+two->h()));
    }
};

class Tree {
private:
    int nodescurrinqueue; //variable that counts how many nodes are currently in queue
    int maxnodesinqueue; //varaible that counts the max number of nodes in queue at once
    priority_queue<Node*, vector<Node*>, smallerheuristic> frontier; // priority queue used for searching through tree
    vector<Node*>exploredlist; //vector used for searched nodes
    Node* root; //root of tree
public:
    Tree();
    Tree(Node*); //constructor with root
    bool hasbeenexplored(Node*); //checks if passed in Node is in explored list, returns bool
    void addtoexplored(Node*); //adds passed in Node* to explored list
    priority_queue<Node*, vector<Node*>, smallerheuristic> getfrontier(); //returns priority queue
    void addtofrontier(Node*); // adds passed in Node* to frontier
    Node* popfromfrontier(); //pops top node from frontier, returns popped node*
    int getmaxnodesinqueue(); //returns max nodes in queue
    void testtree();



};


#endif //PROJECT1_TREE_H
