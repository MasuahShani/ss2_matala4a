#pragma once
#include "Point.hpp"
#include "Character.hpp"

using namespace std;
namespace ariel{
    class Cowboy: public Character
    {
    private:
        int num_balls;

    public:
        static const int DEFAULT_NUM_BALLS = 6;
        static const int DEFAULT_NUM_HIT = 110;

        Cowboy(string const& name, Point& point):
        Character(point,DEFAULT_NUM_HIT,name) ,num_balls(DEFAULT_NUM_BALLS){}
        ~Cowboy()override{}
        Cowboy():num_balls(DEFAULT_NUM_BALLS){}
        Cowboy (const Cowboy& cow):
        Character(cow), num_balls(cow.num_balls){}
        Cowboy& operator=(const Cowboy& cow)
        {
            if(this!=&cow)
            {
                Character::operator=(cow);
                num_balls=cow.num_balls;
            }
            return *this;
        }
        Cowboy (Cowboy &&cow) noexcept: Character(move(cow)), num_balls(cow.num_balls){}
        Cowboy & operator=(Cowboy&& cow) noexcept
        {
            
            return *this;
        }

        void shoot(Character* enemy){}
        bool hasboolets() const
        {
            return num_balls!=0;
        }
        void reload(){}
        char* print()override{return nullptr;}
        


    };

 

}