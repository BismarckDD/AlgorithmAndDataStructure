/**
 * @file Singleton.cpp
 * @brief To ensure that a class has only one instance
 * @author: BismarckDD
 * @version 1.0 2016/05/21
*/

#include "Singleton.h"
Singleton* Singleton::m_pInstance = NULL;

/**
 * * Construction
 * *
 * * @param VOID
 * * @return 
 * */
Singleton::Singleton()
{
#if DEBUG_TEST_SINGLETON
    static unsigned int i = 0;
    cout << "Construction Singleton:" << ++i << endl;
#endif
}


/**
 * * Destruction
 * *
 * * @param VOID
 * * @return 
 * */
Singleton::~Singleton()
{
#if DEBUG_TEST_SINGLETON
    static unsigned int i = 0;
    cout << "Destruction Singleton:" << ++i << endl;
#endif
}


/**
 * * Instance
 * *
 * * @param void
 * * @return Singleton*
 * * @note Singleton
 * */
Singleton* Singleton::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new Singleton;
    }
    return m_pInstance;
}


/**
 * * Destroy
 * *
 * * @param void
 * * @return void
 * * @note singleton
 * */
void Singleton::Destroy()
{
    if (NULL != m_pInstance) 
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}
