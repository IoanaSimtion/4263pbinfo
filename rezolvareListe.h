#ifndef rezolvareListe.h
#define rezolvareListe.h

#include "lista.h";
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




///todo functie ce returneaza nr de modificari


int nrMinModificari(char* text, char cuv[100][100], int d){

    Lista<int> l;

    int ct=0;

    if(d%2==1){

        return -1;

    }

    for(int i=0;i<d;i++){

        if(strcmp(cuv[i],"if")==0){

            l.add(1);

        }

        if(strcmp(cuv[i],"else")==0){

            l.add(0);

        }

    }

    return ct;

}



void solLista(){

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

            cout<<"Numarul minim de modificari este "<<nrMinModificari(cuv[i],cuv2,dim)<<endl;
		}

	}

}

























#endif // rezolvareListe.h
