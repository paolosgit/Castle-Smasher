#include <iostream>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "CastleAndCharlie.h"
#include "LinkedList.h"
#include "Dave.h"
#include <string>
#include<cstdlib>
#include <ctime>
#include <random>
#include "Play.h"


int main() {

    sf::VideoMode videoMode(2380, 1340, 32);
    sf::RenderWindow window(videoMode, "Castle Smasher");
    sf::Font font;
    font.loadFromFile("Fonts/Pacifico.ttf");

    int scoreNum = 0;
    sf::Text score;
    score.setFont(font);
    std::string scoreString;
    scoreString = std::to_string(scoreNum);
    score.setString("SCORE: " + scoreString);
    score.setFillColor(sf::Color::Black);
    score.setCharacterSize(75);
    score.setPosition(1950, 1200);

    int timeNum = 0;
    sf::Text time;
    time.setFont(font);
    std::string timeString;
    timeString = std::to_string(timeNum);
    time.setString("Time: " + timeString);
    time.setFillColor(sf::Color::Black);
    time.setCharacterSize(75);
    time.setPosition(1350, 1200);

    sf::Clock clock;
    bool showTime = false;


    Play play;
    Dave dave;


    Background background;


    CastleAndCharlie castle;




    LinkedList<sf::Vector2f> positions;
    positions.push_back(castle.getPosition());









    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                window.close();
            }


            window.clear(sf::Color::Black);



            window.draw(background);



            if (positions.getSize() > 1){
                for (int i = 0; i < positions.getSize() - 1; ++i) {
                    castle.setStatus(0);
                    castle.move(positions[i]);
                    window.draw(castle);
                }
            }
            else
            {
                window.draw(castle);
            }


            castle.setStatus(1);
            castle.move(positions[positions.getSize()-1]);
            window.draw(castle);



            sf::Vector2f m_pos = (sf::Vector2f) sf::Mouse::getPosition(window);
            dave.move(m_pos);


            scoreString = std::to_string(scoreNum);
            score.setString("SCORE: " + scoreString);
            window.draw(score);
            window.draw(play);

            if (castle.getGlobalBounds().contains(m_pos)&& sf::Mouse::isButtonPressed(sf::Mouse::Left) && showTime ==true){
                std::random_device rd;
                std::uniform_int_distribution<int> distx(50, 2080);
                float x = distx(rd);
                std::uniform_int_distribution<int> disty(50, 900);
                float y = disty(rd);

                positions.push_back({x,y});
                scoreNum +=1;

            }


            if(play.getGlobalBounds().contains(m_pos)&& sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                while(positions.getSize() != 1){
                    positions.pop_back();
                }
                clock.restart();
                scoreNum = 0;
                showTime = true;



            }

            sf::Time timer = clock.getElapsedTime();
            timeNum = timer.asSeconds();
            timeNum = (timeNum - 20) * (-1);
            timeString = std::to_string(timeNum);
            if (showTime == true) {

                time.setString("Time: " + timeString);
                if (timeNum == 0) {
                    showTime = false;
                }

            }
            else{
                time.setString("Time: 0");
            }



            window.draw(time);

            window.draw(dave);

            window.display();

        }
    }

    return 0;
}
