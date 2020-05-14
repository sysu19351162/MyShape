#include"Shape.h"

#include<iostream>
#include<memory>
#include<string>
#include<math.h>
#include <iterator>

using std::cout;
using std::endl;
using std::shared_ptr;

Point::Point():x_(0),y_(0)//点无参构造函数
{
	cout << "calling the Point constructor" << endl;
}


Point::Point(double x, double y) :x_(x), y_(y)//点含参构造函数
{
	cout << "calling the Point constructor" <<  endl;
}


Point::Point(Point &p):x_(p.x_),y_(p.y_)//点复制构造函数
{
	cout << "calling the Point constructor" << endl;
}


Point::~Point()//点析构函数
{
	cout << "calling the Point destructor" << endl;
}


void Point::Print()const
{
	cout << "(" << x_ << "," << y_ << ")" << endl;
}


Edge::Edge()//线无参构造函数
{
	Point p1,p2;

	p1_ = p1;

	p2_ = p2;

	cout << "calling the Edge constructor" << endl;
}


Edge::Edge(Point& p1, Point& p2) :p1_(p1), p2_(p2)//线含参构造函数
{
	cout << "calling the Edge constructor" << endl;
}


Edge::~Edge()//线析构函数
{
	cout << "calling the Edge destructor" << endl;
}


double Edge::Length()const//长度获取函数
{
	double l,x,y;

	x = p1_.x_ * p1_.x_ - p2_.x_ - p2_.x_;//求出x方向上的平方差

	y = p1_.y_ * p1_.y_ - p2_.y_ * p2_.y_;//求出y方向上的平方差

	if (x < 0)x = -x;//取绝对值

	if (y < 0)y = -y;//取绝对值

	l = sqrt(x + y);//计算长度

	return l;
}


void Edge::Print()const
{
	cout << "the information of this Edge:" << endl;

	cout << "P1:";

	p1_.Print();

	cout << "P2:";

	p2_.Print();
}


Shape::Shape()
{
	cout << "calling the Shape constructor" << endl;
}


Shape::~Shape()
{
	cout << "calling the Shape destructor" << endl;
}

std::shared_ptr<Shape> operator &(shared_ptr<Shape>& p1, shared_ptr<Shape>& p2)
{
	if (std::dynamic_pointer_cast<Polygon>(p1) && std::dynamic_pointer_cast<Polygon>(p2))
	{
		return std::make_shared<Polygon>();
	}
	else
	{
		if (std::dynamic_pointer_cast<Circle>(p1) && std::dynamic_pointer_cast<Circle>(p2))
		{
			return std::make_shared<Circle>();
		}
		else
			return std::make_shared<Shape>();
	}
}


std::shared_ptr<Shape> operator |(shared_ptr<Shape>& p1, shared_ptr<Shape>& p2)
{
	if (std::dynamic_pointer_cast<Polygon>(p1) && std::dynamic_pointer_cast<Polygon>(p2))
	{
		return std::make_shared<Polygon>();
	}
	else
	{
		if (std::dynamic_pointer_cast<Circle>(p1) && std::dynamic_pointer_cast<Circle>(p2))
		{
			return std::make_shared<Circle>();
		}
		else
			return std::make_shared<Shape>();
	}

}


Circle::Circle(Point p, double r):center_(p),radius_(r)
{
	cout << "calling the Circle constructor" << endl;
}


Circle::~Circle()
{
	cout << "calling the Circle destructor" << endl;
}


double Circle::Circumference()const//周长获取函数
{
	cout << "calling the Circumference function" << endl;

	double c;//周长

	c = 2 * 3.14 * radius_;

	return c;
}


double Circle::Area()const//面积获取函数
{
	cout << "calling the Area function" << endl;

	double a;//面积

	a = 3.14 * radius_ * radius_;

	return a;
}


void Circle::Print()const//打印函数
{
	cout << "center: (" << center_.x_ << "," << center_.y_ << ")" << endl;//圆心

	cout << "radius: " << radius_ << endl;								  //半径

	cout << "Area: " << (*this).Area() << endl;							  //面积

	cout << "Circumference: " << (*this).Circumference() << endl;		  //周长
}


bool Circle::IsValid()const
{
	if (radius_ > 0)
		return true;
	else
		return false;
}


Polygon::Polygon(std::vector<Edge*>edges)
{
	cout << "calling the Polygon constructor" << endl;

	for (auto i = edges.begin(); i == edges.end(); i++)
	{
		edges_.push_back(*i);
	}
}


Polygon::~Polygon()
{
	cout << "calling the Polygon destructor" << endl;
}


double Polygon::Circumference()const
{
	double c = 0;//周长

	for (auto i : edges_)
	{
		c = c + (*i).Length();
	}

	return c;
}


double Polygon::Area()const
{
	return UnknownValue;
}


void Polygon::Print()const//打印函数
{
	cout << "calling the print function" << endl;

	for (auto i : edges_)							//打印Edge信息
	{
		i->Print();
	}

	cout << "Area:" << this->Area() << endl;		//打印面积

	cout << "Circumference:" << this->Circumference() << endl;//打印周长
}


bool Polygon::IsValid()const
{
	return true;
}

