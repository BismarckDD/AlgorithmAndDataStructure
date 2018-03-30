/**
 * @file Builder.h   
 * @brief 1.When the algorithm to create complex object should be independent of the part of the object, as well as their assembly;  
 *        2.When construction process must be allowed to construct the object is different.
 * @author BismarckDD
 * @version 1.0 2016/05/23
*/  

#ifndef BUILDER_H  
#define BUILDER_H  

#include<iostream>
#include"Computer.h"
#include"Mouse.h"
#include"Keyboard.h"
#include"Monitor.h"
#include"Host.h"
using namespace std;

#define DEBUG_TEST_BUILDER 1

class AbstractComputer;  
class Mouse;  
class Keyboard;  
class Monitor;  
class Host;  

class Builder  
{  
    public:  
        /**  
         * Destruction  
         *  
         * @param void  
         * @return   
         */  
        virtual ~Builder();  

        /**  
         * Create Computer  
         *  
         * @param void  
         * @return AbstractComputer*  
         * @note  
         */  
        virtual AbstractComputer* CreateComputer();  

    protected:  
        /**  
         * Construction  
         *  
         * @param void  
         * @return   
         */  
        Builder();  

    private:  
        /**  
         * Copy Construction  
         *  
         * @param const Builder& cBuilder  
         * @return   
         */  
        Builder(const Builder& cBuilder);  

        /**  
         * Assignment  
         *  
         * @param const Builder& cBuilder  
         * @return Builder&  
         */  
        Builder& operator=(const Builder& cBuilder);  

        /**  
         * Build Mouse  
         *  
         * @param void  
         * @return Mouse*  
         * @note build and process product  
         */  
        virtual Mouse* BuildMouse() = 0;  

        /**  
         * Build Keyboard  
         *  
         * @param void  
         * @return Keyboard*  
         * @note build and process product  
         */  
        virtual Keyboard* BuildKeyboard() = 0;  

        /**  
         * Build Monitor  
         *  
         * @param void  
         * @return Monitor*  
         * @note build and process product  
         */  
        virtual Monitor* BuildMonitor() = 0;  

        /**  
         * Build Host  
         *  
         * @param void  
         * @return Host*  
         * @note build and process product  
         */  
        virtual Host* BuildHost() = 0;  

    public:  
    protected:  
    private:  
};  

class DellBuilder : public Builder  
{  
    public:  
        /**  
         * Destruction  
         *  
         * @param void  
         * @return   
         */  
        virtual ~DellBuilder();  

        /**  
         * Instance  
         *  
         * @param void  
         * @return DellBuilder*  
         * @note singleton  
         */  
        static DellBuilder* Instance();  

        /**  
         * Destroy  
         *  
         * @param void  
         * @return void  
         * @note singleton  
         */  
        static void Destroy();  

        AbstractComputer* CreateComputer();
    protected:  
    private:  
        /**  
         * Construction  
         *  
         * @param void  
         * @return   
         */  
        DellBuilder();  

        /**  
         * Copy Construction  
         *  
         * @param const DellBuilder& cDellBuilder  
         * @return   
         */  
        DellBuilder(const DellBuilder& cDellBuilder);  

        /**  
         * Assignment  
         *  
         * @param const DellBuilder& cDellBuilder  
         * @return DellBuilder&  
         */  
        DellBuilder& operator=(const DellBuilder& cDellBuilder);  

        /**  
         * Build Mouse  
         *  
         * @param void  
         * @return Mouse*  
         * @note build and process product  
         */  
        virtual Mouse* BuildMouse();  

        /**  
         * Build Keyboard  
         *  
         * @param void  
         * @return Keyboard*  
         * @note build and process product  
         */  
        virtual Keyboard* BuildKeyboard();  

        /**  
         * Build Monitor  
         *  
         * @param void  
         * @return Monitor*  
         * @note build and process product  
         */  
        virtual Monitor* BuildMonitor();  

        /**  
         * Build Host  
         *  
         * @param void  
         * @return Host*  
         * @note build and process product  
         */  
        virtual Host* BuildHost();  

    public:  
    protected:  
    private:  
        static DellBuilder* m_pInstance;  
};  


class AsusBuilder : public Builder  
{  
    public:  
        /**  
         * Destruction  
         *  
         * @param void  
         * @return   
         */  
        virtual ~AsusBuilder();  

        /**  
         * Instance  
         *  
         * @param void  
         * @return AsusBuilder*  
         * @note singleton  
         */  
        static AsusBuilder* Instance();  

        /**  
         * Destroy  
         *  
         * @param void  
         * @return void  
         * @note singleton  
         */  
        static void Destroy();  

        AbstractComputer* CreateComputer();
    protected:  
    private:  
        /**  
         * Construction  
         *  
         * @param void  
         * @return   
         */  
        AsusBuilder();  

        /**  
         * Copy Construction  
         *  
         * @param const AsusBuilder& cAsusBuilder  
         * @return   
         */  
        AsusBuilder(const AsusBuilder& cAsusBuilder);  

        /**  
         * Assignment  
         *  
         * @param const AsusBuilder& cAsusBuilder  
         * @return AsusBuilder&  
         */  
        AsusBuilder& operator=(const AsusBuilder& cAsusBuilder);  

        /**  
         * Build Mouse  
         *  
         * @param void  
         * @return Mouse*  
         * @note build and process product  
         */  
        virtual Mouse* BuildMouse();  

        /**  
         * Build Keyboard  
         *  
         * @param void  
         * @return Keyboard*  
         * @note build and process product  
         */  
        virtual Keyboard* BuildKeyboard();  

        /**  
         * Build Monitor  
         *  
         * @param void  
         * @return Monitor*  
         * @note build and process product  
         */  
        virtual Monitor* BuildMonitor();  

        /**  
         * Build Host  
         *  
         * @param void  
         * @return Host*  
         * @note build and process product  
         */  
        virtual Host* BuildHost();  

    public:  
    protected:  
    private:  
        static AsusBuilder* m_pInstance;  
};  

class AcerBuilder : public Builder  
{  
    public:  
        /**  
         * Destruction  
         *  
         * @param void  
         * @return   
         */  
        virtual ~AcerBuilder();  

        /**  
         * Instance  
         *  
         * @param void  
         * @return AcerBuilder*  
         * @note singleton  
         */  
        static AcerBuilder* Instance();  

        /**  
         * Destroy  
         *  
         * @param void  
         * @return void  
         * @note singleton  
         */  
        static void Destroy();  

        AbstractComputer* CreateComputer();
    protected:  
    private:  
        /**  
         * Construction  
         *  
         * @param void  
         * @return   
         */  
        AcerBuilder();  

        /**  
         * Copy Construction  
         *  
         * @param const AcerBuilder& cAcerBuilder  
         * @return   
         */  
        AcerBuilder(const AcerBuilder& cAcerBuilder);  

        /**  
         * Assignment  
         *  
         * @param const AcerBuilder& cAcerBuilder  
         * @return AcerBuilder&  
         */  
        AcerBuilder& operator=(const AcerBuilder& cAcerBuilder);  

        /**  
         * Build Mouse  
         *  
         * @param void  
         * @return Mouse*  
         * @note build and process product  
         */  
        virtual Mouse* BuildMouse();  

        /**  
         * Build Keyboard  
         *  
         * @param void  
         * @return Keyboard*  
         * @note build and process product  
         */  
        virtual Keyboard* BuildKeyboard();  

        /**  
         * Build Monitor  
         *  
         * @param void  
         * @return Monitor*  
         * @note build and process product  
         */  
        virtual Monitor* BuildMonitor();  

        /**  
         * Build Host  
         *  
         * @param void  
         * @return Host*  
         * @note build and process product  
         */  
        virtual Host* BuildHost();  

    public:  
    protected:  
    private:  
        static AcerBuilder* m_pInstance;  
};  
#endif
