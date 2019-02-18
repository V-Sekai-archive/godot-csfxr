#include <csfxr.h>
#include <ao/ao.h>
#include <time.h>

int main()
{
	//init
	ao_initialize();
	int driver = ao_default_driver_id();
	ao_sample_format format = {0};
		format.bits = 16;
		format.channels = 2;
		format.rate = 44100;
		format.byte_format = AO_FMT_LITTLE;
		ao_device *device = ao_open_live(driver, &format, NULL /* no options */);
	srand(time(NULL));

	struct timespec delay;
	delay.tv_sec = 0;


	//play sound
	int i;
	for (i=0; i < 100; i++)
	{
		SfxrSound sound = SfxrBlip(rand());
		ao_play(device, (char *)sound.data, sound.length);
		free(sound.data);
		delay.tv_nsec = (rand() % (300000001 - 20000000)) + 20000000;
		nanosleep(&delay, NULL);
	}


	//cleanup
	ao_close(device);
	ao_shutdown();
	return 0;
}



