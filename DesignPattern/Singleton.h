/*
 * @file Singleton.h
 * @brief To ensure that a class has only one instance
 * @author: BismarckDD
 * @version 1.0 2016/05/21
 */

#ifndef SINGLETON_H
#define SINGLETON_H       

#include<iostream>
using namespace std;

#define DEBUG_TEST_SINGLETON 1

class Singleton
{
    public:
        /**
         * * Destruction
         * *
         * * @param void
         * * @return 
         * */
        ~Singleton();


        /**
         * * Instance
         * *
         * * @param void
         * * @return singleton*
         * * @note singleton
         * */
        static Singleton* Instance();

        /**
         * * Destroy
         * *
         * * @param void
         * * @return void
         * * @note singleton
         * */
        static void Destroy();
    protected:
    private:
        /**
         * * Construction
         * *
         * * @param void
         * * @return 
         * */
        Singleton();


        /**
         * * Copy Construction
         * *
         * * @param void
         * * @return 
         * */
        Singleton(const Singleton& cSingleton);


        /**
         * * Assignment
         * *
         * * @param void
         * * @return Singleton&
         * */
        Singleton& operator=(const Singleton& cSingleton);


    public:
    protected:
    private:
        static Singleton* m_pInstance;
};

#endif 


