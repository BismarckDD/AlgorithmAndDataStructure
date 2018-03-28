/**
 * @file Monitor.h
 * @brief all kinds of Monitor
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#ifndef MONITOR_H
#define MONITOR_H

#include<iostream>
using namespace std;

class Monitor
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Monitor() = 0;

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
        Monitor();

    private:
        /**
         * Copy Construction
         *
         * @param const Monitor& cMonitor
         * @return 
         */
        Monitor(const Monitor& cMonitor);

        /**
         * Assignment
         *
         * @param const Monitor& cMonitor
         * @return Monitor&
         */
        Monitor& operator=(const Monitor& cMonitor);

    public:
    protected:
    private:
};

class DellMonitor : public Monitor
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        DellMonitor();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~DellMonitor();

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
         * @param const DellMonitor& cDellMonitor
         * @return 
         */
        DellMonitor(const DellMonitor& cDellMonitor);

        /**
         * Assignment
         *
         * @param const DellMonitor& cDellMonitor
         * @return DellMonitor&
         */
        DellMonitor& operator=(const DellMonitor& cDellMonitor);

    public:
    protected:
    private:
};


class AsusMonitor : public Monitor
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AsusMonitor();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AsusMonitor();

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
         * @param const AsusMonitor& cAsusMonitor
         * @return 
         */
        AsusMonitor(const AsusMonitor& cAsusMonitor);

        /**
         * Assignment
         *
         * @param const AsusMonitor& cAsusMonitor
         * @return AsusMonitor&
         */
        AsusMonitor& operator=(const AsusMonitor& cAsusMonitor);

    public:
    protected:
    private:
};

class AcerMonitor : public Monitor
{
    public:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        AcerMonitor();

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~AcerMonitor();

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
         * @param const AcerMonitor& cAcerMonitor
         * @return 
         */
        AcerMonitor(const AcerMonitor& cAcerMonitor);

        /**
         * Assignment
         *
         * @param const AcerMonitor& cAcerMonitor
         * @return AcerMonitor&
         */
        AcerMonitor& operator=(const AcerMonitor& cAcerMonitor);

    public:
    protected:
    private:
};

#endif
