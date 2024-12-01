#include "partial_ticket.cpp"
#include "full_ticket.cpp"
#include <iostream>
#include <vector>
using namespace std;

// In menu ra màn hình
void print_menu() {
    cout << "\033[36m==============================MENU==============================\033[0m\n";
    cout << "\033[36m| \033[33m1. Add partial ticket\n";
    cout << "\033[36m| \033[33m2. Add full ticket\n";
    cout << "\033[36m| \033[33m3. Display all tickets\n";
    cout << "\033[36m| \033[33m4. Total of partial tickets\n";
    cout << "\033[36m| \033[33m5. Total income\n";
    cout << "\033[36m| \033[33m6. Exit\n";
    cout << "\033[36m================================================================\033[0m\n";
}

int main() {
    vector<PartialTicket> p_tickets;    // vector chứa các vé từng phần
    vector<FullTicket> f_tickets;    // vector chứa các vé trọn gói
    char choice;

    while (true) {      // in menu và xử lý lựa chọn của user
        print_menu();
        cout << "\033[31m---> Enter your choice: \033[0m"; cin >> choice;
        cin.ignore(INT32_MAX, '\n');
        switch (choice){
            case '1': {
                PartialTicket ticket;
                cin >> ticket;
                p_tickets.push_back(ticket);
                cout << "\033[32m---> Ticket added successfully!\033[0m\n";
                break;
            }

            case '2': {
                FullTicket ticket;
                cin >> ticket;
                f_tickets.push_back(ticket);
                cout << "\033[32m---> Ticket added successfully!\033[0m\n";
                break;
            }

            case '3': {
                if (p_tickets.size() == 0) {
                    cout << "\033[31m---> No partial tickets to display!\033[0m\n";
                } else {
                    for (PartialTicket ticket : p_tickets) {
                        cout << ticket;
                    }
                }

                if (f_tickets.size() == 0) {
                    cout << "\033[31m---> No full tickets to display!\033[0m\n";
                } else {
                    for (FullTicket ticket : f_tickets) {
                        cout << ticket;
                    }
                }
                break;
            }

            case '4': {
                cout << "\033[32m---> Total of partial tickets: " << p_tickets.size() << "\033[0m\n";
                break;
            }

            case '5': {
                int total_income = 0;
                for (PartialTicket ticket : p_tickets) {
                    total_income += ticket.total_price();
                }
                for (FullTicket ticket : f_tickets) {
                    total_income += ticket.total_price();
                }
                cout << "\033[32m---> Total income: " << total_income << "\033[0m\n";
                break;
            }

            case '6': {
                cout << "\033[32m---> Bye!\033[0m\n";
                return 0;
            }
            
            default: {
                cout << "\033[31m[x] Invalid choice!\033[0m\n";
            }
        }
    }
}