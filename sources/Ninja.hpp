#pragma once
#include "Point.hpp"
#include "Character.hpp"

namespace ariel{
    class Ninja : public Character
    {
    private:
        
        int speed;

    public:
        Ninja(Point point,int num_hit, string const& name, int speed):
        Character(point,num_hit,name), speed(speed){}
        ~Ninja () override{}
        Ninja():speed(0){}
        Ninja (const Ninja& ninja):Character(ninja),speed(ninja.speed){}
        Ninja& operator=(const Ninja& ninja)
        {
            if(this!=&ninja)
            {
                speed=ninja.speed;
            }
            return *this;
        }
        Ninja (Ninja &&ninja) noexcept: Character(std::move(ninja)), speed(ninja.speed){}
        Ninja & operator=(Ninja&& ninga) noexcept{return *this;}

        void move(Character* enemy){}
        void slash(Character* enemy){}
        char* print()override{return nullptr;}
        void setSpeed(int speed)
        {
            this->speed=speed;
        }



    };

}