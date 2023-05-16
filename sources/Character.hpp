#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>


#include "Point.hpp"

using namespace std;

namespace ariel{
    class Character
    {
    private:
        Point point;
        int num_hit;
        char* name;
        bool in_team;

    public:
        Character(Point& point,int num_hit, string const& name):
        point(point),num_hit(num_hit), name(new char[name.length() + 1])
        {   
            strncpy(this->name, name.c_str(),name.length());
            in_team=false;
        }
        virtual ~Character(){
        //    delete[] name;
        }
        Character():num_hit(0)
        {
            string name="name";
            this->name=new char[name.length() + 1];
            strncpy(this->name, name.c_str(),name.length());
            Point poi;
            point=poi;
        }
        Character (const Character& chara):
        point(chara.point),num_hit(chara.num_hit),
        name(chara.name){}
        Character& operator=(const Character& chara)
        {
            if(!(this==&chara))
            {
                name=chara.name;
                num_hit=chara.num_hit;
                point=chara.point;
            }
        
            return *this;
        }
        // Character (Character &&chara) noexcept :num_hit(chara.num_hit),
        // name(chara.name),point(chara.point)
        // {
        //    chara.point = nullptr;
// }
        Character(Character&& chara) noexcept
        : name(chara.name), point(move(chara.point)), num_hit(chara.num_hit)
        {
            //chara.point = nullptr;
        }
        Character & operator=(Character&& chara) noexcept
        {
            if(!(*this==chara))
            {
                name=chara.name;
                num_hit=chara.num_hit;
                point=chara.point;
            }
            
            return *this;
            
        }

        bool isAlive ()const 
        {
            return num_hit!=0;
        }
        double distance(Character& other)
        {
            return point.distance(other.point);
        }
        void hit(int num)
        {
            num_hit-=num;
            if(num_hit<0)
            {
                num_hit=0;
            }
        }
        char* getName(){return name;}
        Point getLocation(){return point;}
        virtual char* print(){return name;}
        bool operator==(const Character& chara) const
        {
            if(point.getX()==chara.point.getX() && point.getY()==chara.point.getY())
            {
                return (name==chara.name)&&(num_hit==chara.num_hit);
            }
            return false;
        }
        // bool operator==(const Character& chara) const
        // {
        //     return (name==chara.name)&&(num_hit==chara.num_hit)&&(point==chara.point);
        // }
        void setIn_team(bool bol)
        {
            in_team=bol;
        }
        bool getIn_team()
        {
            return in_team;
        }
        



    };

}
