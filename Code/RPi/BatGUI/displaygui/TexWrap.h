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
        void render(SDL_Renderer*);
        int load(string, SDL_Renderer*);
        int loadText(string, TTF_Font*, SDL_Color,int, SDL_Renderer*);
        void setDim(int, int);
        void setPos(int, int);
    protected:
        SDL_Texture* texture;
        SDL_Rect rectangle;
        int width;
        int height;
        SDL_Point position;
    private:

};

#endif // TEXWRAP_H
