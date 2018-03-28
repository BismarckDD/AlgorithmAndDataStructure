/**
 * @file SimpleFactory.h 
 * @brief Define an interface for creating an object, and the package object is created
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H

#include<iostream>
#include"Profession.h"
using namespace std;

#define DEBUG_TEST_SIMPLEFACTORY 1

class Profession;

class SimpleFactory
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        ~SimpleFactory();

        /**
         * Instance
         *
         * @param void
         * @return singleton*
         * @note singleton
         */
        static SimpleFactory* Instance();

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
         * @return void
         * @note Profession Type to identify the creating
         */
        Profession* CreateProfession(int iProfessionType);

    protected:
    private:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        SimpleFactory();

        /**
         * Copy Construction
         *
         * @param const SimpleFactory& cSimpleFactory
         * @return 
         */
        SimpleFactory(const SimpleFactory& cSimpleFactory);

        /**
         * Assignment
         *
         * @param const SimpleFactory& cSimpleFactory
         * @return SimpleFactory&
         */
        SimpleFactory& operator=(const SimpleFactory& cSimpleFactory);

    public:
    protected:
    private:
        static SimpleFactory* m_pInstance;
};
#endif
