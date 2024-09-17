#include <iostream>
using namespace std;

class Fraction
{
private:

    int numerator;   
    int denominator; 

    int gcd(int a, int b) 
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    void reduce() 
    {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:

    Fraction() : numerator(0), denominator(1) {}  
    Fraction(int n, int d) : numerator(n), denominator(d)
    {
        if (denominator == 0) 
        {
            cout << "Denominator cannot be zero. Setting denominator to 1." << endl;
            denominator = 1;
        }
        reduce();  
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const 
    {
        return denominator;
    }

    void setNumerator(int n) 
    {
        numerator = n;
        reduce();  
    }

    void setDenominator(int d) 
    {
        if (d == 0) 
        {
            cout << "Denominator cannot be zero. Setting denominator to 1." << endl;
            denominator = 1;
        }
        else 
        {
            denominator = d;
        }
        reduce();  
    }

    void input() 
    {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) 
        {
            cout << "Denominator cannot be zero. Setting denominator to 1." << endl;
            denominator = 1;
        }
        reduce();  
    }

    void output() const 
    {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction add(const Fraction& other) const
    {
        int n = numerator * other.denominator + other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction subtract(const Fraction& other) const 
    {
        int n = numerator * other.denominator - other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction multiply(const Fraction& other) const 
    {
        int n = numerator * other.numerator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction divide(const Fraction& other) const 
    {
        int n = numerator * other.denominator;
        int d = denominator * other.numerator;
        return Fraction(n, d);
    }
};

int main() 
{
    Fraction f1, f2, result;

    cout << "Input first fraction:" << endl;
    f1.input();
    cout << "Input second fraction:" << endl;
    f2.input();
    cout << "Results:" << endl;

    f1.add(f2).output();        
    f1.subtract(f2).output();   
    f1.multiply(f2).output();   
    f1.divide(f2).output();     

    return 0;
}