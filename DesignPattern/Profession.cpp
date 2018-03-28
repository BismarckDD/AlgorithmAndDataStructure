/**
 * @file Profession.cpp
 * @brief All kinds of Professions
 * @author BismarckDD
 * @version 1.0 2016/05/22
*/

#include "Profession.h"

/**
 * Construction
 *
 * @param void
 * @return 
 */
Profession::Profession()
{
    cout<<"Construction Profession"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Profession::~Profession()
{
    cout<<"Destruction Profession"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void Profession::Operation()
{
    //system error log
    cerr<<"got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
}

/**
 * Construction
 *
 * @param void
 * @return 
 */
Warrior::Warrior()
{
    cout<<"Construction Warrior"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Warrior::~Warrior()
{
    cout<<"Destruction Warrior"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void Warrior::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
Master::Master()
{
    cout<<"Construction Master"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Master::~Master()
{
    cout<<"Destruction Master"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void Master::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
Amazon::Amazon()
{
    cout<<"Construction Amazon"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Amazon::~Amazon()
{
    cout<<"Destruction Amazon"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void Amazon::Operation()
{

}


