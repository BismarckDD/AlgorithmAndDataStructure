/** 
 * @file Profession.h 
 * @brief All kinds of Professions
 * @author BismarckDD
 * @version 1.0 2016/05/22
*/

#ifndef PROFESSION_H
#define PROFESSION_H

#include<iostream>
using namespace std;

class Profession
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        Profession();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Profession() = 0;

        /**
         * Operation
         *
         * @param void
         * @return 
         */
        virtual void Operation() = 0;

    protected:
    private:
        /**
         * Copy Construction
         *
         * @param const Profession& cSimpleFactory
         * @return 
         */
        Profession(const Profession& cSimpleFactory);

        /**
         * Assignment
         *
         * @param const Profession& cSimpleFactory
         * @return Profession&
         */
        Profession& operator=(const Profession& cSimpleFactory);

    public:
    protected:
    private:
};

class Warrior : public Profession
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        Warrior();
        
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Warrior();

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
         * @param const Warrior& cSimpleFactory
         * @return 
         */
        Warrior(const Warrior& cSimpleFactory);

        /**
         * Assignment
         *
         * @param const Warrior& cSimpleFactory
         * @return Warrior&
         */
        Warrior& operator=(const Warrior& cSimpleFactory);

    public:
    protected:
    private:
};

class Master : public Profession
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        Master();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Master();

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
         * @param const Master& cSimpleFactory
         * @return 
         */
        Master(const Master& cSimpleFactory);
        
        /**
         * Assignment
         *
         * @param const Master& cSimpleFactory
         * @return Master&
         */
        Master& operator=(const Master& cSimpleFactory);

    public:
    protected:
    private:
};

class Amazon : public Profession
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        Amazon();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Amazon();

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
         * @param const Amazon& cSimpleFactory
         * @return 
         */
        Amazon(const Amazon& cSimpleFactory);
        
        /**
         * Assignment
         *
         * @param const Amazon& cSimpleFactory
         * @return Amazon&
         */
        Amazon& operator=(const Amazon& cSimpleFactory);

    public:
    protected:
    private:
};

#endif
