//
// Created by t on 12/19/2019.
//

#ifndef TTA_CARD_HPP
#define TTA_CARD_HPP


#include <string>

class Card {

public:

    Card(std::string name, std::string text):name(name), text(text) {};
    const std::string &getName() const;

    void setName(const std::string &name);

private:
    std::string name;
    std::string text;
public:
    const std::string &getText() const;

    void setText(const std::string &text);
};

class MilitaryCard : public Card {

};

class CivilCard : public Card {

};

#endif //TTA_CARD_HPP
