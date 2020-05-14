#pragma once
#ifndef _EDGE_H_
#define _EDGE_H_

class Point
{
public:
	Point();//点无参构造函数

	Point(double, double);//点含参构造函数

	Point(Point& p);//点复制构造函数

	~Point();//点析构函数

	void Print()const;

	double x_;

	double y_;
private:

};


class Edge
{
public:
	Edge();//线默认构造函数

	Edge(Point &p1, Point &p2);//线构造函数

	~Edge();//线析构函数

	double Length()const;//长度获取函数

	void Print()const;

private:
	Point p1_;

	Point p2_;
};
#endif