//
// Created by Paolo Octoman on 1/17/23.
//

#ifndef WHATEVER_CASTLEANDCHARLIE_H
#define WHATEVER_CASTLEANDCHARLIE_H
#include "Charlie.h"
#include "SandCastle.h"
#include "SFML/Graphics.hpp"

class CastleAndCharlie : public sf::Transformable, public sf::Drawable{
private:
    Charlie charlie;
    SandCastle castle;
    bool fine;

public:
    CastleAndCharlie();
    CastleAndCharlie(float x, float y);
    void setStatus(int value);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    bool isFine() const;
    void move(float x, float y);
    void move(sf::Vector2f pos);
    void moveRandom();
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();


};


#endif //WHATEVER_CASTLEANDCHARLIE_H
