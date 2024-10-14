# Bakery Management System
## Overview
This Bakery Management System is a C++ console application designed to manage a bakery's menu items and handle user interactions like authentication and purchasing. The system supports different bakery categories, including breads, with functionalities to display menus, select items, and calculate prices.

## Features
User Authentication: Supports login functionality with username and password validation.
Menu Categories: Includes various categories (like breads) with a list of items and their respective prices.
Dynamic Pricing: Allows users to choose items and calculates the total price based on selections.
Modular Design: The system is structured with object-oriented principles, utilizing inheritance for menu handling.

##Technologies Used
C++: The entire application is developed in C++ using object-oriented programming (OOP) concepts.
Windows API: Uses the windows.h library for console text formatting.
File Handling: Includes basic file I/O functionality to store and retrieve user data.

## How to Run
Clone the repository:
bash
Copy code
git clone https://github.com/yourusername/bakery-management-system.git
Compile the code using a C++ compiler, such as g++:
bash
Copy code
g++ -o bakery_app bakery_app.cpp
Run the executable:
bash
Copy code
./bakery_app


## Code Structure
User Class: Handles user data (username, password) and authentication logic.
Bakery Class: Serves as a base class for different bakery item categories.
Breads Class: Derived from Bakery, it manages a specific menu of bread items.
Future Enhancements
Extend menu categories to include pastries, beverages, and cakes.
Add a shopping cart feature for multiple item purchases.
Implement a database for persistent user and order data.
