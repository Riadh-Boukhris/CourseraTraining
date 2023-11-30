#include <stdio.h>

typedef enum {
    january = 1, february, march, april, may, june,
    july, august, september, october, november, december
} Month;

typedef struct {
    Month m;
    int d;
} Date;

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(Month m, int year) {
    switch (m) {
        case february:
            return isLeapYear(year) ? 29 : 28;
        case april:
        case june:
        case september:
        case november:
            return 30;
        default:
            return 31;
    }
}

Date nextday(Date day) {
    int days = daysInMonth(day.m, 2023); // assuming year is 2023, you can modify accordingly

    if (day.d == days) {
        day.d = 1;
        day.m = (day.m % 12) + 1;
    } else {
        day.d++;
    }

    return day;
}

void printdate(Date day) {
    const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("%s %d\n", monthNames[day.m - 1], day.d);
}

int main() {
    Date date = {december, 12};
    printf("Current date: ");
    printdate(date);

    Date nextDate = nextday(date);
    printf("Next day: ");
    printdate(nextDate);

    return 0;
}
