#pragma once
#include "mylib.h"

class LifeBar{
public:
    LifeBar(float maxLife) : m_maxLife(maxLife), m_currentLife(maxLife) {
        m_background.setSize(sf::Vector2f(200, 20));
        m_background.setFillColor(sf::Color::Black);
        m_background.setOutlineThickness(0.3f);
        
        m_life.setSize(sf::Vector2f(200, 20));
        m_life.setFillColor(gray);
        
        m_font.loadFromFile(font_path);
        m_text.setFont(m_font);
        m_text.setCharacterSize(24);
        m_text.setFillColor(black);
    }

    void setPosition(sf::Vector2f pos) {
        m_background.setPosition(pos.x, pos.y);
        m_life.setPosition(pos.x, pos.y);
        m_text.setPosition(pos.x + 5, pos.y - 20); 
    }

    void setLife(float life) {
        m_currentLife = life;
        updateLifeBar();
    }

    void updateLifeBar() {
        float ratio = m_currentLife / m_maxLife;
        m_life.setSize(sf::Vector2f(200 * ratio, 20));

        m_text.setString("Life: " + std::to_string(m_currentLife));
    }

    void draw(sf::RenderWindow& window) {
        window.draw(m_background);
        window.draw(m_life);
        window.draw(m_text);
    }

private:
    float m_maxLife;
    float m_currentLife;
    sf::RectangleShape m_background;
    sf::RectangleShape m_life;
    sf::Font m_font;
    sf::Text m_text;
};