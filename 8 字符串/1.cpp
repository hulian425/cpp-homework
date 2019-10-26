#include<iostream>
#include<cassert>
using namespace std;

class Point{
public:
    Point() : x(0),y(0)
    {
        cout << "Default Constructor called." <<endl;
    }
    Point(int _x, int _y) : x(_x), y(_y)
    {
        cout << "Constructor called." <<endl;
    }
    ~Point()
    {
        cout << "Constructor called." <<endl;
    }
    int getx() const
    {
        return x;
    }
    int gety() const
    {
        return y;
    }
    void move(int newX, int newY)
    {
        x = newX;
        y = newY;
    }
    void Display()
    {
        cout << "(" << x << "," << y << ") ";
    }
private:
    int x, y;
};

class MatrixofPoints{
public:
    MatrixofPoints(int _size1, int _size2) : size1(_size1), size2(_size2)
    {
        int i;
        points = new Point* [size1];
        for(i = 0; i < size1; i++)
        {
            points[i] = new Point[size2];
        }
    }
    ~MatrixofPoints()
    {
        int i;
        cout << "Deleting..." <<endl;
        for(i = 0; i < size1; i++)
            delete[] points[i];
        delete[] points;
    }
    Point &element(int index1, int index2)
    {
        assert(index1 >= 0 && index1 < size1 && index2 >= 0 && index2 < size2);
        return points[index1][index2]6 5
    ;
    }
private:
    Point** points;
    int size1;
    int size2;
};

int main()
{
    int x, y;
    cout << "Please enter the size of the Matrix: ";
    cin >> x >> y;

    MatrixofPoints points(x, y);
    int r, c; //r代表行 c代表列
    for(r = 0; r < x; r++)
    {
        for(c = 0; c < y; c++)
        {
            points.element(r, c).move(r + 1, c + 1);
            points.element(r, c).Display();
        }
        cout <<endl;
    }
    return 0;
}
