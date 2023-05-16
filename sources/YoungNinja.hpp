#pragma once
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel{
    class YoungNinja : public Ninja
    {
    private:
      
    public:
        static const int DEFAULT_SPEED = 14;
        static const int DEFAULT_NUM_HIT = 100;

        YoungNinja(string const& name, Point point):
        Ninja(std::move(point),DEFAULT_NUM_HIT,name, DEFAULT_SPEED){}
        ~YoungNinja () override{}
        YoungNinja()
        {
            setSpeed(DEFAULT_SPEED);
        }
        
        YoungNinja (const YoungNinja& ninja):Ninja(ninja)
        {
            
        }
        YoungNinja& operator=(const YoungNinja& ninja){return *this;}
        YoungNinja (YoungNinja &&ninja) noexcept{}
        YoungNinja & operator=(YoungNinja&& ninga) noexcept{return *this;}
    };

}