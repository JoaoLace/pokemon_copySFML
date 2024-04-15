#pragma once 

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#define width 800
#define heigth 720
#define window_size sf::VideoMode(800,720)
#define charmander_img "img/charmander.jpg"
#define bulbassalro_img "img/bulbassalro.png"
#define font_path "fonts/PKMN RBYGSC.ttf"
#define sprite_scale sf::Vector2f(4.f,4.f)
#define white sf::Color::White
#define black sf::Color::Black
#define gray sf::Color(128, 128, 128)
#define player_pos sf::Vector2f(100, heigth - 300)
#define enemy_pos sf::Vector2f(width - 250, 50)
#define player_namePos sf::Vector2f(width - 350,50 + 52 *4)
#define enemy_namePos sf::Vector2f(50, 0)
#define player_levelPos sf::Vector2f(width - 350 + 30*5.5, 50 + 52 *4 + 32)
#define enemy_levelPos sf::Vector2f(50 + 30*5,0 + 32)
#define player_lifePos sf::Vector2f(width - 350 + 30 *3,  50 + 52 *4 + 42 + 30)
#define enemy_lifePos sf::Vector2f(50 + 30*2,0 + 72)
