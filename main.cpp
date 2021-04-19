#include <iostream>
#include <vector>

int main() {
    int choice =0;
   int temp = 0;
   int algorithm = 0;

   std::vector<int> inputpuzzle;
   // std::cout << "Hello, World!" << std::endl;
   std::cout << "Welcome to mbaez007's 8 puzzle solver." << std::endl;
   std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << std::endl;
   std::cin>>choice;
   if(choice==1){
       std::cout<<"Nice, youve chosen to use the default puzzle."<<std::endl;

       //Continue processing default puzzle.

   }
   else if(choice==2){
       std::cout<<"Nice youve chosen to enter your own"<<std::endl;
       std::cout << "Enter your puzzle, use a zero to represent the blank" << std::endl;
       std::cout << "Enter the first row, use space or tab between numbers" << std::endl;
          for(int i=0;i<3;i++) {std::cin>>temp; inputpuzzle.push_back(temp);}
          std::cout << "Enter the second row, use space or tab between numbers" << std::endl;
          for(int i=0;i<3;i++) {std::cin>>temp;inputpuzzle.push_back(temp);}
          std::cout << "Enter the third row, use space or tab between numbers"<<std::endl;
          for(int i=0;i<3;i++){std::cin>>temp;inputpuzzle.push_back(temp);}

          //Continue processing user input puzzle

       //testing user inputted puzzle
       for(int i=0;i<9;i++){if(i%3==0 && i!=0){std::cout<<std::endl;}std::cout<<inputpuzzle[i]<<" ";}
   }

   else{std::cout<<"Wrong input"<<std::endl;}

   std::cout<<std::endl;
   std::cout<<"Now enter your choice for algorithm"<<std::endl;
   std::cout<<"1 for Uniform Cost Search"<<std::endl;
   std::cout<<"2 for A* with Misplaced Tile heuristic"<<std::endl;
   std::cout<<"3 fot A* with Euclidian distance heuristic"<<std::endl;
   std::cin>>algorithm;
   if(algorithm==1){ algorithm=1;}//call ucs
   else if(algorithm==2){algorithm=2;}//call A*
   else if(algorithm==3){algorithm=3;}//call A*
   else{std::cout<<"Wrong input"<<std::endl;}




    return 0;
}