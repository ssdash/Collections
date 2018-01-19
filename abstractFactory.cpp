#include<iostream>
#include<string>
using namespace std;

class Shape
{
    public:
	Shape()
	{
	    id = total++;
	}
	virtual void draw() = 0;
    protected:
	int id;
	static int total;
};
int Shape::total = 0;

class Circle : public Shape
{
    public:
	void draw()
	{
	    cout << "Circle " << id << ":draw" << endl;
	}
};


class Square: public Shape
{
    public:
	void draw()
	{
	    cout << "Square " << id << ":draw" << endl;
	}
};


class Ellipse: public Shape
{
    public:
	void draw()
	{
	    cout << "Ellipse " << id << ":draw" << endl;
	}
};

class Rectangle: public Shape
{
    public:
	void draw()
	{
	    cout << "Rectangle " << id << ":draw" << endl;
	}
};

class Factory
{
    public:
	virtual Shape* createCurvedInstance() = 0;
	virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory
{
    Shape* createCurvedInstance()
    {
	return new Circle;
    }
    Shape* createStraightInstance()
    {
	return new Square;
    }
};

class RobustShapeFactory : public Factory
{
    Shape* createCurvedInstance()
    {
	return new Ellipse;
    }
    Shape* createStraightInstance()
    {
	return new Rectangle;
    }
};

int main()
{
    Factory* factory = new SimpleShapeFactory();
    Shape* shapes[2];
    shapes[0] = factory->createCurvedInstance();
    shapes[1] = factory->createStraightInstance();


    Factory* factory1 = new RobustShapeFactory();
    Shape* shapes1[2];
    shapes1[0] = factory1->createCurvedInstance();
    shapes1[1] = factory1->createStraightInstance();

    for(int i=0;i<2;i++)
    {
	shapes[i]->draw();
    }

    for(int i=0;i<2;i++)
    {
	shapes1[i]->draw();
    }

    return 0;
}
