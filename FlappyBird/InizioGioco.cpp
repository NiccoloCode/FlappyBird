//
//  InizioGioco.cpp
//  Gioco
//
//  Created by Niccolò Feresini on 18/11/20.
//  Copyright © 2020 Niccolò Feresini. All rights reserved.
//


#include <SFML/Graphics.hpp>
#include "BackgroundManager.hpp"
using namespace sf;

namespace nf {

class InizioGioco{

private:

    RenderWindow* pWindow;
    Event evento;
    bool condizioneCiclo=true;
    BackgroundManager* pBackground;
public:
    
    InizioGioco(RenderWindow& windowMain,Sprite& spriteMain)
    {
        pBackground = new BackgroundManager(1,spriteMain);
        pWindow=&windowMain;
    }
    void start()
    {
        while(condizioneCiclo)
        {
            while (pWindow->pollEvent(evento)) {
                if(evento.key.code==Keyboard::Key::Enter) condizioneCiclo=false;
                
         }
            pWindow->clear();
            pBackground->drawStatico(*pWindow);
            pWindow->display();
        }
    }
    
};
}
