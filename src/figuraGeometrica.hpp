/**
 * Abstract class to represent generic primitive objects
 * @author Layza Amorim
 */


#ifndef PROJECT_FIGURAGEOMETRICA_HPP
#define PROJECT_FIGURAGEOMETRICA_HPP


#include "sculptor.hpp"

class FiguraGeometrica {
public:
    virtual void draw(Sculptor &t) = 0; /// instructs an object to draw itself into an object of type Sculptor
};


#endif //PROJECT_FIGURAGEOMETRICA_HPP
