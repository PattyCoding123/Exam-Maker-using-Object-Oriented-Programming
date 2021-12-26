#include <iostream>
#include <iomanip>
#include "Quiz.h"
using namespace std;

// largest function, which is a private function that will search through the questions array
// and return the pointer that points to the NAquestion which has the most amount of points
NAquestion* Quiz::largest(int lowerIndex, int upperIndex) {
	NAquestion* max; // declare a max variable which holds an NAquestion pointer
	
	// First, define the base case where the the size of the sublist is only 1 NAquestion pointer
	if (lowerIndex == upperIndex)
		return questions[lowerIndex];

	else {
		// Recursively call the largest function for the max NAquestion pointer
		max = largest(lowerIndex + 1, upperIndex);

		// If questions[lowerIndex] is greater than max, return questions[lowerIndex]
		if (*(questions[lowerIndex]) >= *max)
			return questions[lowerIndex];

		else
			return max;
	}
	
}

// largestQuestion function is what will be available to the user
NAquestion* Quiz::largestQuestion() {
	return largest();
}

// get method for quiz score
double Quiz::getScore() const {
	return score;
}

// This function will set NAquestion object pointers into the questions array
// It does some validations.
void Quiz::setQuestion(int position, NAquestion* ptr) {
	if (position < 0 || position > 4) // if i is out of bounds, do nothing
		return;

	else {
		// if question[position] has a null value, set it to have a NAquestion pointer
		if (questions[position] == nullptr) {
			questions[position] = ptr;
		}

		// if question[position] already has a dynamic NAquestion, delete
		// to free memory and store new ptr 
		else {
			delete questions[position];
			questions[position] = ptr;
		}

	}
}


// This function is the getter for the NAquestion object pointers
NAquestion* Quiz::getQuestion(int position) const {
	// if position is out of bounds, return nullptr
	if (position < 0 || position > 4)
		return nullptr;

	else
		return questions[position];
}


// This will reset the questions in the questions array by deleting the questions from memory
// and making all positions equal to nullptr
void Quiz::resetQuestions() {

	for (int i = 0; i < 5; i++) {
		// if an NAquestion pointer is not null, delete the dynamic question from memory
		if (questions[i] != nullptr) {
			delete questions[i];
		}

		questions[i] = nullptr;
	}

	cout << "\nQuestions have been reset!" << endl;
}


// this method will display each question and will allow us to accept and check a user's input
// it will also keep track of questions that user gets right and will return score at the end.
void Quiz::startAttempt() {
	// declare number of questions counter, total points, user's obtained points, and user input variable
	int questionCount = 0;
	int totalPoints = 0;
	int userPoints = 0;
	float userAns;

	for (int i = 0; i < 5; i++) {
		// if question[i] points to a dynamic NAquestion, we will do the following:
		if (questions[i] != nullptr) {
			questionCount++; // increase question counter
			totalPoints += questions[i]->getPoints(); // add points to total point count
			questions[i]->display(); // display question 
			cout << "Answer: ";
			cin >> userAns; // get user input

			// isCorrect will either add the correct amount of points or 0 to user's obtained points
			userPoints = userPoints + questions[i]->isCorrect(userAns);
		}
	}

	// displays quiz info IF there was at least one question, does nothing if all positions
	// in question array were null
	if (questionCount != 0) {
		score = ((float)userPoints / (float)totalPoints) * 100.0;
		cout << "Your score = " << setprecision(4) << score << "%" << endl;
	}

}

// The sort function will utilize insertion sort in order to rearrange the order of the questions
// in the array by putting them in ascending order based off the number of points. We will utilize
// the overloaded boolean operators to help us with the insertion sort.
void Quiz::sort() {
	// declare integer variable "firstOutOfOrder" and "location"
	// declare NAquestion* variable "temp"
	int firstOutOfOrder, location;
	NAquestion *temp;

	for (firstOutOfOrder = 1; firstOutOfOrder < 5; firstOutOfOrder++)
		// if questions[firstOutOfOrder] has less points than questions[firstOutOfOrder - 1], set up swap
		// since questions[firstOutOfOrder] should be before questions[firstOutOfOrder - 1]
		if (*(questions[firstOutOfOrder]) < *(questions[firstOutOfOrder - 1]))
		{
			// Assign temp to hold question[firstOutOfOrder], and set location to firstOutOfOrder
			temp = questions[firstOutOfOrder];
			location = firstOutOfOrder;

			// Create a do-while loop which will keep going until question[location - 1] 
			// has less points than temp or until we reach index 0
			do
			{
				// Keep shifting values up the array(this is the sort) by assigning the element
				// at the CURRENT position with the value of the PREVIOUS position 
				questions[location] = questions[location - 1];
				location--;

			} while (location > 0 && *(questions[location - 1]) > *temp);

			// set tempt to correct position in list
			questions[location] = temp;
		}

	// end the insertion sort
}

// Quiz constructor with no parameter, sets all positions in questions array to nullptr and set score = 0
Quiz::Quiz() {
	// initialize all values as nullptr in the questions array
	for (int i = 0; i < 5; i++) {
		questions[i] = nullptr;
	}

	score = 0;
}