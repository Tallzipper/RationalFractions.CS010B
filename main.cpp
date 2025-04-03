#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int num); 
      Rational(int num, int den); 
      Rational add(const Rational & B) const; 
      Rational subtract(const Rational & B) const; 
      Rational multiply(const Rational & B) const; 
      Rational divide(const Rational & B) const;
      void simplify();
      void display() const;
   private:
      int gcd(int num, int den) const;
};

// Implement Rational class memberfunctions here


Rational::Rational() 
{

   numerator = 0;
   denominator = 1;

}

Rational::Rational(int num)
{

   numerator = num;
   denominator = 1;

}

Rational::Rational(int num, int den)
{

   numerator = num;
   denominator = den; 

}

Rational Rational::add(const Rational& B ) const
{
 
   int top; // hehehehe
   int bttm; // This is far too immature
   
   top = (numerator * B.denominator) + (denominator * B.numerator);
   bttm = denominator * B.denominator;

   return Rational(top, bttm);

}

Rational Rational::subtract(const Rational& B ) const
{

   int top; // It is unreasonable that I find this so funny
   int bttm; // but i can't be stopped, this is My code!

   top = (numerator * B.denominator) - (denominator * B.numerator);
   bttm = denominator * B.denominator;

   return Rational(top, bttm);

}

Rational Rational::multiply(const Rational& B ) const
{

   int top; // I really hope I find this code again one day
   int bttm; // In case I lose this sense of humor

   top = numerator * B.numerator;
   bttm = denominator * B.denominator;

   return Rational(top, bttm);

}

Rational Rational::divide(const Rational& B ) const
{

   int top; // Who am I kidding
   int bttm; // I'll never not be this funny

   top = numerator * B.denominator;
   bttm = B.numerator * denominator;

   return Rational(top, bttm);

}

void Rational::simplify()
{

   int div = gcd(numerator, denominator);

   numerator /= div;
   denominator /= div;

}

void Rational::display() const
{

   cout << numerator << " / " << denominator;

}

int Rational::gcd(int num, int den) const
{

   int temp = den;

   while (den != 0) 
   {
      temp = den;
      den = num % den;
      num = temp;
   }

   return num;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

