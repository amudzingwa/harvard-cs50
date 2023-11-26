#include <stdio.h>
#include <cs50.h>

void checkValidity(long cardNumber);
long reversedNumber(long creditCardNumber);
void checkCardIssuer(long cardNumber);

long creditCardNumber;

int main() {
  creditCardNumber = get_long("Enter the Credit Card Number: ");
  checkValidity(creditCardNumber);
  checkCardIssuer(creditCardNumber);

  return 0;
}

void checkValidity(long cardNumber) {
   cardNumber = reversedNumber(cardNumber);
   long tempCardNumber = cardNumber;

   //COUNT THE NUMBER OF DIGITS
   int count = 0;

   while (tempCardNumber != 0) {
      tempCardNumber /= 10;
      count++;
   } //END COUNT NUMBER OF DIGITS

   long cardNumberArray[count];

   for (int i = 0; i < count; i++) {
      cardNumberArray[i] = cardNumber % 10;
      cardNumber /= 10;
   }

   int newArraySize = count / 2;

   long everyOtherNumberArray[newArraySize];
   int newArrayIndex = 0;

   for (int i = 1; i < count; i += 2) {
      everyOtherNumberArray[newArrayIndex] = cardNumberArray[i];
      newArrayIndex++;
   }

   //Create an array of the remaining numbers
   int arraySize = (count + 1) / 2;  // Adjust size for odd count
   long newArray[arraySize];
   int arrayIndex = 0;

   for (int i = 0; i < count; i += 2) {
      newArray[arrayIndex] = cardNumberArray[i];
      arrayIndex++;
   }

   long sum = 0;

   for (int i = 0; i < arraySize; i++) {
      sum += newArray[i];
   } //End iteration

   //Iterate through the new array and multiply each number by 2
   long totalSum = 0;

   for (int i = 0; i < newArraySize; i++) {
      everyOtherNumberArray[i] *= 2;
      totalSum += everyOtherNumberArray[i];
   } //End iteration

   int sumTotal = totalSum + sum;
   long checkSum = (sumTotal % 10);

   // Check if checkSum is 0 and print Valid or Invalid accordingly
   if (checkSum == 0) {
      printf("Valid\n");
   } else {
      printf("Invalid\n");
   }
}




void checkCardIssuer(long cardNumber) {
  int count = 0;
  long tempCardNumber = cardNumber;

  while (tempCardNumber != 0) {
    tempCardNumber /= 10;
    count++;
  }

  printf("Number of digits: %d\n", count);

  long cardNumberArray[count];

  if (count == 13 || count == 15 || count == 16) {
    for (int i = 0; i < count; i++) {
      cardNumberArray[i] = cardNumber % 10;
      cardNumber /= 10;
    }

    if (count == 15 && ((cardNumberArray[14] == 3 && (cardNumberArray[13] == 4 || cardNumberArray[13] == 7)))) {
    printf("AMEX\n");
} else if (count == 16 && (cardNumberArray[15] == 5 && cardNumberArray[14] >= 1 && cardNumberArray[14] <= 5)) {
    printf("Mastercard\n");
} else if (((count == 13 || count == 16) && cardNumberArray[12] == 4) || ((count == 16 || count == 16) && cardNumberArray[15] == 4)) {
    printf("VISA\n");
} else {
    printf("Invalid! Unknown issuer!\n");
}
  }
}



long reversedNumber(long cc_Number) {
  int reverse = 0, remainder;

  while (cc_Number != 0) {
    remainder = cc_Number % 10;
    reverse = reverse * 10 + remainder;
    cc_Number /= 10;
  }

  return reverse;
}
