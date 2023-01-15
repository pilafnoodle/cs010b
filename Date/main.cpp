#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();
   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010
       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 
       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   //Date(int month, int day, int year);
   Date(unsigned m, unsigned d, unsigned y);
   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */  
   //Date(const string &m, int d, int y);
   Date(const string &mn, unsigned d, unsigned y);
   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;
   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;
   int getMonth()const;
   int getDay()const;
   int getYear()const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;
   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;
   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;
   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};

//constructors
Date::Date(unsigned m, unsigned d, unsigned y){
    bool invalid=false;
    month=m;
    year=y;
    day=d;
    if(m>12){
        invalid=true;
        month=12;
    }else if(m<=0){ 
        invalid=true;
        month=1;
    }
    if(d>daysPerMonth(month,y)){
          //check if day is greater than daysinmonth
        day=daysPerMonth(month,y);
        //cout<<"days per month is "<<daysPerMonth(m,y)<<endl;
        invalid=true;
    }
    if(d<=0){
        day=1;
    }
    if(invalid){
        cout<<"Invalid date values: Date corrected to "<<month<<"/"<<day<<"/"<<year<<"."<<endl;
    }
}
//fails 2 Octbr 32 2015
Date::Date(const string &m, unsigned d, unsigned y){//WORK ON THIS 10/13
    bool invalid=false;
    bool badMonth=false;
    month = number(m);
    year=y;
    day=d;
    if(number(m)==0){//priortize because without valid month everything else is invalid
        month=1;
        day=1;
        year=2000;
        cout<<"Invalid month name: the Date was set to 1/1/2000."<<endl;
        badMonth=true;
    }
    if((d>daysPerMonth(month,y)||month>12)&&(!badMonth)){ 
        day=daysPerMonth(month,y);
        invalid=true;
    }
    if(d<=0){
        day=1;
        invalid=true;
    }
    if(invalid&&!badMonth){
        cout<<"Invalid date values: Date corrected to "<<month<<"/"<<day<<"/"<<year<<"."<<endl;
    }
}

Date::Date(){
    this->month=1;
    this->day=1;
    this->year=2000;
}


// Implement the Date member functions here
void Date::printNumeric() const{ //do i need getters here? used to be this->day
      cout<<getMonth()<<"/"<<getDay()<<"/"<<getYear(); //is this valid even when the variables are private?
}
void Date::printAlpha() const{
   vector<string> monthsCap={"January","February","March","April","May","June","July","August","September","October","November","December"};
   cout<<monthsCap[getMonth()-1]<<" "<<getDay()<<", "<<getYear();
}
bool Date::isLeap(unsigned y) const{

    //if divisible by 4, then it could be a leap year
    //if divisble by 4 AND 100 then its not a leap year
    //but if divisble by 400 then it is a leap year
    
    if(!(y%4==0)){//if not divisible by 4, then no chance of leap year
        return false;
    }else if((y%4==0)&&(y%100==0)){
        return (y%400==0);  //return whether or not it is divisilbe by 4000
    }else if(y%4==0){
        return true;
    }else{
        return false;
    }

/*
    if((y%4==0) || ((y%4==0)&& !(y%100==0) && (y%400==0)) ||  ){ //(y%4==0 || y%400==0)&&!(year%100==0) scuffed
       return true;
    }
    return false;*/
}
unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
    vector<int> maxDays={31,28,31,30,31,30,31,31,30,31,30,31};
    if((isLeap(y)) && (m==2)){
        return 29;
    }else{
        return maxDays[month-1]; //-1 accounts for that indices start at 0
    }
}

string Date::name(unsigned m) const{
   vector<string> monthsCap={"January","February","March","April","May","June","July","August","September","October","November","December"};
   return monthsCap[m-1];
}

unsigned Date::number(const string &m) const{
   if(m=="january"||m=="January"){
        return 1;
   }else if(m=="february"||m=="February"){
        return 2;
   }else if(m=="march"||m=="March"){
        return 3;
   }else if(m=="april"||m=="April"){
        return 4;
   }else if(m=="may"||m=="May"){
        return 5;
   }else if(m=="june"||m=="June"){
        return 6;
   }else if(m=="july"||m=="July"){
        return 7;
   }else if(m=="august"||m=="August"){
        return 8;
   }else if(m=="september"||m=="September"){
        return 9;
   }else if(m=="october"||m=="October"){
        return 10;
   }else if(m=="november"||m=="November"){
        return 11;
   }else if(m=="december"||m=="December"){
        return 12;
   }else{
        return 0;
   }
}
//Do I need these?
int Date::getMonth()const{
    return this->month;
}
int Date::getDay()const{
    return this->day;
}
int Date::getYear()const{
    return this->year;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
