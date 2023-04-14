//
// Created by Paolo Octoman on 1/17/23.
//

#ifndef WHATEVER_PLAY_H
#define WHATEVER_PLAY_H

#include <string>
#include <SFML/Graphics.hpp>
class Play : public sf::Drawable, public sf::Transformable{
private:
    std::string text;
    sf::RectangleShape box;
    sf::Font font;
    sf::Text play;
public:
    Play();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds();
};



#endif //WHATEVER_PLAY_H
