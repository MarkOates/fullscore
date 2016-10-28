



#include <iostream>
#include <vector>
#include <string>



int main(int argv, char **argc)
{
   std::vector<std::string> args;
   for (int i=0; i<argv; i++) args.push_back(argc[i]);

   std::cout << "WORKING!" << std::endl;
   return 0;
}




