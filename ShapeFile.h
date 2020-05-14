#pragma once
#ifndef _SHAPEFILE_H_
#define _SHAPEFILE_H_

#include <fstream>
#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include"Shape.h"

using namespace std;

class ShapeFile
{
public:
	ShapeFile(string Filename);

	~ShapeFile();

	void Generate(string, string, string);

	void print();

	map<string, Point>point;

	map<string, Circle>circle;

	map<string, Polygon>polygon;

	map<string, Shape*>shape;

private:
	
	std::vector<Shape*> compositeShapes_;

};

#endif 