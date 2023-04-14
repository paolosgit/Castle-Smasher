//
// Created by Paolo Octoman on 1/17/23.
//

#ifndef WHATEVER_DAVE_H
#define WHATEVER_DAVE_H
#include "SFML/Graphics.hpp"


class Dave: public sf::Transformable, public sf::Drawable {
private:
    sf::Texture daveTextture;
    sf::Sprite daveSprite;
    sf::Texture horseTexture;
    sf::Sprite horseSprite;

public:
    Dave();
    void move(sf::Vector2f mouseCoor);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //WHATEVER_DAVE_H
