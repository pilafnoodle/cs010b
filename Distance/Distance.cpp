//implement all functons declared in distance.h
#include "Distance.h"
 //g++ Distance.cpp main.cpp -Wall -Werror -Wuninitialized -o a.out

//default constructor
    Distance::Distance(){
        feet=0;
        inches=0;
    }
   /* Constructs a distance of ft feet and in inches,
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
        Just convert negative inches to positive. Don't subtract from feet.
   */
    Distance::Distance(unsigned ft, double in){ //works
        feet=ft;
        inches=in;
        init();
    }

   /* Constructs a distance of 0 ft and in inches, 
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
        Just convert negative inches to positive. Don't subtract from feet.
   */
    Distance::Distance(double in){//need to test
        feet=0;
        inches=in;
        init();
        /*
        if(in<0){
            inches=in*-1;
            in=inches;
        }
        if(in>=12){
            inches=in-(int(in/12)*12); //find whole number of feet, convert to inches and then subtract from starting
        }*/
    }


   /* Returns just the feet portion of the Distance
   */
   unsigned Distance::getFeet() const{
    return feet;
   }


   /* Returns just the inches portion of the Distance
   */
    double Distance::getInches() const{
        return inches;
    }


   /* Returns the entire distance as the equivalent amount of inches.
        (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
   */
    double Distance::distanceInInches() const{
        return feet*12+inches;
    }


   /* Returns the entire distance as the equivalent amount of feet.
        (e.g., 3 feet 6 inches would be returned as 3.5 feet)
   */
    double Distance::distanceInFeet() const{
        return inches/12+feet;
    }


   /* Returns the entire distance as the equivalent amount of meters.
        1 inch equals 0.0254 meters.
        (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
   */
    double Distance::distanceInMeters() const{
        return (feet*12+inches)*0.0254;
    }


   /* Returns the sum of 2 Distances.
   */
    Distance Distance::operator+(const Distance &rhs) const{
        return Distance(this->feet+rhs.getFeet(),this->inches+rhs.getInches());
    }


   /* Returns the difference between 2 Distances.
   */
    Distance Distance::operator-(const Distance &rhs) const{
        //return Distance(this->feet-rhs.getFeet(),this->inches-rhs.getInches());
        double distin1=this->distanceInInches();
        double distin2=rhs.distanceInInches();
        return Distance(distin1-distin2);

    }


   /* Outputs to the stream out the Distance in the format: 
        feet' inches'' (i.e. 3' 3.41'')
   */
    ostream & operator<<(ostream &out, const Distance &rhs){
        out<<rhs.getFeet()<<"' "<<rhs.getInches()<<"\"";
        return out;
    }

   /* Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.
   */
    void Distance::init(){
        if(inches<0){
            inches=inches*-1;
        }
        if(inches>=12){
            feet=feet+int(inches/12); //is typecasting expected?
            inches=inches-(int(inches/12)*12); //find whole number of feet, convert to inches and then subtract from starting
        }
    }
