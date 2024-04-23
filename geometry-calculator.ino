bool shouldRun = true; // Flag to control program execution

void setup() {
  Serial.begin(9600);
  displayMenu(); // Display the menu once when the program starts
}

void loop() {
  if (!shouldRun) {
    return; // Exit the loop and end the program
  }

  char choice = getUserChoice();

  switch (choice) {
    case '1':
      calculateCircleArea();
      break;
    case '2':
      calculateRectangleArea();
      break;
    case '3':
      calculateTriangleArea();
      break;
    case '4':
      Serial.println("Exiting program.");
      shouldRun = false; // Set flag to false to exit the loop
      break;
    default:
      Serial.println("Invalid choice. Please enter a number from 1 to 4.");
  }

  if (shouldRun) {
    char tryAgain;
    do {
      Serial.println("Do you want to try again (y/n)?");
      while (!Serial.available()); // Wait for user input
      tryAgain = Serial.read();
      if (tryAgain == 'n' || tryAgain == 'N') {
        Serial.println("Exiting program.");
        shouldRun = false; // Set flag to false to exit the loop
        break;
      }
    } while (tryAgain != 'y' && tryAgain != 'Y');

    if (shouldRun) {
      // Display the menu again if the user wants to try again
      displayMenu();
    }
  }
}

void displayMenu() {
  Serial.println("<<<<< Geometry Calculator >>>>>");
  Serial.println("1. Calculate the Area of a Circle");
  Serial.println("2. Calculate the Area of a Rectangle");
  Serial.println("3. Calculate the Area of a Triangle");
  Serial.println("4. Quit");
  Serial.println("Enter your choice (1-4):");
}

char getUserChoice() {
  while (!Serial.available()); // Wait for user input
  return Serial.read();
}

void calculateCircleArea() {
  Serial.println("*** Computing for the area of the circle ***");
  Serial.println("Enter radius of the circle: ");
  float radius = getPositiveFloatInput();
  float area = 3.14159 * radius * radius;
  Serial.print("The area of the circle with a radius of ");
  Serial.print(radius);
  Serial.print(" is ");
  Serial.println(area);
}

void calculateRectangleArea() {
  Serial.println("*** Computing for the area of the rectangle ***");
  Serial.println("Enter length of the rectangle: ");
  float length = getPositiveFloatInput();
  Serial.println("Enter width of the rectangle: ");
  float width = getPositiveFloatInput();
  float area = length * width;
  Serial.print("The area of the rectangle with length ");
  Serial.print(length);
  Serial.print(" and width ");
  Serial.print(width);
  Serial.print(" is ");
  Serial.println(area);
}

void calculateTriangleArea() {
  Serial.println("*** Computing for the area of the triangle ***");
  Serial.println("Enter length of the triangle's base: ");
  float base = getPositiveFloatInput();
  Serial.println("Enter height of the triangle: ");
  float height = getPositiveFloatInput();
  float area = 0.5 * base * height;
  Serial.print("The area of the triangle with base ");
  Serial.print(base);
  Serial.print(" and height ");
  Serial.print(height);
  Serial.print(" is ");
  Serial.println(area);
}

float getPositiveFloatInput() {
  float input;

  while (true) {
    while (!Serial.available()); // Wait for user input
    input = Serial.parseFloat();
    
    if (input >= 0) {
      return input;
    } else {
      Serial.println("Error: Please enter a positive value.");
      Serial.println("Do you want to add the positive value? (y/n)?");
      
      char tryAgain;
      while (!Serial.available()); // Wait for user input
      tryAgain = Serial.read();
      
      if (tryAgain == 'n' || tryAgain == 'N') {
        Serial.println("Exiting program.");
        exit(0); // Exit the program
      } else if (tryAgain == 'y' || tryAgain == 'Y') {
        Serial.println("Enter the value again:");
      } else {
        Serial.println("Invalid choice. Please enter 'y' or 'n'.");
      }
    }
  }


  return input;
}