#include <iostream> 
#include <string> 
#include "NAquestion.h"
using namespace std;

// This file is the implementation file of NAquestion class

// This is the setter function for the min and max correct answer
void NAquestion::setCorrectAnswer(float min, float max) {
	if (min > max)
		cout << "Error: Minimum value is greater than Maximum value. Answers were not changed." << endl;

	else {
		correctAnswerMin = min;
		correctAnswerMax = max;
	}
}

// The next to functions will be the getters for the correctAnswerMin
// and the correctAnswerMax respectively
float NAquestion::getCorrectAnswerMin() const {
	return correctAnswerMin;
}

float NAquestion::getCorrectAnswerMax() const {
	return correctAnswerMax;
}

// The following function returns the amount of points of the question if the user's answer
// is between the min and max. Returns 0 points otherwise.
// It will also display either a Correct or Incorrect message to user
int NAquestion::isCorrect(float ans) const {
	if (ans >= correctAnswerMin && ans <= correctAnswerMax) {
		cout << "Your answer is CORRECT!" << endl << endl;
		return getPoints();
	}

	else {
		cout << "Your answer is NOT correct!" << endl << endl;
		return 0;
	}
		
}

// Constructor with no parameters, sets text to empty string
// We declared the default amount of points an NAquestion receives is 1 in the Question class
// And default Min and Max answers are zero.
NAquestion::NAquestion() : Question() {
}

// Constructor with 4 parameters to initialize the question's text,
// minimum answer, and maximum answer, and the number of points (determined by the user)
NAquestion::NAquestion(string setQuestion, float setMin, float setMax, int setPts) : Question(setQuestion) {
	setCorrectAnswer(setMin, setMax);
	setPoints(setPts);
}

// Overloaded operator >= which compares the two question's number of points.
// Returns true if the first question's points is greater or equal to the second
// question's points.
bool NAquestion::operator>=(const NAquestion& q) {
	return (getPoints() >= q.getPoints());
}

// Overloaded operator > which compares the two question's number of points.
// Returns true if the first question's points is greater than the second
// question's points
bool NAquestion::operator>(const NAquestion& q) {
	return (getPoints() > q.getPoints());
}

// Overloaded operator < which compares the two question's number of points.
// Returns true if the first question's points is less than the second
// question's points
bool NAquestion::operator<(const NAquestion& q) {
	return (getPoints() < q.getPoints());
}