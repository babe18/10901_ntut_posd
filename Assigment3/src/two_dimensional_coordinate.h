
#ifndef TWO_DIMENSIONAL_COORDINATE
#define TWO_DIMENSIONAL_COORDINATE
class TwoDimensionalCoordinate {
private:
	double _x, _y;

public:
    TwoDimensionalCoordinate(double x, double y):_x(x),_y(y){}

    double getX() {
        return _x;
	}

	double getY() {
		return _y;
	}
};
#endif