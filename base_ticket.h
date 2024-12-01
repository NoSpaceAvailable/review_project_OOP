#pragma once
#include <iostream>
#define PT_PREFIX "PT"      // tiền tố của vé từng phần
#define FULL_PREFIX "FU"    // tiền tố của vé trọn gói

using namespace std;

static int _ticket_id = 0;

class BaseTicket {
    protected:
        string ticket_id;
        string owner_fullname;
        int year_of_birth;
    public:
        BaseTicket();
        // Hàm thuần ảo, cho phép class con tự định nghĩa lại để tính giá vé
        virtual int total_price() const = 0;
        // Hàm thuần ảo, cho phép class con tự định nghĩa lại để lấy loại vé
        virtual string gettype() = 0;
        // Nạp chồng toán tử nhập
        friend istream& operator>>(istream&, BaseTicket& ticket);
        // Nạp chồng toán tử xuất
        friend ostream& operator<<(ostream&, const BaseTicket& ticket);
};