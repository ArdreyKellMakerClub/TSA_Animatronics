#ifndef TEXWRAP_H
#define TEXWRAP_H
#include "displaygui.h"
using namespace std;

class TexWrap
{
    public:
        TexWrap();
        virtual ~TexWrap();

        int getWidth();
        int getHeight();

        void free();
        void render(int,int, SDL_Renderer*);
        int load(string, SDL_Renderer*);
        int loadText(string, SDL_Color,int, SDL_Renderer*);
        void setDim(int, int);
    protected:

    private:
        SDL_Texture* texture;
        SDL_Rect rectangle;
        int width;
        int height;
};

#endif // TEXWRAP_H
