//
//  Score.cpp
//  Gioco
//
//  Created by Niccolò Feresini on 17/11/20.
//  Copyright © 2020 Niccolò Feresini. All rights reserved.
//

#include "Score.hpp"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "string"
#include "BackgroundManager.hpp"

using namespace sf;
using namespace std;

namespace nf
{

class Score
{
private:
    int score=0;
    Font font;
    Clock time;
    //int cont=0;
public:
    
    Score (RenderWindow& window){
        if(!font.loadFromFile("/Users/niccoloferesini/Desktop/GameProgramming/Gioco/Cripsy.ttf"))
        {
            printf("\n errore di caricamento del punteggio del giocatore");
            return;
        }
    }
    
    void draw(RenderWindow& window){
        
            score = (int)time.getElapsedTime().asSeconds()/0.5;
            string scoreStringa = to_string(score);
            Text scoreText(scoreStringa,font,40);
            scoreText.setPosition(900, 50);
            scoreText.setFillColor(Color::Red);
            window.draw(scoreText);
        }
    };

}
