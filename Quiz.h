#pragma once
#include <iostream>
#include <string>
#include "NAquestion.h"

// This class, called quiz, will hold NAquestion pointers
class Quiz {
private:
	double score;
	NAquestion* questions[5];
	NAquestion* largest(int lowerIndex = 0, int upperIndex = 4);

public:
	double getScore() const;
	void setQuestion(int position, NAquestion* ptr);
	NAquestion* getQuestion(int position) const;
	void resetQuestions();
	void startAttempt();
	NAquestion* largestQuestion();
	void sort();
	Quiz();

};
