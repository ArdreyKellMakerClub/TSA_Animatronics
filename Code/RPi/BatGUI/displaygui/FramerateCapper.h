#ifndef FRAMERATECAPPER_H
#define FRAMERATECAPPER_H
#include <displaygui.h>

class FramerateCapper
{
    public:
        FramerateCapper();
        virtual ~FramerateCapper();

        void start();
        void stop();
        void pause();
        void resume();

        unsigned int ticks();
        int status();
    protected:
    private:
        unsigned int ticksFromStart;
        unsigned int ticksFromPause;
        bool isStarted;
        bool isPaused;
};

#endif // FRAMERATECAPPER_H
