#pragma once
#include <string>

// "Question" will be the base class for this assignment

class Question {
private:
	// Default and minimum value for points is 1
	std::string text;
	int points = 1;

public:
	void setText(std::string text);
	std::string getText() const;
	void setPoints(int points);
	int getPoints() const;
	void display() const;
	Question();
	Question(std::string question);

}; 