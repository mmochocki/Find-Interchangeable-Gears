#include <iostream>
#include <fstream>
#include <cmath>
#include <windows.h>

using namespace std;
// check git chain connection
const double mojeKola[43] = {28,30,33,36,38,39,40,40,40,42,44,46,47,48,48,48,48,50,52,56,60,60,60,60,62,67,68,68,70,71,72,73,74,80,83,84,86,86,95,100,103,109};
int iloscKol = 43;
int iloscZebow;
double blad = 0.00001;

long double stopnie;
long double stopniePlus;
long double modul;
long double parametr = 7.9577;
long double wynikAngle;
long double wynikAnglePlus;
long double angleAcceptable;

void oblicz2(){


for (int i = 0; i < iloscKol; i++){
        for (int j = 0; j < iloscKol; j++){
            if(i!=j){
                long double dzielnikKonfiguracji = (24/mojeKola[i])*(mojeKola[j]);
                if(dzielnikKonfiguracji == iloscZebow)
                {
                    cout << mojeKola[i] << " / " << mojeKola[j] << endl;
                }
            }
    }
}

}



void oblicz4(){
for (int i = 0; i < iloscKol; i++){
        for (int j = 0; j < iloscKol; j++){
                for (int k = 0; k < iloscKol; k++){
                    for (int l = 0; l < iloscKol; l++){
                            if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
                                long double dzielnikKonfiguracji2 = ((24/mojeKola[i])*(mojeKola[j]/mojeKola[k]) * mojeKola[l]);
                                if(dzielnikKonfiguracji2 < (iloscZebow + blad) && (dzielnikKonfiguracji2 > (iloscZebow - blad)))
                                {
                                    cout << mojeKola[i] << " / " << mojeKola[j] << " | ";
                                    cout << mojeKola[k] << " / " << mojeKola[l] << endl;
                                }
                            }

                    }

                }
        }
}

}


void oblicz4angle(){

long double bladAngle = 0.0000001;
bool find = false;
            while(find == false){
                for (int i = 0; i < iloscKol; i++){
                    for (int j = 0; j < iloscKol; j++){
                            for (int k = 0; k < iloscKol; k++){
                                for (int l = 0; l < iloscKol; l++){
                                            if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l){
                                            long double dzielnikKonfiguracji3 = (mojeKola[i]/mojeKola[j])*(mojeKola[k]/mojeKola[l]);
                                            if(dzielnikKonfiguracji3 < (wynikAngle + bladAngle) && (dzielnikKonfiguracji3 >(wynikAngle - bladAngle)))
                                            {

                                                cout << mojeKola[i] << " / " << mojeKola[j] << " | ";
                                                cout << mojeKola[k] << " / " << mojeKola[l] << endl;

                                                cout << "Z bledem: " << bladAngle;
                                                if (angleAcceptable > bladAngle)
                                                    cout << " -> OK" <<endl;

                                                else if (angleAcceptable <= bladAngle)
                                                    cout << " -> Nieakceptowalny Blad!" <<endl;

                                                system("pause");
                                                cout << endl;
                                                bladAngle += 0.001;
                                            }

                                            }
                                }

                            }
                    }
            }
            bladAngle += 0.0000001;
            }

}


void oblicz6(){

    int licznik = 1;
    for (int i = 0; i < iloscKol; i++){
            for (int j = 0; j < iloscKol; j++){
                    for (int k = 0; k < iloscKol; k++){
                        for (int l = 0; l < iloscKol; l++){
                                 for (int m = 0; m < iloscKol; m++){
                                        for (int n = 0; n < iloscKol; n++){
                                            if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l && i!=m && i!=n && j!=m && j!=n && k!=m && k!=n && l!=m && l!=n){
                                                    double dzielnikKonfiguracji = ((24/mojeKola[i])*(mojeKola[j]/mojeKola[k]) * (mojeKola[m]/mojeKola[n]) * mojeKola[l]);
                                                    if(dzielnikKonfiguracji < (iloscZebow + blad) && (dzielnikKonfiguracji > (iloscZebow - blad)))
                                                    {
                                                        cout << mojeKola[i] << " | " << mojeKola[j] << "/";
                                                        cout << mojeKola[k] << " | " << mojeKola[m] << "/";
                                                        cout << mojeKola[n] << " | " << mojeKola[l] << endl;

                                                            if (licznik == 10)
                                                                    {
                                                                        cout << endl << "Z bledem w ilosci zebow = " << blad << endl;
                                                                        cout << "Wyswietlono 10 pozycji." << endl;
                                                                        cout << "Wcisnij ENTER aby wyswietlic kolejne." << endl << endl;
                                                                        licznik = 0;
                                                                        //licznik++;
                                                                        system("pause");

                                                                    }
                                                                    licznik++;
                                                    }
                                }

                        }

                    }
            }
    }



}
}
}

void pobierzDane(){
    cout << "Podaj ilosc zebow: ";
    cin >> iloscZebow;
    cout << endl;
}

void pobierzDaneAngle(){
    cout << "Podaj kat: ";
    cin >> stopnie;
    cout << "Podaj modul: ";
    cin >> modul;
}

void wynikAnglieFunc(){
    stopniePlus = stopnie + 1;
    stopnie = M_PI * stopnie/180;

    stopniePlus = M_PI * stopniePlus/180;
    long double kat = sin(stopnie);
    long double katPlus = sin(stopniePlus);
    cout << endl <<"Sinus podanego kata wynosi: "<< kat << endl;
    wynikAngle = ((parametr * kat)/modul);
    wynikAnglePlus = ((parametr * katPlus)/modul);
    cout <<"Sprawdzany wynik wynosi: "<< wynikAngle << endl<< endl;
    angleAcceptable = (wynikAnglePlus-wynikAngle) * 0.49 ;
}


void angleMain(){
    //zaktualizuj();
    pobierzDaneAngle();
    wynikAnglieFunc();
    oblicz4angle();
}




void wypiszTab(){
    for (int i = 0; i < 30; i++){
        cout << mojeKola[i] << endl;
    }

}

int main()
{
    angleMain();
    system("pause");
}
