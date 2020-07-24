#include <chrono>
#include <iostream>
#include <thread>

int main()
{
	std::chrono::system_clock::time_point lastTick = std::chrono::system_clock::now();
	while(true)
	{
		auto now = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> work_time = now - lastTick;
		const auto delta = 1000.0 / 60;
		if(work_time.count() < delta)
		{
			std::chrono::duration<double, std::milli> delta_ms(delta - work_time.count());
			auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
			std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
		}
		lastTick = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> sleep_time = lastTick - now;

		printf("FPS: %f \n", 1000 / (work_time + sleep_time).count());
	}
	return 0;
}
