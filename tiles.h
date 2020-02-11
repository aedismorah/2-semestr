#include <iostream>
#include <string.h>
using namespace std;

class Tiles
{
public:
    
    string brand_name;
    int size_h;
    int size_w;
    double price; 
    
    void setData(int x,int y)
    {
    size_h=x;
    size_w=y;
    }
    
    void getData()
    {
        cout <<"NAME: "<< brand_name << endl;
        cout << "HIGH: " << size_h << endl;
        cout << "WEIGHT: " << size_w << endl;
        cout << "PRICE: " << price << endl;
    }

};
    
    
class Children
{
  public:
    void main_method(char N,int A)
    {
       ChildrenName = N;
       ChildrenAges = A;
    }
    
private:
    int ChildrenAges;
    char ChildrenName;
};


