#include "./shape.h"

class Ellipse: public Shape{

public:
    Ellipse(double semiMajorAxes, double semiMinorAxes) {
      if(semiMajorAxes <= 0.0 || semiMinorAxes <= 0.0) throw std::string("This is not an ellipse!");

      _semiMajorAxes = semiMajorAxes;
      _semiMinorAxes = semiMinorAxes;
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
        double a = _semiMajorAxes;
        double b = _semiMinorAxes;
        double s = M_PI*a*b;
        return TruncateNumberDouble(s);

    }

    double perimeter() const {
        double a = _semiMajorAxes;
        double b = _semiMinorAxes;
        double l = 2*M_PI*b+4*(a-b);
        return TruncateNumberDouble(l);
    }

    string info() const {
        return "Ellipse ("+TruncateNumberStr(_semiMajorAxes)+", "+TruncateNumberStr(_semiMinorAxes)+")";
    }

  private:
    double _semiMajorAxes, _semiMinorAxes;
};
