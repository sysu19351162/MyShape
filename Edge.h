#pragma once
#ifndef _EDGE_H_
#define _EDGE_H_

class Point
{
public:
	Point();//���޲ι��캯��

	Point(double, double);//�㺬�ι��캯��

	Point(Point& p);//�㸴�ƹ��캯��

	~Point();//����������

	void Print()const;

	double x_;

	double y_;
private:

};


class Edge
{
public:
	Edge();//��Ĭ�Ϲ��캯��

	Edge(Point &p1, Point &p2);//�߹��캯��

	~Edge();//����������

	double Length()const;//���Ȼ�ȡ����

	void Print()const;

private:
	Point p1_;

	Point p2_;
};
#endif