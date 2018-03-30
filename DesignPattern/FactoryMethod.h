/**
 * @file FactoryMethod.h
 * @brief 1. Define an interface for creating an object, and the package object is 
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

#include<iostream>
#include"Profession.h"
using namespace std;

#define DEBUG_TEST_FACTORYMETHOD 1

class Profession;

class FactoryMethod
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~FactoryMethod() = 0;

        /**
         * Create Profession
         *
         * @param void
         * @return Profession* 
         * @note
         */
        virtual Profession* CreateProfession() = 0;

    protected:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        FactoryMethod();

    private:
        /**
         * Copy Construction
         *
         * @param const FactoryMethod& cFactoryMethod
         * @return 
         */
        FactoryMethod(const FactoryMethod& cFactoryMethod);

        /**
         * Assignment
         *
         * @param const FactoryMethod& cFactoryMethod
         * @return FactoryMethod&
         */
        FactoryMethod& operator=(const FactoryMethod& cFactoryMethod);
    public:
    protected:
    private:
};

class WarriorFactory : public FactoryMethod
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~WarriorFactory();

        /**
         * Instance
         *
         * @param void
         * @return FactoryMethod*
         * @note singleton
         */
        static FactoryMethod* Instance();

        /**
         * Destroy
         *
         * @param void
         * @return void
         * @note singleton
         */
        static void Destroy();

        /**
         * Create Profession
         *
         * @param void
         * @return Profession* 
         * @note create Warrior
         */
        Profession* CreateProfession();
    protected:
    private:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        WarriorFactory();

        /**
         * Copy Construction
         *
         * @param const WarriorFactory& cWarriorFactory
         * @return 
         */
        WarriorFactory(const WarriorFactory& cWarriorFactory);

        /**
         * Assignment
         *
         * @param const WarriorFactory& cWarriorFactory
         * @return WarriorFactory&
         */
        WarriorFactory& operator=(const WarriorFactory& cWarriorFactory);

    public:
    protected:
    private:
        static WarriorFactory* m_pInstance;
};


class MasterFactory : public FactoryMethod
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        ~MasterFactory();

        /**
         * Instance
         *
         * @param void
         * @return FactoryMethod*
         * @note singleton
         */
        static FactoryMethod* Instance();

        /**
         * Destroy
         *
         * @param void
         * @return void
         * @note singleton
         */
        static void Destroy();

        /**
         * Create Profession
         *
         * @param void
         * @return Profession* 
         * @note create Master
         */
        Profession* CreateProfession();
    protected:
    private:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        MasterFactory();

        /**
         * Copy Construction
         *
         * @param const MasterFactory& cMasterFactory
         * @return 
         */
        MasterFactory(const MasterFactory& cMasterFactory);

        /**
         * Assignment
         *
         * @param const MasterFactory& cMasterFactory
         * @return MasterFactory&
         */
        MasterFactory& operator=(const MasterFactory& cMasterFactory);

    public:
    protected:
    private:
        static MasterFactory* m_pInstance;
};

class AmazonFactory: public FactoryMethod
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        ~AmazonFactory();

        /**
         * Instance
         *
         * @param void
         * @return FactoryMethod*
         * @note singleton
         */
        static FactoryMethod* Instance();

        /**
         * Destroy
         *
         * @param void
         * @return void
         * @note singleton
         */
        static void Destroy();

        /**
         * Create Profession
         *
         * @param void
         * @return Profession* 
         * @note create Master
         */
        Profession* CreateProfession();
    protected:
    private:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AmazonFactory();

        /**
         * Copy Construction
         *
         * @param const AmazonFactory& cAmazonFactory
         * @return 
         */
        AmazonFactory(const AmazonFactory& cAmazonFactory);

        /**
         * Assignment
         *
         * @param const AmazonFactory& cAmazonFactory
         * @return AmazonFactory&
         */
        AmazonFactory& operator=(const AmazonFactory& cAmazonFactory);

    public:
    protected:
    private:
        static AmazonFactory* m_pInstance;
};

#endif

