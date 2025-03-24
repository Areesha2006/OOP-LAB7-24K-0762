#include<iostream>
#include<math.h>
using namespace std;
class Shape{
    protected:
        string position,color;
        int borderThickness;
    public:
        Shape(string color,string pos,int thickness):color(color),position(pos),borderThickness(thickness){}
        virtual void draw(){
            cout<<"A "<<color<<" shape is drawn in the "<<position<<" have border thickness "<<borderThickness<<"cm"<<endl;
        }
        virtual void calculateArea(){
            cout<<"Area is 0"<<endl;
        }
        virtual void calculatePerimeter(){
            cout<<"Perimeter is 0"<<endl;
        }
};
class Circle: public Shape{
    int radius;
    public:
    Circle(string color,string pos,int thickness,int r):Shape(color,pos,thickness),radius(r){}
        void draw(){
            cout<<"A "<<color<<" circle is drawn in the "<<position<<" have border thickness "<<borderThickness<<"cm and radius "<<radius<<endl;
        }
        void calculateArea(){
            float area=3.142*radius*radius;
            cout<<"Area is "<<area<<endl;
        }
        void calculatePerimeter(){
            float perimeter=2*radius*3.142;
            cout<<"Perimeter is "<<perimeter<<endl;
        }
};
class Rectangle: public Shape{
    int width,height;
    public:
    Rectangle(string color,string pos,int thickness,int w,int h):Shape(color,pos,thickness),width(w),height(h){}
        void draw(){
            cout<<"A "<<color<<" rectangle is drawn in the "<<position<<" have border thickness "<<borderThickness<<"cm, width "<<width<<" and height "<<height<<endl;
        }
        void calculateArea(){
            int area=width*height;
            cout<<"Area is "<<area<<endl;
        }
        void calculatePerimeter(){
            int perimeter=2*(width+height);
            cout<<"Perimeter is "<<perimeter<<endl;
        }
};
class Triangle: public Shape{
    int base,height;
    public:
    Triangle(string color,string pos,int thickness,int b,int h):Shape(color,pos,thickness),base(b),height(h){}
        void draw(){
            cout<<"A "<<color<<" triangle is drawn in the "<<position<<" have border thickness "<<borderThickness<<"cm, base "<<base<<" and height "<<height<<endl;
        }
        void calculateArea(){
            float area=0.5*(base*height);
            cout<<"Area is "<<area<<endl;
        }
        void calculatePerimeter(){
            float perimeter=base+height+sqrt(pow(base,2.0)+pow(height,2.0));
            cout<<"Perimeter is "<<perimeter<<endl;
        }
};
class Polygon: public Shape{
    int n,l,r;
    public:
        Polygon(string color,string pos,int thickness,int n,int l,int r):Shape(color,pos,thickness),n(n),l(l),r(r){}
        void draw(){
            cout<<"A "<<color<<" polygon is drawn in the "<<position<<" have border thickness "<<borderThickness<<"cm,"<<n<<" sides each having lenght "<<l<<"and radius of inscribe circle is "<<r<<endl;
        }
        void calculateArea(){
            float area=(n/2.0)*(l*r);
            cout<<"Area is "<<area<<endl;
        }
        void calculatePerimeter(){
            int perimeter=n*l;
            cout<<"Perimeter is "<<perimeter<<endl;
        }
};
int main(){
    string color,pos;
    int r,border,w,h,b,l,n;
    Shape *s;
    cout<<"Enter the color of the circle: ";
    cin>>color;
    cout<<"Enter the border thickness of the circle: ";
    cin>>border;
    cout<<"Enter the radius of the circle: ";
    cin>>r;
    Circle c(color,"center",border,r);
    s=&c;
    cout<<"Drawing the circle"<<endl;
    s->draw();
    s->calculateArea();
    s->calculatePerimeter();
    cout<<endl<<"Enter the color of the rectangle: ";
    cin>>color;
    cout<<"Enter the border thickness of the rectangle: ";
    cin>>border;
    cout<<"Enter the width of the rectangle: ";
    cin>>w;
    cout<<"Enter the height of the rectangle: ";
    cin>>h;
    Rectangle rec(color,"top-left corner",border,w,h);
    s=&rec;
    cout<<"Drawing the rectangle"<<endl;
    s->draw();
    s->calculateArea();
    s->calculatePerimeter();
    cout<<endl<<"Enter the color of the triangle: ";
    cin>>color;
    cout<<"Enter the border thickness of the triangle: ";
    cin>>border;
    cout<<"Enter the position of the triangle: ";
    cin>>pos;
    cout<<"Enter the base of the triangle: ";
    cin>>b;
    cout<<"Enter the height of the triangle: ";
    cin>>h;
    Triangle t(color,pos,border,b,h);
    s=&t;
    cout<<"Drawing the triangle"<<endl;
    s->draw();
    s->calculateArea();
    s->calculatePerimeter();
    cout<<endl<<"Enter the color of the polygon: ";
    cin>>color;
    cout<<"Enter the border thickness of the polygon: ";
    cin>>border;
    cout<<"Enter the position of the polygon: ";
    cin>>pos;
    cout<<"How many sides are there in polygon: ";
    cin>>n;
    cout<<"Enter lenght of each side: ";
    cin>>l;
    cout<<"Enter the radius of the inscribe circle: ";
    cin>>r;
    Polygon p(color,pos,border,n,l,r);
    s=&p;
    cout<<"Drawing the polygon"<<endl;
    s->draw();
    s->calculateArea();
    s->calculatePerimeter();
    return 0;
}