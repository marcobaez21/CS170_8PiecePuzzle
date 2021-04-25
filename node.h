//
// Created by marco on 4/18/2021.
//

#ifndef PROJECT1_NODE_H
#define PROJECT1_NODE_H

#include "problem.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
private:
    Node* parent;
    Node* left;
    Node* down;
    Node* right;
    Node* up;
    Problem NodeProblem;
    Node* moveleft(vector<int>, int, string, int, Node*); //changes puzzle vector to move the zero left
    Node* movedown(vector<int>, int, string, int, Node*); // changes puzzle vector to move the zero down
    Node* moveright(vector<int>, int, string, int, Node*); //changes puzzle vector to move the zero right
    Node* moveup(vector<int>, int, string, int, Node*); //changes puzzle vector to move the zero up
    int heuristic; // the "h" value of the heuristic
    int UCS; // the "g" value of the heuristic
    string heuristicstring; // used to see if were using eucledian or misplaced
public:
    Node();
    Node(vector<int>, string, int, Node*); //constructor with puzzle, string heauristic and parent node*
    Node* getParent(); // returns parent
    Node* getChild(string); // returns child
    vector<int> getPuzzle(); //returns puzzle vector
    void expand(); //expands a node*, uses the moveleft-moveup functions
    int getHeuristic(string); //calculates and returns heaurstic value
    int g(); //returns UCS or "g" value
    int h(); //returns heauristic or "h" value
    bool isgoal(); //returns bool of current node is goal puzzle

};

#endif //PROJECT1_NODE_H
