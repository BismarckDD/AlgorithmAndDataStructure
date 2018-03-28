/**
 * @file Builder.cpp
 * @brief 1.When the algorithm to create complex object should be independent of the part of the object, as well as their assembly;
 *        2.When construction process must be allowed to construct the object is different.
 * @author BismarckDD
 * @version 1.0 2016/05/23
 */
 
#include "Builder.h"
#include "AbstractFactory.h"
#include "Computer.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Monitor.h"
#include "Host.h"

/**
* Construction
*
* @param void
* @return 
*/
Builder::Builder()
{

}

/**
* Destruction
*
* @param void
* @return 
*/
Builder::~Builder()
{

}

/**
* Create Computer
*
* @param void
* @return AbstractComputer*
* @note
*/
AbstractComputer* 
Builder::CreateComputer()
{
    //build Mouse;
    Mouse* pMouse = BuildMouse();
    //build Keyboard;
    Keyboard* pKeyboard = BuildKeyboard();
    //build Monitor;
    Monitor* pMonitor = BuildMonitor();
    //build Host;
    Host* pHost = BuildHost();

    return NULL; //new Computer(pMouse, pKeyboard, pMonitor, pHost);
}

/**
* Build Mouse
*
* @param void
* @return Mouse*
* @note build and process product
*/
Mouse* 
Builder::BuildMouse()
{
    //system error log
    cerr<<"[Builder::BuildMouse] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    
    return NULL;
}

/**
* Build Keyboard
*
* @param void
* @return Keyboard*
* @note build and process product
*/
Keyboard* 
Builder::BuildKeyboard()
{
    //system error log
    cerr<<"[Builder::BuildKeyboard] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    
    return NULL;
}
/**
* Build Monitor
*
* @param void
* @return Monitor*
* @note build and process product
*/
Monitor* 
Builder::BuildMonitor()
{
    //system error log
    cerr<<"[Builder::BuildMonitor] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    
    return NULL;
}

/**
* Build Host
*
* @param void
* @return Host*
* @note build and process product
*/
Host* 
Builder::BuildHost()
{
    //system error log
    cerr<<"[Builder::BuildHost] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    
    return NULL;
}

DellBuilder* DellBuilder::m_pInstance = NULL;

/**
* Construction
*
* @param void
* @return 
*/
DellBuilder::DellBuilder()
{

}

/**
* Destruction
*
* @param void
* @return 
*/
DellBuilder::~DellBuilder()
{

}

/**
* Instance
*
* @param void
* @return DellBuilder*
* @note singleton
*/
DellBuilder* 
DellBuilder::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new DellBuilder;
    }
    return m_pInstance;
}

/**
* Destroy
*
* @param void
* @return void
* @note singleton
*/
void 
DellBuilder::Destroy()
{
    if (NULL != m_pInstance) 
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

/**
* Build Mouse
*
* @param void
* @return Mouse*
* @note build and process product
*/
Mouse* 
DellBuilder::BuildMouse()
{
    return DellFactory::Instance()->CreateMouse();
}

/**
* Build Keyboard
*
* @param void
* @return Keyboard*
* @note build and process product
*/
Keyboard* 
DellBuilder::BuildKeyboard()
{
    return DellFactory::Instance()->CreateKeyboard();
}

/**
* Build Monitor
*
* @param void
* @return Monitor*
* @note build and process product
*/
Monitor* 
DellBuilder::BuildMonitor()
{
    return DellFactory::Instance()->CreateMonitor();
}

/**
* Build Host
*
* @param void
* @return Host*
* @note build and process product
*/
Host* 
DellBuilder::BuildHost()
{
    return DellFactory::Instance()->CreateHost();
}

AbstractComputer*
DellBuilder::CreateComputer()
{
    Mouse* pMouse = BuildMouse();
    Keyboard* pKeyboard = BuildKeyboard();
    Monitor* pMonitor = BuildMonitor();
    Host* pHost = BuildHost();
    return new DellComputer(pMouse, pKeyboard, pMonitor, pHost);
}

AsusBuilder* AsusBuilder::m_pInstance = NULL;

/**
* Construction
*
* @param void
* @return 
*/
AsusBuilder::AsusBuilder()
{

}

/**
* Destruction
*
* @param void
* @return 
*/
AsusBuilder::~AsusBuilder()
{

}

/**
* Instance
*
* @param void
* @return AsusBuilder*
* @note singleton
*/
AsusBuilder* 
AsusBuilder::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new AsusBuilder;
    }
    return m_pInstance;
}

/**
* Destroy
*
* @param void
* @return void
* @note singleton
*/
void 
AsusBuilder::Destroy()
{
    if (NULL != m_pInstance) 
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

/**
* Build Mouse
*
* @param void
* @return Mouse*
* @note build and process product
*/
Mouse* 
AsusBuilder::BuildMouse()
{
    return AsusFactory::Instance()->CreateMouse();
}

/**
* Build Keyboard
*
* @param void
* @return Keyboard*
* @note build and process product
*/
Keyboard* 
AsusBuilder::BuildKeyboard()
{
    return AsusFactory::Instance()->CreateKeyboard();
}

/**
* Build Monitor
*
* @param void
* @return Monitor*
* @note build and process product
*/
Monitor* 
AsusBuilder::BuildMonitor()
{
    return AsusFactory::Instance()->CreateMonitor();
}

/**
* Build Host
*
* @param void
* @return Host*
* @note build and process product
*/
Host* 
AsusBuilder::BuildHost()
{
    return AsusFactory::Instance()->CreateHost();
}

AbstractComputer*
AsusBuilder::CreateComputer()
{
    Mouse* pMouse = BuildMouse();
    Keyboard* pKeyboard = BuildKeyboard();
    Monitor* pMonitor = BuildMonitor();
    Host* pHost = BuildHost();
    return new AsusComputer(pMouse, pKeyboard, pMonitor, pHost);
}

AcerBuilder* AcerBuilder::m_pInstance = NULL;

/**
* Construction
*
* @param void
* @return 
*/
AcerBuilder::AcerBuilder()
{

}

/**
* Destruction
*
* @param void
* @return 
*/
AcerBuilder::~AcerBuilder()
{

}

/**
* Instance
*
* @param void
* @return AcerBuilder*
* @note singleton
*/
AcerBuilder* 
AcerBuilder::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new AcerBuilder;
    }
    return m_pInstance;
}

/**
* Destroy
*
* @param void
* @return void
* @note singleton
*/
void 
AcerBuilder::Destroy()
{
    if (NULL != m_pInstance) 
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

/**
* Build Mouse
*
* @param void
* @return Mouse*
* @note build and process product
*/
Mouse* 
AcerBuilder::BuildMouse()
{
    return AcerFactory::Instance()->CreateMouse();
}

/**
* Build Keyboard
*
* @param void
* @return Keyboard*
* @note build and process product
*/
Keyboard* 
AcerBuilder::BuildKeyboard()
{
    return AcerFactory::Instance()->CreateKeyboard();
}

/**
* Build Monitor
*
* @param void
* @return Monitor*
* @note build and process product
*/
Monitor* 
AcerBuilder::BuildMonitor()
{
    return AcerFactory::Instance()->CreateMonitor();
}

/**
* Build Host
*
* @param void
* @return Host*
* @note build and process product
*/
Host* 
AcerBuilder::BuildHost()
{
    return AcerFactory::Instance()->CreateHost();
}

AbstractComputer*
AcerBuilder::CreateComputer()
{
    Mouse* pMouse = BuildMouse();
    Keyboard* pKeyboard = BuildKeyboard();
    Monitor* pMonitor = BuildMonitor();
    Host* pHost = BuildHost();
    return new AcerComputer(pMouse, pKeyboard, pMonitor, pHost);
}
