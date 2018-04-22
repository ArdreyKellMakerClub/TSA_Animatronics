#include "Menu.h"

Menu::Menu(){
    page = START;
}


Menu::~Menu()
{
    //dtor
}


void Menu::render(SDL_Renderer* ren){
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

    if(narrKey==0){
        Mix_PlayChannel(0, intro, 0);
        ++narrKey;
    }
}
void Menu::renderEcho(SDL_Renderer* ren){
    diagram.render(ren);
    goBack.TexWrap::render(ren);
    //ping ardiuno for stuff


    switch(narrKey){
        case 0:
            Mix_PlayChannel(0, echo1, 0);
            ++narrKey;
            break;
        case 1:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, echo2, 0);
                narrKey = -1;
            }
            break;
        case 2:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, echoErr, 0);
                narrKey=-1;
            }
            cout<<Mix_GetError()<<nl;
            break;
        case 3:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, echoSucc1, 0);
                narrKey = -1;
            }
            break;
        case 4:
            //distance()
            narrKey = -1;
            break;
        case 5:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, echoSucc2, 0);
                narrKey= -1;
            }
            break;
    }
}
void Menu::renderPollen(SDL_Renderer* ren){
    banana.render(ren);
    mango.render(ren);
    guava.render(ren);
    goBack.TexWrap::render(ren);
    switch(narrKey){
        case 0:
            Mix_PlayChannel(0, pollenNarr, 0);
            cout<<Mix_GetError()<<nl;
            ++narrKey;
            break;
        case 1:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, backNarr, 0);
                ++narrKey;
            }
            break;
    }
}
void Menu::renderFlight(SDL_Renderer* ren){
    switch(narrKey){
        case 0:
            Mix_PlayChannel(0, flap1, 0);
            ++narrKey;
            break;
        case 1:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, flap2, 0);
                ++narrKey;
            }
            break;
        case 2:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, flap3, 0);
                ++narrKey;
            }
            break;
        case 3:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, flap4, 0);
                ++narrKey;
            }
            break;
        case 4:
            if(Mix_Playing(0)==0){
                Mix_PlayChannel(0, backNarr, 0);
                ++narrKey;
            }
            break;
    }
    bat.render(ren);
    goBack.TexWrap::render(ren);
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
    }
}
void Menu::handleStartEvent(SDL_Event*e){
    if(start.handleEvent(e)){
        page = MAIN;
        narrKey = 0;
    }
}
void Menu::handleMainEvent(SDL_Event*e){
    if(echo.handleEvent(e)){
        page = ECHO;
        narrKey=0;
    }
    else if(pollen.handleEvent(e)){
        page = POLLEN;
        narrKey = 0;

    }
    else if(flight.handleEvent(e)){
        page = FLIGHT;
        narrKey = 0;
    }
    else if(quit.handleEvent(e)){
        page = QUIT;
        Mix_PlayChannel(-1, batman, 0);
    }
}
void Menu::handleEchoEvent(SDL_Event*e){
    if(goBack.handleEvent(e)){
        Mix_HaltChannel(0);
        page = MAIN;
        narrKey = 1;
    }
}
void Menu::handlePollenEvent(SDL_Event*e){
    if(goBack.handleEvent(e)){
        Mix_HaltChannel(0);
        narrKey = 1;
        page = MAIN;
    }
}
void Menu::handleFlightEvent(SDL_Event*e){
    if(goBack.handleEvent(e)){
        Mix_HaltChannel(0);
        narrKey = 1;
        page = MAIN;
    }
}


void Menu::close(){

}

void Menu::load(SDL_Renderer*ren){
    SDL_RenderClear(ren);SDL_RenderPresent(ren);
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

}
void Menu::loadStart(SDL_Renderer*ren){
    start = Button();
    start.TexWrap::load("assets/images/start/start_unpressed.bmp", ren);
    start.TexWrap::setPos(SCREEN_WIDTH/2-start.TexWrap::getWidth()/2, \
                          SCREEN_HEIGHT/2-start.TexWrap::getHeight()/2);

    intro = Mix_LoadWAV("assets/audio/Intro.wav");
    batman = Mix_LoadWAV("assets/audio/batman.wav");
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
    flight.TexWrap::load("assets/images/flight/flight_unpressed.bmp", ren);
    flight.TexWrap::setPos(SCREEN_WIDTH*3/4-flight.TexWrap::getWidth()/2,\
                           SCREEN_HEIGHT*3/5-flight.TexWrap::getHeight()/2);

    quit = Button();
    quit.TexWrap::load("assets/images/quit/quit_unpressed.bmp", ren);
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
    goBack = Button();
    goBack.TexWrap::load("assets/images/back/back_unpressed.bmp", ren);
    goBack.TexWrap::setPos(SCREEN_WIDTH/2-goBack.TexWrap::getWidth()/2,\
                           SCREEN_HEIGHT*6/7-goBack.TexWrap::getHeight()/2);

    diagram = TexWrap();
    diagram.load("assets/images/diagram.bmp", ren);
    diagram.setPos(SCREEN_WIDTH/2-diagram.getWidth()/2,\
                   SCREEN_HEIGHT/2-diagram.getHeight()/2);

    echo1 = Mix_LoadWAV("assets/audio/Echo1.wav");
    echo2 = Mix_LoadWAV("assets/audio/Echo2.wav");
    echoErr = Mix_LoadWAV("assets/audio/EchoErr.wav");
    echoSucc1 = Mix_LoadWAV("assets/audio/EchoSucc1.wav");
    echoSucc2 = Mix_LoadWAV("assets/audio/EchoSucc2.wav");
}
void Menu::loadPollen(SDL_Renderer*ren){
    banana = TexWrap();
    banana.load("assets/images/banana.bmp", ren);
    banana.setPos(SCREEN_WIDTH/4-banana.getWidth()/2, \
                  SCREEN_HEIGHT/2-banana.getHeight()/2);

    mango = TexWrap();
    mango.load("assets/images/mango.bmp", ren);
    mango.setPos(SCREEN_WIDTH/2-mango.getWidth()/2, \
                 SCREEN_HEIGHT/2-mango.getHeight()/2);

    guava = TexWrap();
    guava.load("assets/images/guava.bmp", ren);
    guava.setPos(SCREEN_WIDTH*3/4-guava.getWidth()/2, \
                 SCREEN_HEIGHT/2-guava.getHeight()/2);


    pollenNarr = Mix_LoadWAV("assets/audio/Pollination.wav");
    if(pollenNarr == nullptr) cout<<"failed to load pollenNarr! SDL_Mixer error: "<<Mix_GetError()<<nl;

    backNarr = Mix_LoadWAV("assets/audio/back.wav");
    if(backNarr == nullptr) cout<<"failed to load backNarr! SDL_Mixer error: "<<Mix_GetError()<<nl;
}
void Menu::loadFlight(SDL_Renderer*ren){
    bat = TexWrap();
    bat.load("assets/images/bat.bmp", ren);
    bat.setPos(SCREEN_WIDTH/2-bat.getWidth()/2,\
               SCREEN_HEIGHT/2-bat.getHeight()/2);

    flap1 = Mix_LoadWAV("assets/audio/Flap1.wav");
    flap2 = Mix_LoadWAV("assets/audio/Flap2.wav");
    flap3 = Mix_LoadWAV("assets/audio/Flap3.wav");
    flap4 = Mix_LoadWAV("assets/audio/Flap4.wav");
}


bool Menu::quitFlag(){
    return page == QUIT;
}





















