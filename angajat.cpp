#include <iostream>
#include <cstring>

#include "angajat.h"

using namespace std;


Angajat::Angajat():nume(NULL), salariu(0) {
    strcpy(CNP, "0000000000000");
}

Angajat::Angajat(const char *new_nume, const char new_CNP[], int new_salariu):salariu(new_salariu) {
    if(nume != NULL) {
        delete [] nume;
        nume = NULL;
    }

    nume = new char[strlen(new_nume) + 1];

    strcpy(nume, new_nume);

    strcpy(CNP, new_CNP);
}

Angajat::Angajat(const Angajat &a) {
    // cout<<"\nconst de copiere\n";
    
    Angajat::copie(a);

    // if(nume != NULL) {
    //     delete [] nume;
    //     nume = NULL;
    // }

    // nume = new char[strlen(a.nume) + 1];

    // strcpy(nume, a.nume);

    // strcpy(CNP, a.CNP);

    // salariu = a.salariu;
}

Angajat::~Angajat() {
    if(nume != NULL) {
        delete [] nume;
    }
    strcpy(CNP, "0000000000000");
    salariu = 0;
}


void Angajat::afisare() const{
    if(nume != NULL) {
        cout<<"Nume: "<<nume<<endl;
    }
    else
        cout<<"Nume: --"<<endl;

    cout<<"CNP: "<<CNP<<endl;
    
    cout<<"Salariu: "<<salariu<<endl;
}


void Angajat::copie(const Angajat &a) {
    if(nume != NULL) {
        delete [] nume;
        nume = NULL;
    }

    nume = new char[strlen(a.nume) + 1];

    strcpy(nume, a.nume);

    strcpy(CNP, a.CNP);

    salariu = a.salariu;
}

int Angajat::getSalariu() const {
    return salariu;
}

int Angajat::getType() const {
    if(CNP[0] == '1' || CNP[0] == '5')
        return 0;
    else if(CNP[0] == '2' || CNP[0] == '6')
        return 1;

    return 2;
}

char* Angajat::getNume() const {
    return nume;
}


// Lab 3:
Angajat& Angajat::operator=(const Angajat &a) {
    if(this != &a) {
        copie(a);
    }

    return *this;
}

bool operator==(const Angajat &a, const Angajat &b) {
    return ((strcmp(a.nume, b.nume) == 0) && (strcmp(a.CNP, b.CNP) == 0) && a.salariu == b.salariu) ? 1 : 0;
}

bool operator!=(const Angajat &a, const Angajat &b) {
    return !(a==b);
}

void sortare(Angajat *vec, const int dim) {
    for(int i = 0; i < dim-1; i++) {
        for(int j = i+1; j < dim; j++) {
            if(strcmp(vec[i].nume, vec[j].nume) > 0) {
                Angajat temp;
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}
