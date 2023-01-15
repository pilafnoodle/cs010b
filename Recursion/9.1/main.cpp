#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s){
   if(s.size()<2){
      return;
   }
   char temp1=s[0];
   char temp2=s[s.size()-1];

   string x = s.substr(1,s.size()-2);
   flipString(x);

   s=temp2+x+temp1;

}


