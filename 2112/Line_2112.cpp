//2112 ������

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
		cout << "�� ����" << endl;
	}
	void line_length() {
		int a = p2.getX() - p1.getX();
		int b = p2.getY() - p1.getY();
		cout << "�� (" << p1.getX() << ", "<<p1.getY()<<")�� ��("<<p2.getX()<<", "<<p2.getY()<<")�� �մ� "<<name<<"�� ���� : "<< sqrt((a * a) + (b * b)) << endl;
	}
	~Line() {
		cout << "�� �Ҹ�" << endl;
	}
};
int main() {
	srand((unsigned)time(0));

	char line_name[11];
	cout << "�� �̸��� �Է��ϼ��� : ";
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