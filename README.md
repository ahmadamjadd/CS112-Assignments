# CS112 - Object-Oriented Programming (OOP) Assignments

This repository contains challenging assignments from the CS112 Object-Oriented Programming (OOP) course. These assignments focus on core OOP concepts and practical problem-solving skills using C++. Below is a description of each assignment in the repository.

---

## Assignment 1: Console-Based Car Racing Game

**Objective:**  
Develop a console-based car racing game with two cars racing on a track. The player can control each car through specific keyboard keys, with each car's position and points stored in a structure.

**Requirements:**  
- Define a `Car` structure with `position` and `points` as members.
- Implement a nested structure `RacingTrack` with `trackLength`.
- Control each car's movement using keyboard keys (e.g., 'a'/'d' for Car 1, 'j'/'l' for Car 2).
- Display the racing track with a specified length, and prevent cars from moving beyond track boundaries.
- Include a scoring system where each car accumulates points.
- Display the current position and points of each car, and provide a quit functionality to exit the game.

---

## Assignment 2: Strategic Five

**Objective:**  
Implement a classic strategy board game called "Strategic Five," supporting both Human vs. Human and Human vs. Bot modes.

**Requirements:**  
- Allow the user to select board dimensions (9x9 or 15x15).
- Include two gameplay modes: Human vs. Human and Human vs. Bot.
- Implement logical strategies in the Bot’s decision-making to provide a challenging gameplay experience.
- Utilize classes to encapsulate the game's logic and functionality.

---

## Assignment 3: Infinitely Spinning Doughnut in Terminal

**Objective:**  
Create an animation of an infinitely spinning doughnut displayed in the terminal.

**Requirements:**  
- Use a loop to continuously render a rotating doughnut shape in the console window.
- Implement ASCII art or similar techniques to achieve a visually appealing spinning effect.

---

## Assignment 4: Car and Engine Composition

**Objective:**  
Demonstrate the concept of composition in C++ by modeling the relationship between a `Car` and an `Engine`.

**Requirements:**  
- Create two classes: `Engine` (with `cylinders` and `horsepower`) and `Car` (with `make`, `model`, and an `Engine` instance).
- Implement getter and setter functions for the car’s `make`, `model`, `cylinders`, and `horsepower`.
- Provide a `printInfo` function in the `Car` class to display the car’s make, model, and engine specifications.

---

## Assignment 5: Custom String Class with Operator Overloading

**Objective:**  
Implement a custom string class in C++ with a variety of functionalities using operator overloading.

**Requirements:**  
- Create a class `CMyString` with a dynamic character array to store the string.
- Implement constructors: default, one that accepts a character array, and one that takes the size of the string.
- Include functions to return the size of the string and character array.
- Overload various operators (e.g., `+`, `+=`, `[]`, `==`, `!=`, `>`, `<`, `()`, `<<`, `>>`, `=`, left/right shift) for string manipulation, comparison, and assignment.
- Test all operations in the main function, displaying the string before and after each operation.

---

## Assignment 6: Sparse Polynomial Addition

**Objective:**  
Implement sparse polynomial addition by reading coefficients from a file and performing group addition.

**Requirements:**  
- Read polynomial data from a file in the specified format.
- Display file contents with scrolling options if needed.
- Perform polynomial addition by successively adding each polynomial to the cumulative result and display the final result.
- Output the result to a file (`result_addition.txt`) with relevant details.
- Display additional information: file name, number of polynomials, number of variables, non-zero values count, data structure used, and time taken for addition.
- Avoid using built-in functions, implementing custom logic for reading, displaying, and adding polynomials.

---

## About the Repository

These assignments demonstrate fundamental and advanced OOP principles in C++. Each assignment explores practical applications of OOP concepts such as structure usage, composition, class-based game development, custom data structures, and operator overloading, providing a comprehensive understanding of C++ and OOP.
