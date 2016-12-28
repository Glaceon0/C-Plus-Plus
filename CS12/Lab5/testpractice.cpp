//This is the code for Circle.h, question 31 on the practice midterm
// Don't forget to define those at the beginning of an .h file
#ifndef _CIRCLE_H
#define _CIRCLE_H

Class Circle {
    private
      Point center;
      double radius;
    public
      Circle();
      Circle(point, double);
      void display() const;
      const double operator-(const circle& rhs) const;
};

#endif

//Code for void load_users
//Function definition
void load_users(const string& filename, vector<User>& users) {
    ifstream inFS;
    if(!inFS.is_open()) {
        cout << "Cannot open" << filename;
        return 1;
    }
    User person1;
    string user = "";
    string pass = "";
    while(inFS.good()) {
        inFS >> user;
        inFS >> pass;
        person1 = User(user, pass);
        users.push_back(person1);
    }
    return;
}
//Yeah, that's it really. 