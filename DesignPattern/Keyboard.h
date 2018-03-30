/**
 * @file Keyboard.h 
 * @brief all kinds of Keyboard
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include<iostream>
using namespace std;

class Keyboard
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Keyboard() = 0;

        /**
         * Operation
         *
         * @param void
         * @return 
         */
        virtual void Operation() = 0;

    protected:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        Keyboard();

    private:
        /**
         * Copy Construction
         *
         * @param const Keyboard& cKeyboard
         * @return 
         */
        Keyboard(const Keyboard& cKeyboard);

        /**
         * Assignment
         *
         * @param const Keyboard& cKeyboard
         * @return Keyboard&
         */
        Keyboard& operator=(const Keyboard& cKeyboard);

    public:
    protected:
    private:
};

class DellKeyboard : public Keyboard
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        DellKeyboard();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~DellKeyboard();


        /**
         * Operation
         *
         * @param void
         * @return 
         */
        virtual void Operation();


    protected:
    private:
        /**
         * Copy Construction
         *
         * @param const DellKeyboard& cDellKeyboard
         * @return 
         */
        DellKeyboard(const DellKeyboard& cDellKeyboard);

        /**
         * Assignment
         *
         * @param const DellKeyboard& cDellKeyboard
         * @return DellKeyboard&
         */
        DellKeyboard& operator=(const DellKeyboard& cDellKeyboard);

    public:
    protected:
    private:
};

class AsusKeyboard : public Keyboard
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AsusKeyboard();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AsusKeyboard();

        /**
         * Operation
         *
         * @param void
         * @return 
         */
        virtual void Operation();
    
    protected:
    private:
        /**
         * Copy Construction
         *
         * @param const AsusKeyboard& cAsusKeyboard
         * @return 
         */
        AsusKeyboard(const AsusKeyboard& cAsusKeyboard);

        /**
         * Assignment
         *
         * @param const AsusKeyboard& cAsusKeyboard
         * @return AsusKeyboard&
         */
        AsusKeyboard& operator=(const AsusKeyboard& cAsusKeyboard);

    public:
    protected:
    private:
};

class AcerKeyboard : public Keyboard
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AcerKeyboard();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AcerKeyboard();

        /**
         * Operation
         *
         * @param void
         * @return 
         */
        virtual void Operation();

    protected:
    private:
        /**
         * Copy Construction
         *
         * @param const AcerKeyboard& cAcerKeyboard
         * @return 
         */
        AcerKeyboard(const AcerKeyboard& cAcerKeyboard);

        /**
         * Assignment
         *
         * @param const AcerKeyboard& cAcerKeyboard
         * @return AcerKeyboard&
         */
        AcerKeyboard& operator=(const AcerKeyboard& cAcerKeyboard);

    public:
    protected:
    private:
};

#endif
