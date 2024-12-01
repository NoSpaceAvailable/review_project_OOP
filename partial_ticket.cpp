#pragma once
#include "partial_ticket.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

PartialTicket::PartialTicket(
    int played_games = 0,
    int price_per_game = 20000,
    int entry_price = 70000,
    int year_of_birth = 1970,
    string owner_fullname = "<none>"
) {
    this->played_games = played_games;
    this->price_per_game = price_per_game;
    this->entry_price = entry_price;
    this->year_of_birth = year_of_birth;
    this->owner_fullname = owner_fullname;
    stringstream ss;
    ss << setw(8) << setfill('0') << ++_ticket_id;
    this->ticket_id = PT_PREFIX + ss.str();
}

int PartialTicket::total_price() const {
    return this->entry_price + this->played_games * this->price_per_game;
}

string PartialTicket::gettype() {
    return PT_PREFIX;
}

istream& operator>>(istream& in, PartialTicket& ticket) {
    cout << "\033[31mEnter owner fullname: \033[0m"; getline(in, ticket.owner_fullname);
    cout << "\033[31mEnter year of birth: \033[0m"; in >> ticket.year_of_birth;
    cout << "\033[31mEnter played games: \033[0m"; in >> ticket.played_games;
    cin.ignore(INT32_MAX, '\n');
    return in;
}

ostream& operator<<(ostream& out, const PartialTicket& ticket) {
    out << "\033[32m==============================TICKET==============================\033[0m\n";
    out << "\033[32m| \033[33mTicket ID: " << ticket.ticket_id << "\033[0m\n";
    out << "\033[32m| \033[33mTicket Type: Partial Ticket\n";
    out << "\033[32m| \033[33mOwner Fullname: " << ticket.owner_fullname << "\033[0m\n";
    out << "\033[32m| \033[33mYear of Birth: " << ticket.year_of_birth << "\033[0m\n";
    out << "\033[32m| \033[33mPlayed Games: " << ticket.played_games << "\033[0m\n";
    out << "\033[32m| \033[33mPrice per Game: " << ticket.price_per_game << "\033[0m\n";
    out << "\033[32m| \033[33mEntry Price: " << ticket.entry_price << "\033[0m\n";
    out << "\033[32m| \033[33mTotal Price: " << ticket.total_price() << "\033[0m\n";
    out << "\033[32m==================================================================\033[0m\n";
    return out;
}
