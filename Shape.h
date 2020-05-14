#pragma once

#ifndef _SHAPE_H_
#define _SHAPE_H_

#include"Edge.h"
#include<vector>
#include<memory>
#include<iostream>

using namespace std;

class Point;
class Edge;

class Shape
{
public:
	Shape();

	~Shape();

	virtual double  Circumference()const = 0;

	virtual double Area()const = 0;

	virtual void Print()const = 0;

	virtual bool IsValid()const = 0;

	static const int UnknownValue = -1;

	friend std::shared_ptr<Shape> operator &(shared_ptr<Shape>& p1, shared_ptr<Shape>& p2);

	friend std::shared_ptr<Shape> operator |(shared_ptr<Shape>& p1, shared_ptr<Shape>& p2);

private:

};


std::shared_ptr<Shape> operator &(std::shared_ptr<Shape>& p1, std::shared_ptr<Shape>& p2);


std::shared_ptr<Shape> operator |(std::shared_ptr<Shape>& p1, std::shared_ptr<Shape>& p2);


class Circle :public Shape
{
public:
	Circle(Point p, double r);

	~Circle();

	double  Circumference()const override;

	double Area()const override;

	void Print()const override;

	bool IsValid()const override;

	friend std::shared_ptr<Shape> operator &(shared_ptr<Shape>& p1, shared_ptr<Shape>& p2);

	friend std::shared_ptr<Shape> operator |(shared_ptr<Shape>& p1, shared_ptr<Shape>& p2);

private:
	Point center_;

	double radius_;
};


class Polygon :public Shape
{
public:
	Polygon(std::vector<Edge*>edges);

	~Polygon();

	double  Circumference()const override;

	double Area()const override;

	void Print()const override;

	bool IsValid()const override;

	friend std::shared_ptr<Shape> operator &(shared_ptr<Shape>& p1, shared_ptr<Shape>& p2);

	friend std::shared_ptr<Shape> operator |(shared_ptr<Shape>& p1, shared_ptr<Shape>& p2);

private:
	std::vector<Edge*>edges_;
};

#endif