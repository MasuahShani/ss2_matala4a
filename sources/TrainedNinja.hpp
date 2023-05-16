#pragma once
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja : public Ninja
    {
    private:

    public:
        static const int DEFAULT_SPEED = 12;
        static const int DEFAULT_NUM_HIT = 120;

        TrainedNinja(string const& name, Point point):
        Ninja(std::move(point),DEFAULT_NUM_HIT,name, DEFAULT_SPEED){}
        ~TrainedNinja () override{}
        TrainedNinja()
        {
            setSpeed(DEFAULT_SPEED);
        }
        
        TrainedNinja (const TrainedNinja& ninja):Ninja(ninja)
        {
            
        }
        TrainedNinja& operator=(const TrainedNinja& ninja){return *this;}
        TrainedNinja (TrainedNinja &&ninja) noexcept{}
        TrainedNinja & operator=(TrainedNinja&& ninga) noexcept{return *this;}


    };

}