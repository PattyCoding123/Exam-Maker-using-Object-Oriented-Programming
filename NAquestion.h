#pragma once
#include <string>
#include "Question.h"

// NAquestion will be a derived class of "Question"
// We will use public as member access specifier

class NAquestion : public Question {
private:
	float correctAnswerMin = 0;
	float correctAnswerMax = 0;

public:
	void setCorrectAnswer(float min, float max);
	float getCorrectAnswerMin() const;
	float getCorrectAnswerMax() const;
	int isCorrect(float ans) const;
	NAquestion();
	NAquestion(std::string setQuestion, float setMin, float setMax, int setPoints);
	bool operator>=(const NAquestion& q);
	bool operator>(const NAquestion& q);
	bool operator<(const NAquestion& q);

};


