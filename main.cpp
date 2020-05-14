#include<iostream>
#include<istream>
#include<fstream>
#include<string>
#include<memory>
#include<vector>
#include<iterator>
#include<map>
#include"Edge.h"
#include"Shape.h"
#include"ShapeFile.h"

using namespace std;

int main()
{
	string filename = "shapes.txt";

	ShapeFile shapefile(filename);

	shapefile.print();

}