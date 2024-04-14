#include <iostream>
#include "Polynom.h"
using namespace std;

int main()
{
    int bonus = 1;
    if (bonus == 1) {
        Polynom pol;
        cin >> pol;
        double d;
        cin >> d;
        cout << "Polinomul este: " << pol;
        cout << endl;
        pol = pol + d;
        cout << "pol + d = " << pol;
        pol = d + pol;
        cout << endl;
        cout << "d + pol = " << pol;
        cout << endl;
        pol = pol - d;
        cout << "pol - d = " << pol;
        cout << endl;
        pol = d - pol;
        cout << "d - pol = " << pol;
        cout << endl;
        pol.squared();
        cout << "pol^2 = " << pol;
        cout << endl;
        Polynom pol2;
        cin >> pol2;
        cout << "Apply_Transformation = ";
        pol.ApplyTransformation(pol2);
        cout << pol;
        cout << endl;
        cout << "Display = ";
        pol.display(pol2);
    }
    else {
        Polynom p(5);
        p.Afisare();
        double q[10];
        for (int i = 0; i < 10; ++i) {
            q[i] = i;
        }
        Polynom a(9, q);
        cout << endl << "a = ";
        a.Afisare();
        cout << endl;
        Polynom w(a);
        cout << "w = ";
        w.Afisare();
        cout << endl << "p = ";
        p.Afisare();
        cout << endl << "Grad p: " << p.get_grad() << " cu coef grad " << p.get_grad() << " = " << p.get_coef_grad(5);
        w.set_grad(4);
        cout << endl;
        cout << "Grad nou w :  " << w.get_grad() << " Iar polinomul este : ";
        w.Afisare();
        w.modif_coef(6, 4);
        cout << endl << "w = ";
        w.Afisare();
        cout << endl << "a = ";
        a.Afisare();
        cout << endl;
        cout << w.calcul(2);
        Polynom z;
        z = w + a;
        cout << endl;
        cout << "w + a = ";
        z.Afisare();
        z = w - a;
        cout << endl << "w - a = ";
        z.Afisare();
        Polynom c, x;
        for (int i = 0; i <= 3; ++i) {
            c.modif_coef(i, i), x.modif_coef(i, i);
        }
        Polynom f;
        f = c * x;
        cout << endl << "c = ";
        c.Afisare();
        cout << endl << "x = ";
        x.Afisare();
        cout << endl << "c * x = ";
        f.Afisare();
        cout << endl;
        Polynom v;
        cin >> v;
        cout << v;
        v = v;
        cout << endl;
        cout << v;
        cout << endl;
        double l = 10;
    }
    return 0;
}

