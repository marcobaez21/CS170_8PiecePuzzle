//
// Created by marco on 4/18/2021.
//

#ifndef PROJECT1_PROBLEM_H
#define PROJECT1_PROBLEM_H

#include <iostream>
#include <vector>
using namespace std;

class Problem
{
private:
    vector<int> puzzle; // vector storing puzzle
    bool isgoal; // variable storing if current puzzle is goal puzzle
public:
    Problem();
    Problem(vector<int>);
    vector<int> returnpuzzle(); //returns internal puzzle vector
    int returnzero(); //returns index for where the zero or empty spot is
    bool isgoalstate(); //returns bool for if current puzzle is goal puzzle
};

#endif //PROJECT1_PROBLEM_H
