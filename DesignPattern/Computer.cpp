/** 
 * @file Computer.h
 * @brief all kinds of Computer
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#include "Computer.h"

/**
 * Construction
 *
 * @param void
 * @return 
 */
Computer::Computer()
{
    cout<<"Construction Computer"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Computer::~Computer()
{
    cout<<"Destruction Computer"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void
Computer::Operation()
{
    //system error log
    cerr<<"[Computer::Operation] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
}

/**
 * Construction
 *
 * @param void
 * @return 
 */
DellComputer::DellComputer()
{
    cout<<"Construction DellComputer"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
DellComputer::~DellComputer()
{
    cout<<"Destruction DellComputer"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
DellComputer::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AsusComputer::AsusComputer()
{
    cout<<"Construction AsusComputer"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AsusComputer::~AsusComputer()
{
    cout<<"Destruction AsusComputer"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AsusComputer::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AcerComputer::AcerComputer()
{
    cout<<"Construction AcerComputer"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AcerComputer::~AcerComputer()
{
    cout<<"Destruction AcerComputer"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AcerComputer::Operation()
{

}

