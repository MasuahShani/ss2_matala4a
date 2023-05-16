#pragma once

#include "Team.hpp"

namespace ariel{
    class SmartTeam
    {
    private:
        
        Character** warriors;
        int amount;
        int* wich_kind;

       
    public:
        static const int SIZE = 10;
        SmartTeam(Character* leader):warriors(new Character*[SIZE]),amount(0),wich_kind(new int[SIZE])
        {
            if(Cowboy* c_le = dynamic_cast<Cowboy*>(leader))
            {
                wich_kind[amount]=1;
                warriors[amount++]=c_le;
            }
            else if (Ninja* n_le = dynamic_cast<Ninja*>(leader))
            {
               wich_kind[amount]=2;
               warriors[amount++]=n_le;
            }
            else
            {
                throw std::invalid_argument("invalid_argument");
            }
            
        }
        ~SmartTeam()
        {
            // for(int i=0; i<amount;i++)
            // {
            //     delete warriors[i];
            // }
            // delete[] warriors;
            // delete[]wich_kind;
        }//delete all the warriros and the arrs
        SmartTeam():warriors(new Character*[SIZE]),amount(0),wich_kind(new int[SIZE]){}
        SmartTeam (const SmartTeam& team):warriors(new Character*[SIZE]),amount(0),wich_kind(new int[SIZE]){}/////////////////////not good
        SmartTeam& operator=(const SmartTeam& team)
        {
            if(this!=&team)
            {
                //copy
            }
            return *this;
        }
         SmartTeam (SmartTeam &&team) noexcept: warriors(nullptr), amount(0), wich_kind(nullptr)////////////////////not good
         {
            try {
                warriors = new Character*[SIZE];
                wich_kind = new int[SIZE];
            } catch (const std::bad_alloc&) {
                std::cerr << "Error: memory allocation failed." << std::endl;
                exit(1);
            }
        }
        
        SmartTeam & operator=(SmartTeam&& team) noexcept{return *this;}

        void add(Character* warrior){}
        void attack(Team* other){}
        int stillAlive()const{return amount;}
        void print(){}
//////////////////////לא הבנתי מה ההבדל.!!!
    };
    
    
    
}