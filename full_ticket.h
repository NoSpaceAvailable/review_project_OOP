#pragma once
#include "base_ticket.cpp"
#include <iostream>

using namespace std;

class FullTicket : public BaseTicket {
    protected:
        int entry_price;    // giá vé vào cổng
    public:
        // khởi tạo vé trọn gói với giá vé vào cổng, năm sinh và tên chủ vé
        FullTicket(int, int, string);
        // nạp chồng toán tử nhập
        friend istream& operator>>(istream&, FullTicket&);
        // nạp chồng toán tử xuất, in ra màn hình toàn bộ thông tin vé
        friend ostream& operator<<(ostream&, const FullTicket&);
        // override các phương thức ảo tính tổng tiền vé từ lớp cha
        int total_price() const override;
        // override phương thức ảo lấy loại vé từ lớp cha
        string gettype() override;
};
