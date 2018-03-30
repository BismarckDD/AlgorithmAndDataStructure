/** 
 * @file Host.h
 * @brief all kinds of Host
 * @author BismarckDD
 * @version 1.0 2016/05/22
*/

#ifndef HOST_H
#define HOST_H

#include<iostream>
using namespace std;

class Host
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Host() = 0;

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
        Host();

    private:
        /**
         * Copy Construction
         *
         * @param const Host& cHost
         * @return 
         */
        Host(const Host& cHost);

        /**
         * Assignment
         *
         * @param const Host& cHost
         * @return Host&
         */
        Host& operator=(const Host& cHost);

    public:
    protected:
    private:
};

class DellHost : public Host
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        DellHost();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~DellHost();

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
         * @param const DellHost& cDellHost
         * @return 
         */
        DellHost(const DellHost& cDellHost);

        /**
         * Assignment
         *
         * @param const DellHost& cDellHost
         * @return DellHost&
         */
        DellHost& operator=(const DellHost& cDellHost);

    public:
    protected:
    private:
};

class AsusHost : public Host
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AsusHost();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AsusHost();

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
         * @param const AsusHost& cAsusHost
         * @return 
         */
        AsusHost(const AsusHost& cAsusHost);

        /**
         * Assignment
         *
         * @param const AsusHost& cAsusHost
         * @return AsusHost&
         */
        AsusHost& operator=(const AsusHost& cAsusHost);

    public:
    protected:
    private:
};

class AcerHost : public Host
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AcerHost();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AcerHost();

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
         * @param const AcerHost& cAcerHost
         * @return 
         */
        AcerHost(const AcerHost& cAcerHost);

        /**
         * Assignment
         *
         * @param const AcerHost& cAcerHost
         * @return AcerHost&
         */
        AcerHost& operator=(const AcerHost& cAcerHost);

    public:
    protected:
    private:
};

#endif
