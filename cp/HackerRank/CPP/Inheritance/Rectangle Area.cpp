#include <iostream>
using namespace std;
class Rectangle{
    protected:
        int heigth ; 
        int width ;
    public : 
        void display(){
            cout << heigth << " " << width << endl ; 
        }
}; 
class RectangleArea  : public Rectangle {
    public :
        void read_input(){
            cin >> heigth >> width ; 
        }
        void display(){
            cout << heigth * width << endl ;
        }
} ; 
int main()
{
    RectangleArea r_area;
    r_area.read_input();
    r_area.Rectangle::display();
    r_area.display();
    return 0;
}
