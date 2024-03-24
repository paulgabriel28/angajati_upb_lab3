#include <iostream>
#include "angajat.h"

using namespace std;

int nr_angajat(const Angajat *, const int , const Angajat &);
void add_angajat(Angajat *&, int &, const Angajat &);
void copie_vector(Angajat *&, const Angajat *, const int);
void duplicat(Angajat *&a, int &dim);
void unicat(Angajat *&a, int &dim);



int nr_angajat(const Angajat *vec, const int dim, const Angajat &a) {
    int nr = 0;
    for(int i = 0; i < dim; i++) {
        if(vec[i] == a) {
            nr++;
        }
    }

    return nr;
}

void add_angajat(Angajat *&vec, int &dim, const Angajat &a) {
    bool ok = 1;
    
    for(int i = 0; i < dim; i++) {
        if(vec[i] == a) {
            ok = 0;
            break;
        }
    }
    
    if(ok == 1) {
        Angajat *temp = new Angajat[dim];
        copie_vector(temp, vec, dim);
        temp = vec;
        
        delete [] vec;
        vec = new Angajat[dim+1];

        copie_vector(vec, temp, dim);
        vec[dim] = a;
        dim++;
    }
}

void copie_vector(Angajat *&a, const Angajat *b, const int dim) {
    if(a != b && a != NULL, b != NULL) { 
        delete [] a;
        a = new Angajat[dim];

        for(int i = 0; i < dim; i++) {
            a[i] = b[i];
        }
    }
}


void unicat(Angajat *&a, int &dim) {
    Angajat *temp;
    temp = new Angajat[dim];
    int poz_temp = 0;

    for(int i = 0; i < dim; i++) {
        bool unic = 1;
        for(int j = 0; j < dim; j++) {

            if(i != j) {
                if(a[i] == a[j]) {
                    unic = 0;
                    break;
                }

            }
        }

        if(unic == 1) {
            temp[poz_temp] = a[i];
            poz_temp++;
        }
    }
    delete [] a;
    a = NULL;
    
    a = new Angajat[poz_temp];
    dim = poz_temp;
    a = temp;
}


void duplicat(Angajat *&a, int &dim) {
    Angajat *temp;
    temp = new Angajat[dim];
    int poz_temp = 0;

    for(int i = 0; i < dim; i++) {
        bool unic = 1;
        
        for(int j = 0; j < poz_temp; j++) {
            if(a[i] == temp[j]) {
                unic = 0;
                break;
            }
        }

        if(unic) {
            temp[poz_temp] = a[i];
            poz_temp++;
        }
    }

    delete [] a;
    a = new Angajat[poz_temp];
    dim = poz_temp;

    for(int i = 0; i < poz_temp; i++) {
        a[i] = temp[i];
    }

    delete [] temp;
}


void citire(Angajat &a) {
    cout<<"Nume: ";
    char temp_nume[101];
    cin>>temp_nume;

    cout<<"CNP: ";
    char temp_CNP[14];
    cin>>temp_CNP;

    cout<<"Salariu: ";
    int temp_salariu;
    cin>>temp_salariu;

    Angajat temp_a(temp_nume, temp_CNP, temp_salariu);
    a = temp_a;
}

int main()
{
    // 1.
    Angajat *a;
    
    int dim;
    cout<<"1. Dimensiune vector angajati: ";
    cin>>dim;

    a = new Angajat[dim];

    for(int i = 0; i < dim; i++) {
        citire(a[i]);   
    }


    // 2.
    int nr_angajati_0 = nr_angajat(a, dim, a[0]);
    cout<<"\n2. Numar Angajati [ a[0] apare de * ori ] = "<<nr_angajati_0;


    // 3.
    cout<<"\n3. Vector sortat [ dupa nume ]:\n";
    sortare(a, dim);
    for(int i = 0; i < dim; i++) {
        a[i].afisare();
        cout<<"---\n";
    }


    // 4.
    cout<<"\n4. Adaugare nou angajat: \n";
    cout<<"\n[!] Noul angajat: \n";
    Angajat a_new;
    citire(a_new);
    add_angajat(a, dim, a_new);
    
    for(int i = 0; i < dim; i++) {
        a[i].afisare();
        cout<<"---\n";
    }

    // Bomnus
    cout<<"\n* Bonus, unicat: \n";
    unicat(a, dim);

    for(int i = 0; i < dim; i++) {
        a[i].afisare();
        cout<<"---\n";
    }

    // done :)

    return 0;
}