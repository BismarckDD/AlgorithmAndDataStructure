/** 
 * @file FactoryMethod.cpp
 * @brief 1. Define an interface for creating an object, and the package object is created
 *        2. The work of the specific class of delay to sub-class
 * @author BismarckDD
 * @version 1.0 2016/05/22
*/

#include "Profession.h"
#include "FactoryMethod.h"

/**
 * Construction
 *
 * @param void
 * @return 
 */
FactoryMethod::FactoryMethod()
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
FactoryMethod::~FactoryMethod()
{

}

/**
 * Create Profession
 *
 * @param void
 * @return Profession* 
 * @note
 */
Profession* FactoryMethod::CreateProfession()
{
    //system error log
    cerr<<"got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
    return NULL;
}

WarriorFactory* WarriorFactory::m_pInstance = NULL;

/**
 * Construction
 *
 * @param void
 * @return 
 */
WarriorFactory::WarriorFactory()
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
WarriorFactory::~WarriorFactory()
{

}

/**
 * Instance
 *
 * @param void
 * @return FactoryMethod*
 * @note WarriorFactory
 */
FactoryMethod* WarriorFactory::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new WarriorFactory;
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
void WarriorFactory::Destroy()
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
 * @return Profession* 
 * @note create Warrior
 */
Profession* WarriorFactory::CreateProfession()
{
    return new Warrior;
}

MasterFactory* MasterFactory::m_pInstance = NULL;

/**
 * Construction
 *
 * @param void
 * @return 
 */
MasterFactory::MasterFactory()
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
MasterFactory::~MasterFactory()
{

}

/**
 * Instance
 *
 * @param void
 * @return FactoryMethod*
 * @note MasterFactory
 */
FactoryMethod* MasterFactory::Instance()
{
    if (NULL == m_pInstance) 
    {
        m_pInstance = new MasterFactory;
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
void MasterFactory::Destroy()
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
 * @return Profession* 
 * @note create Master
 */
Profession* MasterFactory::CreateProfession()
{
    return new Master;
}
