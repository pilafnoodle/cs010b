#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector{
    public:
        IntVector(); //added this
        IntVector(unsigned capacity);
        IntVector(unsigned capacity, int value);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;

        
        void insert(unsigned index, int value);
        void clear();
        int & at(unsigned index);
        void erase(unsigned index);
        void push_back(int value);
        void pop_back();
        void resize(unsigned size, int value = 0);
        void reserve(unsigned n);
        void assign(unsigned n, int value);
        int & back();
        int & front();
    


    private:
        unsigned _size;
        unsigned _capacity;
        int* _data;
        void expand();
        void expand(unsigned amount);

};

#endif