#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void delay(int seconds) {
    Sleep(seconds * 1000);
}
void Headline()
{
    printf("\n\n\t\t\t-------------------------------------------------------------------------------");
    printf("\n\t\t\t| \x1b[34m                             Alarm Clock                            \x1b[0m        |");
    printf("\n\t\t\t-------------------------------------------------------------------------------");
}

int main() {
     Headline();
    int alarmHour, alarmMinute;
    printf("\n\nEnter alarm time \033[32m(HH:MM)\033[0m: ");
    scanf("%d:%d", &alarmHour, &alarmMinute);

    time_t now;
    struct tm *alarmTime;
    int stopwatchSeconds = 0;

    while (1) {
        time(&now);
        alarmTime = localtime(&now);

        if (alarmTime->tm_hour == alarmHour && alarmTime->tm_min == alarmMinute) {
                 printf("\x1b[31m");
                printf("\n\n\n\n\t\t\t\t\t|| T I M E   T O   W A K E   U P! ||\n\n\n");
                printf("\x1b[0m");


        system("start wmplayer /play /close C:\\Users\\user\\Music\\alarm.mp3");


            break;
        }

        printf("Stopwatch: %02d:%02d:%02d\r", stopwatchSeconds / 3600, (stopwatchSeconds % 3600) / 60, stopwatchSeconds % 60);
        fflush(stdout);

        delay(1);
        stopwatchSeconds++;
    }

    return 0;
}
