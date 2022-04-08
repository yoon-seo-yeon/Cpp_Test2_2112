//2112 윤서연

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Point {
private:
	int x,y;
public:
	Point(int x, int y) : x(x), y(y) {}
	int getX() { return x;  }
	int getY() { return y;  }
};
class Line {
	Point p1, p2;
	char* name;
public:
	Line(Point& p1, Point& p2, char* line_name) : p1(p1), p2(p2){
		name = new char[strlen(line_name)+1];
		strcpy(name, line_name);
		cout << "선 생성" << endl;
	}
	void line_length() {
		int a = p2.getX() - p1.getX();
		int b = p2.getY() - p1.getY();
		cout << "점 (" << p1.getX() << ", "<<p1.getY()<<")와 점("<<p2.getX()<<", "<<p2.getY()<<")를 잇는 "<<name<<"의 길이 : "<< sqrt((a * a) + (b * b)) << endl;
	}
	~Line() {
		cout << "선 소멸" << endl;
	}
};
int main() {
	srand((unsigned)time(0));

	char line_name[11];
	cout << "선 이름을 입력하세요 : ";
	cin >> line_name;

	int x, y;

	x = rand() % 61 - 30;
	y = rand() % 61 - 30;
	Point p1(x, y);

	x = rand() % 61 - 30;
	y = rand() % 61 - 30;
	Point p2(x, y);

	Line line(p1, p2, line_name);
	line.line_length();

	return 0;
}