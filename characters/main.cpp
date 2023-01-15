#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(string filename, char ch);

int main() {
   string filename;
   char ch;
   int chCnt = 0;

   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;
   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(string filename, char ch){

   ifstream inFS;
   int total=0;
   char filech;

   inFS.open(filename);
   if (!inFS.is_open()) {
      cout << "Error opening "<<filename<< endl;
      exit(1); 
   }

   //count number of times the character is found
   inFS.get(filech);

   while(!inFS.fail()){
      if(filech==ch){
         total++;
      }
      inFS.get(filech);

   }
   return total;
}
