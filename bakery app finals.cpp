#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <regex>
#include <limits>

using namespace std;

// User class to handle user data and validation
class User {
    private:
        string username;
        string password;

    public:
        User() // Default constructor
        {
        }

        User(const string& username, const string& password) // Parameterized constructor
        {
            this->username = username;
            this->password = password;
        }

        string getUsername() {
            return username;
        }

        string getPassword() {
            return password;
        }

        void setUsername(const string& username) {
            this->username = username;
        }

        void setPassword(const string& password) {
            this->password = password;
        }

        bool validate(const string& username, const string& password) {
            return this->username == username && this->password == password;
        }
};

// Base class Bakery for different menu categories
class Bakery {
    public:
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        virtual void displayMenu() = 0; // Pure virtual function to display menu
        virtual double getPrice(int choice) = 0; // Pure virtual function to get price of an item
        virtual string getItem(int choice) = 0; // Pure virtual function to get item name

        Bakery() // Default constructor
        {
        }

        virtual ~Bakery() // Virtual destructor
        {
        }
};

// Derived class for Breads menu
class Breads : public Bakery {
    private:
        string items[6] = { "Garlic Bread", "Cinnamon Bread", "Sourdough Bread", "Baguette", "Banana Bread", "Focaccia" };
        double prices[6] = { 150.0, 180.0, 200.0, 220.0, 190.0, 210.0 };

    public:
        Breads() // Default constructor
        {
        }

        void displayMenu() {
            SetConsoleTextAttribute(h, 0);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\tBREADS MENU:\n\t\t\t\t\t";
            for (int i = 0; i < 6; i++) {
                cout << (i + 1) << ". " << items[i] << " (Rs." << prices[i] << ")\n\t\t\t\t\t";
            }
        }

        double getPrice(int choice) {
            return prices[choice - 1];
        }

        string getItem(int choice) {
            return items[choice - 1];
        }
};

// Derived class for Sundaes menu
class Sundaes : public Bakery {
    private:
        string items[6] = { "Vanilla Sundae", "Chocolate Sundae", "Oreo Sundae", "Lotus Sundae", "Caramel Sundae", "Mint Chocolate Sundae" };
        double prices[6] = { 120.0, 130.0, 140.0, 150.0, 160.0, 170.0 };

    public:
        Sundaes() // Default constructor
        {
        }

        void displayMenu() {
            SetConsoleTextAttribute(h, 0);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\tSUNDAES MENU:\n\t\t\t\t\t";
            for (int i = 0; i < 6; i++) {
                cout << (i + 1) << ". " << items[i] << " (Rs." << prices[i] << ")\n\t\t\t\t\t";
            }
        }

        double getPrice(int choice) {
            return prices[choice - 1];
        }

        string getItem(int choice) {
            return items[choice - 1];
        }
};

// Derived class for Cakes menu
class Cakes : public Bakery {
    private:
        string items[6] = { "Dark Forest Cake", "Strawberry Shortcake", "Caramel Cake", "Carrot Cake", "Nutella Cake", "Red Velvet Cake" };
        double prices[6] = { 500.0, 550.0, 600.0, 650.0, 700.0, 750.0 };

    public:
        Cakes() // Default constructor
        {
        }

        void displayMenu() {
            SetConsoleTextAttribute(h, 0);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\tCAKES MENU:\n\t\t\t\t\t";
            for (int i = 0; i < 6; i++) {
                cout << (i + 1) << ". " << items[i] << " (Rs." << prices[i] << ")\n\t\t\t\t\t";
            }
        }

        double getPrice(int choice) {
            return prices[choice - 1];
        }

        string getItem(int choice) {
            return items[choice - 1];
        }
};

// Derived class for Donuts menu
class Donuts : public Bakery {
    private:
        string items[6] = { "Lemon and Cheese Donut", "Plain Glaze Donut", "Strawberry Jam Donut", "Chocolate Glazed Donut", "Lotus Donut", "Ferrero Rocher Donut" };
        double prices[6] = { 80.0, 90.0, 100.0, 110.0, 120.0, 130.0 };

    public:
        Donuts() // Default constructor
        {
        }

        void displayMenu() {
            SetConsoleTextAttribute(h, 0);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\tDONUTS MENU:\n\t\t\t\t\t";
            for (int i = 0; i < 6; i++) {
                cout << (i + 1) << ". " << items[i] << " (Rs." << prices[i] << ")\n\t\t\t\t\t";
            }
        }

        double getPrice(int choice) {
            return prices[choice - 1];
        }

        string getItem(int choice) {
            return items[choice - 1];
        }
};

// Main application class for Bakery
class BakeryApp {
    private:
        User users[100]; // Array to store users
        int userCount; // Number of users
        string currentUsername; // Current logged in user
        bool loggedIn; // Login status
        string orderItems[100]; // Array to store ordered items
        int orderQuantities[100]; // Array to store quantities of ordered items
        double totalBill; // Total bill amount
        int orderCount; // Number of items ordered
        const double deliveryCharge = 250.0; // Fixed delivery charge

    public:
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        BakeryApp() 
        {
            userCount = 0;
            loggedIn = false;
            totalBill = 0.0;
            orderCount = 0;
            loadUsers();
        }

        ~BakeryApp() 
        {
            saveUsers();
        }

        void loadUsers() 
        {
            ifstream infile("users.txt");
            if (infile.is_open()) 
            {
                string username, password;
                while (infile >> username >> password) 
                {
                    users[userCount++] = User(username, password);
                }
                infile.close();
            }
            else
            {
                cout << "\t\t\tUnable to open file 'users.txt' for reading.\n";
            }
        }

        void saveUsers() 
        {
            ofstream outfile("users.txt");
            if (outfile.is_open()) 
            {
                for (int i = 0; i < userCount; i++) 
                {
                    outfile << users[i].getUsername() << " " << users[i].getPassword() << "\n";
                }
                outfile.close();
            }
            else
            {
                cout << "\t\t\tUnable to open file 'users.txt' for writing.\n";
            }
        }

        void signup() 
        {
            SetConsoleTextAttribute(h, 8);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            string username, password;
            cout << "\t\t\t\t\tEnter new username: ";
            cin >> username;
            cout << "\t\t\t\t\tEnter new password: ";
            cin >> password;
            users[userCount++] = User(username, password);
            SetConsoleTextAttribute(h, 10);
            cout << "\n\n\t\t\t\t\tSignup successful! Please login to continue.\n";
            saveUsers(); // Save the new user immediately
            Sleep(2000);
            system("CLS");
        }

        bool login() 
        {
            string username, password;
            int attempts = 0;
            while (attempts < 3) 
            {
                SetConsoleTextAttribute(h, 3);
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                cout << "\t\t\t\t\tEnter username: ";
                cin >> username;
                cout << "\t\t\t\t\tEnter password: ";
                cin >> password;
                for (int i = 0; i < userCount; i++) 
                {
                    if (users[i].validate(username, password)) 
                    {
                        currentUsername = username;
                        loggedIn = true;
                        SetConsoleTextAttribute(h, 10);
                        cout << "\n\n\t\t\t\t\tLogin successful!\n";
                        system("CLS");
                        return true;
                    }
                }
                SetConsoleTextAttribute(h, 12);
                cout << "\n\n\t\t\t\t\tInvalid credentials. Please try again.\n";
                attempts++;
                Sleep(2000);
                system("CLS");
            }
            SetConsoleTextAttribute(h, 12);
            cout << "\t\t\t\t\t\n\nToo many failed attempts. Please try again later.\n";
            SetConsoleTextAttribute(h, 0);
            return false;
        }

        void displayIntro() 
        {
            SetConsoleTextAttribute(h, 11);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t1. Login\n\t\t\t\t\t2. Signup\n";
            int choice;
            while (true) {
                try {
                    cout << "\t\t\t\t\tEnter Your Choice:";
                    cin >> choice;
                    if (cin.fail()) {
                        throw invalid_argument("Invalid input, please enter a number.");
                    }
                    if (choice != 1 && choice != 2) {
                        throw invalid_argument("Invalid choice, please enter 1 or 2.");
                    }
                    break;
                }
                catch (const invalid_argument& e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    SetConsoleTextAttribute(h, 12);
                    cout << "\t\t\t\t\t" << e.what() << "\n";
                    SetConsoleTextAttribute(h, 11);
                }
            }
            system("CLS");
            if (choice == 1) 
            {
                if (login()) 
                {
                    showLoading();
                    displayHomePage();
                }
            } 
            else if (choice == 2) 
            {
                signup();
                displayIntro();
            }
        }

        void showLoading() 
        {
            cout << "\t\t\tLoading";
            for (int i = 0; i < 5; ++i) 
            {
                cout << ".";
                for (int j = 0; j < 50000000; ++j); // simple delay
            }
            cout << "\n";
            cout << "\n\n\t\t\t";
            char x = 219;
            cout << "\t\t\t";
            for (int i = 0; i <= 27; i++) 
            {
                cout << x;
                for (int j = 0; j < 100000000; ++j);
            }
            system("CLS");
        }

        void displayHomePage() 
        {
            int choice;
            while (true) 
            {
                SetConsoleTextAttribute(h, 14);
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                cout << "\t\t\t\t\tHOME PAGE\n\t\t\t\t\t1. Breads\n\t\t\t\t\t2. Sundaes\n\t\t\t\t\t3. Cakes\n\t\t\t\t\t4. Donuts\n\t\t\t\t\t5. Checkout\n";
                while (true) {
                    try {
                        cout << "\n\t\t\t\t\tEnter Your Choice:";
                        cin >> choice;
                        if (cin.fail()) {
                            throw invalid_argument("Invalid input, please enter a number.");
                        }
                        if (choice < 1 || choice > 5) {
                            throw invalid_argument("Invalid choice, please enter a number between 1 and 5.");
                        }
                        break;
                    }
                    catch (const invalid_argument& e) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        SetConsoleTextAttribute(h, 12);
                        cout << "\t\t\t\t\t" << e.what() << "\n";
                        SetConsoleTextAttribute(h, 14);
                    }
                }
                system("CLS");
                switch (choice) 
                {
                    case 1:
                        handleOrder(new Breads());
                        break;
                    case 2:
                        handleOrder(new Sundaes());
                        break;
                    case 3:
                        handleOrder(new Cakes());
                        break;
                    case 4:
                        handleOrder(new Donuts());
                        break;
                    case 5:
                        checkout();
                        return;
                    default:
                        SetConsoleTextAttribute(h, 12);
                        cout << "\n\t\t\t\t\tInvalid choice, please try again.\n";
                        break;
                }
            }
        }

        void handleOrder(Bakery* bakery) 
        {
            bakery->displayMenu();
            int choice;
            cout << "\t\t\tEnter your choice: ";
            while (true) {
                try {
                    cin >> choice;
                    if (cin.fail()) {
                        throw invalid_argument("Invalid input, please enter a number.");
                    }
                    if (choice < 1 || choice > 6) {
                        throw invalid_argument("Invalid choice, please enter a number between 1 and 6.");
                    }
                    break;
                }
                catch (const invalid_argument& e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    SetConsoleTextAttribute(h, 12);
                    cout << "\t\t\t" << e.what() << "\n\t\t\t";
                    SetConsoleTextAttribute(h, 15);
                }
            }
            cout << "\t\t\tEnter quantity: ";
            int quantity;
            while (true) {
                try {
                    cin >> quantity;
                    if (cin.fail() || quantity < 1) {
                        throw invalid_argument("Invalid input, please enter a positive number.");
                    }
                    break;
                }
                catch (const invalid_argument& e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    SetConsoleTextAttribute(h, 12);
                    cout << "\t\t\t" << e.what() << "\n\t\t\t";
                    SetConsoleTextAttribute(h, 15);
                }
            }
            double price = bakery->getPrice(choice);
            totalBill += price * quantity;
            orderItems[orderCount] = bakery->getItem(choice);
            orderQuantities[orderCount] = quantity;
            orderCount++;

            char more;
            cout << "\t\t\tWould you like to order another item? (y/n): ";
            while (true) {
                try {
                    cin >> more;
                    if (cin.fail() || (more != 'y' && more != 'Y' && more != 'n' && more != 'N')) {
                        throw invalid_argument("Invalid input, please enter 'y' or 'n'.");
                    }
                    break;
                }
                catch (const invalid_argument& e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    SetConsoleTextAttribute(h, 12);
                    cout << "\t\t\t" << e.what() << "\n\t\t\t";
                    SetConsoleTextAttribute(h, 15);
                }
            }
            system("CLS");
            if (more == 'y' || more == 'Y') 
            {
                handleOrder(bakery);
            } 
            else 
            {
                delete bakery;
                displayHomePage();
            }
        }

        void checkout() 
        {
            SetConsoleTextAttribute(h, 6);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\tCheckout:\n\t\t\t\t\t1. Pickup\n\t\t\t\t\t2. Delivery\n";
            int choice;
            while (true) {
                try {
                    cout << "\n\n\t\t\t\t\tEnter your choice:";
                    cin >> choice;
                    if (cin.fail()) {
                        throw invalid_argument("Invalid input, please enter a number.");
                    }
                    if (choice != 1 && choice != 2) {
                        throw invalid_argument("Invalid choice, please enter 1 or 2.");
                    }
                    break;
                }
                catch (const invalid_argument& e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    SetConsoleTextAttribute(h, 12);
                    cout << "\t\t\t\t\t" << e.what() << "\n";
                    SetConsoleTextAttribute(h, 6);
                }
            }
            system("CLS");
            if (choice == 1) 
            {
                payment();
            } 
            else if (choice == 2) 
            {
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                string address;
                cout << "\t\t\t\t\tEnter delivery address: ";
                cin.ignore();
                getline(cin, address);
                totalBill += deliveryCharge;
                system("CLS");
                payment();
                cout << "\t\t\t\t\tDelivery Address: " << address << "\n";
            }
        }

        void payment() 
        {
            SetConsoleTextAttribute(h, 9);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\tPayment method:\n\t\t\t\t\t1. Online payment\n\t\t\t\t\t2. Cash payment\n";
            int choice;
            while (true) {
                try {
                    cout << "\n\n\t\t\t\t\tEnter your choice:";
                    cin >> choice;
                    if (cin.fail()) {
                        throw invalid_argument("Invalid input, please enter a number.");
                    }
                    if (choice != 1 && choice != 2) {
                        throw invalid_argument("Invalid choice, please enter 1 or 2.");
                    }
                    break;
                }
                catch (const invalid_argument& e) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    SetConsoleTextAttribute(h, 12);
                    cout << "\t\t\t\t\t" << e.what() << "\n";
                    SetConsoleTextAttribute(h, 9);
                }
            }
            system("CLS");
            if (choice == 1) 
            {
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                string cardNumber;
                bool validCard = false;
                while (!validCard) {
                    cout << "\t\t\t\tEnter 16-digit card number: ";
                    cin >> cardNumber;
                    if (regex_match(cardNumber, regex("\\d{16}"))) {
                        validCard = true;
                    } else {
                        SetConsoleTextAttribute(h, 12);
                        cout << "\t\t\t\tInvalid card number. Please enter exactly 16 digits.\n";
                        SetConsoleTextAttribute(h, 9);
                    }
                }
                cout << "\t\t\t\t\tPayment successful.\n";
                system("CLS");
            } 
            else if (choice == 2) 
            {
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
                cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
                cout << "\t\t\t\t\tYou chose to pay with cash.\n";
                Sleep(2000);
                system("CLS");
            }
            displayBill();
        }

        void displayBill() 
        {
            SetConsoleTextAttribute(h, 0);
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\t\t\t\t\t<> Maida's Kitchenette <>\n\n";
            cout << "\t\t\t\t\t<><><><><><><><><><><><><\n\n";
            cout << "\n\t\t\t\t\tTotal Bill:\n";
            cout << "\t\t\t\t\tTotal: Rs." << totalBill << "\n";
            cout << "\t\t\t\t\tThank you for ordering from Maida's Kitchenette!\n";
            cout << "\t\t\t\t\tBakery contact info: +123456789\n";
            exit(0);
        }
};

int main() 
{
    BakeryApp app;
    app.displayIntro();
    return 0;
}
