#include <iostream>
#ifdef Polynom
#endif // Polynom

class Polynom{
    int grad;
    double *coef;
public:
    //Constructori
    Polynom();
    Polynom(int);
    Polynom(int,double[]);
    Polynom(Polynom &p);//Constructor de copiere
    //destructor
    ~Polynom();
    //getter
    int get_grad()const; // returneaza gradul polinomului
    double get_coef_grad(int)const; // returneaza coeficientul gradului

    //setter
    void set_grad(int); // seteaza gradul polinomului

    //Afisare Polinom
    void Afisare()const{
        for (int i = 0; i <= grad; ++i){
            if (i == 0 && coef[i] != 0)
                std::cout << coef[i] << "+";
            else if (i < grad && coef[i] != 0)
                std::cout << coef[i] << "X^" << i << "+";
            else if (i == grad && coef[i] != 0)
                std::cout << coef[i] << "X^" << i;
        }
    }
    //functii
    void modif_coef(int,double);// modifica coeficientul gradului
    double calcul(double);//calculeaza valoarea polinomului intr un punct
    void maxi_ind(double& maxi, int &indice,Polynom &p){
        maxi = p.coef[0];
        for (int i = 0; i <= p.grad; ++i){
            if (p.coef[i] > maxi)
                maxi = p.coef[i], indice = i;
        }
    }
    //functie BONUS
    void squared(); // pol^2
    void ApplyTransformation(Polynom&);
    void display(Polynom&);
    //supraincarcare operatori BONUS
    //adunare
    Polynom operator +(double); //d + pol
    //scadere
    Polynom operator -(double); //d - pol
    //Inmultire
    Polynom operator *(double); //d * pol
    //supraincarcare operatori
    Polynom operator-(Polynom &p); // scadere
    Polynom operator*(Polynom &p); // inmultire
    Polynom& operator=(const Polynom &p); // egal
    friend std::ostream& operator<<(std::ostream&, Polynom); // cout
    friend std::istream& operator>>(std::istream&, Polynom&);// cin
};
//supraincarcare "+"(adunare) inafara clasei fara friend.
Polynom operator+(Polynom &p, Polynom &q);
//BONUS
Polynom operator +(double,Polynom& pol); // d + pol
Polynom operator -(double,Polynom& pol);// d - pol
