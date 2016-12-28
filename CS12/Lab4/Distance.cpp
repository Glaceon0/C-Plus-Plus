#include <iostream>
using namespace std;

#include "Distance.h"

Distance::Distance() {
   feet = 0;
   inches = 0.0;
}

Distance::Distance(unsigned feet, double inches) {
   if (inches > 12.0 || inches < 0.0 || feet < 0) {
      this->feet = feet;
      this->inches = inches;
      init();
   }
   else {
      this->feet = feet;
      this->inches = inches;
   }
}

Distance::Distance(double inches) {
   feet = 0;
   if (inches > 12.0 || inches < 0.0) {
      this->inches = inches;
      init();
   }
   else {
      this->inches = inches;
   }
}

unsigned Distance::getFeet() const {
   return feet;
}
 
double Distance::getInches() const {
   return inches;
}
 
double Distance::distanceInInches() const {
   double inch = 0.0;
   inch = feet * 12.0 + inches;
   return inch;
}
 
double Distance::distanceInFeet() const {
   double Feet = 0.0;
   Feet = feet + (inches / 12.0);
   return Feet;
}
 
double Distance::distanceInMeters() const {
   double meters = 0.0;
   meters = (feet * 12.0 * 0.0254) + (inches * 0.0254);
   return meters;
}
 
const Distance Distance::operator+(const Distance &rhs) const {
   Distance sum;
   sum.feet = this->feet + rhs.feet;
   sum.inches = this->inches + rhs.inches;
   if (sum.inches > 12) {
      sum.feet = sum.feet + static_cast<unsigned>(sum.inches / 12.0);
      sum.inches = ((sum.inches / 12.0) - static_cast<unsigned>(sum.inches / 12.0)) * 12.0;
   }
   return sum;
}
 
const Distance Distance::operator-(const Distance& rhs) const {
   Distance diff;
   if(this->feet > rhs.feet || this->feet == rhs.feet){
      if (rhs.inches > this->inches && this->feet > rhs.feet){
         //this->inches = this->inches + 12.0;
         diff.feet = this->feet - 1 - rhs.feet;
         diff.inches = (this->inches + 12.0) - rhs.inches;
         return diff;
      }
      else if (this->inches > rhs.inches) {
         diff.feet = this->feet - rhs.feet;
         diff.inches = this->inches - rhs.inches;
         return diff;
      }
   }
   else if (rhs.feet > this->feet || rhs.feet == this->feet) {
      if (this->inches > rhs.inches && this->feet < rhs.feet) {
         diff.feet = rhs.feet - 1 - this->feet;
         diff.inches = (rhs.inches + 12 - this->inches);
         return diff;
      }
      else if (rhs.inches > this->inches) {
         diff.feet = rhs.feet - this->feet;
         diff.inches = rhs.inches - this->inches;
         return diff;
      }
   }
   diff.inches = rhs.inches - this->inches;
   return diff;
}
 
ostream & operator<<(ostream& out, const Distance& rhs) {
     out << rhs.feet <<"\' " << rhs.inches << '"';
     return out;
}
 
void Distance::init() {
   if (feet < 0) {
      feet *= -1;
   }
   else if (inches < 0.0) {
      inches *= -1;
   }
   if (inches > 12.0) {
      feet = feet + static_cast<unsigned>(inches / 12.0);
      inches = ((inches / 12.0) - static_cast<unsigned>(inches / 12.0)) * 12.0;
   }
   return;
}