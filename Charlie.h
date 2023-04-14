//
// Created by Paolo Octoman on 1/17/23.
//

#ifndef WHATEVER_CHARLIE_H
#define WHATEVER_CHARLIE_H

#include <SFML/Graphics.hpp>
class Charlie: public sf::Transformable, public sf::Drawable {

private:
    sf::Texture HCtexture;
    sf::Texture* ptr;
    sf::Sprite HCsprite;
    sf::Texture SCtexture;
    sf::Sprite SCsprite;
    bool happy = false;
public:
    bool isHappy() const;

    Charlie();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void setStatus(int value);

    void move(sf::Vector2f newPos);

    void move(float x, float y);

    sf::FloatRect getGloablBounds();


};


#endif //WHATEVER_CHARLIE_H
