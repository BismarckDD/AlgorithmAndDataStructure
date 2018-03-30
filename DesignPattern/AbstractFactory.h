/**
 * @file AbstractFactory.h
 * @brief 1. Define an interface for creating an object, and the package object is created
 *        2. The work of the specific class of delay to sub-class
 *        3. Interface provides an object created for different class｣ｨCreating a group of related or dependent objects｣ｩ.
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include<iostream>
using namespace std;

#define DEBUG_TEST_ABSTRACTFACTORY 1

class Mouse;
class Keyboard;
class Monitor;
class Host;
class Computer;

class AbstractFactory
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AbstractFactory() = 0;

        /**
         * Create Mouse
         *
         * @param void
         * @return Mouse* 
         * @note
         */
        virtual Mouse* CreateMouse() = 0;

        /**
         * Create Keyboard
         *
         * @param void
         * @return Keyboard* 
         * @note
         */
        virtual Keyboard* CreateKeyboard() = 0;

        /**
         * Create Monitor
         *
         * @param void
         * @return Monitor* 
         * @note
         */
        virtual Monitor* CreateMonitor() = 0;

        /**
         * Create Host
         *
         * @param void
         * @return Host* 
         * @note
         */
        virtual Host* CreateHost() = 0;

        /**
         * Create Computer
         *
         * @param void
         * @return Computer* 
         * @note
         */
        virtual Computer* CreateComputer() = 0;

    protected:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AbstractFactory();

    private:
        /**
         * Copy Construction
         *
         * @param const AbstractFactory& cAbstractFactory
         * @return 
         */
        AbstractFactory(const AbstractFactory& cAbstractFactory);

        /**
         * Assignment
         *
         * @param const AbstractFactory& cAbstractFactory
         * @return AbstractFactory&
         */
        AbstractFactory& operator=(const AbstractFactory& cAbstractFactory);

    public:
    protected:
    private:
};


class DellFactory : public AbstractFactory
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~DellFactory();


        /**
         * Instance
         *
         * @param void
         * @return AbstractFactory*
         * @note singleton
         */
        static AbstractFactory* Instance();

        /**
         * Destroy
         *
         * @param void
         * @return void
         * @note singleton
         */
        static void Destroy();


        /**
         * Create Mouse
         *
         * @param void
         * @return Mouse* 
         * @note
         */
        virtual Mouse* CreateMouse();


        /**
         * Create Keyboard
         *
         * @param void
         * @return Keyboard* 
         * @note
         */
        virtual Keyboard* CreateKeyboard();


        /**
         * Create Monitor
         *
         * @param void
         * @return Monitor* 
         * @note
         */
        virtual Monitor* CreateMonitor();

        /**
         * Create Host
         *
         * @param void
         * @return Host* 
         * @note
         */
        virtual Host* CreateHost();

        /**
         * Create Computer
         *
         * @param void
         * @return Computer* 
         * @note
         */
        virtual Computer* CreateComputer();

    protected:
    private:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        DellFactory();

        /**
         * Copy Construction
         *
         * @param const DellFactory& cDellFactory
         * @return 
         */
        DellFactory(const DellFactory& cDellFactory);

        /**
         * Assignment
         *
         * @param const DellFactory& cDellFactory
         * @return DellFactory&
         */
        DellFactory& operator=(const DellFactory& cDellFactory);

    public:
    protected:
    private:
        static DellFactory* m_pInstance;
};

class AsusFactory : public AbstractFactory
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AsusFactory();

        /**
         * Instance
         *
         * @param void
         * @return AbstractFactory*
         * @note singleton
         */
        static AbstractFactory* Instance();

        /**
         * Destroy
         *
         * @param void
         * @return void
         * @note singleton
         */
        static void Destroy();

        /**
         * Create Mouse
         *
         * @param void
         * @return Mouse* 
         * @note
         */
        virtual Mouse* CreateMouse();

        /**
         * Create Keyboard
         *
         * @param void
         * @return Keyboard* 
         * @note
         */
        virtual Keyboard* CreateKeyboard();

        /**
         * Create Monitor
         *
         * @param void
         * @return Monitor* 
         * @note
         */
        virtual Monitor* CreateMonitor();

        /**
         * Create Host
         *
         * @param void
         * @return Host* 
         * @note
         */
        virtual Host* CreateHost();

        /**
         * Create Computer
         *
         * @param void
         * @return Computer* 
         * @note
         */
        virtual Computer* CreateComputer();

    protected:
    private:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AsusFactory();

        /**
         * Copy Construction
         *
         * @param const AsusFactory& cAsusFactory
         * @return 
         */
        AsusFactory(const AsusFactory& cAsusFactory);

        /**
         * Assignment
         *
         * @param const AsusFactory& cAsusFactory
         * @return AsusFactory&
         */
        AsusFactory& operator=(const AsusFactory& cAsusFactory);

    public:
    protected:
    private:
        static AsusFactory* m_pInstance;
};

class AcerFactory : public AbstractFactory
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AcerFactory();

        /**
         * Instance
         *
         * @param void
         * @return AbstractFactory*
         * @note singleton
         */
        static AbstractFactory* Instance();

        /**
         * Destroy
         *
         * @param void
         * @return void
         * @note singleton
         */
        static void Destroy();

        /**
         * Create Mouse
         *
         * @param void
         * @return Mouse* 
         * @note
         */
        virtual Mouse* CreateMouse();

        /**
         * Create Keyboard
         *
         * @param void
         * @return Keyboard* 
         * @note
         */
        virtual Keyboard* CreateKeyboard();

        /**
         * Create Monitor
         *
         * @param void
         * @return Monitor* 
         * @note
         */
        virtual Monitor* CreateMonitor();

        /**
         * Create Host
         *
         * @param void
         * @return Host* 
         * @note
         */
        virtual Host* CreateHost();
        
        /**
         * Create Computer
         *
         * @param void
         * @return Computer* 
         * @note
         */
        virtual Computer* CreateComputer();

    protected:
    private:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AcerFactory();

        /**
         * Copy Construction
         *
         * @param const AcerFactory& cAcerFactory
         * @return 
         */
        AcerFactory(const AcerFactory& cAcerFactory);

        /**
         * Assignment
         *
         * @param const AcerFactory& cAcerFactory
         * @return AcerFactory&
         */
        AcerFactory& operator=(const AcerFactory& cAcerFactory);

    public:
    protected:
    private:
        static AcerFactory* m_pInstance;
};


#endif
