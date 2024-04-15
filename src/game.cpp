#include "../include/game.h"
// Main function
void Game::run(){
    init();
    while(game_running){
        update();
        render();
    }
}
// Destructor
Game::~Game(){
    if (window != nullptr){
        delete window;
    }
    if (bulbassalro_texture != nullptr){
        delete bulbassalro_texture;
    }
    if (bulbassalro_sprite != nullptr){
        delete bulbassalro_sprite;
    }
    if (charmander_texture != nullptr){
        delete charmander_texture;
    }
    if (charmander_sprite != nullptr){
        delete charmander_sprite;
    }
    if (lifebar != nullptr){
        delete lifebar;
    }
}
// Init functions
void Game::init(){
    initVariables();
    initTextures();
    initSprites();
    initText();
    initLifebar();
    initWindow();
}
void Game::initVariables(){
    game_running = true;
}
void Game::initTextures(){
    bulbassalro_texture = new sf::Texture();
    charmander_texture = new sf::Texture();
    if (!bulbassalro_texture->loadFromFile(bulbassalro_img)){
        std::cout << "ERROR: Loading from file bulbassalro_texture";
    }
    if (!charmander_texture->loadFromFile(charmander_img)){
        std::cout << "ERROR: Loading from file charmander_texture";
    }
}
void Game::initSprites(){
    bulbassalro_sprite = new sf::Sprite();
    bulbassalro_sprite->setTexture(*bulbassalro_texture);
    bulbassalro_sprite->setScale(sprite_scale);
    bulbassalro_sprite->setPosition(player_pos);

    charmander_sprite = new sf::Sprite();
    charmander_sprite->setTexture(*charmander_texture);
    charmander_sprite->setScale(sprite_scale);
    charmander_sprite->setPosition(enemy_pos);
}
void Game::initWindow(){
    window = new sf::RenderWindow(window_size, "Pokemon Clone", sf::Style::Close | sf::Style::Titlebar);
    window->setPosition(sf::Vector2i(600,200));
    window->setFramerateLimit(30);

}
void Game::initText(){
    if (!font.loadFromFile(font_path)){
        std::cout << "ERROR: Failed to load font";
    }
    player_name = createText(font,black,30,"BULBASSAURO",player_namePos);
    enemy_name = createText(font,black,30,"CHARMANDER",enemy_namePos);
    player_level = createText(font,black,24,":L5",player_levelPos);
    enemy_level = createText(font,black,26,":L5", enemy_levelPos);
}
void Game::initLifebar(){
    lifebar = new LifeBar(100);
    lifebar->setPosition(enemy_lifePos);

    lifebar2 = new LifeBar(100);
    lifebar2->setPosition(player_lifePos);
}
// Update functions
void Game::update(){
    updateEvent();
}
void Game::updateEvent(){
     while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
            game_running = false;
        }
        else if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Escape){
                window->close();
                game_running = false;
            }
        }
    }
}
void Game::updateLifebar(int value){
    life -= value;
    if (life < 0)
        life = 0;
    lifebar->setLife(life);
}
// Render functions 
void Game::render(){
    window->clear(white);
    renderSprites();
    renderText();
    lifebar->draw(*window);
    lifebar2->draw(*window);
    window->display();
}
void Game::renderSprites(){
    window->draw(*bulbassalro_sprite);
    window->draw(*charmander_sprite);
}
void Game::renderText(){
    window->draw(player_name);
    window->draw(enemy_name);
    window->draw(player_level);
    window->draw(enemy_level);
}

// OTHERS FUNCTIONS
sf::Text Game::createText(const sf::Font& font, sf::Color color, int size, const char* str, sf::Vector2f position){
    sf::Text text;
    text.setFont(font);
    text.setFillColor(color);
    text.setCharacterSize(size);
    text.setString(str);
    text.setPosition(position);
    return text;
}