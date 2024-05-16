#include <iostream>
using namespace std;

int main() {
    char productName1[] = "Подарункова упаковка";
    char productName2[] = "Ялинкові прикраси";
    char productName3[] = "Новорічні свічки";
    char productName4[] = "Солодощі";
    
    double productPrice1 = 10.99;
    double productPrice2 = 5.49;
    double productPrice3 = 3.99;
    double productPrice4 = 2.79;

    int productQuantity1 = 20;
    int productQuantity2 = 30;
    int productQuantity3 = 15;
    int productQuantity4 = 40;

    double totalRevenue = 0.0;

    int clients;
    cout << "Введіть кількість клієнтів: ";
    cin >> clients;

    for (int client = 1; client <= clients; ++client) {
        double clientTotal = 0.0;
        cout << "\nКлієнт " << client << endl;
        cout << "Список товарів:" << endl;
        cout << "1. " << productName1 << " - $" << productPrice1 << " (залишок: " << productQuantity1 << ")" << endl;
        cout << "2. " << productName2 << " - $" << productPrice2 << " (залишок: " << productQuantity2 << ")" << endl;
        cout << "3. " << productName3 << " - $" << productPrice3 << " (залишок: " << productQuantity3 << ")" << endl;
        cout << "4. " << productName4 << " - $" << productPrice4 << " (залишок: " << productQuantity4 << ")" << endl;
        for (int i = 0; i < 4; ++i) {
            int choice;
            cout << "Оберіть товар (введіть номер): ";
            cin >> choice;
            if (choice == 0) {
                break;
            }
            double* productPrice;
            int* productQuantity;
            char* productName;
            switch (choice) {
                case 1:
                    productName = productName1;
                    productPrice = &productPrice1;
                    productQuantity = &productQuantity1;
                    break;
                case 2:
                    productName = productName2;
                    productPrice = &productPrice2;
                    productQuantity = &productQuantity2;
                    break;
                case 3:
                    productName = productName3;
                    productPrice = &productPrice3;
                    productQuantity = &productQuantity3;
                    break;
                case 4:
                    productName = productName4;
                    productPrice = &productPrice4;
                    productQuantity = &productQuantity4;
                    break;
                default:
                    cout << "Невірний вибір товару. Будь ласка, спробуйте знову." << endl;
                    --i;
                    continue;
            }
            int quantity;
            cout << "Введіть кількість товару: ";
            cin >> quantity;
            if (quantity <= 0 || quantity > *productQuantity) {
                cout << "Некоректна кількість товару. Будь ласка, спробуйте знову." << endl;
                --i;
                continue;
            }
            double total = *productPrice * quantity;
            clientTotal += total;
            totalRevenue += total;
            *productQuantity -= quantity;
            cout << "Додано в корзину: " << productName << " x " << quantity << " - $" << total << endl;
        }
        cout << "Загальна сума покупки клієнта " << client << ": $" << clientTotal << endl;
    }
    cout << "\nЗагальна виручка магазину: $"<< totalRevenue << endl;
    return 0;
}