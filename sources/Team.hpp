#pragma once
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <typeinfo>


namespace ariel{
    class Team
    {
    private:
        
        Cowboy** c_warriors;
        Ninja** n_warriors;
        int amount_cowboy;
        int amount_ninja;
        int leader;

       
    public:

        static const int SIZE = 10;
        Team(Character* leader):c_warriors(new Cowboy*[SIZE]),
        n_warriors(new Ninja*[SIZE]),amount_cowboy(0),
        amount_ninja(0),leader(0)
        {
            if(Cowboy* c_le = dynamic_cast<Cowboy*>(leader))
            {
                if(c_le->getIn_team())
                {
                    throw std::invalid_argument("invalid_argument");
                }
                this->leader=1;
                c_warriors[amount_cowboy++]=c_le;
                c_le->setIn_team(true);


            }
            else if (Ninja* n_le = dynamic_cast<Ninja*>(leader))
            {
                if(n_le->getIn_team())
                {
                    throw std::invalid_argument("invalid_argument");
                }
                this->leader=2;
                n_warriors[amount_ninja++]=n_le;

            }
            else
            {
                throw std::invalid_argument("invalid_argument");
            }
            
        }
        ~Team()
        {
            // for(int i=0; i<amount_cowboy;i++)
            // {
            //     delete c_warriors[i];
            // }
            // delete[] c_warriors;
            // for(int i=0; i<amount_ninja;i++)
            // {
            //     delete n_warriors[i];
            // }
            // delete[] n_warriors;

        }//delete all the warriros and the arrs
        Team():c_warriors(new Cowboy*[SIZE]),
        n_warriors(new Ninja*[SIZE]),amount_cowboy(0),
        amount_ninja(0),leader(0)
        {}
        Team (const Team& team):c_warriors(new Cowboy*[SIZE]),
        n_warriors(new Ninja*[SIZE]),amount_cowboy(0),
        amount_ninja(0),leader(0)
        {}////not good
        Team& operator=(const Team& team)
        {
            if(this!=&team)
            {
                //dosome
            }
            return *this;
        }

        Team (Team &&team) noexcept: c_warriors(nullptr),n_warriors(nullptr), amount_cowboy(0),amount_ninja(0),leader(0) {
            try {
                c_warriors = new Cowboy*[SIZE];
                n_warriors = new Ninja*[SIZE];
            } catch (const std::bad_alloc&) {
                std::cerr << "Error: memory allocation failed." << std::endl;
                exit(1);
            }

        }
            

        Team & operator=(Team&& team) noexcept{return *this;}

        void add(Character* warrior)
        {
            if(Cowboy* c_w = dynamic_cast<Cowboy*>(warrior))
            {
                if(c_w->getIn_team())
                {
                    throw std::invalid_argument("invalid_argument");
                }
                
                c_warriors[amount_cowboy++]=c_w;
                c_w->setIn_team(true);


            }
            else if (Ninja* n_w = dynamic_cast<Ninja*>(warrior))
            {
                if(n_w->getIn_team())
                {
                    throw std::invalid_argument("invalid_argument");
                }
                n_warriors[amount_ninja++]=n_w;
                n_w->setIn_team(true);

            }
            else
            {
                throw std::invalid_argument("invalid_argument");
            }

        }
        void attack(Team* other)///not good
        {
            other->amount_cowboy=0;
            other->amount_ninja=0;
        }
        int stillAlive()const{return amount_cowboy+amount_ninja;}
        void print(){}
    };
    
    
    
}
