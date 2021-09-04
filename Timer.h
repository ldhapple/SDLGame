#pragma once
#include <SDL.h>
class Timer {
public:
	Timer();
	~Timer();

	void setInterval(int interval);	// 타이머의 주기를 설정

	void start();		// 타이머를 구동

	void pause();		// 타이머를 멈춤
	void resume();		// 타이머를 계속 진행

	bool done();		// 타이머 시간이 다 되었는지 조사

private:
	int interval;		// 타이머의 주기
	int startTicks;		// 타이머가 시작된 시점의 tick값
	int pauseTicks;		// 타이머를 일시정지한 시점의 tick값
};

Timer::Timer() {
	// 값들의 초기화
	interval = 0;
	startTicks = 0;
	pauseTicks = 0;
}
Timer::~Timer() {
}

void Timer::setInterval(int interval) {
	this->interval = interval;
}
void Timer::start() {
	startTicks = SDL_GetTicks(); // startTicks에 타이머가 시작된 시점의 tick값을 대입
}
void Timer::pause() {
	if (pauseTicks == 0)
		pauseTicks = SDL_GetTicks(); // pauseTicks에 타이머가 일시정지된 시점의 tick 값을 대입
}
void Timer::resume() {
	if (pauseTicks != 0) {
		startTicks += SDL_GetTicks() - pauseTicks; // startTicks에 일시정지된 기간(현재 tick에서 일시정지된 시점의 tick을 뺀 값)
												// 을 더해서 일시정지된 기간만큼 타이머를 뒤로 미룬다.
		pauseTicks = 0; // pauseTicks를 0으로
	}
}
bool Timer::done() {
	if (pauseTicks == 0 &&  // 퓨즈중이 아니고
		SDL_GetTicks() - startTicks >= interval) { // 현재 tick에서 타이머가 시작된 시점의 tick값이 주기를 넘어섯으면
		start();	// 타이머를 재시작
		return true;	//  true를반환
	}
	return false;
}
