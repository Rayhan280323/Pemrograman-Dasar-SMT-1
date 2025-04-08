#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Order {
    int category;
    int item;
    int quantity;
    string name;
};

void displayMenuCoffee() {
    cout << "== Espresso Based ==" << endl;
    cout << "1. Espresso          : 13.000" << endl;
    cout << "2. Americano         : 15.000" << endl;
    cout << "3. Cappuccino        : 17.000" << endl;
    cout << "4. Latte             : 17.000" << endl;
    cout << "5. Caramel Machiatto : 20.000" << endl;
    cout << endl;
}

void displayMenuNonCoffee() {
    cout << "== Milk Based ==" << endl;
    cout << "1. Chocolate         : 17.000" << endl;
    cout << "2. Taro              : 17.000" << endl;
    cout << "3. Matcha            : 17.000" << endl;
    cout << "4. Thai Tea          : 17.000" << endl;
    cout << "5. Regal             : 19.000" << endl;
    cout << endl;
}

void displayMenuAdd() {
    cout << "== Additional ==" << endl;
    cout << "1. Espresso Shot     : 5.000" << endl;
    cout << "2. Caramel Syrup     : 6.000" << endl;
    cout << "3. Ice Tube          : 6.000" << endl;
    cout << endl;
}

void displayMenuSnack() {
    cout << "== Snack ==" << endl;
    cout << "1. French Fries      : 15.000" << endl;
    cout << "2. Siomay            : 15.000" << endl;
    cout << "3. Bomb Cookies      : 18.000" << endl;
    cout << "4. Croissant         : 18.000" << endl;
    cout << endl;
}

void displayMenuCombo() {
    cout << "== Congratulations, You Can only Choose One for All Beverages + All Snack within only pay Rp 25.000 and cannot choose additional menu ==" << endl;
    cout << " What are You looking for today : " << endl;
    cout <<endl;
}

int main() {
    const int MX_ORDRS = 10;
    const int CTGR_COFFEE = 1;
    const int CTGR_NON_COFFEE = 2;
    const int CTGR_SNCK = 3;
    const int CTGR_ADD = 4;

    string menuCoffee[] = {"Espresso", "Americano", "Cappuccino", "Latte", "Caramel Machiatto"};
    float pricesCoffee[] = {13000, 15000, 17000, 17000, 20000};

    string menuNonCoffee[] = {"Chocolate", "Taro", "Matcha", "Thai Tea", "Regal"};
    float pricesNonCoffee[] = {17000, 17000, 17000, 17000, 19000};

    string menuAdd[] = {"Espresso Shot", "Caramel Syrup", "Ice Tube"};
    float pricesAdd[] = {5000, 6000, 6000};

    string menuSnack[] = {"French Fries", "Siomay", "Bomb Cookies", "Croissant"};
    float pricesSnack[] = {15000, 15000, 18000, 18000};

    char Program;
    string Day, custname, addorders, cashlessPayment, confirminvoice,confirmlast;
    int orderCount = 0, menuchoices, custchoices, totalPrice;
    int discMonday = 25000;
    vector<Order> orders;
    int paymentMethod;
    float totalPayment, payment, change;

utama:
    cout << "===== Art U I Know Coffee =====" << endl;
    cout << " Input the Day (ex. Monday): ";
    cin >> Day;
    bool isMonday = (Day == "Monday");

    if (Day != "Monday" && Day != "Tuesday" && Day != "Wednesday" && Day != "Thursday" && Day != "Friday" && Day != "Saturday" && Day != "Sunday") {
        cout << "Your Input Was Wrong !!!" << endl;
        goto utama;
    } else {
        cout << " Input Your Name: ";
        getline (cin >> ws, custname);
        system("cls");

        cout << endl;
        if (isMonday) {
            cout << " Hi " << custname << " You got Happiest's Monday Promo!!!" << endl;
            cout << endl;
            displayMenuCombo();
            goto mondayPromo;
            
        } else {
            cout << "Hi " << custname << " What are You looking for today : " << endl;
            cout << " 1. Customer Self Service " << endl;
            cout << " 2. Out " << endl;
            cout <<endl;
            cout << " Input Choices (1/2) : ";
            cin  >> Program;
            cout << endl;
            system("cls");
            switch (Program) {

            case '1': {
                menu:
                do {
                    cout << endl;
                    cout << "== Welcome To The Club ==" << endl;
                    if (isMonday) {
                        mondayPromo:
                        cout << " 1. Espresso Based" << endl;
                        cout << " 2. Milk Based" << endl;
                        cout << " 3. Snack" << endl;
                        cout <<endl;
                        cout << "== Input Choices (1/2/3) == : ";
                        cin >> menuchoices;
                    } else {
                        cout << " 1. Espresso Based" << endl;
                        cout << " 2. Milk Based" << endl;
                        cout << " 3. Snack" << endl;
                        cout << " 4. Additional" << endl;
                        cout << "== Input Choices(1/2/3/4) == : ";
                        cin  >> menuchoices;
                        cout <<endl;
                    }
                    
                    switch (menuchoices) {
                    case 1:
                        displayMenuCoffee();
                        break;

                    case 2:
                        displayMenuNonCoffee();
                        break;

                    case 3:
                        displayMenuSnack();
                        break;

                    case 4:
                        displayMenuAdd();
                        break;

                    default:
                        cout << "Invalid Input" << endl;
                        goto utama;
                    }

                    if (menuchoices == 1 || menuchoices == 2 || menuchoices == 3 || menuchoices == 4) {
                        cout << " Input Your Choices : ";
                        cin >> custchoices;

                        Order newOrder = {menuchoices, custchoices};
                        if (menuchoices == 1) {
                            newOrder.name = menuCoffee[custchoices - 1];
                        } else if (menuchoices == 2) {
                            newOrder.name = menuNonCoffee[custchoices - 1];
                        } else if (menuchoices == 3) {
                            newOrder.name = menuSnack[custchoices - 1];
                        } else if (menuchoices == 4) {
                            newOrder.name = menuAdd[custchoices - 1];
                        } else {
                            cout << "Invalid Choices";
                            return 1;
                        }
                        
                        bool orderExists = false;
                        int existingIndex = -1;
                        for (int i = 0; i < orders.size(); ++i) {
                            if (orders[i].category == menuchoices && orders[i].item == custchoices) {
                                orderExists = true;
                                existingIndex = i;
                                break;
                            }
                        }

                        
                        
                        if (isMonday){
                            bool orderExists = false;
                            int existingIndex = -1;
                            for (int i = 0; i < orders.size(); ++i) {
                                if (orders[i].category == menuchoices && orders[i].item == custchoices) {
                                    orderExists = true;
                                    existingIndex = i;
                                    addordersMonday:
                                    newOrder.quantity = 1;
                                    orders.push_back(newOrder); 
                                    break;
                                }
                            }
                            
                            
                        } else {
                            cout << " Input Quantity : ";
                            cin >> newOrder.quantity;
                            orders.push_back(newOrder);
                        }
                        

                        cout << "Do you want to add more to your orders? (y/n) : ";
                        cin >> addorders;
                        cout << endl;
                        system("cls");
                    }

                } while (addorders == "y" && orderCount < MX_ORDRS);
            
                cout << "== Your Orders ==" << endl;
                float totalPrice = 0;
                for (int i = 0; i < orders.size(); ++i) {
                    Order order = orders[i];
                    int category = order.category;
                    int item = order.item;
                    string name = order.name;

                    if (category == CTGR_COFFEE) {
                        cout << menuCoffee[item - 1] << " : " << order.quantity << " x " << pricesCoffee[item - 1] << endl;
                        totalPrice += order.quantity * pricesCoffee[item - 1];
                    } else if (category == CTGR_NON_COFFEE) {
                        cout << menuNonCoffee[item - 1] << " : " << order.quantity << " x " << pricesNonCoffee[item - 1] << endl;
                        totalPrice += order.quantity * pricesNonCoffee[item - 1];
                    } else if (category == CTGR_SNCK) {
                        cout << menuSnack[item - 1] << " : " << order.quantity << " x " << pricesSnack[item - 1] << endl;
                        totalPrice += order.quantity * pricesSnack[item - 1];
                    } else if (category == CTGR_ADD) {
                        cout << menuAdd[item - 1] << " : " << order.quantity << " x " << pricesAdd[item - 1] << endl;
                        totalPrice += order.quantity * pricesAdd[item - 1];
                    }
                }
                
                

                
                if (Day != "Monday") {
                	 cout << "Do you want to change the quantity of your orders? (y/n) : ";
                     cin >> addorders;
                     if (addorders == "y") {
                      orders.clear();
                      goto menu;
                } 
                	
				}
           

                if (isMonday) {
                	totalPrice = discMonday;
                    cout << "Special Price : Rp " << totalPrice << endl;
                } else {
                    cout << "Total Price: Rp " << totalPrice << endl;
                }

                string methodpay[] = {"Gopay", "Dana", "Shopeepay", "Cash"};

            payment:
                cout << "Select Payment Method : " << endl;
                cout << "1. Gopay" << endl;
                cout << "2. Dana" << endl;
                cout << "3. Shopeepay" << endl;
                cout << "4. Cash" << endl;
                cout << "Enter your choice (1/2/3/4): ";
                cin >> paymentMethod;

                if (paymentMethod == 1 || paymentMethod == 2 || paymentMethod == 3) {
                    paymentless:
                    cout << "Send to a Gopay/Dana/Shopeepay Number 0895637931215 (A.n Rayhan Sulistyawan)" << endl;
                    cout << "Show the evidence of transfer (Success/Failed) : ";
                    cin >> cashlessPayment;

                    if (cashlessPayment == "Success") {
                        cout << "Congratulations "<< custname << ", Your Payment Successful. Thank you!" << endl;
                    } else if (cashlessPayment == "Failed") {
                        cout << "Payment Failed, Please Try Again" << endl;
                        goto payment;
                    } else {
                        cout << "Invalid input. Please enter 'Success' or 'Failed'." << endl;
                        goto paymentless;
                    }

                } else if (paymentMethod == 4) {
                    cout << "Enter the your your amount of money : Rp ";
                    cin >> totalPayment;

                    if (totalPayment >= totalPrice) {
                        change = totalPayment - totalPrice;
                        cout << "Congratulations "<< custname << ", Your Payment Successful. Thank you!" << endl;
                        cout << "Change: Rp " << change << endl;
                    } else {
                        cout << "Insufficient payment." << endl;
                        goto payment;
                    }
                } else {
                    cout << "Invalid payment method." << endl;
                    goto payment;
                }

                cout << " Do you want to print the invoice (y/n) : ";
                cin >> confirminvoice;
                cout << endl;
                system("cls");
                if (confirminvoice == "y") {
                    cout << "===============================" << endl;
                    cout << "===== Art U I Know Coffee =====" << endl;
                    cout << "===============================" << endl;
                    cout << "Customer Name  : " << custname << endl;
                    cout << "Day            : " << Day << endl;
                    cout << "   ===== Your Orders =====" << endl;
                    for (int i = 0; i < orders.size(); ++i) {
                        Order order = orders[i];
                        int category = order.category;
                        int item = order.item;
                        string name = order.name;

                        if (category == CTGR_COFFEE) {
                            cout << menuCoffee[item - 1] << "       : " << order.quantity << " x " << pricesCoffee[item - 1] << endl;
                        } else if (category == CTGR_NON_COFFEE) {
                            cout << menuNonCoffee[item - 1] << "      : " << order.quantity << " x " << pricesNonCoffee[item - 1] << endl;
                        } else if (category == CTGR_SNCK) {
                            cout << menuSnack[item - 1] << "         : " << order.quantity << " x " << pricesSnack[item - 1] << endl;
                        } else if (category == CTGR_ADD) {
                            cout << menuAdd[item - 1] << "          : " << order.quantity << " x " << pricesAdd[item - 1] << endl;
                        }
                    }
                    cout << "Total Price    : Rp " << totalPrice << endl;
                    cout << "Payment Method : " << methodpay[paymentMethod - 1] << endl;
                    if (paymentMethod == 4) {
                        cout << "Change         : Rp " << change << endl;
                    }
                    cout << "===============================" << endl;
                    cout <<endl;
                    cout << "== Please Wait Until Your Name is Called to Collect Your Order ==" <<endl;
                    cout <<endl;
                    cout << "Do you want to exit ? (y/n) : ";
                    cin  >> confirmlast;
                    if (confirmlast == "y"){
                        cout << "== Exiting Program ==" << endl;
                        return 1;
                    } else if (confirmlast == "n"){
                        goto menu;
                    } else {
                        cout << "Error"<<endl;
                        cout << "Invalid Choices";
                    }
                    break;
                }
            }
        case '2': {
            cout << "== Exiting Program ==" << endl;
            break;
          }
        }
     }
   }
return 0;
}

