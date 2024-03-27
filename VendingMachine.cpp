#include <iostream>

using namespace std;

class cashRegister {
    private:
        int cashOnHand;
    public:
        cashRegister() {
            cashOnHand = 500;
        }
        
        cashRegister(int cash) {
            cashOnHand = cash;
        }
        
        int getCurrentBalance() {
            return cashOnHand;
        }
        
        void acceptAmount(int cash) {
            cashOnHand = cash + cashOnHand;
        }
};

class dispenserType: public cashRegister{
    private:
        int numberOfItems;
        int cost;
        
    public:
        dispenserType() {
            cost = 50;
            numberOfItems = 50;
        }
        
        dispenserType(int numberOfItems, int cost) {
            this-> numberOfItems = numberOfItems;
            this-> cost = cost;
        }
        
        int getNoOfItems() {
             return numberOfItems;
        }
        
        int getCost() {
            return cost;
        }
        
        void makeSale() {
            numberOfItems--;
        }
};

void showSelection() {
    cout << "*** Welcome to Candy Shop ***" << endl;
    cout << "To select an item, enter" << endl;
    cout << "1 for Candy" << endl;
    cout << "2 for Chips" << endl;
    cout << "3 for Gum" << endl;
    cout << "4 for Cookies" << endl;
    cout << "5 to Exit" << endl;
}

void sellProduct(dispenserType& refrence_dispenser, cashRegister& refrence_register) {
    if(refrence_dispenser.getNoOfItems() > 0) {
        int cost = refrence_dispenser.getCost();
        cout << "Please deposit " << cost << " cents" << endl;
        int total_deposit;
        cin >> total_deposit;
    
    while(total_deposit < cost) {
        cout << "Please deposit an additional " << cost - total_deposit << " cents" << endl;
        int additional;
        cin >> additional;
        total_deposit = total_deposit + additional;
    }
    
    while(total_deposit > cost) {
        cout << "\nYou entered an additional " << total_deposit - cost << " extra cents, please retrieve from the bottom of the vending machine!" << endl;
        break;
    }
    refrence_register.acceptAmount(cost);
    refrence_dispenser.makeSale();
    cout << "Collect your item at the bottom and enjoy!" << endl;
    cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n" << endl;
    }
    
    else {
        cout << "Sorry, this item is sold out. " << endl;
    }

}

int main()
{
    dispenserType candy(1, 50);
    dispenserType chips(10, 65);
    dispenserType gum(100, 45);
    dispenserType cookies(51, 85);
    cashRegister refrence_register(500);
    
    int userInput = 0;
    showSelection();
    while(userInput != 5) {
    cin >> userInput;
        
        if(userInput == 1) {
            sellProduct(candy, refrence_register);
            showSelection();
        }
        
        else if(userInput == 2) {
            sellProduct(chips, refrence_register);
            showSelection();
        }
        
        else if(userInput == 3) {
            sellProduct(gum, refrence_register);
            showSelection();
        }
        
        else if(userInput == 4) {
            sellProduct(cookies, refrence_register);
            showSelection();
        }
        
        else if(userInput == 5) {
            break;
        }
        
        else {
            cout << "That option is not avaibale. Please select the correct options";
            showSelection();
        }
        
    }
    return 0;
}


