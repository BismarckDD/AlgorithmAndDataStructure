/** @file Mouse.h
 *  @brief all kinds of Mouse
 *  @author BismarckDD
 *  @version 1.0 2016/05/22
*/

#ifndef MOUSE_H
#define MOUSE_H

#include<iostream>
using namespace std;

class Mouse
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Mouse() = 0;

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
        Mouse();

    private:
        /**
         * Copy Construction
         *
         * @param const Mouse& cMouse
         * @return 
         */
        Mouse(const Mouse& cMouse);

        /**
         * Assignment
         *
         * @param const Mouse& cMouse
         * @return Mouse&
         */
        Mouse& operator=(const Mouse& cMouse);

    public:
    protected:
    private:
};

class DellMouse : public Mouse
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        DellMouse();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~DellMouse();

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
         * @param const DellMouse& cDellMouse
         * @return 
         */
        DellMouse(const DellMouse& cDellMouse);

        /**
         * Assignment
         *
         * @param const DellMouse& cDellMouse
         * @return DellMouse&
         */
        DellMouse& operator=(const DellMouse& cDellMouse);

    public:
    protected:
    private:
};

class AsusMouse : public Mouse
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AsusMouse();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AsusMouse();

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
         * @param const AsusMouse& cAsusMouse
         * @return 
         */
        AsusMouse(const AsusMouse& cAsusMouse);

        /**
         * Assignment
         *
         * @param const AsusMouse& cAsusMouse
         * @return AsusMouse&
         */
        AsusMouse& operator=(const AsusMouse& cAsusMouse);

    public:
    protected:
    private:
};

class AcerMouse : public Mouse
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AcerMouse();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AcerMouse();

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
         * @param const AcerMouse& cAcerMouse
         * @return 
         */
        AcerMouse(const AcerMouse& cAcerMouse);

        /**
         * Assignment
         *
         * @param const AcerMouse& cAcerMouse
         * @return AcerMouse&
         */
        AcerMouse& operator=(const AcerMouse& cAcerMouse);

    public:
    protected:
    private:
};

#endif
