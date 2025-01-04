#include <stdio.h>
#include <time.h>

// int main() {
//     // Vaqtni olish
//     time_t current_time;
//     struct tm *time_info;

//     // Hozirgi vaqti olish
//     time(&current_time);

//     // Mahalliy vaqtga o'tkazish
//     time_info = localtime(&current_time);

//     // Vaqtni formatlab chiqarish
//     printf("Current date and time: %s", asctime(time_info));

//     return 0;
// }

int main() {
    // Vaqtni olish
    time_t current_time;
    struct tm *time_info;
    char time_str[20];  // Soat:daqiqa:soniya uchun

    // Hozirgi vaqti olish
    time(&current_time);

    // Mahalliy vaqtga o'tkazish
    time_info = localtime(&current_time);

    // Formatlash: "HH:MM:SS"
    strftime(time_str, sizeof(time_str), "%H:%M:%S %d.%m.%Y", time_info);

    // Natijani chiqarish
    printf("Current time: %s\n", time_str);

    return 0;
}