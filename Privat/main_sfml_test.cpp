#include <C:\sfml\include\SFML\Graphics.hpp>
#include <C:\sfml\include\SFML\Graphics\BlenderMode.hpp>
#include <iostream>

int main() {
    // Fenster erstellen
    sf::RenderWindow window(sf::VideoMode(800, 600), "Healthbar Beispiel");
    window.setFramerateLimit(60);

    // Healthbar-Eigenschaften
    float maxHealth = 100.0f;
    float currentHealth = 100.0f;
    float healthBarWidth = 300.0f;
    float healthBarHeight = 30.0f;

    // Healthbar-Hintergrund (grau)
    sf::RectangleShape healthBarBackground(sf::Vector2f(healthBarWidth, healthBarHeight));
    healthBarBackground.setPosition(50, 50);
    healthBarBackground.setFillColor(sf::Color(100, 100, 100));

    // Healthbar (grün)
    sf::RectangleShape healthBar(sf::Vector2f(healthBarWidth, healthBarHeight));
    healthBar.setPosition(50, 50);
    healthBar.setFillColor(sf::Color::Green);

    // Text für den Health-Wert
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) { // Pfad zur Schriftart anpassen
        std::cerr << "Fehler: Schriftart konnte nicht geladen werden!" << std::endl;
        return -1;
    }

    sf::Text healthText;
    healthText.setFont(font);
    healthText.setString("Health: 100%");
    healthText.setCharacterSize(24);
    healthText.setFillColor(sf::Color::White);
    healthText.setPosition(50, 100);

    // Hauptschleife
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Beispiel: Healthbar durch Tastendruck verringern
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left && currentHealth > 0) {
                    currentHealth -= 10.0f;
                    if (currentHealth < 0) currentHealth = 0;
                }
                if (event.key.code == sf::Keyboard::Right && currentHealth < maxHealth) {
                    currentHealth += 10.0f;
                    if (currentHealth > maxHealth) currentHealth = maxHealth;
                }
            }
        }

        // Healthbar aktualisieren
        float healthPercentage = currentHealth / maxHealth;
        healthBar.setSize(sf::Vector2f(healthBarWidth * healthPercentage, healthBarHeight));

        // Health-Text aktualisieren
        healthText.setString("Health: " + std::to_string(static_cast<int>(currentHealth)) + "%");

        // Fenster löschen
        window.clear(sf::Color::Black);

        // Healthbar zeichnen
        window.draw(healthBarBackground);
        window.draw(healthBar);
        window.draw(healthText);

        // Fenster anzeigen
        window.display();
    }

    return 0;
}