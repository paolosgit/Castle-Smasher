//
// Created by Paolo Octoman on 1/16/23.
//

#include "Background.h"

Background::Background() {

    backTexture.loadFromFile("Images/beach.png");
    background.setTexture(backTexture);
    background.setScale(5,2.2);

}

void Background::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
}

Background::Background(sf::VideoMode videoMode) {
    backTexture.loadFromFile("Images/beach.png");
    background.setTexture(backTexture);
    background.setPosition(videoMode.width/2,videoMode.height/2);

}
