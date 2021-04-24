//
// Created by marco on 4/19/2021.
//
#ifndef TREE_CPP
#define TREE_CPP
#include "tree.h"
using namespace std;

Tree::Tree() {
    this->root=NULL;
}

Tree::Tree(Node* input) {
    this->root=input;
    this->frontier.push(root);
    this->nodescurrinqueue=1;
    this->maxnodesinqueue=1;

}

bool Tree::hasbeenexplored(Node* input) {
    for(int i=0;i<this->exploredlist.size();i++){
        if(this->exploredlist.at(i)->getPuzzle()==input->getPuzzle())
            return true;
    }
    return false;
}

void Tree::addtoexplored(Node* input) {
    this->exploredlist.push_back(input);
}

priority_queue<Node*, vector<Node*>, smallerheuristic> Tree::getfrontier() {
    return this->frontier;
}

void Tree::addtofrontier(Node* input) {
    //this->frontier.push(input);
    if(input->getChild("l")!=NULL && !this->hasbeenexplored(input->getChild("l"))){ //checks that left child is not null and that it hasnt been explored
        this->frontier.push(input->getChild("l"));
        this->nodescurrinqueue++;
    }
    if(input->getChild("d")!=NULL && !this->hasbeenexplored(input->getChild("d"))){ //checks that down child is not null and that it has not been explored
        this->frontier.push(input->getChild("d"));
        this->nodescurrinqueue++;
    }
    if(input->getChild("r")!=NULL && !this->hasbeenexplored(input->getChild("r"))){ //checks that right child is not null and that it has not been explored
        this->frontier.push(input->getChild("r"));
        this->nodescurrinqueue++;
    }
    if(input->getChild("u")!=NULL && !this->hasbeenexplored(input->getChild("u"))){ //checks that up child is not null and that it has not been explored
        this->frontier.push(input->getChild("u"));
        this->nodescurrinqueue++;
    }
    if(this->nodescurrinqueue>this->maxnodesinqueue)this->maxnodesinqueue=this->nodescurrinqueue; //makes sure that the maxnodesinqueue variable is accurate
}

Node* Tree::popfromfrontier() {
    Node* temp = this->frontier.top();
    this->frontier.pop();
    --this->nodescurrinqueue;
    return temp;
}

int Tree::getmaxnodesinqueue() {
    return this->maxnodesinqueue;
}

void Tree::testtree() {
    vector<int> v = {1, 1, 1};
    Node* n = new Node(v, "no", 0, NULL);

    vector<int> v2 = {2, 2, 2};
    Node* n2 =  new Node(v2, "no", 0, NULL);

    vector<int> v3 = {3, 3, 3};
    Node* n3 = new Node(v3, "no", 0, NULL);

    cout<< "Size: should be 1: " << this->frontier.size() << endl;
    cout<<"Printing top: " <<endl;
    for(int i=0; i<this->frontier.top()->getPuzzle().size();i++){cout<<this->frontier.top()->getPuzzle().at(i);}
    cout<<endl;

    this->frontier.push(n);
    cout<<"Size should be 2: "<< this->frontier.size() << endl;
    cout<<"Printing top: " <<endl;
    for(int i=0; i<this->frontier.top()->getPuzzle().size();i++){cout<<this->frontier.top()->getPuzzle().at(i);}
    cout<<endl;

    this->frontier.push(n2);
    this->frontier.push(n3);
    cout<<"Size should be 4: "<< this->frontier.size() << endl;
    cout<<"Printing top: " <<endl;
    for(int i=0; i<this->frontier.top()->getPuzzle().size();i++){cout<<this->frontier.top()->getPuzzle().at(i);}
    cout<<endl;

    this->frontier.pop();
    this->frontier.pop();
    cout<<"Size should be 2: "<<this->frontier.size()<<endl;
    cout<<"Printing top: " <<endl;
    for(int i=0; i<this->frontier.top()->getPuzzle().size();i++){cout<<this->frontier.top()->getPuzzle().at(i);}
    cout<<endl;
}

#endif