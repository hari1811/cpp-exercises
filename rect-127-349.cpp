//Name : K Haripriya , Employee ID : 127349

#include <iostream>
using namespace std;

//point class
class POINT {

public:
	float x, y;

	POINT(float x, float y): x(x), y(y){}
};

//rectangle class
class RECT {
	POINT top_left, bottom_right;

public:
	RECT(POINT tl, POINT br) : top_left(tl), bottom_right(br) {

		if (tl.x >= br.x || tl.y <= br.y) {
			cout << "A rectangle cannot be created with the given points!" << endl;

			top_left = POINT(0, 1);
			bottom_right = POINT(1, 0);
			cout << "Rectangle with default coordinates (0,1) and (1,0) created." << endl;
		}
		else {
			cout << "rectangle created with coordinates";
			cout << "(" << tl.x << ", " << tl.y << ") and (" << br.x << ", " << br.y << ")" << endl;
		}
	}

	bool x_on_rect(float inp){
		return (inp == top_left.x || inp == bottom_right.x);
	}

	bool y_on_rect(float inp){
		return (inp == top_left.y || inp == bottom_right.y);
	}

	bool x_on_or_in_rect(float inp){
		return (inp >= top_left.x && inp <= bottom_right.x);
	}

	bool y_on_or_in_rect(float inp) {
		return (inp <= top_left.y && inp >= bottom_right.y);
	}
};


/**
*	@Function	IsPointOnRect
*	@returns    1 if the point pt lies on the boundary of rect
*	   	        0 otherwise
**/
int  IsPointOnRect(RECT rect, POINT pt) {
	if ((rect.x_on_rect(pt.x) && rect.y_on_or_in_rect(pt.y)) ||
		(rect.y_on_rect(pt.y) && rect.x_on_or_in_rect(pt.x)))
		return 1;
	else
		return 0;
}


/**
*	@Function	IsPointOnOrInRect
*	@returns    1 if the point pt lies within or on the boundary of rect
*	   	        0 otherwise
**/
int  IsPointOnOrInRect(RECT rect, POINT pt) {
	if (rect.x_on_or_in_rect(pt.x) && rect.y_on_or_in_rect(pt.y))
		return 1;
	else
		return 0;
}



void main() {

	//Creating rectangle
	POINT a(0, 1);
	POINT b(1, 0);
	RECT rect1(a, b);

	//Creating test points
	POINT test1(0, 0);
	POINT test2(0.5, 1);
	POINT test3(0.2, 0.5);
	POINT test4(5, 5);

	//Testing
	cout << "\n----------------------\n";
	cout << "point (" << test1.x << ", " << test1.y << ") onRECT? : " << IsPointOnRect(rect1, test1) << endl;
	cout << "point (" << test1.x << ", " << test1.y << ") on_or_in_RECT? : " << IsPointOnOrInRect(rect1, test1) << endl;

	cout << "\n----------------------\n";
	cout << "point (" << test2.x << ", " << test2.y << ") onRECT? : " << IsPointOnRect(rect1, test2) << endl;
	cout << "point (" << test2.x << ", " << test2.y << ") on_or_in_RECT? : " << IsPointOnOrInRect(rect1, test2) << endl;

	cout << "\n----------------------\n";
	cout << "point (" << test3.x << ", " << test3.y << ") onRECT? : " << IsPointOnRect(rect1, test3) << endl;
	cout << "point (" << test3.x << ", " << test3.y << ") on_or_in_RECT? : " << IsPointOnOrInRect(rect1, test3) << endl;

	cout << "\n----------------------\n";
	cout << "point (" << test4.x << ", " << test4.y << ") onRECT? : " << IsPointOnRect(rect1, test4) << endl;
	cout << "point (" << test4.x << ", " << test4.y << ") on_or_in_RECT? : " << IsPointOnOrInRect(rect1, test4) << endl;

}