#ifndef REZOLVARE_H_INCLUDED
#define REZOLVARE_H_INCLUDED

#include "stiva.h";
#include <string.h>


///todo functie ce afiseaza matricea de cuv

void afisareMatrice(char cuv[100][100], int dim){

    for(int i=0;i<dim;i++){

        cout<<cuv[i]<<endl;

    }

}



///todo functie ce sparge un text in cuvinte


void cuvinte(char* text, char cuv[100][100], int& dim){

    char* p=strtok(text," ");

    while(p!=NULL){

        strcpy(cuv[dim],p);

        p=strtok(NULL," ");

        dim++;

    }

    //afisareMatrice(cuv,dim);

}





///todo functie ce verifica daca scrierea este corecta


bool scriereCorecta(char* text, char cuv[100][100], int& d, int j) {

    d=0;

    cuvinte(text,cuv,d);

    Stiva<int> s;

    for(int i=0;i<d;i++){

        //cout<<cuv[i]<<endl;

        if(strcmp(cuv[i],"if")==0){

            s.push(1);

        }

        if(strcmp(cuv[i],"else")==0){

            if(s.isEmpty()){

                return false;

            }

            s.pop();

        }

    }

    return s.isEmpty();

}





///todo functie ce returneaza nr minim de moficari

int nrMinModificari(char* text, char cuv[100][100], int d, int i){

    int ct=0;

    if(d%2==1){

        return -1;

    }

    Stiva<int> s;

    for(int i=0;i<d;i++){

        //cout<<cuv[i]<<endl;

        if(strcmp(cuv[i],"if")==0){

            s.push(1);

        }

        if(strcmp(cuv[i],"else")==0){

            if(s.isEmpty()){

                s.push(1);

                ct++;

            }
            else{

                s.pop();

            }

        }

    }

    if(ct==1){

        return 1;

    }

    if(!s.isEmpty()){

        //cout<<"aici"<<endl;

        while(!s.isEmpty()){

            s.pop();

            ct++;
        }

    }

    return ct/2;

}




void sol6() {

	int dim;

	char cuv[100][100], cuv2[100][100], n[100];

	cout << "Din cate programe se extrag instructiunuile?" << endl;

	cin.getline(n,100);

	int lungime=stoi(n);

	for (int i = 0; i < lungime; i++) {

		cout << "Introduceti instructiunea extrasa din programul nr " << i + 1<< endl;

        cin.getline(cuv[i],100);

        //cout<<endl<<cuv[i]<<endl;

		if(scriereCorecta(cuv[i],cuv2,dim,i)){

            cout << "Numarul minim de modificari este 0"<<endl;

		}
		else{

            cout<<"Numarul minim de modificari este "<<nrMinModificari(cuv[i],cuv2,dim,i)<<endl;
		}

	}

}












































#endif // REZOLVARE_H_INCLUDED
