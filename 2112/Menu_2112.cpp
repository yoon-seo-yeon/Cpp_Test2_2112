//2112 윤서연
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point() {}
	void point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	~Point() {}
	int getX() { return x; }
	int getY() { return y; }
};
class Circle {
private:
	Point p;
	static int cnt;
	int r;
	static const double PI;
public:
	Circle() { cout << ++cnt << "번째 원 생성" << endl; }
	~Circle() { cout << cnt-- << "번째 원 소멸" << endl; }
	void area(Point& p, int r) {
		this->p = p;
		this->r = r;
		cout << "점의 좌표(" << p.getX() << ", " << p.getY() << ")와 반지름 " << r << "인 원의 넓이  : " << (r * r * PI) << endl;
	}
};
class Line {
private:
	Point p1, p2;
	static int cnt;
	char* name;
public:
	Line() { cout << ++cnt << "번째 선 생성" << endl; }
	void Line_name(char* line_name) {
		this->name = new char[strlen(line_name) + 1];
		strcpy(this->name, line_name);
	}
	void line_length(Point &p1, Point &p2) {
		this->p1 = p1;
		this->p2 = p2;
		int a = p2.getX() - p1.getX();
		int b = p2.getY() - p1.getY();
		cout << "점 (" << p1.getX() << ", " << p1.getY() << ")와 점(" << p2.getX() << ", " << p2.getY() << ")를 잇는 " << name << "의 길이 : " << sqrt((a * a) + (b * b)) << endl;
	}
	~Line() {
		delete[] name;
		cout << cnt-- << "번째 선 소멸" << endl;
	}
};

int Circle::cnt = 0;
int Line::cnt = 0;
const double Circle::PI = 3.141592;

int main() {
	srand((unsigned)time(0));
	int select, cir_n, line_n;	//메뉴 선택, 원 선 갯수 입력
	char line_name[11];

	while (true) {
		cout << "============" << endl << "== SELECT ==" << endl << "============" << endl;
		cout << "1. 원의 넓이 구하기" << endl << "2. 선 그리기" << endl << "0. 종료" << endl;
		cout << "메뉴 선택 == > ";
		cin >> select;
		cout << endl;

		if (select == 1) {
			cout << "원의 갯수를 입력하세요. ";
			cin >> cir_n;

			Point* p = new Point[cir_n];
			Circle* cir = new Circle[cir_n];

			for (int i = 0; i < cir_n; i++) {
				p[i].point(rand() % 101, rand() % 101);
				cir[i].area(p[i], rand() % 10 + 1);
			}
			for (int i = cir_n-1; i >= 0; i--) { cir[i].~Circle(); }
			for (int i = 0; i < cir_n; i++) { p[i].~Point(); }
		}
		else if (select == 2) {
			cout << "선의 갯수를 입력하세요. ";
			cin >> line_n;

			Line* line = new Line[line_n];
			Point* p1 = new Point[line_n];
			Point* p2 = new Point[line_n];
			
			for (int i = 0; i < line_n; i++) {
				cout << "선의 이름을 입력하세요. : ";
				cin >> line_name;
				line[i].Line_name(line_name);
			}
			for (int i = 0; i < line_n; i++) {
				p1[i].point(rand() % 61 - 30, rand() % 61 - 30);
				p2[i].point(rand() % 61 - 30, rand() % 61 - 30);
				line[i].line_length(p1[i], p2[i]);
			}
			for (int i = line_n-1; i >= 0; i--) { line[i].~Line(); }
			for (int i = 0; i < line_n; i++) {
				p1[i].~Point();
				p2[i].~Point();
			}
		}
		else if (select == 0) { return 0; }
		else { cout << "메뉴를 다시 선택하세요." << endl; }
		cout << endl << endl << endl;
	}
	return 0;
}