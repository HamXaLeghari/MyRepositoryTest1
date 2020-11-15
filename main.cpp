#include <iostream>
#include <cmath>

using namespace std;

class Point;
class Rectangle;

class Point {

private:
    float x,y;

public:

    Point(){ x = y = 1;};

    Point(float x, float y):x(x),y(y){};

    float getx(){
        if(x <0.0 or x>20.00) {
            return 1;
        }
        else return x;

    }

    float gety(){
        if(y <0.0 or y>20.00) {
            y = 1.00;
        }
        return y;

    }

    void setx(float x){

        if(x <0.0 or x>20.00) {
            Point::x = 1;
        }

        else Point::x = x;

    }

    void sety(float y){

        if(y <0.0 or y>20.00) {
            this->y = 1;
        }

        else this->y = y;

    }

};



class Rectangle {

private:
    float length,width,Area,Perimeter;
    Point p1,p2,p3,p4;
    char fillChar , perimeterChar;

public:


    Rectangle(float x1, float y1 , float x2 , float y2 , float x3 , float y3 , float x4 , float y4)
            :p1(x1,y1),p2(x2,y2),p3(x3,y3),p4(x4,y4) {

        length = sqrt(pow(p2.getx() - p1.getx(), 2) + pow(p2.gety() - p1.gety(), 2));

        width = sqrt(pow(p4.getx() - p1.getx(), 2) + pow(p4.gety() - p1.gety(), 2));

        testRectangle(p1,p2,p3,p4);

        if (!testRectangle(p1, p2, p3, p4)) {

            cout << "Given Coordinates donot form a Rectangle" << endl;

        }

        else {

            if (Set())
                cout << "Coordinates make a square" << endl;
            else {
                if (length < width) {
                    float temp;

                    temp = length;
                    length = width;
                    width = temp;

                }

                calculateArea();
                calculatePerimeter();
                Display();
            }
        }

    }

    bool Set() {
        return length == width;
    }

    void calculateArea(){

        Area = length * width;

    }

    void calculatePerimeter(){

        Perimeter = 2 * (length + width);

    }
    void Display() {
        cout<<"Length = "<<length<<endl;
        cout<<"Width = "<<width<<endl;
        cout << "Area = " << Area<<endl;
        cout<<"Perimeter = " << Perimeter << endl;
    }

    bool testRectangle(Point p1 , Point p2 , Point p3 , Point p4){

        float length1 , length2, width1 , width2;

        length1 = sqrt(pow(p2.getx() - p1.getx(), 2) + pow(p2.gety() - p1.gety(), 2));
        length2 = sqrt(pow(p4.getx() - p3.getx(), 2) + pow(p4.gety() - p3.gety(), 2));

        if(length1 != length2)
            return false;


        width1 = sqrt(pow(p4.getx() - p1.getx(), 2) + pow(p4.gety() - p1.gety(), 2));
        width2 = sqrt(pow(p3.getx() - p2.getx(), 2) + pow(p3.gety() - p2.gety(), 2));

        return width1 == width2;

    }

    char setFillChar(char fillChar) {
        return Rectangle::fillChar = fillChar;


    }

    char setPerimeterChar(char perimeterChar) {
        return Rectangle::perimeterChar = perimeterChar;
    }





    void Draw(){

        for (int i = 1; i <=width; ++i) {

            for (int j = 1; j <=length ; ++j) {

                if(i == 1 or i >= width or j ==1 or j >= length) {
                    cout << perimeterChar;
                } else
                    cout<<fillChar;

            }
           cout<<endl;
        }


    }


};

int main() {

    Rectangle rectangle(10,20,20,20,20,5,10,5);  // (TEST POINTS) 1.{p1(1,4),p2(4,4),p3(4,2),p4(1,2)} 2.{p1(10,20),p2(20,20),p3(20,20),p4(10,5)}
    rectangle.setPerimeterChar('#');
    rectangle.setFillChar('*');
    rectangle.Draw();



    return 0;
}