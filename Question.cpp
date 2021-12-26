#include <iostream> 
#include <string> 
#include "Question.h"
using namespace std; // to avoid writing std::

// This is the implementation file for Question class

// setter for question text
void Question::setText(string text) {
	this->text = text;
}

// getter for question text
string Question::getText() const {
	return text;
}

// setter for question's points
// It will do a check: If input passed is greater than or equal to 1, the function will change the points.
// If not, display an error message.
void Question::setPoints(int points) {
	if(points >= 1)
		this->points = points;
	else
		cout << "Error: Minimum point value is 1. Number of points for this question was not changed." << endl;
}

// getter for question's points
int Question::getPoints() const {
	return points;
}

// display question of text
void Question::display() const {
	cout << text << endl;
}

// constructor with no parameters that sets text as an empty string
Question::Question() {
	text = "";
}

// constructor that will set text of question
Question::Question(string question) {
	text = question;
}

