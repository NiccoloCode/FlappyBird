//
//  Flappy.hpp
//  Gioco
//
//  Created by Niccolò Feresini on 14/11/2020.
//  Copyright © 2020 Niccolò Feresini. All rights reserved.
//

#define Background_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#ifndef Background_h
#define Background_h
using namespace sf;
using namespace std;

namespace nf
{
class BackgroundManager{
private:
    
    //controllo posizione
    
    void CheckPosition()
    {
        int size = vettoreSpriteBackgorunds.size();
        
        if (size <= 1)
        {
            printf("/ndimensione vettore non valido");
            return;
        }
        for(auto& spriteBackground: vettoreSpriteBackgorunds)
        {
            if(spriteBackground.getPosition().x<=-1000)
            {
                spriteBackground.setPosition(1000*(size-1), spriteBackground.getPosition().y);
            }
        }
    }
    
    // disegna l'immagine sullo schermo
    
    void ShowBackground(RenderWindow& window)
    {
        for (auto& spriteBackground: vettoreSpriteBackgorunds)
        {
            spriteBackground.move(-0.75,0);
            window.draw(spriteBackground);
        }
    }
    
    vector<Sprite> vettoreSpriteBackgorunds;

public:
/*
 BackgroundManager(){};
 BackgroundManager(const BackgroundManager& b){}
 BackgroundManager& operator=(const BackgroundManager& b){}

 
 

 (tilde)BackgroundManager(){};
 */
    BackgroundManager() = delete;
    
    BackgroundManager& operator=(BackgroundManager& b)
    {
        
    };
    
    BackgroundManager(int numeroDiBackgrounds,Sprite sfondoSprite)
    {
    
        vettoreSpriteBackgorunds.push_back(sfondoSprite);
        
        for(int i=1;i<numeroDiBackgrounds;i++){
            sfondoSprite.setPosition(sfondoSprite.getPosition().x+1000, sfondoSprite.getPosition().y);
            vettoreSpriteBackgorunds.push_back(sfondoSprite);
        }
    }
    
    vector<Sprite> getVettoreSpriteBackgorunds()
    {
        return vettoreSpriteBackgorunds;
    }
    
    void Run(RenderWindow& window)
    {
        CheckPosition();
    }
    
    void draw(RenderWindow& window)
    {
        ShowBackground(window);
    }
    
    void drawStatico(RenderWindow& window)
    {
        window.draw(vettoreSpriteBackgorunds[0]);
        
    }
};

}

#endif /* Flappy_hpp */
