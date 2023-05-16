#pragma once

#include "Team.hpp"

namespace ariel{
    class Team2 
    {
    private:
        
        Character** warriors;
        int amount;
        int* wich_kind;

       
    public:
        static const int SIZE = 10;
        Team2(Character* leader):warriors(new Character*[SIZE]),amount(0),wich_kind(new int[SIZE])
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
        ~Team2()
        {
            // for(int i=0; i<amount;i++)
            // {
            //     delete warriors[i];
            // }
            // delete[] warriors;
            // delete[]wich_kind;
        }//delete all the warriros and the arrs
        Team2():warriors(new Character*[SIZE]),amount(0),wich_kind(new int[SIZE]){}
        Team2 (const Team2& team):warriors(new Character*[SIZE]),amount(0),wich_kind(new int[SIZE]){}

        Team2 (Team2 &&team) noexcept: warriors(nullptr), amount(0), wich_kind(nullptr)////////////////////not good
         {
            try {
                warriors = new Character*[SIZE];
                wich_kind = new int[SIZE];
            } catch (const std::bad_alloc&) {
                std::cerr << "Error: memory allocation failed." << std::endl;
                exit(1);
            }
        }
        
        Team2& operator=(const Team2& team)
        {
            if(this!=&team)
            {
                //copy
            }
            return *this;
        }
      
        Team2 & operator=(Team2&& team) noexcept{return *this;}

        void add(Character* warrior){}
        void attack(Team* other){}
        int stillAlive()const{return amount;}
        void print(){}
//////////////////////לא הבנתי מה ההבדל.!!!
    };
    
    
    
}