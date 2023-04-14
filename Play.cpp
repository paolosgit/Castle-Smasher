//
// Created by Paolo Octoman on 1/17/23.
//

#include "Play.h"

Play::Play() {
    box.setSize({250, 100});
    box.setFillColor(sf::Color::Red);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(5);

    box.setPosition({1650, 1200});

    font.loadFromFile("Fonts/Pacifico.ttf");
    play.setFont(font);
    text = "Play";
    play.setString(text);
    play.setCharacterSize(50);
    play.setPosition((2*box.getGlobalBounds().left + box.getGlobalBounds().width)/2 - 50, (2*box.getGlobalBounds().top + box.getGlobalBounds().height)/2 - 25);

}

void Play::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(play);
}

sf::FloatRect Play::getGlobalBounds() {
    return box.getGlobalBounds();
}
