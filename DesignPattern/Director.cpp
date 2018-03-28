/**
 * @file Director.cpp
 * @brief 1.When the algorithm to create complex object should be independent of the part of the object, as well as their assembly;
 *        2.When construction process must be allowed to construct the object is different.
 * @author BismarckDD
 * @version 1.0 2016/05/23
 */

#include "Director.h"
#include "Builder.h"
#include "AbstractFactory.h"
#include "Computer.h"

/**
 * Construction
 *
 * @param Builder* pBuilder
 * @return 
 */
Director::Director(Builder* pBuilder):
    m_pBuilder(pBuilder)
{

}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Director::~Director()
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
Director::CreateComputer()
{
    if (NULL != m_pBuilder) 
    {
        return m_pBuilder->CreateComputer();
    }
    return NULL;
}

