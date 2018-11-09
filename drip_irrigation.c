//Make file for drip irrigation system

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "drip_irrigation.h"

/*Global variables*/

time_t set_time;
time_t start;
time_t end;
time_t down_time_start;
time_t down_time_end;
time_t down_time_timer;

typedef struct
{
  char* interval_date_str;                //Start interval string
  char* interval_date_str2;               //End interval string
  char* interval_length_str;              //Interval length string
  char* month_str;                        //Start interval string
  char* date_str;                         //Start interval string
  char* year_str;                         //Start interval string
  char* interval_str;                     //Interval length string
  char* month_str2;                       //End interval string
  char* date_str2;                        //End interval string
  char* year_str2;                        //End interval string
  unsigned int month;                     //Start interval month
  unsigned int date;                      //Start interval date
  unsigned int year;                      //Start interval year
  unsigned int month2;                    //End interval month
  unsigned int date2;                     //End interval date
  unsigned int year2;                     //End interval year
  unsigned int interval_hours;            //Interval length
  unsigned int interval_minutes;          //Interval length
} interval_s;

/* https://en.wikipedia.org/wiki/C_date_and_time_functions */

/* Time functions */
void setup_time()
{
  time_t curr_time;
  char* curr_time_string;

  curr_time = time(NULL);
  if (curr_time == ((time_t)-1))
  {
      fprintf(stderr, "Failure to obtain the current time.\n");
      exit(EXIT_FAILURE);
  }

  /* Convert to local time format. */
  curr_time_string = ctime(&curr_time);

  if (c_time_string == NULL)
  {
      fprintf(stderr, "Failure to convert the current time.\n");
      exit(EXIT_FAILURE);
  }

  /* Print to stdout. ctime() has already added a terminating newline character. */
  set_time = curr_time;
  printf("Irrigation system start time: %s\n", curr_time_string);
  exit(EXIT_SUCCESS);
}

void start_time()
{
  if (water_starts)
  {
    time_t curr_time;
    char* curr_time_string;

    curr_time = time(NULL);
    if (curr_time == ((time_t)-1))
    {
        fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    curr_time_string = ctime(&curr_time);

    if (c_time_string == NULL)
    {
        fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */
    start = curr_time;
    printf("Watering began on: %s\n", curr_time_string);
    exit(EXIT_SUCCESS);
  }
  return;
}

void end_time()
{
  if (water_ends)
  {
    time_t curr_time;
    char* curr_time_string;

    curr_time = time(NULL);
    if (curr_time == ((time_t)-1))
    {
        fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    curr_time_string = ctime(&curr_time);

    if (c_time_string == NULL)
    {
        fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */
    end = curr_time;
    printf("Watering ended on: %s\n", curr_time_string);
    exit(EXIT_SUCCESS);
  }
  return;
}

void down_time()
{
  time_t curr_time;
  char* curr_time_string;

  if (water_ends && (malfunctions || repair || movement))
  {
    curr_time = time(NULL);
    if (curr_time == ((time_t)-1))
    {
        fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    curr_time_string = ctime(&curr_time);

    if (c_time_string == NULL)
    {
        fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */
    down_time_start = curr_time;
    printf("Watering paused on: %s\n", curr_time_string);
    //exit(EXIT_SUCCESS);
  }
  while (watering_off)
  {
    wait;
  }
  if (water_starts)
  {
    curr_time = time(NULL);
    if (curr_time == ((time_t)-1))
    {
        fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    curr_time_string = ctime(&curr_time);

    if (c_time_string == NULL)
    {
        fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */
    down_time_end = curr_time;
    printf("Watering restarted on: %s\n", curr_time_string);
    down_time_timer = difftime(down_time_start, down_time_end);
    curr_time_string = ctime(&down_time_timer);
    printf("Time elapsed : %s\n", curr_time_string);
    exit(EXIT_SUCCESS);
  }
  return;
}

int interval_watering()
{
  int i;
  interval_s water;   //Refer to this struct when checking watering interval variables

  printf("Date to start interval (mm/dd/yyyy): \n");
  scanf("%s", water.interval_date_str);
  printf("Date to end interval (mm/dd/yyyy): \n");
  scanf("%s", water.interval_date_str2);
  printf("Interval length (hh:mm): \n");
  scanf("%s", water.interval_length_str);
  for (i = 0; i < 2; i++)
  {
    if (water.interval_date_str[i] >= VALID_MIN_NUM && water.interval_date_str[i] <= VALID_MAX_NUM) //Check if valid number
    {
      water.month_str[i] = water.interval_date_str[i];
    }
    else  //Invalid
    {
      printf("Invalid input.\n");
      return -1;
    }
    if (water.interval_date_str2[i] >= VALID_MIN_NUM && water.interval_date_str2[i] <= VALID_MAX_NUM) //Check if valid number
    {
      water.month_str2[i] = water.interval_date_str2[i];
    }
    else  //Invalid
    {
      printf("Invalid input.\n");
      return -1;
    }
    if (water.interval_length_str[i] >= VALID_MIN_NUM && water.interval_length_str[i] <= VALID_MAX_NUM) //Check if valid number
    {
      water.interval_str[i] = water.interval_length_str[i];
    }
    else  //Invalid
    {
      printf("Invalid input.\n");
      return -1;
    }
  }
  water.month = atoi(water.month_str);
  water.month2 = atoi(water.month_str2);
  water.interval_hours = atoi(water.interval_str);
  for (i = 3; i < 5; i++)
  {
    if (water.interval_date_str[i] >= VALID_MIN_NUM && water.interval_date_str[i] <= VALID_MAX_NUM) //Check if valid number
    {
      water.date_str[i] = water.interval_date_str[i];
    }
    else  //Invalid
    {
      printf("Invalid input.\n");
      return -1;
    }
    if (water.interval_date_str2[i] >= VALID_MIN_NUM && water.interval_date_str2[i] <= VALID_MAX_NUM) //Check if valid number
    {
      water.date_str2[i] = water.interval_date_str2[i];
    }
    else  //Invalid
    {
      printf("Invalid input.\n");
      return -1;
    }
    if (water.interval_length_str[i] >= VALID_MIN_NUM && water.interval_length_str[i] <= VALID_MAX_NUM) //Check if valid number
    {
      water.interval_str[i - 3] = water.interval_length_str[i];
    }
    else  //Invalid
    {
      printf("Invalid input.\n");
      return -1;
    }
  }
  water.date = atoi(water.date_str);
  water.date2 = atoi(water.date_str2);
  water.interval_minutes = atoi(water.interval_str);
  for (i = 6; i < 8; i++)
  {
    if (water.interval_date_str[i] >= VALID_MIN_NUM && water.interval_date_str[i] <= VALID_MAX_NUM) //Check if valid number
    {
      water.year_str[i] = water.interval_date_str[i];
    }
    else  //Invalid
    {
      printf("Invalid input.\n");
      return -1;
    }
    if (water.interval_date_str2[i] >= VALID_MIN_NUM && water.interval_date_str2[i] <= VALID_MAX_NUM) //Check if valid number
    {
      water.year_str2[i] = water.interval_date_str2[i];
    }
    else  //Invalid
    {
      printf("Invalid input.\n");
      return -1;
    }
  }
  water.year = atoi(water.year_str);
  water.year2 = atoi(water.year_str2);

  return 0;
}
