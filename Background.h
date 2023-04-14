//
// Created by Paolo Octoman on 1/16/23.
//

#ifndef WHATEVER_BACKGROUND_H
#define WHATEVER_BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background : public sf::Transformable, public sf::Drawable{
private:
    sf::Texture backTexture;
    sf::Sprite background;
public:
    Background();
    Background(sf::VideoMode videoMode);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //WHATEVER_BACKGROUND_H
