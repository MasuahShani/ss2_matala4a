#pragma once
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel{
    class OldNinja : public Ninja
    {
    private:
      
    public:
        static const int DEFAULT_SPEED = 8;
        static const int DEFAULT_NUM_HIT = 150;

        OldNinja(string const& name, Point point):
        Ninja(std::move(point),DEFAULT_NUM_HIT,name, DEFAULT_SPEED){}
        ~OldNinja () override{}
        OldNinja()
        {
            setSpeed(DEFAULT_SPEED);
        }
        
        OldNinja (const OldNinja& ninja):Ninja(ninja)
        {
            
        }
        OldNinja& operator=(const OldNinja& ninja){return *this;}
        OldNinja (OldNinja &&ninja) noexcept{}
        OldNinja & operator=(OldNinja&& ninga) noexcept{return *this;}


    };

}