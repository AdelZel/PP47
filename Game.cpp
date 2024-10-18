
#include "Button.h"
#include "Score.h"
#include "Game.h"
#include "Entity.h"
#include "Projectile.h"
#include "Laser.h"
#include "Spaceship.h"
#include "Player.h"
#include "Enemy.h"

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

Game::Game()
{
    sizeOfProj = sizeof(projectiles)/ sizeof(Projectile);
    for (size_t i = 0; i < sizeOfProj; i++)
    {
        projectiles[i] = new Projectile();
    }
    
    Clock sclock;
    this->dT = 0.f;
    this->score.SetScore(0);
    this->gameState = 0;
    this->tBackMenuButtons.loadFromFile("images/iBackMenuButtons.png");
    this->sBackMenuButtons.setTexture(tBackMenuButtons);
    this->tBackRecords.loadFromFile("images/iBackRecords.png");
    this->sBackRecords.setTexture(tBackRecords);
    this->tBackGameplay.loadFromFile("images/iBack.png");
    this->sBackGameplay.setTexture(tBackGameplay);
    this->tBackGameplayD.loadFromFile("images/iBack.png");
    this->sBackGameplayD.setTexture(tBackGameplay);
    this->tPlayer.loadFromFile("images/iPlayer.png");
    this->sPlayer.setTexture(tPlayer);
    this->tLaser.loadFromFile("images/iLaser.png");
    this->sLaser.setTexture(tLaser);
    this->tEnemy.loadFromFile("images/iEnemy.png");
    this->sEnemy.setTexture(tEnemy);
    sEnemy.setRotation(180.f);
    
    this->tBackDeathScreen.loadFromFile("images/iBackDeathScreen.png");
    this->sBackDeathScreen.setTexture(tBackDeathScreen);
    // entitties sprites
    // stuff here
}

int Game::get_gameState()
{
    return this->gameState;
}

void Game::set_gameState(int gs)
{
    if (gs == 0 || gs == 1 ||  gs == 2 ||  gs == 3)
    {
        this->gameState = gs;
    }
}

float Game::deltaTime() { return this->sclock.restart().asSeconds(); }

void Game::run()
{
    bool keyReleased = true;
    Font font; // initiate a general purpose font
    font.loadFromFile("fonts/CourierNew.ttf"); // load font from file

    float screenWidth = 640.f; // screen width
    float screenHeight = 360.f; // screen height
    float heightRatio = screenHeight / screenWidth;    // setup intial aspect ratio for height
    float widthRatio = screenWidth / screenHeight;    // setup intial aspect ratio for width

    float scoreUpdateTimer;
    float startTimer;
    float spaceSpeed;

    RenderWindow window(VideoMode(screenWidth, screenHeight), "LSD"); // create window

    sf::Vector2u windowSize = window.getSize();    // get current win size
    if (windowSize.y * widthRatio <= windowSize.x) { windowSize.x = windowSize.y * widthRatio; } // adapt width if height changed
    else if (windowSize.x * heightRatio <= windowSize.y) { windowSize.y = windowSize.x * heightRatio; } // adapt height if height width
    window.setSize(windowSize);    // set the new size
    bool wasResized = false;
    
    Event event; // empty first 
    Event lastEvent;

    Player player(Vector2f(window.getSize().x/2-sPlayer.getLocalBounds().width/2, (window.getSize().y/6)*5), Vector2f(sPlayer.getLocalBounds().width, sPlayer.getLocalBounds().height), &sPlayer, 1.f);
    Enemy enemy;

    for (int i =0; i <3; i++)
    {
        enemies[i] = new Enemy(Vector2f(window.getSize().x/2-sPlayer.getLocalBounds().width/2, (window.getSize().y/2)-1.3f*i*sPlayer.getLocalBounds().height), Vector2f(sPlayer.getLocalBounds().width, sPlayer.getLocalBounds().height), new Sprite(tEnemy), 1.f);
    }

    while (window.isOpen())
    {
////////////////////////////////////////////////////////////////////////////////////////     

        bool flag = window.pollEvent(event); // get any event that happens to the main win
        cout << flag << endl;
        // if (
        //     (lastEvent.type == event.type) &&
        //     (event.type == Event::MouseButtonReleased) &&
        //     (event.mouseButton.button == Mouse::Left)
        //     )
        // {
        //     cout << "proverka" << endl;
        //     Event event;
        // }

        // cout << event.type << endl;

        if (event.type == Event::Closed) { window.close(); } // if win is closed manually

        dT = this->deltaTime(); // count delta time so everything moves smoothly no matter fps

        if (event.type == Event::Resized && !wasResized)
        {
            sf::Vector2u windowSize = window.getSize();    // get current win size
            if (windowSize.y * widthRatio <= windowSize.x) { windowSize.x = windowSize.y * widthRatio; } // adapt width if height changed
            else if (windowSize.x * heightRatio <= windowSize.y) { windowSize.y = windowSize.x * heightRatio; } // adapt height if height width
            window.setSize(windowSize);    // set the new size
            wasResized = true;
        } else { wasResized = false; }

////////////////////////////////////////////////////////////////////////////////////////            

        if (this->get_gameState() == 0)            // 0 STATE - MENU
        {
            int buttonPosX = window.getSize().x / 3;
            int buttonPosY = window.getSize().y / 2;
            int buttonSizeX = window.getSize().x / 3;
            int buttonSizeY = window.getSize().y / 12;
        
            Button bPlay(Vector2i(buttonPosX, buttonPosY), Vector2i(buttonSizeX, buttonSizeY));
            Button bRecs(Vector2i(buttonPosX, buttonPosY + (buttonSizeY*2)), Vector2i(buttonSizeX, buttonSizeY));
            Button bExit(Vector2i(buttonPosX, buttonPosY + (buttonSizeY*4)), Vector2i(buttonSizeX, buttonSizeY));
        
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left && flag)
            {
                if (bExit.checkClick(Mouse::getPosition(window))) { window.close(); }
                if (bRecs.checkClick(Mouse::getPosition(window))) { this->set_gameState(3); }
                if (bPlay.checkClick(Mouse::getPosition(window)))
                {
                    cout << "starting game!" << endl;
                    this->set_gameState(1);
                    scoreUpdateTimer = 0.f;
                    startTimer = 0.f;
                    spaceSpeed = 0;
                    sBackGameplay.setPosition(0, -7.f*window.getSize().y);
                    sBackGameplayD.setPosition(0, -15.f*window.getSize().y);
                    score.SetScore(0);
                }
            }

            window.clear();
            window.draw(sBackMenuButtons);
            window.display();
        }

////////////////////////////////////////////////////////////////////////////////////////

        else if (this->get_gameState() == 1)            // 1 STATE - GAMEPLAY
        {

            Text scoreText;
            string scoreIntString = to_string(this->score.GetScore());
            string scoreString = "Score: " + scoreIntString;
            scoreText.setFont(font);
            scoreText.setString(scoreString);
            scoreText.setCharacterSize(window.getSize().y / 15);
            scoreText.setFillColor(Color::White);


            Text startingText;
            string startingTimerString = to_string(3-(int)startTimer);
            string startingString = "a - left\nd - right\nspace - shoot!\nwe start in:\n" + startingTimerString;
            startingText.setFont(font);
            startingText.setString(startingString);
            startingText.setCharacterSize(window.getSize().y / 15);
            startingText.setFillColor(Color::White);
            startingText.setPosition(window.getSize().x/2.f - startingText.getLocalBounds().width/2.f, window.getSize().y/2.f - startingText.getLocalBounds().height/2.f);

            

            // starting screen
            if  ( startTimer < 3 )
            {
                startTimer += dT;
                spaceSpeed = -5;
                scoreUpdateTimer = 0;
            }
            //

            // score upd-ing
            scoreUpdateTimer += dT;
            if (scoreUpdateTimer >= 1)
            {
                score.SetScore(score.GetScore()+1);
                scoreUpdateTimer = 0.f;
            }
            // //

            // // moves each projectile according to its speed each frame
            for (size_t i = 0; i < sizeOfProj; i++)
            {
                if (projectiles[i]->get_ownerType() != -1)
                {
                    if (projectiles[i]->checkCollision(player) && projectiles[i]->get_ownerType() == 1)
                    {
                        //player dies if they get hit with enemy projectile
                        cout << "player got hit" << endl;
                        set_gameState(2);
                        DeleteProjectile(i, projectiles[i]);
                    }

                    if (projectiles[i]->get_ownerType() == 0)
                    {
                        for (size_t j = 0; j < 3; j++)
                        {
                            if (projectiles[i]->checkCollision(*enemies[j]))
                            {
                                cout << "im trying to delete stuff" << endl;
                                DeleteEnemy(j, enemies[j]);
                                DeleteProjectile(i, projectiles[i]);
                            }
                            
                        }
                        
                    }
                    
                    
                if (projectiles[i]->get_location().y > screenHeight || projectiles[i]->get_location().y < 0)
                {
                    cout << "projectile " << i << " was destroyed at y location: " << projectiles[i]->get_location().y << endl;
                    DeleteProjectile(i, projectiles[i]);
                }
                    projectiles[i]->Fire(&player);
                } 
            }


            // scrolling background
            sBackGameplay.move(0, dT*(5+spaceSpeed));
            sBackGameplayD.move(0, dT*(5+spaceSpeed));
            spaceSpeed += (dT*3.f);
            if ( (sBackGameplay.getPosition().y >= 0) && (sBackGameplayD.getPosition().y >= 0) )
            {
                if (sBackGameplayD.getPosition().y > sBackGameplay.getPosition().y)
                {
                    sBackGameplayD.move(0, -8.f*window.getSize().y);
                }
                else
                {
                    sBackGameplay.move(0, -8.f*window.getSize().y);
                }
            }


            //
            if (startTimer < 5){
                startTimer += dT;
            } else {
                for (int i =0; i <3; i++)
                {
                    enemies[i]->act(dT, &window);
                    if (enemies[i]->get_hp() == -1)
                    {
                        enemies[i] = new Enemy(Vector2f(window.getSize().x/2-sPlayer.getLocalBounds().width/2, (window.getSize().y/2)-1.3f*i*sPlayer.getLocalBounds().height), Vector2f(sPlayer.getLocalBounds().width, sPlayer.getLocalBounds().height), new Sprite(tEnemy), 1.f);
                    }
                }
            }
            
            // //


            // keyboard input handle
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                cout << "Left in " << this->get_gameState() << " game state" << endl;
                player.move(player.get_location()-Vector2f((float)(((float)window.getSize().x)*player.get_speed()/1600.f), 0.f));
            }
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                cout << "Right in " << this->get_gameState() << " game state" << endl;
                player.move(player.get_location()+Vector2f((float)(((float)window.getSize().x)*player.get_speed()/1600.f), 0.f));
            }


            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                cout << "Space in " << this->get_gameState() << " game state" << endl;
              if (keyReleased)
                    {
                player.shoot();
                keyReleased = false;
              }
            }

            if (Keyboard::isKeyPressed(Keyboard::K))
            {
                { this->set_gameState(2); 
                cout << "ddd" << endl;}
            }
          
          if (event.type == 6)
            {
                keyReleased = true;
            }
            // // 


            // player boundaries set
            if (player.get_location().x < 0)
            {
                player.move(Vector2f(0, player.get_location().y));
            }
            else if (((player.get_location().x + player.get_size().x) > window.getSize().x))
            {
                player.move(Vector2f(window.getSize().x-player.get_size().x, player.get_location().y));
            }
            // //



            window.clear();
            window.draw(sBackGameplay);
            window.draw(sBackGameplayD);

            window.draw(sPlayer);
            if (startTimer < 3) { window.draw(startingText); } else
            {
                window.draw(scoreText);

                for (int i =0; i <3; i++) {if(enemies[i]->get_hp() != -1) {window.draw(*enemies[i]->get_enemySprite());} }
                for (size_t i = 0; i < sizeOfProj; i++)
                {
                    if (projectiles[i]->get_ownerType() != -1)
                    {
                            if (projectiles[i]->get_ownerType() == 0)
                        {
                            sLaser.setRotation(-90.f);
                            sLaser.setColor(Color::Blue);
                            sLaser.setPosition(projectiles[i]->get_location().x + 15, projectiles[i]->get_location().y);

                        } else if (projectiles[i]->get_ownerType() == 1)
                        {
                            sLaser.setRotation(90.f);
                            sLaser.setColor(Color::Red);
                            sLaser.setPosition(projectiles[i]->get_location().x - 15, projectiles[i]->get_location().y);

                        }
                        
                        window.draw(sLaser);
                    }
                }
                
            }

            window.display();
        }
    
////////////////////////////////////////////////////////////////////////////////////////

        else if (this->get_gameState() == 2)            // 2 STATE - death screen
        {
                for (size_t i = 0; i < sizeOfProj; i++)
        {
            projectiles[i] = new Projectile();
        }
            // button positions and sizes
            int buttonPosX = window.getSize().x / 3;
            int buttonPosY = window.getSize().y / 2;
            int buttonSizeX = window.getSize().x / 3;
            int buttonSizeY = window.getSize().y / 12;

            // create final score text
            Text finalScoreText;
            string finalScoreString = to_string(this->score.GetScore());
            finalScoreText.setFont(font);
            finalScoreText.setString(finalScoreString);
            finalScoreText.setCharacterSize(window.getSize().y / 12);
            finalScoreText.setFillColor(Color::White);
            // adjust position based on window size 
            float centerX = (window.getSize().x - finalScoreText.getGlobalBounds().width) / 2;
            float positionY = window.getSize().y * 0.25f; // adjust vertical position
            finalScoreText.setPosition(centerX, positionY);

            // menu, save, and exit buttons
            Button bMenu(Vector2i(buttonPosX, buttonPosY), Vector2i(buttonSizeX, buttonSizeY));
            Button bSave(Vector2i(buttonPosX, buttonPosY + (buttonSizeY * 2)), Vector2i(buttonSizeX, buttonSizeY));
            Button bExit(Vector2i(buttonPosX, buttonPosY + (buttonSizeY * 4)), Vector2i(buttonSizeX, buttonSizeY));


            // nickname input 
            Text nicknameText;
            nicknameText.setFont(font);
            nicknameText.setString("Enter your nickname: ");
            nicknameText.setCharacterSize(window.getSize().y / 15);
            nicknameText.setFillColor(Color::White);
            nicknameText.setPosition(buttonPosX, buttonPosY - buttonSizeY * 2);

            // nickname input handling
            static std::string nickname = "";
            if (event.type == Event::TextEntered && flag)
            {
                if (event.text.unicode < 128 && event.text.unicode != 13 && event.text.unicode != 8) // ignore enter and backspace
                {
                    nickname += static_cast<char>(event.text.unicode);
                }
                else if (event.text.unicode == 8 && !nickname.empty()) // handle backspace
                {
                    nickname.pop_back();
                }
            }

            Text enteredNickname;
            enteredNickname.setFont(font);
            enteredNickname.setString(nickname);
            enteredNickname.setCharacterSize(window.getSize().y / 15);
            enteredNickname.setFillColor(Color::White);
            enteredNickname.setPosition(buttonPosX, buttonPosY - buttonSizeY);


            // check if button clicks
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left && flag) {
                // Ensure mouse position is taken correctly
                Vector2i mousePos = Mouse::getPosition(window);
                if (bExit.checkClick(mousePos)) {
                    window.close();
                }
                if (bMenu.checkClick(mousePos)) {
                    this->set_gameState(0);   // set game state to MENU (0)
                    cout << "Changing to menu!" << endl; 
                }

                if (bSave.checkClick(mousePos)) {
                    this->score.WriteNewHighScore(nickname, this->score.GetScore()); // Saves score
                    this->set_gameState(3);   // set game state to records (3)
                    cout << "Score saved!" << endl;
                }

            }

            window.clear();
            window.draw(sBackDeathScreen);
            window.draw(finalScoreText);  // draw final score
            window.draw(nicknameText);
            window.draw(enteredNickname); // displaying entered nickname

            window.display();
        }



        

////////////////////////////////////////////////////////////////////////////////////////

        else if (this->get_gameState() == 3)            // 3 STATE - records
        {
        
            // creating header for records screen //
            Text recordsTableHeader ;
            recordsTableHeader.setFont(font);
            recordsTableHeader.setString("Top 5 Records:");
            recordsTableHeader.setCharacterSize(window.getSize().y / 10);
            recordsTableHeader.setFillColor(Color::White);
            recordsTableHeader.setPosition(Vector2f(windowSize.x/4, 0));
            Text recordsTable;
            recordsTable.setFont(font);
            recordsTable.setString(score.FetchScores());
            recordsTable.setCharacterSize(window.getSize().y / 10);
            recordsTable.setFillColor(Color::White);
            recordsTable.setPosition(Vector2f(windowSize.x/3, 50));
            // //

            if (event.type == Event::KeyReleased && event.key.code == Keyboard::Q )
            {
                cout << "bye from gamestate: " << this->get_gameState() << "!" << endl;
                this->set_gameState(0);
            }

            window.clear();
            window.draw(sBackRecords);
            window.draw(recordsTableHeader);
            window.draw(recordsTable);
            window.display();
        }
    lastEvent = event;
    }
}

void Game::AddNewProjectile(Projectile* added){
    for (int i = 0; i < sizeOfProj; i++)
    {
        cout << "c" << endl;
        if (projectiles[i]->get_ownerType() == -1)
        {
            cout << "d" << endl;
            projectiles[i] = added;
            return;
        }   
    }
    

}

void Game::DeleteProjectile(int delSpot, Projectile* dave){
    cout << "dave projectile" << endl;
    delete dave;
    cout << "reassigning" << endl;
    projectiles[delSpot] = new Projectile();
    cout << "reassigned" << endl;
}

void Game::DeleteEnemy(int delSpot, Enemy* dave){
    cout << "dave enemy" << endl;
    delete dave;
    cout << "reassigning" << endl;
    enemies[delSpot] = new Enemy();
    cout << "reassigned" << endl;
    score.AddScore(50);
    cout << "added score" << endl;
}