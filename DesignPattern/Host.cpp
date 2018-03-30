/** 
 * @file Host.h
 * @brief all kinds of Host
 * @author BismarckDD
 * @version 1.0 2016/05/22
*/

#include "Host.h"

/**
 * Construction
 *
 * @param void
 * @return 
 */
Host::Host()
{
    cout<<"Construction Host"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Host::~Host()
{
    cout<<"Destruction Host"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void
Host::Operation()
{
    //system error log
    cerr<<"[Host::Operation] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
}

/**
 * Construction
 *
 * @param void
 * @return 
 */
DellHost::DellHost()
{
    cout<<"Construction DellHost"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
DellHost::~DellHost()
{
    cout<<"Destruction DellHost"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
DellHost::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AsusHost::AsusHost()
{
    cout<<"Construction AsusHost"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AsusHost::~AsusHost()
{
    cout<<"Destruction AsusHost"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AsusHost::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AcerHost::AcerHost()
{
    cout<<"Construction AcerHost"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AcerHost::~AcerHost()
{
    cout<<"Destruction AcerHost"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AcerHost::Operation()
{

}

