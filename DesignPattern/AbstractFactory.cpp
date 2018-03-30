/**
 * @file AbstractFactory.cpp
 * @brief  1. Define an interface for creating an object, and the package object is created
 *         2. The work of the specific class of delay to sub-class
 *         3. Interface provides an object created for different class｣ｨCreating a group of related or dependent objects｣ｩ.
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#include"AbstractFactory.h"
#include"Mouse.h"
#include"Keyboard.h"
#include"Monitor.h"
#include"Host.h"
#include"Computer.h"

/**
 * Construction
 *
 * @param void
 * @return 
 */
AbstractFactory::AbstractFactory()
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AbstractFactory::~AbstractFactory()
{

}

/**
 * Create Mouse
 *
 * @param void
 * @return Mouse* 
 * @note
 */
Mouse* 
AbstractFactory::CreateMouse()
{
    //system error log
    cerr<<"[AbstractFactory::CreateMouse] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    return NULL;
}

/**
 * Create Keyboard
 *
 * @param void
 * @return Keyboard* 
 * @note
 */
Keyboard* 
AbstractFactory::CreateKeyboard()
{
    //system error log
    cerr<<"[AbstractFactory::CreateKeyboard] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    return NULL;
}

/**
 * Create Monitor
 *
 * @param void
 * @return Monitor* 
 * @note
 */
Monitor* 
AbstractFactory::CreateMonitor()
{
    //system error log
    cerr<<"[AbstractFactory::CreateMonitor] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    return NULL;
}

/**
 * Create Host
 *
 * @param void
 * @return Host* 
 * @note
 */
Host* 
AbstractFactory::CreateHost()
{
    //system error log
    cerr<<"[AbstractFactory::CreateHost] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    return NULL;
}

/**
 * Create Computer
 *
 * @param void
 * @return Computer* 
 * @note
 */
Computer* 
AbstractFactory::CreateComputer()
{
    //system error log
    cerr<<"[AbstractFactory::CreateComputer] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    return NULL;
}

DellFactory* DellFactory::m_pInstance = NULL;

/**
 * Construction
 *
 * @param void
 * @return 
 */
DellFactory::DellFactory()
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
DellFactory::~DellFactory()
{

}

/**
 * Instance
 *
 * @param void
 * @return AbstractFactory*
 * @note singleton
 */
 AbstractFactory* 
DellFactory::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new DellFactory;
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
DellFactory::Destroy()
{
    if (NULL != m_pInstance) 
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

/**
 * Create Mouse
 *
 * @param void
 * @return Mouse* 
 * @note
 */
Mouse* 
DellFactory::CreateMouse()
{
    return new DellMouse;
}

/**
 * Create Keyboard
 *
 * @param void
 * @return Keyboard* 
 * @note
 */
Keyboard* 
DellFactory::CreateKeyboard()
{
    return new DellKeyboard;
}

/**
 * Create Monitor
 *
 * @param void
 * @return Monitor* 
 * @note
 */
Monitor* 
DellFactory::CreateMonitor()
{
    return new DellMonitor;
}

/**
 * Create Host
 *
 * @param void
 * @return Host* 
 * @note
 */
Host* 
DellFactory::CreateHost()
{
    return new DellHost;
}

/**
 * Create Computer
 *
 * @param void
 * @return Computer* 
 * @note
 */
Computer* 
DellFactory::CreateComputer()
{
    return new DellComputer;
}

AsusFactory* AsusFactory::m_pInstance = NULL;

/**
 * Construction
 *
 * @param void
 * @return 
 */
AsusFactory::AsusFactory()
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AsusFactory::~AsusFactory()
{

}

/**
 * Instance
 *
 * @param void
 * @return AbstractFactory*
 * @note singleton
 */
AbstractFactory* 
AsusFactory::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new AsusFactory;
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
AsusFactory::Destroy()
{
    if (NULL != m_pInstance) 
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

/**
 * Create Mouse
 *
 * @param void
 * @return Mouse* 
 * @note
 */
Mouse* 
AsusFactory::CreateMouse()
{
    return new AsusMouse;
}

/**
 * Create Keyboard
 *
 * @param void
 * @return Keyboard* 
 * @note
 */
Keyboard* 
AsusFactory::CreateKeyboard()
{
    return new AsusKeyboard;
}

/**
 * Create Monitor
 *
 * @param void
 * @return Monitor* 
 * @note
 */
Monitor* 
AsusFactory::CreateMonitor()
{
    return new AsusMonitor;
}

/**
 * Create Host
 *
 * @param void
 * @return Host* 
 * @note
 */
Host* 
AsusFactory::CreateHost()
{
    return new AsusHost;
}

/**
 * Create Computer
 *
 * @param void
 * @return Computer* 
 * @note
 */
Computer* 
AsusFactory::CreateComputer()
{
    return new AsusComputer;
}

AcerFactory* AcerFactory::m_pInstance = NULL;

/**
 * Construction
 *
 * @param void
 * @return 
 */
AcerFactory::AcerFactory()
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AcerFactory::~AcerFactory()
{

}

/**
 * Instance
 *
 * @param void
 * @return AbstractFactory*
 * @note singleton
 */
AbstractFactory* 
AcerFactory::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new AcerFactory;
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
AcerFactory::Destroy()
{
    if (NULL != m_pInstance) 
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

/**
 * Create Mouse
 *
 * @param void
 * @return Mouse* 
 * @note
 */
Mouse* 
AcerFactory::CreateMouse()
{
    return new AcerMouse;
}

/**
 * Create Keyboard
 *
 * @param void
 * @return Keyboard* 
 * @note
 */
Keyboard* 
AcerFactory::CreateKeyboard()
{
    return new AcerKeyboard;
}

/**
 * Create Monitor
 *
 * @param void
 * @return Monitor* 
 * @note
 */
Monitor* 
AcerFactory::CreateMonitor()
{
    return new AcerMonitor;
}

/**
 * Create Host
 *
 * @param void
 * @return Host* 
 * @note
 */
Host* 
AcerFactory::CreateHost()
{
    return new AcerHost;
}

/**
 * Create Computer
 *
 * @param void
 * @return Computer* 
 * @note
 */
Computer* 
AcerFactory::CreateComputer()
{
    return new AcerComputer;
}

