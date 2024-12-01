#pragma once
#include "base_ticket.cpp"
#include <iostream>

using namespace std;

class PartialTicket : public BaseTicket {
    protected:
        int played_games;      // số game đã chơi
        int price_per_game;     // giá vé mỗi game
        int entry_price;        // giá vé vào cổng
    public:
        // khởi tạo vé từng phần với số game đã chơi, giá vé mỗi game, giá vé vào cổng, năm sinh và tên chủ vé
        PartialTicket(int, int, int, int, string);
        // nạp chồng toán tử nhập
        friend istream& operator>>(istream&, PartialTicket&);
        // nạp chồng toán tử xuất, in toàn bộ thông tin vé
        friend ostream& operator<<(ostream&, const PartialTicket&);
        // override phương thức ảo tính tổng tiền vé từ lớp cha
        int total_price() const override;
        // override phương thức ảo lấy loại vé từ lớp cha
        string gettype() override;
};
