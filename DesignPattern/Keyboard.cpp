/**
 * @file Keyboard.cpp 
 * @brief all kinds of Keyboard
 * @author BismarckDD
 * @version 1.0 2016/05/22
*/

#include "Keyboard.h"

/**
 * Construction
 *
 * @param void
 * @return 
 */
Keyboard::Keyboard()
{
    cout<<"Construction Keyboard"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
Keyboard::~Keyboard()
{
    cout<<"Destruction Keyboard"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
    void
Keyboard::Operation()
{
    //system error log
    cerr<<"[Keyboard::Operation] got called from thread "<</*ThreadID*/"at: "/**gettimeofday()*/<<endl;
}

/**
 * Construction
 *
 * @param void
 * @return 
 */
DellKeyboard::DellKeyboard()
{
    cout<<"Construction DellKeyboard"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
DellKeyboard::~DellKeyboard()
{
    cout<<"Destruction DellKeyboard"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
    void 
DellKeyboard::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AsusKeyboard::AsusKeyboard()
{
    cout<<"Construction AsusKeyboard"<<endl;
}


/**
 * Destruction
 *
 * @param void
 * @return 
 */
AsusKeyboard::~AsusKeyboard()
{
    cout<<"Destruction AsusKeyboard"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AsusKeyboard::Operation()
{

}

/**
 * Construction
 *
 * @param void
 * @return 
 */
AcerKeyboard::AcerKeyboard()
{
    cout<<"Construction AcerKeyboard"<<endl;
}

/**
 * Destruction
 *
 * @param void
 * @return 
 */
AcerKeyboard::~AcerKeyboard()
{
    cout<<"Destruction AcerKeyboard"<<endl;
}

/**
 * Operation
 *
 * @param void
 * @return 
 */
void 
AcerKeyboard::Operation()
{

}
