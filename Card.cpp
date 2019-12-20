//
// Created by t on 12/19/2019.
//

#include "Card.hpp"

const std::string &Card::getName() const {
    return name;
}

void Card::setName(const std::string &name) {
    Card::name = name;
}

const std::string &Card::getText() const {
    return text;
}

void Card::setText(const std::string &text) {
    Card::text = text;
}
