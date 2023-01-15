#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);
//g++ main.cpp -Wall -Werror -Wuninitialized -o a.out


int main(int argc, char *argv[]){

    //Get from the command line the name of the file that contains the wind tunnel data.
   string tunnelData; 
   tunnelData=argv[1];
   vector<double> angle;
   vector<double> coeLift;
   double reqAngle;
   string answer="Yes";

    readData(tunnelData, angle, coeLift);   
    reorder(angle,coeLift);
    unsigned int i;
     for( i =0; i<angle.size();i++){
        cout<<angle[i]<<", "<<coeLift[i]<<endl;
    }

    cin>>reqAngle;
    readData(tunnelData, angle, coeLift);   
   

    if (!isOrdered(angle)) {
		reorder(angle, coeLift);
	}
  
    cout<<interpolation(reqAngle,angle, coeLift)<<endl;
    cout<<"Do you want to enter another flight path angle?"<<endl;
    cin>>answer;
    
    while(answer=="Yes"||answer=="yes"){
        cin>>reqAngle;
        readData(tunnelData, angle, coeLift);  

        if (!isOrdered(angle)) {
            reorder(angle, coeLift);
        }
        
        cout<<interpolation(reqAngle,angle, coeLift)<<endl;
        cout<<"Do you want to enter another flight path angle?"<<endl;
        cin>>answer;
    }
     return 0;
}

void readData(const string &filename, vector<double> &v1, vector<double> &v2){

    ifstream inFS;
    double angle;
    double coeLift;
    string line;

    inFS.open(filename);
    if (!inFS.is_open()) {
      cout << "Error opening "<<filename<< endl;
      exit(1); 
    }

    while((inFS>>angle>>coeLift)){ 
       v1.push_back(angle);
       v2.push_back(coeLift);
    }
}

double interpolation(double reqAngle, const vector<double> &angles, const vector<double> &coeLift){//returns coefficient of lift
    double a; 
    double c;
    double b=reqAngle;
    unsigned int i;

    if((reqAngle>angles[angles.size()-1])||(reqAngle<angles[0])){ //tests for out of bounds
        cout<<"Angle is out of bounds"<<endl;
        return 0;
    }

    for(i=0; i<angles.size();i++){ //checks if coeLift is already given
        if(reqAngle==angles[i]){
            return coeLift[i];
        }
    }
    int pos;
    for(i=0; i<angles.size();i++){//finds bounds for formula
        if(reqAngle>angles[i]){
            a=angles[i];
            pos=i;
        }
    }
    c=angles[pos+1];
    
    return coeLift[pos]+((b-a)/(c-a))*(coeLift[pos+1]-coeLift[pos]);    //f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))
}

bool isOrdered(const vector<double> &angles){
    unsigned int i;
    for(i=1; i<angles.size();i++){
        if(angles[i]<angles[i-1]){
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &angles, vector<double> &coeLift){ //selection sort algorithm which doesnt work
    unsigned int i;
    unsigned int j;

    if(angles.size()==0){
        return; 
    }

    for(i=0; i<angles.size()-1;++i){

        unsigned minIndex=i;

        for(j=i; j<angles.size();++j){//finding the minimum index
            if(angles[j]<angles[minIndex]){
                minIndex=j;
            }
        }
        swap(angles[i],angles[minIndex]);
        swap(coeLift[i],coeLift[minIndex]);
    } 
}




