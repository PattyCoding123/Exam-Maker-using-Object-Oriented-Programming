//==========================================================
// Title:      Assignment 06 Sorting
// Course:     CSC 2110
// Author:     Patrick Ducusin
// Date:       12/01/2021
// Description: We are going to making another program that
// will allow the user to set up a quiz with multiple questions
// and a range of answers.
// This time, we will also be focusing on sorting. We will
// still use overloaded operators to have more functionality
// with our objects. For the main output, we will set up multiple
// Numeric Answer questions with differing numbers of points.
// Then, we will call the sorting function in order to sort the 
// questions in the array based off their point values. Finally,
// start a quiz attempt in the main.
//==========================================================
#include <iostream> 
#include "NAquestion.h"
#include "Quiz.h"
using namespace std; // to avoid writing std::

int main()
{
	cout << "Assignment 6" << endl;
	cout << "-------------------------" << endl;

	// Declare a quiz variable and an NAquestion pointer
	Quiz exam1;
	NAquestion* ptrNAq;

	// Create 5 dynamic NAquestion objects which will be set in the Quiz object array of questions
	// Each question should have a different point value
	ptrNAq = new NAquestion("How much feet are in a mile?", 5200, 5300, 10);
	exam1.setQuestion(0, ptrNAq);
	ptrNAq = new NAquestion("What is the rate of acceleration due to gravity on the moon (in m/s^2)?", 1.5, 2, 5);
	exam1.setQuestion(1, ptrNAq);
	ptrNAq = new NAquestion("What percentage of Earth is made of water?", 70, 75, 25);
	exam1.setQuestion(2, ptrNAq);
	ptrNAq = new NAquestion("What ph level is more basic?", 8, 14, 15);
	exam1.setQuestion(3, ptrNAq);
	ptrNAq = new NAquestion("What is the average minimum wage in the United States?", 7, 12, 20);
	exam1.setQuestion(4, ptrNAq);

	// Call the sort function. This will sort the questions in ascending order based on point-value.
	cout << "Sorting questions..." << endl;
	exam1.sort();

	// Start a quiz attempt
	cout << "\nQuiz Attempt!" << endl;
	cout << "-------------------------" << endl;
	exam1.startAttempt();

	return 0;
}