//
//  Tubi.cpp
//  Gioco
//
//  Created by Niccolò Feresini on 19/11/20.
//  Copyright © 2020 Niccolò Feresini. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include "Tubi.hpp"
#include "BackgroundManager.hpp"
#include <list>

using namespace sf;
using namespace std;

namespace nf {

class Tubi
{
private:
    
    typedef struct{
        int lunghezza;
        int altezza;
    }dimensioneRettangolo;
    
    Clock time;
    Texture textureTubi;
    Sprite* pSpriteTubi;
    IntRect coordinateRettangolo;
    dimensioneRettangolo dimensioneRect;
    list<BackgroundManager*> pbackgroundTubi;
    bool condizioneDiCostruzione;
    
    bool devoCostrureIlTubo()
    {
    
        if((condizioneDiCostruzione || pbackgroundTubi.size()<=4) && (time.getElapsedTime().asSeconds()>=2))
        {
            time.restart();
            return true;
        }
        return false;
    }
    
    void costruttoreVettoreSpriteTubi()
    {
        sceltaCasualeSprite();
        pbackgroundTubi.push_back(new BackgroundManager(1,*pSpriteTubi));
    }
    
    void distruggiTubo()
    {
        condizioneDiCostruzione=false;
        if(pbackgroundTubi.size()==0) return;
        if(pbackgroundTubi.front()->getVettoreSpriteBackgorunds()[0].getPosition().x<dimensioneRect.lunghezza*(-1))
        {
            delete pbackgroundTubi.front();
            pbackgroundTubi.pop_front();
            condizioneDiCostruzione=true;
        }
    }
    
    bool controlloIntersezioneTubi(float posizioneTuboDaInserire)
    {
        for(auto& ptubo: pbackgroundTubi)
        {
            //if()
        }
    }
    
public:
    
    Tubi(string pathTexture,IntRect vettoreCoordinateRettangolo)
    {
        if(!textureTubi.loadFromFile(pathTexture))
        {
            printf("\ncaricamento tubi non valido ");
        }
        coordinateRettangolo=vettoreCoordinateRettangolo;
        dimensioneRect.lunghezza=vettoreCoordinateRettangolo.width;
        dimensioneRect.altezza=vettoreCoordinateRettangolo.height;
        pSpriteTubi = nullptr;
    }
    
    void sceltaCasualeSprite()
    {
        if(pSpriteTubi != nullptr)
            delete pSpriteTubi;
        int numeroCasuale=rand()%4;
        switch (numeroCasuale)
        {
            case 0:
                pSpriteTubi=new Sprite(textureTubi,coordinateRettangolo);
                break;
            case 1:
                coordinateRettangolo.left=dimensioneRect.lunghezza;
                pSpriteTubi=new Sprite(textureTubi,coordinateRettangolo);
                break;
            case 2:
                coordinateRettangolo.top=dimensioneRect.altezza;
                pSpriteTubi=new Sprite(textureTubi,coordinateRettangolo);
                break;
            case 3:
                coordinateRettangolo.left=dimensioneRect.lunghezza;
                coordinateRettangolo.top=dimensioneRect.altezza;
                pSpriteTubi=new Sprite(textureTubi,coordinateRettangolo);
                break;
            default:
                break;
        }
       
        //pSpriteTubi->setPosition((numeroCasuale+1)*1000, 0);
    
    }
    
    void draw(RenderWindow& window)
    {
        distruggiTubo();
        
        if(devoCostrureIlTubo()){
            costruttoreVettoreSpriteTubi();
        }
        
        coordinateRettangolo.left=0;
        coordinateRettangolo.top=0;
        
        for(auto& pTubo : pbackgroundTubi)
        {
            pTubo->draw(window);
        }
        
    }
    
    
};

}

