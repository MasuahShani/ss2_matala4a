#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <algorithm> // For __gcd; taken from the internet
#include <typeinfo> // For typeid(...)
#include <sstream>

#include "sources/Point.hpp"
#include "sources/SmartTeam.hpp"
#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("constractors do not throw")
{
    CHECK_NOTHROW(Point p1(1,1));
    Point p1(1,1);
    CHECK_NOTHROW(Point p2);
    Point p2;
    CHECK_NOTHROW(Point p3(p2));

    CHECK_NOTHROW(Character c1(p1,5,"name"));
    CHECK_NOTHROW(Character c2);
    Character c2;
    CHECK_NOTHROW(Character c3(c2));

    CHECK_NOTHROW(Cowboy b1("name",p1));
    CHECK_NOTHROW(Cowboy b2);
    Cowboy b2;
    CHECK_NOTHROW(Cowboy b3(b2));

    CHECK_NOTHROW(Ninja n1(p1,6,"name",6));
    CHECK_NOTHROW(Ninja n2);
    Ninja n2;
    CHECK_NOTHROW(Ninja n3(n2));

    CHECK_NOTHROW(OldNinja on1("name",p1));
    CHECK_NOTHROW(OldNinja on2);
    OldNinja on2;
    CHECK_NOTHROW(OldNinja on3(on2));

    CHECK_NOTHROW(TrainedNinja tn1("name",p1));
    CHECK_NOTHROW(TrainedNinja tn2);
    TrainedNinja tn2;
    CHECK_NOTHROW(TrainedNinja tn3(tn2));

    CHECK_NOTHROW(YoungNinja yn1("name",p1));
    CHECK_NOTHROW(YoungNinja yn2);
    YoungNinja yn2;
    CHECK_NOTHROW(YoungNinja yn3(yn2));

   
    CHECK_NOTHROW(Team t2(&b2));
    CHECK_NOTHROW(Team t2(&n2));
    CHECK_NOTHROW(Team t2(&on2));
    CHECK_NOTHROW(Team t2(&tn2));
    CHECK_NOTHROW(Team t2(&yn2));
    CHECK_NOTHROW(Team t2);
    Team t2;
    CHECK_NOTHROW(Team t3(t2));

    
    CHECK_NOTHROW(Team2 t2(&b2));
    CHECK_NOTHROW(Team2 t2(&n2));
    CHECK_NOTHROW(Team2 t2(&on2));
    CHECK_NOTHROW(Team2 t2(&tn2));
    CHECK_NOTHROW(Team2 t2(&yn2));
    CHECK_NOTHROW(Team2 t2);
    Team2 t22;
    CHECK_NOTHROW(Team2 t3(t22));

   
    CHECK_NOTHROW(SmartTeam t2(&b2));
    CHECK_NOTHROW(SmartTeam t2(&n2));
    CHECK_NOTHROW(SmartTeam t2(&on2));
    CHECK_NOTHROW(SmartTeam t2(&tn2));
    CHECK_NOTHROW(SmartTeam t2(&yn2));
    CHECK_NOTHROW(SmartTeam st2);
    SmartTeam st2;
    CHECK_NOTHROW(SmartTeam t3(st2));
    
    
}

TEST_CASE("constractor throws")
{
    Character c2;
    Point p1;
    //add regular charcter to teem
    CHECK_THROWS_AS(SmartTeam t1(&c2), std::invalid_argument);
    CHECK_THROWS_AS(Team2 t1(&c2), std::invalid_argument);
    CHECK_THROWS_AS(Team t1(&c2), std::invalid_argument);

    //negative 
    CHECK_THROWS_AS(Ninja n1(p1,-6,"name",6), std::invalid_argument);
    CHECK_THROWS_AS(Ninja n1(p1,6,"name",-6), std::invalid_argument);
    CHECK_THROWS_AS(Ninja n1(p1,-6,"name",-6), std::invalid_argument);

    CHECK_THROWS_AS(Point p2(-1,1), std::invalid_argument);
    CHECK_THROWS_AS(Point p2(-1,-1), std::invalid_argument);
    CHECK_THROWS_AS(Point p2(1,-1), std::invalid_argument);

    CHECK_THROWS_AS(Character c1(p1,-5,"name"), std::invalid_argument);

    Cowboy cb1,cb2,cb3,cb4,cb5,cb6,cb7,cb8,cb9,cb10,cb11;
    Team t(&cb1);
    t.add(&cb2);
    t.add(&cb3);
    t.add(&cb4);
    t.add(&cb5);
    t.add(&cb6);
    t.add(&cb7);
    t.add(&cb8);
    t.add(&cb9);
    t.add(&cb10);
    //add more then 10 players
    CHECK_THROWS_AS(t.add(&cb11),std::invalid_argument);






}

TEST_CASE("add the same player throws")
{
    Cowboy b;
    Team t1(&b);
    Team t2;
    CHECK_THROWS_AS(t1.add(&b), std::invalid_argument);
    CHECK_THROWS_AS(t2.add(&b), std::invalid_argument);

}

TEST_CASE("charcter ded")
{
    Point p;
    Character c(p,0,"name");
    CHECK(!c.isAlive());

}
TEST_CASE("cowboy funcs")
{
    Point p1;
    Cowboy cb("name",p1);
    Cowboy cb1("name1",p1);
    int ind=0;
    for(int i=0;i<5;i++)
    {
        ind++;
        cb.shoot(&cb1);
        if(!cb.hasboolets())
        {
            cb.reload();
            CHECK(ind%6==0);
        }
    }

    
    CHECK(!cb1.isAlive());
    //shoot ded enemy
    CHECK_NOTHROW(cb.shoot(&cb1));
    //shoot himself
    CHECK_THROWS_AS(cb.shoot(&cb), std::runtime_error);
    //shoot when he deds
    CHECK_THROWS_AS(cb1.shoot(&cb), std::runtime_error);

}
TEST_CASE("ninga funcs")
{
    Point p1(1,0);
    TrainedNinja tn("name",p1);
    TrainedNinja tn1("name1",p1);
    Point p2;
    Ninja n(p2, 10, "name",10);
    YoungNinja yn("name",p2);
    OldNinja on("name",p2);
    for(int i=0;i<3;i++)
    {
        tn.slash(&tn1);
    }
    CHECK(!tn1.isAlive());
    // slash after the enemy ded
    CHECK_NOTHROW(tn.slash(&tn1));
    //slash himself, move himself
    CHECK_THROWS(tn.slash(&tn));
    CHECK_THROWS(tn.move(&tn));
    //slash after he ded
    CHECK_THROWS(tn1.slash(&tn));
    //negative speed
    CHECK_THROWS(n.setSpeed(-1));
    //try to change spaciel ninja to speed!=his speed
    CHECK_THROWS(tn.setSpeed(100));
    CHECK_THROWS(yn.setSpeed(100));
    CHECK_THROWS(on.setSpeed(100));

    
}
TEST_CASE("attack")
{
    //attack her self
    Cowboy c1;
    Cowboy c2;
    Team t1(&c1);
    Team t2(&c2);
    CHECK_THROWS(t1.attack(&t1));
    //attack ded team  
    while (t1.stillAlive())
    {
        t2.attack(&t1);
    }
    CHECK_THROWS(t2.attack(&t1));
    CHECK_THROWS(t1.attack(&t2));
   
    
}
TEST_CASE("point func")
{
    
    //On the X axis and with a distance of the size of the difference in the X values, the function returns the dst point
    Point p1(5,0);
    Point p2(9,0);

    Point p3=moveTowards(p1,p2,4);
    CHECK(p3.getX()==9 );
    CHECK(p3.getY()==0 );



}