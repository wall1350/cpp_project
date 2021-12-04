#if !defined( EXAMPLE_H )
#define EXAMPLE_H
#include <math.h>
#include <stdexcept>
#include <gtest/gtest.h>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
};
#endif
