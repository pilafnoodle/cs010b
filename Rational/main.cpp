#include <iostream>
using namespace std;
//g++ main.cpp -Wall -Werror -Wuninitialized -o a.out
// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;

      //new
      int getNum()const;
      int getDen()const;
      //void setNum();
      //void setDen();
      
   private:
      int gcd(int, int) const;
};

Rational::Rational(){
   numerator=0;
   denominator=1;
}
Rational::Rational(int numerator){
   this->numerator=numerator;
   denominator=1;
}
Rational::Rational(int numerator, int denominator){
   this->numerator=numerator;
   this->denominator=denominator;
}

Rational Rational::add(const Rational &r) const{ //done?
    //(a/b) + (c/d) = (ad + bc) / (b*d)
    int a=getNum(); 
    int b=getDen();
    int c=r.getNum();
    int d=r.getDen();

   Rational result(a*d + b*c , b*d);
   return result;

}

Rational Rational::subtract(const Rational &r)const {
   //(a/b) - (c/d) = (ad - bc) / (b*d)
   int a=this->getNum(); 
   int b=this->getDen();
   int c=r.getNum();
   int d=r.getDen();

   Rational result( (a*d - b*c), (b*d));
   return result;

}
Rational Rational::multiply(const Rational &r)const {
   //(a/b) * (c/d) = (ac) / (bd)
   int a=this->getNum(); 
   int b=this->getDen();
   int c=r.getNum();
   int d=r.getDen();

   return Rational( (a*c),(b*d));
}
Rational Rational::divide(const Rational &r)const{
   //(a/b) / (c/d) = (ad) / (cb)
   int a=this->getNum(); 
   int b=this->getDen();
   int c=r.getNum();
   int d=r.getDen();

   Rational result ( (a*d), (c*b));
   return result;
}

void Rational::display() const{
   cout<<this->numerator<<" / "<<this->denominator;

}

void Rational::simplify(){
   int factor=this->gcd(getNum(),getDen());
   //cout<<this->numerator<<"divided by "<<gcd<<" is "<<this->numerator/gcd<<endl;
   //cout<<this->denominator<<"divided by "<<gcd<<" is "<<this->denominator/gcd<<endl;

   this->numerator=this->numerator/factor;
   this->denominator=this->denominator/factor;
}

int Rational::gcd(int n1, int n2) const{
   int smallerNum=min(n1,n2);
   int gcd=1;
   for(int i=2; i<=smallerNum;i++){
      if((n1%i ==0) && (n2%i==0)){
         gcd=i;
         break;
      }
   }
   //cout<<"the gcd of "<<n1<<" and "<<n2<<" is "<<gcd<<endl; debug line
   return gcd;

}

int Rational::getNum()const{
   return this->numerator;
}
int Rational::getDen()const{
   return this->denominator;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {

   //cout<<"the main is now running"<<endl;

   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

