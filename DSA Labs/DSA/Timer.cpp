#include "Timer.h"

// Start the timer
void Timer::Start() {
	mBegin = steady_clock::now();
}

// Stop the timer
void Timer::Stop() {
	mEnd = steady_clock::now();
}

// Get the elapsed time (in both micro and nano seconds)
void Timer::Elapsed() {
	cout << "Time difference = " << duration_cast<milliseconds>(mEnd - mBegin).count() << " milliseconds\n";
	cout << "Time difference = " << duration_cast<microseconds>(mEnd - mBegin).count() << " microseconds\n";
	cout << "Time difference = " << duration_cast<nanoseconds> (mEnd - mBegin).count() << " nanoseconds\n";
}


