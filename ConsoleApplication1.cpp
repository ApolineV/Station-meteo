// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include "K8055.h"
#include "ConsoleApplication1.h"
#include "mysql.h"
#include "time.h"




using namespace std;

int main()
{
	; , ;
	

	0 int hander = K8055::OpenDevice(0);
	int h, min, s, timer=0,sec;
	time_t now;

	time(&now);

	printf("Aujourd'hui est : %s", ctime(&now));
	struct tm *local = localtime(&now);
	h = local->tm_hour;
	min = local->tm_min;
	s = local->tm_sec;
	sec = s+5;
	printf("L'heure : %02d:%02d:%02d\n", h, min, s);

	mySQL = mysql_init(NULL);

	while (timer < 60)
	{
		if (s == sec)
		{
			int valeur = K8055::ReadAnalogChannel(1);
			cout << valeur << endl;
			float v = (float)valeur;

			int va = ((v / 255) * 90) - 30;

			cout << va << " C" << endl;
			timer = timer + 1;
			sec = sec + 5;
			if (sec > 60)
			{
				sec = sec - 60;

			}
			printf("L'heure : %02d:%02d:%02d\n", h, min, s); 

		}

		time_t now;

		time(&now);
		struct tm *local = localtime(&now);
		h = local->tm_hour;
		min = local->tm_min;
		s = local->tm_sec;
		
		
	}
	

	 //SDL_Delay(1000);
	 //SDL_GetTicks
}
