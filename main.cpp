#include <iostream>
#include <vector>
//#include "Astar.cpp"
#include "tree.h"

void trace(Node* input){
    vector<Node*> reversedlist;
    vector<int> finishedpuzzle = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    while(input->getParent()!=NULL){
        reversedlist.push_back(input->getParent());
        input=input->getParent();
    }
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Printing trace for answer"<<endl;
    cout<<"------------------------------------------------------"<<endl;

    for(int i=reversedlist.size()-1;i>=0;i--){
        cout<<endl;
        for(int j=0;j<9;j++){if(j%3==0 && j!=0){std::cout<<std::endl;}std::cout<<reversedlist.at(i)->getPuzzle().at(j)<<" ";}
        cout<<endl;
    }
    cout<<endl;
    for(int j=0;j<9;j++){if(j%3==0 && j!=0){std::cout<<std::endl;}std::cout<<finishedpuzzle.at(j)<<" ";}
    cout<<endl;
    cout<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Thank you!"<<endl;
    cout<<"------------------------------------------------------"<<endl;

}

void astar(Tree input){
    Node* topnode = NULL;
    int totalnodesexpanded = 0;

    if(input.getfrontier().empty()){
        cout<<"Error: No solution"<<endl;
    }

    cout<<endl<<"Expanding state:"<<endl;

    while(!input.getfrontier().empty()){
        //topnode=input.getfrontier().pop(); WHO DESIGNED THIS POP SHOULD RETURN POPPED VARIABLE AHHH
       // topnode=input.popfromfrontier();
      // topnode=input.getfrontier().top();
       //cout<<"Top node: " <<endl;
       //for(int i=0; i<topnode->getPuzzle().size();i++){cout<<topnode->getPuzzle().at(i);}
       //cout<<endl;
       topnode=input.popfromfrontier();
        if(topnode->isgoal()){
            cout<<"Finished"<<endl;
            cout<<"Number of nodes expanded were: " << totalnodesexpanded << endl;
            cout<<"Max Number of nodes in queue at once was: " << input.getmaxnodesinqueue() << endl;
            cout<<endl;
            int input;
            cout<<"Do you want a trace for the solution? Press 1 for yes and 2 for no"<<endl;
            cin>>input;
            if(input==1){trace(topnode);}
                 else if(input==2){return;}
            return;
        }
        if(totalnodesexpanded>=1){
            cout<<"The best state to expand with g(n) = " << topnode->g() << " and h(n) = " << topnode->h() << " is: " << endl;
            for(int i=0;i<9;i++){if(i%3==0 && i!=0){std::cout<<std::endl;}std::cout<<topnode->getPuzzle().at(i)<<" ";}
        }
        topnode->expand();
        totalnodesexpanded++;
        input.addtoexplored(topnode);
        input.addtofrontier(topnode);
    }
    cout<<endl<<"No solution :( "<<endl;
}

void uniformcostsearch(Tree input){
    Node* topnode = NULL;
    int numofnodes=0;

    while(!input.getfrontier().empty()){
        topnode = input.popfromfrontier();
        input.addtoexplored(topnode);

        if(numofnodes>0){
            cout<<"The best state to expand with g(n) = " << topnode->g() << " and h(n) = " << topnode->h() << " is: " << endl;
        }

        topnode->expand();
        numofnodes++;

        if(topnode->getChild("l")!=NULL){
            if(topnode->getChild("l")->isgoal()){
                cout<<"GOAL!!!"<<endl;
                cout<<"Number of nodes expanded: "<<numofnodes<<endl;
                cout<<"Max Number of nodes in queue at once was: " << input.getmaxnodesinqueue() << endl;
                cout<<endl;
                int input;
                cout<<"Do you want a trace for the solution? Press 1 for yes and 2 for no"<<endl;
                cin>>input;
                if(input==1){trace(topnode);}
                else if(input==2){return;}
                return ;
            }
        }

        if(topnode->getChild("d")!=NULL) {
            if (topnode->getChild("d")->isgoal()) {
                cout << "GOAL!!!" << endl;
                cout << "Number of nodes expanded: " << numofnodes << endl;
                cout<<"Max Number of nodes in queue at once was: " << input.getmaxnodesinqueue() << endl;
                cout<<endl;
                int input;
                cout<<"Do you want a trace for the solution? Press 1 for yes and 2 for no"<<endl;
                cin>>input;
                if(input==1){trace(topnode);}
                else if(input==2){return;}
                return;
            }
        }


            if(topnode->getChild("r")!=NULL){
                if(topnode->getChild("r")->isgoal()){
                    cout<<"GOAL!!!"<<endl;
                    cout<<"Number of nodes expanded: "<<numofnodes<<endl;
                    cout<<"Max Number of nodes in queue at once was: " << input.getmaxnodesinqueue() << endl;
                    cout<<endl;
                    int input;
                    cout<<"Do you want a trace for the solution? Press 1 for yes and 2 for no"<<endl;
                    cin>>input;
                    if(input==1){trace(topnode);}
                    else if(input==2){return;}
                    return ;
                }
            }

            if(topnode->getChild("u")!=NULL){
                if(topnode->getChild("u")->isgoal()){
                    cout<<"GOAL!!!"<<endl;
                    cout<<"Number of nodes expanded: "<<numofnodes<<endl;
                    cout<<"Max Number of nodes in queue at once was: " << input.getmaxnodesinqueue() << endl;
                    cout<<endl;
                    int input;
                    cout<<"Do you want a trace for the solution? Press 1 for yes and 2 for no"<<endl;
                    cin>>input;
                    if(input==1){trace(topnode);}
                    else if(input==2){return;}
                    return ;
                }
            }


            input.addtofrontier(topnode);
    }
}

int main() {
    int choice =0;
   int temp = 0;
   int algorithm = 0;

   std::vector<int> inputpuzzle = {1, 2, 0, 4, 5, 3, 7, 8, 6};
   // std::cout << "Hello, World!" << std::endl;
   std::cout << "Welcome to mbaez007's 8 puzzle solver." << std::endl;
   std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << std::endl;
   std::cin>>choice;
   if(choice==1){
       std::cout<<"Nice, youve chosen to use the default puzzle."<<std::endl;

       //Continue processing default puzzle.

   }
   else if(choice==2){
       inputpuzzle.clear();
       std::cout<<"Nice youve chosen to enter your own"<<std::endl;
       std::cout << "Enter your puzzle, use a zero to represent the blank" << std::endl;
       std::cout << "Enter the first row, use space or tab between numbers" << std::endl;
          for(int i=0;i<3;i++) {std::cin>>temp; inputpuzzle.push_back(temp);}
          std::cout << "Enter the second row, use space or tab between numbers" << std::endl;
          for(int i=3;i<6;i++) {std::cin>>temp;inputpuzzle.push_back(temp);}
          std::cout << "Enter the third row, use space or tab between numbers"<<std::endl;
          for(int i=6;i<9;i++){std::cin>>temp;inputpuzzle.push_back(temp);}

          //Continue processing user input puzzle

       //testing user inputted puzzle

       cout<<endl;
          cout<<"------------------------------------------------------"<<endl;
       for(int i=0;i<9;i++){if(i%3==0 && i!=0){std::cout<<std::endl;}std::cout<<inputpuzzle[i]<<" ";}
       cout<<endl;
       cout<<"------------------------------------------------------"<<endl;
       cout<<endl;
   }

   else{std::cout<<"Wrong input"<<std::endl;}

   std::cout<<std::endl;
   std::cout<<"Now enter your choice for algorithm"<<std::endl;
   std::cout<<"1 for Uniform Cost Search"<<std::endl;
   std::cout<<"2 for A* with Misplaced Tile heuristic"<<std::endl;
   std::cout<<"3 fot A* with Euclidian distance heuristic"<<std::endl;
   std::cin>>algorithm;
   if(algorithm==1){
      // std::vector<int> testpuzzle = {1, 2, 0, 4, 5, 3, 7, 8, 6}; // for testing
       Node* temp = new Node(inputpuzzle, "UCS", 0, NULL);
       Tree temptree = Tree(temp);
       uniformcostsearch(temptree);
   }//call ucs
   else if(algorithm==2){
     //  std::vector<int> testpuzzle = {1, 2, 3, 4, 5, 6, 8, 7, 0}; // for testing
       Node* temp = new Node(inputpuzzle, "MISPLACED", 0, NULL);
       Tree temptree = Tree(temp);
       //temptree.testtree();
       astar(temptree);

   }//call A*
   else if(algorithm==3){
       Node* temp = new Node(inputpuzzle, "EUCLEDIAN", 0, NULL);
       Tree temptree = Tree(temp);
       astar(temptree);
   }//call A*
   else{std::cout<<"Wrong input"<<std::endl;}




    return 0;
}