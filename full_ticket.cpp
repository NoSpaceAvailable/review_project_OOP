#pragma once
#include "full_ticket.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

FullTicket::FullTicket(
    int entry_price = 200000,
    int year_of_birth = 1970,
    string owner_fullname = "<none>"
) {
    this->entry_price = entry_price;
    this->year_of_birth = year_of_birth;
    this->owner_fullname = owner_fullname;
    stringstream ss;
    ss << setw(8) << setfill('0') << ++_ticket_id;
    this->ticket_id = FULL_PREFIX + ss.str();
}

int FullTicket::total_price() const {
    return this->entry_price;
}

string FullTicket::gettype() {
    return FULL_PREFIX;
}

istream& operator>>(istream& in, FullTicket& ticket) {
    cout << "\033[31mEnter owner fullname: \033[0m"; getline(in, ticket.owner_fullname);
    cout << "\033[31mEnter year of birth: \033[0m"; in >> ticket.year_of_birth;
    cin.ignore(INT32_MAX, '\n');
    return in;
}

ostream& operator<<(ostream& out, const FullTicket& ticket) {
    out << "\033[32m==============================TICKET==============================\033[0m\n";
    out << "\033[32m| \033[33mTicket ID: " << ticket.ticket_id << "\033[0m\n";
    out << "\033[32m| \033[33mTicket Type: Full Ticket\n";
    out << "\033[32m| \033[33mOwner Fullname: " << ticket.owner_fullname << "\033[0m\n";
    out << "\033[32m| \033[33mYear of Birth: " << ticket.year_of_birth << "\033[0m\n";
    out << "\033[32m| \033[33mEntry Price: " << ticket.entry_price << "\033[0m\n";
    out << "\033[32m| \033[33mTotal Price: " << ticket.total_price() << "\033[0m\n";
    out << "\033[32m==================================================================\033[0m\n";
    return out;
}
