#ifndef _timer_h_
#define _timer_h_

#include<ctime>

namespace stdcs
{

namespace tools
{
    class Timer
    {
    private:
        size_t _begin;
        size_t _end;
        double _costTime;

    public:
        Timer()
        {
            _begin = 0;
            _end = 0;
            _costTime = 0;
        }

        ~Timer(){}

        void count()
        {
            _begin = _end;
            _end = clock();
        }

        void reset()
        {
            _begin = 0;
            _end = 0;
            _costTime = 0;

        }

        double getElapse()
        {
            _costTime = (double)(_end-_begin)/CLOCKS_PER_SEC;
            return _costTime;
        }
    };
}

}

#endif
