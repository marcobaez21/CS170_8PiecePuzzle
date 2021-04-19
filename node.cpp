//
// Created by marco on 4/18/2021.
//

#include "node.h"
using namespace std;

Node::Node() {
    this->parent=NULL;
    this->left=NULL;
    this->down=NULL;
    this->right=NULL;
    this->NodeProblem = Problem();
    this->heuristic = 0; // Probably need to fix later
    this->UCS = 0;
    this->heuristicstring = "UCS";
}

Node::Node(vector<int> inputpuzzle, string heuristic, int c,  Node* Parent ) {
    this->parent=Parent;
    this->left=NULL;
    this->down=NULL;
    this->right=NULL;
    this->NodeProblem=Problem(inputpuzzle);
    this->heuristic = 0; // Probably need to fix later
    this->UCS=c;
    this->heuristicstring = heuristic;
}

Node* Node::getParent() {
    return this->parent;
}

Node* Node::getChild(string child) {
    if(child=="l"){ return this->left;}
    else if(child=="d"){ return this->down;}
    else if(child=="r"){ return this->right;}
    else if(child=="u"){return this->up;}
    else { return NULL;}
}

vector<int> Node::getPuzzle() {
    return this->NodeProblem.returnpuzzle();
}

Node* Node::moveleft(vector<int> input, int temp,  string h, int c, Node* p) {
    vector<int> currpuzzle = input;
    int zero = temp;
    int oldzero = currpuzzle.at(zero);
    int oldnonzero = currpuzzle.at(zero-1);
    currpuzzle.at(zero) = oldnonzero;
    currpuzzle.at(zero-1) = oldzero;
    return new Node(currpuzzle, h, c+1, p);
}

Node* Node::movedown(vector<int> input, int temp,  string h, int c, Node* p) {
    vector<int> currpuzzle = input;
    int zero = temp;
    int oldzero = currpuzzle.at(zero);
    int oldnonzero = currpuzzle.at(zero+3);
    currpuzzle.at(zero) = oldnonzero;
    currpuzzle.at(zero+3) = oldzero;
    return new Node(currpuzzle, h, c+1, p);
}

Node* Node::moveright(vector<int> input, int temp, string h, int c, Node* p){
    vector<int> currpuzzle = input;
    int zero = temp;
    int oldzero = currpuzzle.at(zero);
    int oldnonzero = currpuzzle.at(zero+1);
    currpuzzle.at(zero) = oldnonzero;
    currpuzzle.at(zero+1) = oldzero;
    return new Node(currpuzzle, h, c+1, p);
}

Node* Node::moveup(vector<int> input, int temp, string h, int c, Node* p){
    vector<int> currpuzzle = input;
    int zero = temp;
    int oldzero = currpuzzle.at(zero);
    int oldnonzero = currpuzzle.at(zero-3);
    currpuzzle.at(zero) = oldnonzero;
    currpuzzle.at(zero-3) = oldzero;
    return new Node(currpuzzle, h, c+1, p);
}

void Node::expand(){
    vector<int> puzzle = this->getPuzzle();
    vector<int> currpuzzle = puzzle;
    int zero = this->NodeProblem.returnzero();

    cout<<"Expanding this node..."<<endl;
    for(int i=0;i<9;i++){if(i%3==0 && i!=0){std::cout<<std::endl;}std::cout<<currpuzzle[i]<<" ";}

    if(zero==1 || zero==2 || zero==4 || zero==5 || zero==7 || zero==8){ // These values mean that the zero is in the second or third columns so we can move left
        this->left = moveleft(currpuzzle, zero, this->heuristicstring, this->g(), this);
    }

    if(zero<6){ //This value means that the zero is in the first or second row and so we can move down
        this->down = movedown(currpuzzle, zero, this->heuristicstring, this->g(), this);
    }

    if(zero==0 || zero==1 || zero==3 || zero==4 || zero==6 || zero==7){ //These values mean that the zero is in the first or second colums so we can move right
        this->right = moveright(currpuzzle, zero, this->heuristicstring, this->g(), this);
    }

    if(zero>2){ //This value means that the zero is in the second or third row and so we can move up
        this->up = moveup(currpuzzle, zero, this->heuristicstring, this->g(), this);
    }
}

int Node::getHeuristic(string input) {
    //FIX LATER

    int total = 0;
    vector<int> goal = {1, 2, 3, 4, 5, 6, 8, 0};
    vector<int> currpuzzle = this->getPuzzle();

    if(input=="UCS"){ return 0;}
    else if(input=="MISPLACED"){ //simply checks how many numbers are not where they are supposed to be and adds that up
        for(int i=0;i<9;i++){
            if(currpuzzle.at(i) != goal.at(i)){ //fix later and add euclidian
                ++total;
            }
        }
    }
    return total;
}

int Node::g(){
    return this->UCS;
}

int Node::h(){
    return this->heuristic;
}



