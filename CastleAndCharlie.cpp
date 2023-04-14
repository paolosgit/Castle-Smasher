//
// Created by Paolo Octoman on 1/17/23.
//

#include "CastleAndCharlie.h"
#include<cstdlib>
#include <iostream>
#include <ctime>
#include <random>



void CastleAndCharlie::setStatus(int value) {
    if (value == 1){
        castle.setStatus(1);
        charlie.setStatus(1);
        fine = true;
    }
    if (value == 0){
        castle.setStatus(0);
        charlie.setStatus(0);
        fine = false;

    }
}

void CastleAndCharlie::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(castle);
    window.draw(charlie);
}

bool CastleAndCharlie::isFine() const {
    return fine;
}



CastleAndCharlie::CastleAndCharlie() {

    std::random_device rd;
    std::uniform_int_distribution<int> distx(50, 2080);
    int x = distx(rd);
    std::uniform_int_distribution<int> disty(50, 900);
    int y = disty(rd);

    castle.move(x,y);
    charlie.move(castle.getGlobalBounds().left+250,castle.getGlobalBounds().top+50);


    castle.setStatus(1);
    charlie.setStatus(1);
    fine = true;

}

void CastleAndCharlie::move(float x, float y) {
    castle.move(x,y);
    charlie.move(castle.getGlobalBounds().left+250,castle.getGlobalBounds().top+50);
}

CastleAndCharlie::CastleAndCharlie(float x, float y) {
    castle.move(x,y);
    charlie.move(castle.getGlobalBounds().left+250,castle.getGlobalBounds().top+50);


    castle.setStatus(1);
    charlie.setStatus(1);
    fine = true;

    std::cout << "The position coordinates are: " << x << " "<< y << std::endl;
}

void CastleAndCharlie::moveRandom() {
    int  x, y;
    srand(time(0));
    x = rand() % (2280);
    y = rand() % (940);

    move(x,y);
}

sf::FloatRect CastleAndCharlie::getGlobalBounds() {
    return castle.getGlobalBounds();
}

sf::Vector2f CastleAndCharlie::getPosition() {
    sf::Vector2f pos = {castle.getGlobalBounds().left, castle.getGlobalBounds().top};

    return pos;
}

void CastleAndCharlie::move(sf::Vector2f pos) {
    castle.move(pos.x,pos.y);
    charlie.move(castle.getGlobalBounds().left+250,castle.getGlobalBounds().top+50);

}
