//
// Created by marco on 4/18/2021.
//
//
// For help with programming eucledian distance i used this website which gave a formula for both manhattan and eucledian:
// https://www.diva-portal.org/smash/get/diva2:918778/FULLTEXT02.pdf
//I also used this to see how manhattan distance was programmed and changed it accordigly to euclidian distance:
//https://stackoverflow.com/questions/39759721/calculating-the-manhattan-distance-in-the-eight-puzzle/39759853
//

#include "node.h"
#include <cmath>
using namespace std;

Node::Node() {
    this->parent=NULL;
    this->left=NULL;
    this->down=NULL;
    this->right=NULL;
    this->up=NULL;
    this->NodeProblem = Problem();
    this->heuristic =0; // Probably need to fix later
    this->UCS = 0;
    this->heuristicstring = "UCS";
}

Node::Node(vector<int> inputpuzzle, string heuristic, int c,  Node* Parent ) {
    this->parent=Parent;
    this->left=NULL;
    this->down=NULL;
    this->right=NULL;
    this->up=NULL;
    this->NodeProblem=Problem(inputpuzzle);
    this->heuristic = getHeuristic(heuristic); // Probably need to fix later
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

    cout<<"Expanding this node..."<<endl<<endl;
    //for(int i=0;i<9;i++){if(i%3==0 && i!=0){std::cout<<std::endl;}std::cout<<currpuzzle[i]<<" ";}

    if(zero==1 || zero==2 || zero==4 || zero==5 || zero==7 || zero==8){ // These values mean that the zero is in the second or third columns so we can move left
        /*Testing this*/ currpuzzle=puzzle;
        this->left = moveleft(currpuzzle, zero, this->heuristicstring, this->g(), this);
    }

    if(zero<6){ //This value means that the zero is in the first or second row and so we can move down
        /*Testing this*/ currpuzzle=puzzle;
        this->down = movedown(currpuzzle, zero, this->heuristicstring, this->g(), this);
    }

    if(zero==0 || zero==1 || zero==3 || zero==4 || zero==6 || zero==7){ //These values mean that the zero is in the first or second colums so we can move right
        /*Testing this*/ currpuzzle=puzzle;
        this->right = moveright(currpuzzle, zero, this->heuristicstring, this->g(), this);
    }

    if(zero>2){ //This value means that the zero is in the second or third row and so we can move up
        /*Testing this*/ currpuzzle=puzzle;
        this->up = moveup(currpuzzle, zero, this->heuristicstring, this->g(), this);
    }
}

int Node::getHeuristic(string input) {
    //FIX LATER

    int total = 0;
    vector<int> goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    vector<int> currpuzzle = this->getPuzzle();

    if(input=="UCS"){ return 0;}

    else if(input=="MISPLACED"){ //simply checks how many numbers are not where they are supposed to be and adds that up
        for(int i=0;i<goal.size();i++){
            if(currpuzzle.at(i) != goal.at(i)){ //fix later and add euclidian
                ++total;
            }
        }
        return total;
    }

    else if(input=="EUCLEDIAN"){
        for(int i=0;i<goal.size();i++){
            if((currpuzzle.at(i)!=goal.at(i))&&(currpuzzle.at(i)!=0)){
                //total+= pow( (( (currpuzzle.at(i)-1)%3) - (i%3)), 2 ) + pow(( (floor((currpuzzle.at(i)-1)/3))-floor(i/3) ),2);
                total+= sqrt(pow( (( (currpuzzle.at(i)-1)%3) - (i%3)), 2 ) + pow(( (floor((currpuzzle.at(i)-1)/3))-floor(i/3) ),2));
            }
        }
       // return sqrt(total);
        return total;
    }

    else{ return -999999;}

}

int Node::g(){
    return this->UCS;
}

int Node::h(){
    return this->heuristic;
}

bool Node::isgoal() {
    return this->NodeProblem.isgoalstate();
}



