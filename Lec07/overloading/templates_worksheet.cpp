/*
  Starting code for the first part of Lecture 7's worksheet.
*/

#include <iostream>

using namespace std;

template <typename T>
class Complex {
public:
  Complex(T re = 0.0, T im = 0.0);

    Complex<T> operator-(Complex<T> rhs);
    Complex<T> operator/(Complex<T> rhs);
  
    template <typename Q>
    friend ostream& operator<<(ostream& out, Complex<Q> cplx);
    friend istream& operator>>(istream& in, Complex<Q> cplx);
 
private:
  double real, imag;

};

template <typename T>
ostream& operator<<(ostream& out, Complex<T> cplx){
    return out << cplx.real << ' ' << cplx.imag << 'i' << endl;
}

template <typename T>
istream& operator>>(istream& in, Complex<T>& cplx){
    return in >> cplx.real >> cplx.imag;
}

template <typename T>
Complex<T>::Complex(T re, T im) {
  real = re;
  imag = im;
}

template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> rhs){
    return Complex<T>(real-rhs.real, imag-rhs.imag)
}

template <typename T>
Complex<T> Complex<T>::operator/(Complex<T> rhs){
    return Complex<T>(real*rhs.imag, imag *rhs.real)
}

int main() {
  Complex a(1.0, 2.0), b(3.4, 5.0);

//   cout << a+b << endl;

  return 0;
}
