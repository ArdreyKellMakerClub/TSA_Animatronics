#include "Menu.h"

Menu::Menu(){
    page = START;
}


Menu::~Menu()
{
    //dtor
}


void Menu::render(SDL_Renderer* ren, FramerateCapper fps, FramerateCapper cap){
    switch (page){
        case START:
            renderStart(ren);
            break;
        case MAIN:
            renderMain(ren);
            break;
        case ECHO:
            renderEcho(ren);
            break;
        case POLLEN:
            renderPollen(ren);
            break;
        case FLIGHT:
            renderFlight(ren);
            break;
        case TEST:
            renderTest(ren, fps, cap);
            break;
    }
}
void Menu::renderStart(SDL_Renderer* ren){
    start.TexWrap::render(ren);
}
void Menu::renderMain(SDL_Renderer* ren){
    echo.TexWrap::render(ren);
    pollen.TexWrap::render(ren);
    flight.TexWrap::render(ren);
    quit.TexWrap::render(ren);
    echoIco.render(ren);
    pollenIco.render(ren);
    flightIco.render(ren);
}
void Menu::renderEcho(SDL_Renderer* ren){

}
void Menu::renderPollen(SDL_Renderer* ren){

}
void Menu::renderFlight(SDL_Renderer* ren){

}
void Menu::renderTest(SDL_Renderer* ren, FramerateCapper fps, FramerateCapper cap){
    stringstream timeText, timeText1, buttonStr;

    background.render(ren);

    button.TexWrap::setPos( SCREEN_WIDTH/2 + 100*cos(frame*PI/120)-50, \
                            SCREEN_HEIGHT/5 + 120*sin(frame*PI/120));
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

void Menu::handleEvent(SDL_Event*e){
    switch(page){
        case START:
            handleStartEvent(e);
            break;
        case MAIN:
            handleMainEvent(e);
            break;
        case ECHO:
            handleEchoEvent(e);
            break;
        case POLLEN:
            handlePollenEvent(e);
            break;
        case FLIGHT:
            handleFlightEvent(e);
            break;
        case TEST:
            handleTestEvent(e);
            break;
    }
}
void Menu::handleStartEvent(SDL_Event*e){
    if(start.handleEvent(e)){
        page = MAIN;
        //Mix_PlayChannel(-1, intro, 0);
    }
}
void Menu::handleMainEvent(SDL_Event*e){

}
void Menu::handleEchoEvent(SDL_Event*e){

}
void Menu::handlePollenEvent(SDL_Event*e){

}
void Menu::handleFlightEvent(SDL_Event*e){

}
void Menu::handleTestEvent(SDL_Event* e){
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
    SDL_RenderClear(ren);background.render(ren);SDL_RenderPresent(ren);
    font = TTF_OpenFont("assets/font/cmunrm.ttf", 28);
    textColor = {0xFF,0x33,0x00,255};
    frameText.setPos(10,10);

    SDL_RenderClear(ren);background.render(ren);
    frameText.loadText("Loading Start", font, textColor, 28, ren);
    frameText.render(ren);SDL_RenderPresent(ren);
    loadStart(ren);cout<<"Loaded Start!"<<nl;

    SDL_RenderClear(ren);background.render(ren);
    frameText.loadText("Loading Main", font, textColor, 28, ren);
    frameText.render(ren);SDL_RenderPresent(ren);
    loadMain(ren);cout<<"Loaded Main!"<<nl;

    SDL_RenderClear(ren);background.render(ren);
    frameText.loadText("Loading Echo", font, textColor, 28, ren);
    frameText.render(ren);SDL_RenderPresent(ren);
    loadEcho(ren);cout<<"Loaded Echo!"<<nl;

    SDL_RenderClear(ren);background.render(ren);
    frameText.loadText("Loading Pollen", font, textColor, 28, ren);
    frameText.render(ren);SDL_RenderPresent(ren);
    loadPollen(ren);cout<<"Loaded Pollen!"<<nl;

    SDL_RenderClear(ren);background.render(ren);
    frameText.loadText("Loading Flight", font, textColor, 28, ren);
    frameText.render(ren);SDL_RenderPresent(ren);
    loadFlight(ren);cout<<"Loaded Flight!"<<nl;

    SDL_RenderClear(ren);background.render(ren);
    frameText.loadText("Loading Test", font, textColor, 28, ren);
    frameText.render(ren);SDL_RenderPresent(ren);
    loadTest(ren);cout<<"Loaded Test!"<<nl;
}
void Menu::loadStart(SDL_Renderer*ren){
    start = Button();
    start.TexWrap::load("assets/images/start/start_unpressed.bmp", ren);
    start.TexWrap::setPos(SCREEN_WIDTH/2-start.TexWrap::getWidth()/2, SCREEN_HEIGHT/2-start.TexWrap::getHeight()/2);
}
void Menu::loadMain(SDL_Renderer*ren){
    echo = Button();
    echo.TexWrap::load("assets/images/echolocation/echolocation_unpressed.bmp", ren);
    echo.TexWrap::setPos(SCREEN_WIDTH/4-echo.TexWrap::getWidth()/2,\
                         SCREEN_HEIGHT*3/5-echo.TexWrap::getHeight()/2);

    pollen = Button();
    pollen.TexWrap::load("assets/images/pollen/pollen_unpressed.bmp", ren);
    pollen.TexWrap::setPos(SCREEN_WIDTH/2-pollen.TexWrap::getWidth()/2,\
                           SCREEN_HEIGHT*3/5-pollen.TexWrap::getHeight()/2);

    flight = Button();
    flight.TexWrap::load("assets/images/start/start_unpressed.bmp", ren);
    flight.TexWrap::setPos(SCREEN_WIDTH*3/4-flight.TexWrap::getWidth()/2,\
                           SCREEN_HEIGHT*3/5-flight.TexWrap::getHeight()/2);

    quit = Button();
    quit.TexWrap::load("assets/images/start/start_unpressed.bmp", ren);
    quit.TexWrap::setPos(SCREEN_WIDTH/2-quit.TexWrap::getWidth()/2,\
                          SCREEN_HEIGHT*6/7-quit.TexWrap::getHeight()/2);

    echoIco = TexWrap();
    echoIco.load("assets/images/ping.bmp", ren);
    echoIco.setPos(SCREEN_WIDTH/4-echoIco.getWidth()/2,\
                   SCREEN_HEIGHT/3-echoIco.getHeight()/2);

    pollenIco = TexWrap();
    pollenIco.load("assets/images/pollen.bmp", ren);
    pollenIco.setPos(SCREEN_WIDTH/2-pollenIco.TexWrap::getWidth()/2,\
                     SCREEN_HEIGHT/3-pollenIco.TexWrap::getHeight()/2);

    flightIco = TexWrap();
    flightIco.load("assets/images/wing.bmp", ren);
    flightIco.setPos(SCREEN_WIDTH*3/4-flightIco.getWidth()/2,\
                     SCREEN_HEIGHT/3-flightIco.getHeight()/2);
}
void Menu::loadEcho(SDL_Renderer*ren){

}
void Menu::loadPollen(SDL_Renderer*ren){

}
void Menu::loadFlight(SDL_Renderer*ren){

}
void Menu::loadTest(SDL_Renderer*ren){
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






















