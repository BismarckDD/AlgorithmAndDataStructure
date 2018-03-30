/**
 * @file SimpleFactory.cpp
 * @brief Define an interface for creating object, and the package object is created.
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#include "Profession.h"
#include "SimpleFactory.h"

SimpleFactory* SimpleFactory::m_pInstance = NULL;

/**
 * Construction
 *
 * @param void
 * @return 
 */
SimpleFactory::SimpleFactory()
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
SimpleFactory::~SimpleFactory()
{

}

/**
 * Instance
 *
 * @param void
 * @return SimpleFactory*
 * @note SimpleFactory
 */
SimpleFactory* SimpleFactory::Instance()
{
    if (NULL == m_pInstance) {
        m_pInstance = new SimpleFactory;
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
void SimpleFactory::Destroy()
{
    if (NULL != m_pInstance) 
    {
        delete m_pInstance;
        m_pInstance = NULL;
    }
}

/**
 * Create Profession
 *
 * @param void
 * @return void
 * @note Profession Type to identify the creating
 */ 
Profession* SimpleFactory::CreateProfession(int iProfessionType)
{
    if (0 == iProfessionType) 
    {
        // Warrior
        return new Warrior;
    }
    else if (1 == iProfessionType) 
    {
        // Master
        return new Master;
    }
    else 
    {
        return NULL;
    }
}
