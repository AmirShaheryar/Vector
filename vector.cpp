#include <iostream>
using namespace std;

class Vector 
{
private:
    double* data;
    int size;
    int capacity;

    void resize(int newCapacity) 
    {
        double* newData = new double[newCapacity];
        for (int i = 0; i < size; ++i) 
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Vector(int cap = 2) : size(0), capacity(cap)
    {
        if (capacity <= 0) capacity = 2;
        data = new double[capacity];
    }

    ~Vector() 
    {
        delete[] data;
    }            

    int getSize() const 
    {
        return size;
    }

    int getCapacity() const 
    {
        return capacity;
    }

    void Push(double value) 
    {
        if (size == capacity) 
        {
            resize(capacity * 2);
        }
        data[size] = value;
        ++size;
    }

    void Pop() 
    {
        if (size > 0) 
        {
            size--;
        }
    }

    void Insert(int index, double value) 
    {
        if (index < 0 || index > size) 
        {
            cout << "Index out of bounds\n";
            return;
        }

        if (size == capacity) 
        {
            resize(capacity * 2);
        }

        for (int i = size; i > index; --i) 
        {
            data[i] = data[i - 1];
        }

        data[index] = value;
        ++size;
    }

    void Erase(int index)
    {
        if(index<0|| index>=size)
        {
            cout<<" Index out of bound \n";
            return;
        }
        for(int i=index;i<size-1;i++)
        {   
            data[i]=data[i+1];            
        }
        size--;
    }

    double& operator[](int index) 
    {
        return data[index];
    }

    const double& operator[](int index) const 
    {
        return data[index];
    }
};

int main() 
{
    Vector vec;

    vec.Push(10.5);
    vec.Push(20.2);
    vec.Push(30.7);

    cout << "Elements: ";
    for (int i = 0; i < vec.getSize(); ++i) 
    {
        cout << vec[i] << " ";
    }
    cout << "\n";

    cout << "Size: " << vec.getSize() << "\n";
    cout << "Capacity: " << vec.getCapacity() << "\n";

    return 0;
}