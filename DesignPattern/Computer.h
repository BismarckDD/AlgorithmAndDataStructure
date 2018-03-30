/** 
 * @file Computer.h
 * @brief all kinds of Computer
 * @author BismarckDD
 * @version 1.0 2026/05/22
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include<iostream>
using namespace std;

#include"Mouse.h"
#include"Keyboard.h"
#include"Monitor.h"
#include"Host.h"

class Computer
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Computer() = 0;

        /**
         * Operation
         *
         * @param void
         * @return 
         */
        virtual void Operation() = 0;

        Computer(Mouse*, Keyboard*, Monitor*, Host*);
    protected:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        Computer();

    private:
        /**
         * Copy Construction
         *
         * @param const Computer& cComputer
         * @return 
         */
        Computer(const Computer& cComputer);

        /**
         * Assignment
         *
         * @param const Computer& cComputer
         * @return Computer&
         */
        Computer& operator=(const Computer& cComputer);

    public:
    protected:
    private:
};

class DellComputer : public Computer
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        DellComputer();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~DellComputer();

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
         * @param const DellComputer& cDellComputer
         * @return 
         */
        DellComputer(const DellComputer& cDellComputer);

        /**
         * Assignment
         *
         * @param const DellComputer& cDellComputer
         * @return DellComputer&
         */
        DellComputer& operator=(const DellComputer& cDellComputer);

    public:
    protected:
    private:
};

class AsusComputer : public Computer
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AsusComputer();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AsusComputer();

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
         * @param const AsusComputer& cAsusComputer
         * @return 
         */
        AsusComputer(const AsusComputer& cAsusComputer);

        /**
         * Assignment
         *
         * @param const AsusComputer& cAsusComputer
         * @return AsusComputer&
         */
        AsusComputer& operator=(const AsusComputer& cAsusComputer);

    public:
    protected:
    private:
};

class AcerComputer : public Computer
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AcerComputer();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AcerComputer();

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
         * @param const AcerComputer& cAcerComputer
         * @return 
         */
        AcerComputer(const AcerComputer& cAcerComputer);

        /**
         * Assignment
         *
         * @param const AcerComputer& cAcerComputer
         * @return AcerComputer&
         */
        AcerComputer& operator=(const AcerComputer& cAcerComputer);

    public:
    protected:
    private:
};


#endif
