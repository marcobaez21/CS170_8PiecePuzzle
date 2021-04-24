//
// Created by marco on 4/19/2021.
//

#include <iostream>
#ifndef ASTAR
#define ASTAR
#include "tree.h"
#endif
using namespace std;

/*
void astar(Tree input){
    Node* topnode = NULL;
    int totalnodesexpanded = 0;

    cout<<"Expanding state:"<<endl;

    while(!input.getfrontier().empty()){
        //topnode=input.getfrontier().pop(); WHO DESIGNED THIS POP SHOULD RETURN POPPED VARIABLE AHHH
        topnode=input.popfromfrontier();
        if(topnode->isgoal()){
            cout<<"Finished"<<endl;
            cout<<"Number of nudes expanded were: " << totalnodesexpanded << endl;
            cout<<"Max Number of nodes in queue at once was: " << input.getmaxnodesinqueue() << endl;
            //Ask for print trace and then print trace
            //FIX
            //
            return;
        }
        if(totalnodesexpanded>=1){
            cout<<"The best state to expand with g(n) = " << topnode->g() << "and h(n) = " << topnode->h() << " is…" << endl;
            for(int i=0;i<9;i++){if(i%3==0 && i!=0){std::cout<<std::endl;}std::cout<<topnode->getPuzzle().at(i)<<" ";}
        }
        topnode->expand();
        totalnodesexpanded++;
        input.addtoexplored(topnode);
        input.addtofrontier(topnode);
    }
    cout<<endl<<"No solution :( "<<endl;
}*/
