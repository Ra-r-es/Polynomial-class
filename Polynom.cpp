#include <cmath>
#include "Polynom.h"


#include <iostream>
using namespace std;
///Constructori:
Polynom ::Polynom() {
    grad = 1;
    coef = new double[2];
    coef[0] = 0,coef[1] = 1;
}// Constructor default: grad = 0 si polinomul 0
Polynom ::Polynom(int grad) {
    this -> grad = grad;
    coef = new double[grad+1];
    for (int i = 0; i < grad; ++i){
        coef[i] = 0;
    }
    coef[grad] = 0;
}//Constructor in functie de grad : Initializeaza gradul apoi polinomul
Polynom ::Polynom(int grad, double c[]){
    this -> grad = grad;
    coef = new double[grad+1];
    for (int i = 0; i <= grad; ++i){
        this ->coef[i] = c[i];
    }
}//Constructor in functie de grad si un polinom de acelasi grad

Polynom::Polynom(Polynom &p) {
    this -> grad = p.grad;
    coef = new double[grad+1];
    for (int i = 0; i <= p.get_grad(); ++i){
        this -> coef[i] = p.coef[i];
    }
}//Constructor de copiere


Polynom :: ~Polynom() { }//Destructor
//Getteri:

int Polynom ::get_grad()const{
    return grad;
}//returneaza gradul polinomului
double Polynom ::get_coef_grad(int grad) const {
    return coef[grad];
}//returneaza coeficientul gradului

//Setteri:

void Polynom ::set_grad(int grad) {
    this -> grad = grad;
    auto *t = new double[grad+1];//aloca memorie pentru un polinom nou
    for (int i = 0; i <= grad; ++i) { // se copiaza polinomul in t si pune 0 coeficintilor noi
        if (i <= this->grad)
            t[i] = coef[i];
        else
            t[i] = 0;
    }
    delete[] coef;
    coef = t;
}//Seteaza un nou grad polinomului astfel  alocand mai multa memoria sau mai putina
void Polynom ::modif_coef(int grad,double coef) {
    if (grad <= this -> grad)
        this -> coef[grad] = coef;
    else{//daca gradul este mai mare alocam un spatiu corespunzator
        auto *t = new double [grad+1];
        for (int i = 0; i <= grad; ++i){
            if (i <= this->grad){
                t[i] = this -> coef[i];//copiem toti coeficienti
            }
            else if (i < grad)
                t[i] = 0;
            else
                t[i] = coef;
        }
        delete[] this -> coef;//eliberam memoria
        this -> coef = t;
        this -> grad = grad;
    }
}
double Polynom ::calcul(double x) { //calcularea polinomului in punctul x
    double sum = 0;
    for (int i = 0; i <= grad; ++i)
        sum += coef[i]*pow(x,i);
    return sum;
}
Polynom operator+(Polynom &p, Polynom &q) {
    Polynom rez;
    if (p.get_grad() > q.get_grad()){
        rez.set_grad(p.get_grad()); //setarea gradului polinomului rezultat
        for (int i = 0; i <= p.get_grad(); ++i) {// adunarea coeficientilor celor 2 polinoame
            if (i <= q.get_grad())
                rez.modif_coef(i,q.get_coef_grad(i) + p.get_coef_grad(i));
            else
                rez.modif_coef(i,p.get_coef_grad(i));
        }
    }
    else
    {
        rez.set_grad(q.get_grad());//setarea gradului polinomului rezultat
        for (int i = 0; i <= q.get_grad();++i) {// adunarea coeficientilor celor 2 polinoame
            if (i <= p.get_grad())
                rez.modif_coef(i, p.get_coef_grad(i) + q.get_coef_grad(i));
            else
                rez.modif_coef(i,q.get_coef_grad(i));
        }

    }
    return rez;
}
Polynom& Polynom :: operator=(const Polynom &p){
    if (grad == p.grad)// daca gradele sunt egale nu trebuie modificata memoria
        for (int i = 0; i <= grad; ++i)
            coef[i] = p.coef[i];
    else{
        double *t = new double[p.grad + 1];// alocarea memoriei necesare pentru noul grad
        for (int i = 0; i <= p.grad; ++i)
            t[i] = p.coef[i];
        delete[] coef;
        coef = t;
        grad = p.grad;
    }
    return *this;
}
Polynom Polynom ::operator-(Polynom &p){
    Polynom rez;
    if (grad < p.grad) {
        rez.set_grad(p.grad); //setarea gradului polinomului rezultat
        for (int i = 0; i <= p.grad; ++i) //Scaderea coeficientilor polinoamelor
            if (i <= grad)
                rez.modif_coef(i, coef[i] - p.coef[i]);
            else
                rez.modif_coef(i, p.coef[i]);
    }
    else
        rez.set_grad(grad); //setarea gradului polinomului rezultat
        for (int i = 0; i <= grad; ++i){ //Scaderea coeficientilor polinoamelor
            if (i <= p.grad){
                rez.modif_coef(i, coef[i]- p.coef[i]);
            }
            else
                rez.modif_coef(i,coef[i]);
        }
    int i = rez.grad;
    while (coef[i] == 0) {
        i--;
    }
    if (i != rez.grad) {
        auto *t = new double[i];
        for (int j = 0; j <= i; ++j)
            t[i] = coef[i];
        delete[] coef;
        coef = t;
        grad = i;
    }
    return rez;
}
Polynom Polynom ::operator*(Polynom &p){
    Polynom rez(grad+p.grad);
    if (grad < p.grad){
        for (int i = 0; i <= p.grad; ++i){
            for (int j = 0; j <= grad; ++j)
                rez.modif_coef(i+j,coef[j]*p.coef[i] + rez.get_coef_grad(i+j));
        }
    }
    else{
        for (int i = 0; i <= grad; ++i){
            for (int j = 0; j <= p.grad; ++j)
                rez.modif_coef(i+j,coef[i]*p.coef[j] + rez.get_coef_grad(i+j));
        }
    }
    return rez;
}
std::ostream& operator <<(std:: ostream& out, Polynom p){
    for (int i = 0; i <= p.grad; ++i){
        if (i == 0 && p.coef[i] != 0)
            out << p.coef[i] << "+";
        else if (i < p.grad && p.coef[i] != 0) {
            out << p.coef[i] << "X^" << i;
            if (p.coef[i + 1] != 0)
                cout << "+";
        }
        else if (i == p.grad && p.coef[i] != 0)
            out << p.coef[i] << "X^" << i;
    }
    return out;
}
std::istream& operator >> (std::istream& in, Polynom &p){
    in >> p.grad;
    p.coef = new double[p.grad];
    for (int i = 0; i <= p.grad; ++i)
        in >> p.coef[i];
    return in;
}


// Partea BONUS
Polynom Polynom :: operator+(double d) {
    coef[0] += d;
    return *this;
} //pol + d
Polynom  operator +(double d,Polynom& pol){
    pol.modif_coef(0,pol.get_coef_grad(0) + d);
    return pol;
}// d + pol
Polynom operator -(double d,Polynom& pol){
    pol.modif_coef(0, d - pol.get_coef_grad(0));
    for (int i = 1; i <= pol.get_grad(); ++i){
        pol.modif_coef(i,(-1)*pol.get_coef_grad(i));
    }
    return pol;
} //d-pol
Polynom Polynom :: operator-(double d) {
    coef[0] = coef[0] - d;
    return *this;
} // d - pol
Polynom Polynom :: operator*(double d) {
    for (int i = 0; i <= grad; ++i) {
        coef[i] = coef[i] * d;
    }
    return *this;
}// d * pol, pol * d

void Polynom :: squared() {
    Polynom rez(grad+grad);
    for (int i = 0; i <= grad; ++i)
        for (int j = 0; j <= grad; ++j)
            rez.modif_coef(i+j,coef[i]*coef[j] + rez.get_coef_grad(i+j));
    *this = rez;
} //POL^2
void Polynom ::display(Polynom& pol) {
    *this = *this + pol;
    int grd = grad , indice = 0;
    double maxi;
    Polynom rez(*this);
    while(grd > -1){
        maxi_ind(maxi,indice,rez);
        if (maxi  > 0)
            if (indice == 0)
                cout << "+" << maxi;
            else
                cout << "+" << maxi << "X^" << indice;
        else if (maxi < 0)
            if (indice == 0)
                cout << "-" << maxi;
            else
                cout << "-1" << maxi << "X^" << indice;
        else
            break;
        grd-=1;
        rez.coef[indice] = 0;
    }

}
void Polynom ::ApplyTransformation(Polynom &pol) {
    for (int i = 1; i <= grad; ++i){
        int j = i;
        Polynom rez(pol);
        if (j > 1) {
            while (j > 1) {
                rez = rez * rez;
                j -= 1;
            }
        }
        rez = rez * coef[i];
        coef[i] = 0;
        *this = *this + rez;
    }

    for (int i = 0; i <= grad; ++i){
        if (i == 0 && coef[i] != 0)
            cout << coef[i] << "+";
        else if (i < grad && coef[i] != 0){
            cout << coef[i] << "X^" << i;
            if (coef[i+1] != 0)
                cout << "+";
        }
        else if (i <= grad && coef[i] != 0){
            cout << coef[i] << "X^" << i;
        }
    }
}

