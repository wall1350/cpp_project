#include "./shape.h"
class Rectangle: public Shape {
public:
    Rectangle(double length, double width) {
      if(length <= 0.0 || width <= 0.0) throw std::string("This is not a rectangle!");

      _width = width;
      _length = length;
    }

    string TruncateNumberStr(double num) const{
      std::ostringstream streamObj3;
      streamObj3 << std::fixed;
      streamObj3 << setprecision(3);
      streamObj3 << num;
      return streamObj3.str();
    }

    double TruncateNumberDouble(double num) const{
      string s=TruncateNumberStr(num);
      return stod(s);
    }

    double area() const {
        return TruncateNumberDouble(_width*_length);
    }

    double perimeter() const {
        return TruncateNumberDouble((_width+_length)*2.0);
    }

    string info() const {
        return "Rectangle ("+TruncateNumberStr(_length)+", "+TruncateNumberStr(_width)+")";
    }

  private:
    double _width, _length;
  };
