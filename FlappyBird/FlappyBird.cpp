
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include <SFML/Graphics.hpp>
#include "BackgroundManager.hpp"
#include <vector>
#include "Player.cpp"
#include "Score.cpp"
#include "InizioGioco.cpp"
#include "Tubi.cpp"

using namespace sf;
using namespace std;
using namespace nf;

static string filePath = "/Users/niccoloferesini/Desktop/GameProgramming/FlappyBird/FlappyBird";


int main()
{
    Font fontGame;
    if(!fontGame.loadFromFile(filePath+"/Cripsy.ttf"))
    {
        printf("\nfont non corretto");
        return 0;
    }
    
    Color red(255,0,0);
    Text end("GAME OVER",fontGame,200);
    end.setPosition(110, 100);
    end.setFillColor(red);
    Texture sfondoTextureInizioGioco;
    if(!sfondoTextureInizioGioco.loadFromFile(filePath+"/background.jpg"));
    Texture sfondoTextureGioco;
    if(!sfondoTextureGioco.loadFromFile(filePath+"/background.jpg"))
    {
        printf("\n errore di caricamento");
        return 0;
    }
    
    Sprite spriteSfondo(sfondoTextureInizioGioco);
    
    BackgroundManager background(2,spriteSfondo);
    VideoMode screen(1000,480);
    RenderWindow window(screen,"Flappy Birds");
    
    Score scorePlayer(window);
    InizioGioco start(window,spriteSfondo);
    start.start();
    IntRect rettangolo(0,0,133,213);
    Player flappy(filePath+"/flappyBird.png");
    Tubi tubi(filePath+"/tubi.png",rettangolo);
    
    Clock clock;
    int aSeconds = 0;
    
    while (window.isOpen())
    {
        
        bool jump = false;
        Event event;
        while(window.pollEvent(event))
        {
            
            if(event.type==sf::Event::KeyPressed
               && event.key.code==sf::Keyboard::Escape)
                window.close();
            
            if(event.key.code==sf::Keyboard::Space && event.type==sf::Event::KeyPressed)
                jump = true;
            
        }
                
        if(!flappy.isDead()) window.clear();
        
        if(!flappy.isDead())
        {
            background.Run(window);
            flappy.updatePosition(jump);
            background.draw(window);
            flappy.draw(window);
            tubi.draw(window);
            
        }
        else
        {
            window.setTitle("You Lose");
            window.draw(end);
        }
        scorePlayer.draw(window);
        window.display();
        
        
    }
    
}







