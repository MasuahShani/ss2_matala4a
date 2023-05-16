#pragma once
#include <iostream>
#include <cmath>

using namespace std;
namespace ariel{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(double first, double second):x(first),y(second){}
        ~Point(){}
        Point():x(0),y(0){}
        Point (const Point& point):x(point.x),y(point.y){}
        Point& operator=(const Point& point)
        {
            if(!(this==&point))
            {
                x=point.x;
                y=point.y;
            }
            return *this;
        }
        Point (Point &&point) noexcept:x(point.x),y(point.y){}
        
        Point & operator=(Point&& point) noexcept
        {
            
            x=point.x;
            y=point.y;
        
            
            return *this;
        }

        double distance(Point& point) const
        {
            double dlx = x - point.x;
            double dly = y - point.y;
          
            return sqrt(dlx*dlx + dly*dly);
        }
        double getX()const
        {
            return x;
        }
        double getY()const
        {
            return y;
        }
        void print(){}
        bool operator==(const Point& point)const
        {
            return (x==point.x)&&(y==point.y);
        }
        friend Point moveTowards(Point const& src, Point const& dst, double dis)
        {
            double shipua=(src.y-dst.y)/(src.x-dst.x);
            double angle = atan(shipua);
            double ans_x = src.x + dis * cos(angle);
            double ans_y = dst.y + dis * sin(angle);
            return Point(ans_x, ans_y);

        }

    };
}