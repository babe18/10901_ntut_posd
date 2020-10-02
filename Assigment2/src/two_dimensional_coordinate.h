#ifndef TWO_DIMENSIONAL_COORDINATE_H
#define TWO_DIMENSIONAL_COORDINATE_H

class TwoDimensionalCoordinate {
public:
  TwoDimensionalCoordinate(double x, double y):_x(x),_y(y){
    // double ary[] = {_x, _y};
  }

  double getX() {
    // _x = floor(_x*1000)/1000.0;
    return  _x;
	}

	double getY() {
    // _y = floor(_y*1000)/1000.0;
		return _y;
	}
private:
  double _x;
  double _y;
};

#endif
