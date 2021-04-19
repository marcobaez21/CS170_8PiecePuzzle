//
// Created by marco on 4/18/2021.
//

#include "problem.h"

Problem::Problem() {
    this->isgoal=false;
}

Problem::Problem(vector<int> inputpuzzle) {

    vector<int> goalpuzzle = {1, 2, 3 , 4, 5 ,6, 7, 8, 0};
    this->puzzle=inputpuzzle;
    if(this->puzzle==goalpuzzle){isgoal=true;}
    else{isgoal=false;}
}

vector<int> Problem::returnpuzzle() {
    return this->puzzle;
}

int Problem::returnzero() {
    for(int i=0;i<9;i++){
        if(this->puzzle.at(i)==0){ return i;}
    }
    return 99999999;
}

bool Problem::isgoalstate() {
    if(this->isgoal){ return true;}
    else{ return false;}
}

