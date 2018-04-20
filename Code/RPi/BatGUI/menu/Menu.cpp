#include "Menu.h"

Menu::Menu(){
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::render(SDL_Renderer* ren, FramerateCapper fps, FramerateCapper cap){
    switch (state){
        case start:
            break;
        case main:
            break;
        case echo:
            break;
        case pollen:
            break;
        case flight:
            break;
        case test:
            renderTest(ren, fps, cap);
            break;
    }
}


void Menu::renderTest(SDL_Renderer* ren, FramerateCapper fps, FramerateCapper cap){
    stringstream timeText, timeText1, buttonStr;

    background.render(ren);\

    button.TexWrap::setPos( SCREEN_WIDTH/2 + 100*cos(frame*PI/120)-50, SCREEN_HEIGHT/5 + SCREEN_HEIGHT/6*sin(frame*PI/120));
    button.TexWrap::render( ren );
    buttonTest.TexWrap::render(ren);

    if(debug){
        float avgFPS = frame / ( fps.ticks() / 1000.f );
        if( avgFPS > 2000000 ){
            avgFPS = 0;
        }

        //Set text to be render
        timeText1.str(std::string());
        timeText1 <<"Frame: "<< frame;

        timeText.str(std::string());
        timeText << "FPS: "<< avgFPS;

        buttonStr.str(std::string());
        buttonStr<< "Button Status: ";
        switch(buttonTest.getState()){
            case 0:
                buttonStr<<"Unpressed";
                break;
            case 1:
                buttonStr<<"Highlighted";
                break;
            case 2:
                buttonStr<<"Pressed";
                break;
            }

            //draw text
            if(fpsText.loadText( timeText.str(),font, textColor, 28, ren) * \
                frameText.loadText( timeText1.str(),font, textColor, 28, ren) * \
                 buttonText.loadText( buttonStr.str(), font, textColor, 28, ren)<0){
                cout<<"Unable to disply frame info"<<nl;
            }

            //render text
            fpsText.render(ren);
            frameText.render(ren);
            buttonText.render(ren);
        }

        ++frame;
}

void Menu::handleEvent(SDL_Event* e){
    if (buttonTest.handleEvent(e)){
        buttonTest.TexWrap::setPos(rand()%(SCREEN_WIDTH-buttonTest.getWidth()), \
                                   rand()%(SCREEN_HEIGHT-buttonTest.getHeight()));
                Mix_PlayChannel(-1, youSuffer, 0);
    }
    if (button.handleEvent(e)){
        debug = !debug;
    }
}

void Menu::close(){

}

void Menu::load(SDL_Renderer*ren){
    font = TTF_OpenFont("assets/font/cmunrm.ttf", 28);
    textColor = {0x33,0xFF,0x00,255};

    button = Button();
    button.TexWrap::load("assets/images/button/button_unpressed.bmp", ren);

    buttonTest = Button();
    buttonTest.TexWrap::load("assets/images/button/button_unpressed.bmp", ren);
    buttonTest.TexWrap::setPos(SCREEN_WIDTH/3, SCREEN_HEIGHT/2);

    background.TexWrap::load("assets/images/background_placeholder.bmp", ren);
    background.setDim(SCREEN_WIDTH, SCREEN_HEIGHT);
    background.setPos(0,0);

    fpsText = TexWrap();
    fpsText.setPos(10,10);
    frameText = TexWrap();
    frameText.setPos(10,40);
    buttonText = TexWrap();
    buttonText.setPos(10,70);

    youSuffer = Mix_LoadWAV("assets/audio/testChunk.wav");
}
