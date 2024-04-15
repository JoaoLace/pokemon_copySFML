#pragma once
#include "mylib.h"

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

    void update();
    void updateEvent();

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

    bool game_running;
};