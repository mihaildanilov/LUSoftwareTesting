#include <iostream>
#include <string>

bool validatePrice(const std::string& input) {
    if (input.empty()) return false;

    // Check if input consists only of digits and at most one dot
    bool dotFound = false;
    for (char c : input) {
        if (!isdigit(c)) {
            if (c == '.' && !dotFound) {
                dotFound = true;
            } else {
                return false;
            }
        }
    }

    // Ensure there is at most one dot and it's not at the beginning or end
    if (input.front() == '.' || input.back() == '.' || input.find('.') != input.rfind('.')) {
        return false;
    }

    // Split input into integer and fractional parts
    std::string integerPart, fractionalPart;
    size_t dotPos = input.find('.');
    if (dotPos == std::string::npos) {
        integerPart = input;
    } else {
        integerPart = input.substr(0, dotPos);
        fractionalPart = input.substr(dotPos + 1);
    }

    // Validate integer part (max 4 digits) and fractional part (max 2 digits)
    if (integerPart.size() > 4 || fractionalPart.size() > 2) {
        return false;
    }

    // Add trailing zeroes to fractional part if necessary
    if (fractionalPart.empty()) {
        fractionalPart = "00";
    } else if (fractionalPart.size() == 1) {
        fractionalPart += "0";
    }

    // Convert integer and fractional parts to integers for comparison
    int integer = std::stoi(integerPart);
    int fractional = std::stoi(fractionalPart);

    // Ensure price is greater than 0
    if (integer == 0 && fractional == 0) {
        return false;
    }

    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a price: ";
    std::cin >> input;

    if (validatePrice(input)) {
        std::cout << "Valid price\n";
    } else {
        std::cout << "Invalid price\n";
    }

    return 0;
}
