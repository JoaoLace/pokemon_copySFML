#pragma once
#include "mylib.h"
#include "lifebar.h"
class Game{
public:
    void run();
    ~Game();
private:

    void init();
    void initVariables();
    void initTextures();
    void initSprites();
    void initWindow();
    void initText();
    void initLifebar();

    void update();
    void updateEvent();
    void updateLifebar(int value);

    void render();
    void renderSprites();
    void renderText();

    sf::RenderWindow *window;

    sf::Texture *charmander_texture;
    sf::Texture *bulbassalro_texture;

    sf::Sprite *charmander_sprite;
    sf::Sprite *bulbassalro_sprite;

    sf::Event event;

    sf::Font font;
    sf::Text player_name;
    sf::Text enemy_name;
    sf::Text enemy_level;
    sf::Text player_level;

    sf::Text createText(const sf::Font& font, sf::Color color, int size, const char* str, sf::Vector2f position);
    sf::RectangleShape rect;
    bool game_running;

    LifeBar *lifebar;
    LifeBar *lifebar2;
    float life = 100;
};