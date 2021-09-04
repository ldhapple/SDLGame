#pragma once
#include <SDL.h>
class Timer {
public:
	Timer();
	~Timer();

	void setInterval(int interval);	// Ÿ�̸��� �ֱ⸦ ����

	void start();		// Ÿ�̸Ӹ� ����

	void pause();		// Ÿ�̸Ӹ� ����
	void resume();		// Ÿ�̸Ӹ� ��� ����

	bool done();		// Ÿ�̸� �ð��� �� �Ǿ����� ����

private:
	int interval;		// Ÿ�̸��� �ֱ�
	int startTicks;		// Ÿ�̸Ӱ� ���۵� ������ tick��
	int pauseTicks;		// Ÿ�̸Ӹ� �Ͻ������� ������ tick��
};

Timer::Timer() {
	// ������ �ʱ�ȭ
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
	startTicks = SDL_GetTicks(); // startTicks�� Ÿ�̸Ӱ� ���۵� ������ tick���� ����
}
void Timer::pause() {
	if (pauseTicks == 0)
		pauseTicks = SDL_GetTicks(); // pauseTicks�� Ÿ�̸Ӱ� �Ͻ������� ������ tick ���� ����
}
void Timer::resume() {
	if (pauseTicks != 0) {
		startTicks += SDL_GetTicks() - pauseTicks; // startTicks�� �Ͻ������� �Ⱓ(���� tick���� �Ͻ������� ������ tick�� �� ��)
												// �� ���ؼ� �Ͻ������� �Ⱓ��ŭ Ÿ�̸Ӹ� �ڷ� �̷��.
		pauseTicks = 0; // pauseTicks�� 0����
	}
}
bool Timer::done() {
	if (pauseTicks == 0 &&  // ǻ������ �ƴϰ�
		SDL_GetTicks() - startTicks >= interval) { // ���� tick���� Ÿ�̸Ӱ� ���۵� ������ tick���� �ֱ⸦ �Ѿ����
		start();	// Ÿ�̸Ӹ� �����
		return true;	//  true����ȯ
	}
	return false;
}
