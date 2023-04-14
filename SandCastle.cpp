//
// Created by Paolo Octoman on 1/16/23.
//

#include "SandCastle.h"


SandCastle::SandCastle() {
    castleTexture.loadFromFile("Images/castle.png");
    castleSprite.setTexture(castleTexture);
    castleSprite.setScale(0.5,0.5);


    smashedTexture.loadFromFile("Images/smashed.png");
    smashedSprite.setTexture(smashedTexture);
    smashedSprite.setScale(0.5,0.5);

    castleSprite.setPosition(500, 500);
    smashedSprite.setPosition(castleSprite.getGlobalBounds().left - 50,castleSprite.getGlobalBounds().top+100);
    standing = true;


}

void SandCastle::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (isStanding() == true){
        window.draw(castleSprite);
    }
    if (isStanding() == false){
        window.draw(smashedSprite);
    }

}

void SandCastle::setStatus(int value) {
    if (value == 1){
        standing = true;
    }
    if (value == 0){
        standing = false;
    }
}

bool SandCastle::isStanding() const {
    return standing;
}

void SandCastle::move(sf::Vector2f newPos) {
    castleSprite.setPosition(newPos);
    smashedSprite.setPosition(castleSprite.getGlobalBounds().left - 50,castleSprite.getGlobalBounds().top+100);

}

void SandCastle::move(float x, float y) {
    castleSprite.setPosition(x,y);
    smashedSprite.setPosition(castleSprite.getGlobalBounds().left - 50,castleSprite.getGlobalBounds().top+100);
}

sf::FloatRect SandCastle::getGlobalBounds() {
    return castleSprite.getGlobalBounds();
}

