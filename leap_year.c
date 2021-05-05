#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char *Months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char *Days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main(int argc, char* argv[]){
   time_t t; 
   struct tm *t_parts;
   // to get the current time of the machine
   time(&t);
   char* readable_format = ctime(&t);
   // to get the year - month - time separately
   t_parts = localtime(&t);
   int year = (*t_parts).tm_year + 1900;
   
   printf("Time & date: %s", readable_format);
   
   printf("Time is: %d:%d:%d\n",(*t_parts).tm_hour,(*t_parts).tm_min,(*t_parts).tm_sec);
   
   printf("It is the day no: %d of the year.\n",(*t_parts).tm_yday);
   
   printf("Today is %s.\n", Days[(*t_parts).tm_wday]);
   
   printf("Today is %d of %s\n", (*t_parts).tm_mday, Months[(*t_parts).tm_mon]);
   
   if(year % 400 == 0 || year % 100 != 0 && year % 4 == 0){
	printf("year %d is a leap year!", year);
   }
   
   else{
   	printf("year %d is not a leap year!", year);
   }
   
   return 0;
   }
