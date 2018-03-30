/**
 * @file Director.h
 * @brief 1.When the algorithm to create complex object should be independent of the part of the object, as well as their assembly;
 *        2.When construction process must be allowed to construct the object is different.
 * @author BismarckDD
 * @version 1.0 2016/05/23
 */

#ifndef DIRECTOR_H
#define DIRECTOR_H

class AbstractComputer;
class Builder;

class Director
{
    public:
        /**
         * Construction
         *
         * @param Builder* pBuilder
         * @return 
         */
        Director(Builder* pBuilder);

        /**
         * Destruction
         *
         * @param void
         * @return 
         */
        ~Director();

        /**
         * Create Computer
         *
         * @param void
         * @return AbstractComputer*
         * @note
         */
        AbstractComputer* CreateComputer();

    protected:

    private:
        /**
         * Copy Construction
         *
         * @param const Director& cDirector
         * @return 
         */
        Director(const Director& cDirector);

    public:
    protected:
    private:
        Builder* m_pBuilder;
};

#endif
