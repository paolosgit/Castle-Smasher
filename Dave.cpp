//
// Created by Paolo Octoman on 1/17/23.
//

#include "Dave.h"

Dave::Dave() {
    daveTextture.loadFromFile("Images/Dave.png");
    daveSprite.setTexture(daveTextture);
    daveSprite.setScale(0.2,0.2);

    daveSprite.setPosition(100,100);

    horseTexture.loadFromFile("Images/horse.png");
    horseSprite.setTexture(horseTexture);
    horseSprite.setScale(0.45,0.45);
    horseSprite.setPosition(100,100);


}

void Dave::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(horseSprite);
    window.draw(daveSprite);
}

void Dave::move(sf::Vector2f mouseCoor) {
    daveSprite.setPosition(mouseCoor.x - 50,mouseCoor.y - 100);
    horseSprite.setPosition(mouseCoor.x -75,mouseCoor.y - 50);

}

