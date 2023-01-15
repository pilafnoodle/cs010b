#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

class IntVector {
  private:
   unsigned _size;
   unsigned _capacity;
   int *_data;
  public:
   // Declare your constructor here

    IntVector(int[], int, int);
   
	~IntVector();
	unsigned size() const;
	unsigned capacity() const;
	bool empty() const;
	const int & at(unsigned) const;
	int & at(unsigned);
};

#endif
