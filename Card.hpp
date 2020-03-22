//
// Created by t on 12/19/2019.
//

#ifndef TTA_CARD_HPP
#define TTA_CARD_HPP


#include <string>

class Card {

public:

    Card(std::string name, std::string text, int age):name(name), text(text), age(age) {};
    const std::string &getName() const;

    void setName(const std::string &name);


    const std::string &getText() const;

    void setText(const std::string &text);

private:
    int age;
    std::string name;
    std::string text;

};

class MilitaryCard : public Card {

};

class CivilCard : public Card {

};

class RichLandA : public Card {
public:
    RichLandA() : Card("Rich Land A", "Build or upgrade a mine or farm; pay 1 rock less", 0) {};
};

class RichLandI : public Card {
public:
    RichLandI() : Card("Rich Land I", "Build or upgrade a mine or farm; pay 2 rock less", 1) {};
};

class RichLandII : public Card {
public:
    RichLandII() : Card("Rich Land II", "Build or upgrade a mine or farm; pay 3 rock less", 2) {};
};

class UrbanGrowthA: public Card {
public:
    UrbanGrowthA(): Card("Urban Growth A", "Build or upgrade an urban building; pay 1 rock less", 0) {};
};

class UrbanGrowthI: public Card {
public:
    UrbanGrowthI(): Card("Urban Growth A", "Build or upgrade an urban building; pay 2 rock less", 1) {};
};

class UrbanGrowthII: public Card {
public:
    UrbanGrowthII(): Card("Urban Growth A", "Build or upgrade an urban building; pay 3 rock less", 2) {};
};

class FrugalityA: public Card {
public:
    FrugalityA(): Card("Frugality A", "Increase your population. After you pay the food cost, gain 1 food", 0) {};
};
class FrugalityI: public Card {
public:
    FrugalityI(): Card("Frugality I", "Increase your population. After you pay the food cost, gain 2 food", 1) {};
};
class FrugalityII: public Card {
public:
    FrugalityII(): Card("Frugality II", "Increase your population. After you pay the food cost, gain 3 food", 2) {};
};

class StockPileA:public Card {
public:
StockPileA(): Card("Stock Pile A", "Gain 1 rock and 1 food", 0) {};
};

class CulturalHeritageA:public Card {
public:
CulturalHeritageA(): Card("Cultural Heritage A", "Score 1 science and 4 culture", 0) {};
};

class EngineeringGeniusA:public Card {
public:
EngineeringGeniusA(): Card("Engineering Genius A", "Build one stage of a wonder; pay 2 rock less", 0) {};
};

class Patriotism:public Card {
public:
Patriotism(): Card("Patriotism A", "For this turn, you have an extra 1 rock for building and upgrading military units and 1 extra military action. ", 0) {};
};



#endif //TTA_CARD_HPP
