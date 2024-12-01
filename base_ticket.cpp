#pragma once
#include "base_ticket.h"
#include <iostream>

using namespace std;

// Default constructor của class BaseTicket. Khởi tạo các giá trị rác để dễ phân biệt với các vé khác
BaseTicket::BaseTicket() {
    this->ticket_id = "xxxxxxxx";
    this->owner_fullname = "<none>";
    this->year_of_birth = 1970;
}