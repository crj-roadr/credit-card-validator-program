#include <iostream>

int main() {
    const int SIZE = 30;
    unsigned long creditCardNumber;
    int everySecondDigitArray[SIZE] = {0};
    int everySecondDigitDoubledArray[SIZE] = {0};
    int everySecondDigitArraySum = 0;
    int oddNumberedDigitArray[SIZE] = {0};
    int oddNumberedDigitArraySum = 0;

    std::cout << "*** Credit Card Number Validator ***" << std::endl << std::endl;
    std::cout << "Enter a credit card number (14–19 digits long): ";
    std::cin >> creditCardNumber;

    bool isCardNumberCorrectLength = (creditCardNumber < 10000000000000000000 && creditCardNumber > 9999999999999) ? true : false;

    while (!isCardNumberCorrectLength)
    {
        std::cout << creditCardNumber << " is " << (isCardNumberCorrectLength ? "correct" : "not correct") << " length" << std::endl;
        std::cout << "Enter a credit card number (14–19 digits long): ";
        std::cin >> creditCardNumber;

        isCardNumberCorrectLength = (creditCardNumber < 10000000000000000000 && creditCardNumber > 9999999999999) ? true : false;
    }

    unsigned long tempCreditCardNumber = creditCardNumber;

    for (int i = 0; tempCreditCardNumber > 0; i++) {
        if (i % 2 == 1) {
            everySecondDigitArray[i] = tempCreditCardNumber % 10;
        } else {
            oddNumberedDigitArray[i] = (tempCreditCardNumber % 10);
        }
        tempCreditCardNumber /= 10;
    }

    for (int i = 0; i < SIZE; i++) {
        int doubled = everySecondDigitArray[i] * 2;
        if ( doubled < 10) {
            everySecondDigitDoubledArray[i] = doubled;
        } else {
            int firstDigit = doubled / 10;
            int secondDigit = doubled % 10;
            everySecondDigitDoubledArray[i] = firstDigit;
            everySecondDigitDoubledArray[i+1] = secondDigit;
        }
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        everySecondDigitArraySum += everySecondDigitDoubledArray[i];
        oddNumberedDigitArraySum += oddNumberedDigitArray[i];
    }

    int sumOfAllSums = everySecondDigitArraySum + oddNumberedDigitArraySum;
    std::cout << "Sum of every second digits = " << everySecondDigitArraySum << std::endl;
    std::cout << "Sum of odd numbered digits = " << oddNumberedDigitArraySum << std::endl;
    std::cout << "Sum of all sums = " << sumOfAllSums << std::endl;

    std::cout << "Credit Card Number: " << creditCardNumber << " is " << ((sumOfAllSums % 10 == 0) ? "valid" : "not valid") << std::endl;

    return 0;
}