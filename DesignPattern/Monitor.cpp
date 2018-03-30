/**
 * @file Monitor.cpp
 * @brief all kinds of Monitor
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#include "Monitor.h"

/**
 * Construction
 *
 * @param void
 * @return 
 */
Monitor::Monitor()
{
    cout<<"Construction Monitor"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Monitor::~Monitor()
{
    cout<<"Destruction Monitor"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
    void
Monitor::Operation()
{
    //system error log
    cerr<<"[Monitor::Operation] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
}

/**
 * Construction
 *
 * @param void
 * @return 
 */
DellMonitor::DellMonitor()
{
    cout<<"Construction DellMonitor"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
DellMonitor::~DellMonitor()
{
    cout<<"Destruction DellMonitor"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
DellMonitor::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AsusMonitor::AsusMonitor()
{
    cout<<"Construction AsusMonitor"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AsusMonitor::~AsusMonitor()
{
    cout<<"Destruction AsusMonitor"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AsusMonitor::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AcerMonitor::AcerMonitor()
{
    cout<<"Construction AcerMonitor"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AcerMonitor::~AcerMonitor()
{
    cout<<"Destruction AcerMonitor"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AcerMonitor::Operation()
{

}
