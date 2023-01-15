#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//g++ main.cpp -Wall -Werror -Wuninitialized -o a.out

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   inputFile=argv[1];
   outputFile=argv[2];

   vector<int> v;
   int fileNum;
   char dumChar;

   // Create input stream and 
   ifstream inFS;
   //open input csv file
   inFS.open(inputFile);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()) {
      cout << "Error opening "<<inputFile<< endl;
      exit(1); 
   }
   
   // Read in integers from input file to vector.
   while(inFS>>fileNum){//h ere
      v.push_back(fileNum);
      inFS>>dumChar;
   }

   // Close input stream.
   inFS.close();
   
   cout<<"inFS closed"<<endl;
   
   // Get integer average of all values read in.
   int total=0;
   int avg=0;
   unsigned int i=0;
   for(i=0; i<v.size();i++){
      total+=v[i];
      cout<<v[i]<<endl;
   }
   avg=total/v.size(); //INTEGER DIVISION IS HAPPENING HERE

   cout<<"the average of values in data1.csv is "<<avg<<endl;
   
   // Convert each value within vector to be the difference between the original value and the average.
   for(i=0; i<v.size();i++){
      v[i]=v[i]-avg;
   }
   
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
      cout << "Error opening "<<outputFile<< endl;
      exit(1); 
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(i=0; i<v.size();i++){

      if(i==v.size()-1){
         outFS<<v[i];
         break;
      }
      outFS<<v[i]<<", ";
   }
   
   // Close output stream.
   outFS.close();
   cout<<"outFS closed"<<endl;
   
   return 0;
}