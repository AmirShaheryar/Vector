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
};