#include <iostream>
#include <string>
using namespace std;

class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   Date();
   Date(unsigned m, unsigned d, unsigned y);
   Date(const string& mn, unsigned d, unsigned y);
   void printNumeric() const;
   void printAlpha() const;


   /* Add a number of days to one date to get another: 
      this number may be positive or negative.
      Obviously, the new date will be a valid date, 
      accounting for the correct number of days in each month, 
      and for leap years. Gregorian calendar leap year rules
      used no matter how many negative days passed in.
   */
   // Only uncomment the following function (addDays) declaration
   // if you are trying for the extra credit
   // Date addDays(int d) const;

 private:
   bool isLeap(unsigned y) const;
   unsigned daysPerMonth(unsigned m, unsigned y) const;
   string name(unsigned m) const;
   unsigned number(const string& mn) const;
};

// creates the date January 1st, 2000.
Date::Date() {
      monthName = "January";
      month = 1;
      day = 1;
      year = 2000;
   }
   
/* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end). */
Date::Date(unsigned m, unsigned d, unsigned y) {
      unsigned maxDPM = daysPerMonth(m, y);
      year = y;
      
      if(m < 1) {
         monthName = "January";
         month = 1;
         if(d > maxDPM) {
            day = 31;
            cout << "Invalid date values: Date corrected to " << month << "/" 
            << day << "/" << year << "." << endl << endl;
         }
         else if(d == 0) {
            day = 1;
            cout << "Invalid date values: Date corrected to " << month << "/" 
            << day << "/" << year << "." << endl << endl;
         }
         else {
            day = d;
            cout << endl;
         }
      }
      else if(m > 12) {
         monthName = "December";
         month = 12;
         if(d > maxDPM) {
            day = 31;
            cout << "Invalid date values: Date corrected to " << month << "/" 
            << day << "/" << year << "." << endl << endl;
         }
         else if(d == 0) {
            day = 1;
            cout << "Invalid date values: Date corrected to " << month << "/" 
            << day << "/" << year << "." << endl << endl;
         }
         else {
            day = d;
            cout << endl;
         }
      }
      else {
         monthName = name(m);
         month = m;
         if(d > maxDPM) {
            day = maxDPM;
            cout << "Invalid date values: Date corrected to " << month << "/" 
            << day << "/" << year << "." << endl << endl;
         }
         else if(d == 0) {
            day = 1;
            cout << "Invalid date values: Date corrected to " << month << "/" 
            << day << "/" << year << "." << endl << endl;
         }
         else {
            day = d;
            cout << endl;
         }
      }
   }

/* parameterized constructor: month name, day, year
       - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000 
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name. */
Date::Date(const string& mn, unsigned d, unsigned y) {
      if(number(mn) == 1000) {
         monthName = "January";
         month = 1;
         day = 1;
         year = 2000;
         cout << "Invalid month name: the Date was set to " << month << "/" 
         << day << "/" << year << "." << endl << endl;
      }
      else {
         unsigned maxDPM = daysPerMonth(number(mn), y);
         month = number(mn);
         monthName = name(month);
         year = y;
         if(d > maxDPM) {
            day = maxDPM;
            cout << "Invalid date values: Date corrected to " << month << "/" 
            << day << "/" << year << "." << endl << endl;
         }
         else if(d == 0) {
            day = 1;
            cout << "Invalid date values: Date corrected to " << month << "/" 
            << day << "/" << year << "." << endl << endl;
         }
         else {
            day = d;
            cout << endl;
         }
      }
   }
   
/* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end. */
void Date::printNumeric() const {
   cout << "Numeric: " << month << "/" << day << "/" << year;
   return;
   }

/* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end. */
void Date::printAlpha() const {
   cout << "Alpha:   " << monthName << " " << day << ", " << year;
   return;
}

/* Returns true if the year passed in is a leap year, otherwise returns false. */
bool Date::isLeap(unsigned y) const {
      if(y % 4 == 0) {
         if(y % 400 == 0) {
            return true;
         }
         else if(y % 100 == 0) {
            return false;
         }
         else {
            return true;
         }
      }
      else {
         return false;
      }
   }

 /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter. */
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
      unsigned dpm = 31;
      if(m == 2) {
         if(isLeap(y)) {
            dpm = 29;
            return dpm;
         }
         else {
            dpm = 28;
            return dpm;
         }
      }
      else if(m == 4 || m == 6 || m == 9 || m == 11) {
         dpm = 30;
         return dpm;
      }
      else {
         dpm = 31;
         return dpm;
      }
}

/* Returns the name of a given month
      - e.g. name(12) returns the string "December" */
string Date::name(unsigned m) const {
      string corrName = "";
      if(m <= 1) {
         corrName = "January";
         return corrName;
      }
      else if(m == 2) {
         corrName = "February";
         return corrName;
      }
      else if(m == 3) {
         corrName = "March";
         return corrName;
      }
      else if(m == 4) {
         corrName = "April";
         return corrName;
      }
      else if(m == 5) {
         corrName = "May";
         return corrName;
      }
      else if(m == 6) {
         corrName = "June";
         return corrName;
      }
      else if(m == 7) {
         corrName = "July";
         return corrName;
      }
      else if(m == 8) {
         corrName = "August";
         return corrName;
      }
      else if(m == 9) {
         corrName = "September";
         return corrName;
      }
      else if(m == 10) {
         corrName = "October";
         return corrName;
      }
      else if(m == 11) {
         corrName = "November";
         return corrName;
      }
      else {
         corrName = "December";
         return corrName;
      }
   }

/* Returns the number of a given named month
      - e.g. number("March") returns 3  */
unsigned Date::number(const string& mn) const {
      unsigned monthNum = 1000;
      if(mn == "January" || mn == "january") {
         monthNum = 1;
         return monthNum;
      }
      else if(mn == "February" || mn == "february") {
         monthNum = 2;
         return monthNum;
      }
      else if(mn == "March" || mn == "march") {
         monthNum = 3;
         return monthNum;
      }
      else if(mn == "April" || mn == "april") {
         monthNum = 4;
         return monthNum;
      }
      else if(mn == "May" || mn == "may") {
         monthNum = 5;
         return monthNum;
      }
      else if(mn == "June" || mn == "june") {
         monthNum = 6;
         return monthNum;
      }
      else if(mn == "July" || mn == "july") {
         monthNum = 7;
         return monthNum;
      }
      else if(mn == "August" || mn == "august") {
         monthNum = 8;
         return monthNum;
      }
      else if(mn == "September" || mn == "september") {
         monthNum = 9;
         return monthNum;
      }
      else if(mn == "October" || mn == "october") {
         monthNum = 10;
         return monthNum;
      }
      else if(mn == "November" || mn == "november") {
         monthNum = 11;
         return monthNum;
      }
      else if(mn == "December" || mn == "december") {
         monthNum = 12;
         return monthNum;
      }
      else {
         return monthNum;
      }
}

Date getDate();

int main() {
   
   Date userInput;
   
   userInput = getDate();
   
   userInput.printNumeric();
   cout << endl;
   userInput.printAlpha();
   
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned m;
   unsigned d;
   unsigned y;
   string s;
   
   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
   << "1 - Month Number" << endl << "2 - Month Name" << endl 
   << "3 - default" << endl;
   cin >> choice;
   cout << endl;
   
   if(choice == 1) {
      cout << "month number? " << endl;
      cin >> m;
      
      cout << "day? " << endl;
      cin >> d;
      
      cout << "year? " << endl;
      cin >> y;
      
      return Date(m, d, y);
   }
   else if(choice == 2) {
      cout << "month name? " << endl;
      cin >> s; 
      
      cout << "day? " << endl;
      cin >> d;
      
      cout << "year? " << endl;
      cin >> y;
      
      return Date(s, d, y);
   }
   else {
      cout << endl;
      return Date();
   }
}
