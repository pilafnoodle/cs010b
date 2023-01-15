#include <stdexcept>

using namespace std;

#include "IntVector.h"


// Place the implementation of your constructor here

IntVector::IntVector(int arr [], int n1, int n2){
    if(n1>n2){
        _size=0;
        _capacity=0;
    }else{
        _size=n2-n1+1;
        _capacity=n2-n1+1;

        unsigned int i;
        for(i=0; i<this->size(); i++){
            this->at(i)=arr[i];
        }
    }

}





IntVector::~IntVector() {
	delete[] _data;
}

unsigned IntVector::size() const { return _size; }
unsigned IntVector::capacity() const { return _capacity; }
bool IntVector::empty() const { return _size == 0; }

const int & IntVector::at(unsigned index) const {
	if (index < _size) {
	   return _data[index];
	}
	else {
	   throw out_of_range("IntVector::at_range_check");
	}
}

int & IntVector::at(unsigned index)
{
	if (index < _size) {
	   return _data[index];
	}
	else {
	   throw out_of_range("IntVector::at_range_check");
	}
}
