#include<iostream>
#include<istream>
#include<fstream>
#include<string>
#include<memory>
#include<vector>
#include<iterator>
#include<map>
#include"Shape.h"
#include"ShapeFile.h"

class ShapeFile;

using namespace std;

ShapeFile::ShapeFile(string Filename)
{
	fstream is(Filename);

	cout << "calling the ShapeFile constructor" << endl;

	char sign[2] = "#";

	char p[2] = "i";

	char c[2] = "C";

	char poly[2] = "l";//

	string text;

	vector<string> File;

	while (getline(is, text))//将文档每个句子分开
	{
		File.push_back(text);
	}

	for (auto i : File)
	{
		string s;

		if (i[1] == sign[0])//打印分隔语句
		{
			cout << i << endl;

			continue;
		}
		string seperator = " :,";

		string::size_type wordstartpods = i.find_first_not_of(seperator);

		string::size_type wordendpots = i.find_first_of(seperator);

		//读取对象名
		for (; wordstartpods != wordendpots; wordstartpods++)
		{
			s = s + i[wordstartpods];
		}

		size_t pos = 0;

		double x, y;

		//判断对象是否为Point
		if (i[2] == p[0])
		{
			wordstartpods = i.find_first_of("(", pos);

			wordendpots = i.find_first_of(",",wordstartpods);

			string num = {};

			for (; wordstartpods + 1 != wordendpots; wordstartpods++)
			{
				num = num + i[wordstartpods + 1];
			}

			x = atoi(num.c_str());

			wordstartpods = wordendpots;

			wordendpots = i.find_first_of(")", wordstartpods);

			string num1 = {};

			for (; wordstartpods + 1 != wordendpots; wordstartpods++)
			{
				num1 = num1 + i[wordstartpods+1];
			}

			y = atoi(num.c_str());

			Point p(x, y);

			this->point.insert({ s, p});

			continue;
		}

		//判断对象是否为Circle
		if (i[0] == c[0])
		{
			wordstartpods = i.find_first_of(" ", pos);

			wordendpots = i.find_first_of(seperator, wordstartpods);

			string center;

			for (; wordstartpods + 1 != wordendpots; wordstartpods++)//读取中心点
			{
				center = center + i[wordstartpods + 1];
			}

			string num;

			int number;

			wordstartpods++;

			while (wordstartpods++ != string::npos)
			{
				num = num + i[wordstartpods];
			}

			number = atoi(num.c_str());

			Circle c(point.find(center), number);

			this->shape.insert({ s,&c });

			continue;
		}

		//判断对象是否为Polygon
		if (i[2] == poly[0])
		{
			vector<Point> points;

			vector<Edge*> edges;

			vector<Edge> edge;

			wordstartpods = i.find_first_of(" ", wordendpots);

			//读取每一个顶点
			while (wordstartpods != string::npos)
			{
				string p;;

				for (; wordstartpods + 1 != wordendpots; wordstartpods++)
				{
					p = p + i[wordstartpods + 1];
				}

				points.push_back(point.find(p));

				wordstartpods++;
			}

			Edge e(*points.begin(), *points.end());

			edges.push_back(e);

			for (; points.begin() != points.end(); points.begin()++)
			{
				Edge e(*(points.begin()), *(points.begin() + 1));

				edge.push_back(e);
			}

			for (auto i : edge)
			{
				edges.push_back(&i);
			}

			Polygon poly(edges);

			this->shape.insert({s,&poly});

			continue;
		}
	}
}


ShapeFile::~ShapeFile()
{
	cout << "calling the ShapeFile destructor" << endl;
}


void ShapeFile::Generate(string s1, string s2, string sign)
{
	string sig1 = "&";
	string sig2 = "|";

	Shape* s;

	shared_ptr<Shape> s3, s4;

	if (sign[0] == sig1[0])
		s.get(s3.reset(shape.find(s1)) & s4.reset(shape.find(s1));
	if (sign[0] == sig2[0])
		s.get(s3.reset(&shape.find(s1)) | s4.reset(shape.find(s2)));
}


void ShapeFile::print()
{
	for (auto i : (*this).compositeShapes_)
	{
		(*i).Print();
	}
}