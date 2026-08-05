#include <iostream>
using namespace std;
class Vector {
private:
        double* data;
        int size;
public:
        Vector(int s) : size(s)
        {
            data = new double[size];
        }

        ~Vector() 
        {
            delete[] data;
        }            
        int getSize() const {
            return size;
        }

        void Push(double value) {
            if (size == 0) 
            {
                data = new double[1];
                data[0] = value;
                size = 1;
            } 
            else 
            {
                double* newData = new double[size + 1];
                for (int i = 0; i < size; ++i) 
                {
                    newData[i] = data[i];
                }
                newData[size] = value;
                delete[] data;
                data = newData;
                ++size;
            }
        }
};