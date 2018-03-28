/**
 * @file Prototype.h 
 * @brief 1. Copy a large object, the performance increase is quite obvious
          2. Copy objects, simple interface, like copy and paste.
          3. You can create a data object, rather than an empty object
 * @author BismarckDD
 * @version 1.0 2016/05/22
 */

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

class Prototype
{
    public:
        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        virtual ~Prototype();

        /**
         * Create Computer
         *
         * @param void
         * @return Prototype*
         * @note
         */
        virtual Prototype* Clone() const = 0;

    protected:
        /**
         * Construction
         *
         * @param void
         * @return 
         */
        Prototype();

    private:
        /**
         * Copy Construction
         *
         * @param const Prototype& cPrototype
         * @return 
         */
        Prototype(const Prototype& cPrototype);

        /**
         * Assignment
         *
         * @param const Prototype& cPrototype
         * @return Prototype&
         */
        Prototype& operator=(const Prototype& cPrototype);

    public:
    protected:
    private:
};

#endif 
