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
    Node* moveleft(vector<int>, int, string, int, Node*);
    Node* movedown(vector<int>, int, string, int, Node*);
    Node* moveright(vector<int>, int, string, int, Node*);
    Node* moveup(vector<int>, int, string, int, Node*);
    int heuristic;
    int UCS;
    string heuristicstring;
public:
    Node();
    Node(vector<int>, string, int, Node*);
    Node* getParent();
    Node* getChild(string);
    vector<int> getPuzzle();
    void expand();
    int getHeuristic(string);
    int g();
    int h();
    bool isgoal();

};

#endif //PROJECT1_NODE_H
