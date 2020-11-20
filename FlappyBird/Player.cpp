//
//  Player.cpp
//  Gioco
//
//  Created by Niccolò Feresini on 15/11/2020.
//  Copyright © 2020 Niccolò Feresini. All rights reserved.
//

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "BackgroundManager.hpp"
using namespace sf;
using namespace std;



namespace nf {

class Player
{
private:
    Texture playerTexture;
    Sprite playerSprite;
    Clock clock;
    float posizioneInizialeSalto;
    float gravity= 1000;
    float velocitaIniziale=500;
    bool isJumping = false;
    float massimaHigh;
    
    typedef struct{
        float x;
        float y;
    } coordinate;
    
    void moveUp()
    {
        float mSecond = clock.getElapsedTime().asSeconds();
        float finalMaxPosition=posizioneInizialeSalto-massimaHigh;
        float spazioPercorso=(velocitaIniziale*mSecond)-(0.5*gravity*2*mSecond*mSecond);
        if(playerSprite.getPosition().y==finalMaxPosition)
            if(playerSprite.getPosition().y<=finalMaxPosition || spazioPercorso <= 0)
            {
                isJumping=false;
                clock.restart();
                posizioneInizialeSalto = playerSprite.getPosition().y;
                return;
            }
        playerSprite.setPosition(playerSprite.getPosition().x,posizioneInizialeSalto-spazioPercorso);
    }
    
    void movedown()
    {
        float mSecond = clock.getElapsedTime().asSeconds();
        float spazioPercorso=(0.5*gravity*mSecond*mSecond);
        playerSprite.setPosition(playerSprite.getPosition().x, posizioneInizialeSalto+spazioPercorso);
    }
    
public:
    
    Player(string imaginePath)
    {
        
        if(!playerTexture.loadFromFile(imaginePath))
        {
            return 0;
        }
        
        playerSprite.setTexture(playerTexture);
        playerSprite.setPosition(100,200);
        playerSprite.setScale(0.20, 0.20);
    }
    
    coordinate getPosition(){
        
        coordinate coordinateVettoreSprite;
        
        coordinateVettoreSprite.x = playerSprite.getPosition().x;
        
        coordinateVettoreSprite.y = playerSprite.getPosition().y;
        
        return coordinateVettoreSprite;
    }
    
    bool isDead()
    {
        if(playerSprite.getPosition().y>330) return true;
        return false;
    }
    
    void draw(RenderWindow& window)
    {
        window.draw(playerSprite);
    }
    
    void updatePosition(bool isTakingJump)
    {
        if(isDead()) return;
        if(isTakingJump)
        {
            clock.restart();
            isJumping=true;
            posizioneInizialeSalto=playerSprite.getPosition().y;
            massimaHigh=(velocitaIniziale*velocitaIniziale)/(2*gravity);
        }
        
        
        if(!isJumping)
        {
            movedown();
        }
        else
        {
            moveUp();
            
        }
        
    }
    
};



}
