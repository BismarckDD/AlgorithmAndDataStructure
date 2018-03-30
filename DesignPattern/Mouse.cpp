/** 
 * @file Mouse.h
 * @brief all kinds of Mouse
 * @author BismarckDD
 * @version 1.0 2016/05/22
*/

#include "Mouse.h"

/**
 * Construction
 *
 * @param void
 * @return 
 */
Mouse::Mouse()
{
    cout<<"Construction Mouse"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Mouse::~Mouse()
{
    cout<<"Destruction Mouse"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void
Mouse::Operation()
{
    //system error log
    cerr<<"[Mouse::Operation] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
}

/**
 * Construction
 *
 * @param void
 * @return 
 */
DellMouse::DellMouse()
{
    cout<<"Construction DellMouse"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
DellMouse::~DellMouse()
{
    cout<<"Destruction DellMouse"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
DellMouse::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AsusMouse::AsusMouse()
{
    cout<<"Construction AsusMouse"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AsusMouse::~AsusMouse()
{
    cout<<"Destruction AsusMouse"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AsusMouse::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AcerMouse::AcerMouse()
{
    cout<<"Construction AcerMouse"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AcerMouse::~AcerMouse()
{
    cout<<"Destruction AcerMouse"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AcerMouse::Operation()
{

}

