//
// Created by Paolo Octoman on 1/17/23.
//

#include "Charlie.h"

bool Charlie::isHappy() const {
    return happy;
}

Charlie::Charlie() {
    HCtexture.loadFromFile("Images/happyCharlie.png");

    HCsprite.setTexture(HCtexture);
    HCsprite.setScale(0.5,0.5);


    SCtexture.loadFromFile("Images/sadCharlie.png");
    SCsprite.setTexture(SCtexture);
    SCsprite.setScale(0.5,0.5);

    HCsprite.setPosition(500, 500);
    SCsprite.setPosition(HCsprite.getGlobalBounds().left - 50,HCsprite.getGlobalBounds().top+50);
    happy = true;

}

void Charlie::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (isHappy() == true){
        window.draw(HCsprite);
    }
    if (isHappy() == false){
        window.draw(SCsprite);
    }
}

void Charlie::setStatus(int value) {
    if (value == 1){
        happy = true;
    }
    if (value == 0){
        happy = false;
    }
}

void Charlie::move(sf::Vector2f newPos) {
    HCsprite.setPosition(newPos);
    SCsprite.setPosition(HCsprite.getGlobalBounds().left - 50,HCsprite.getGlobalBounds().top+50);


}

void Charlie::move(float x, float y) {
    HCsprite.setPosition(x,y);
    SCsprite.setPosition(HCsprite.getGlobalBounds().left - 50,HCsprite.getGlobalBounds().top+50);

}

sf::FloatRect Charlie::getGloablBounds() {
    return HCsprite.getGlobalBounds();
}


