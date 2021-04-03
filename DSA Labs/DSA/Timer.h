#pragma once

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// A simple static timer class
class Timer
{
private:
	steady_clock::time_point mBegin;
	steady_clock::time_point mEnd;

public:

	Timer() {

	}

	// Start the timer
	void Start();

	// Stop the timer
	void Stop();

	// Get the elapsed time (in both micro and nano seconds)
	void Elapsed();
};

