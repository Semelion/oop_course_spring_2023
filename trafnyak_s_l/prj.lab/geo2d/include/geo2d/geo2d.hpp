#ifndef UNTITLED_GEO2D_H
#define UNTITLED_GEO2D_H

#include <cstdint>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace geo2d{
    class figure{
    public:
        double thickness = 1;
        double transparency = 0.5;
        int r = 0;
        int g = 0;
        int b = 0;
    }

    class point : figure{
        
    }

    class canvas{
    public:
        Rational() = default;
        Rational(const canvas &) = default;
        Rational(canvas &&) = default;

    private:
        double x_start = 0.0;
        double y_start = 0.0;
        double x_end = 0.0;
        double y_end = 0.0;
    }
}

#endif
