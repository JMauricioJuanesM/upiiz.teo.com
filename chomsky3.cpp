#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class chomy{
    public:
    void llenar();
    void mostrar_limpia();
    void generar_chom();
    private:
    string gramatica[70];
    string aux;
    string aux2[10];
    string nuevM[70];
    string norm[70];
    int fil;
    int col;
};

void chomy::llenar(){
    cout<<"cuantas producciones: "<<endl;
    cin>>fil;
    cout<<"introduce las pruducciones: "<<endl;
    for(int i=0; i<fil;i++){
        printf("produccion %i: \n",(i+1));
        cin>>gramatica[i];
        generar_chom();
    }

}

void chomy::mostrar_limpia(){
    puts("la gramtica limpia es: ");
    for(int i=0; i<fil; i++){
        cout<<gramatica[i]<<endl;
    }
}

void chomy::generar_chom(){
    //string norm[70];
    int cont=0;
    char est[1];
    char x[50];
    //leer la matriz para comprobar queno se repitan las reglas generadoras
    cont=0;
    //en este for se haran las proyecciones

    string x3;
    for(int f=0; f<fil;f++){
        col=gramatica[f].length();
        for(int c=0; c<col;c++){
            int cast;
            cast=(int) gramatica[f][c];
            if(cast>=96 && cast<=122){
                x3.clear();
                //cout<<x3<<endl;
                itoa(cont,est,10);
                x3+="A";
                x3+=est;
                x3+="=";
                x3+=gramatica[f][c];
                //strcat(x,x3);
                cout<<x3<<endl;
                norm[cont]=x3;
                cont++;

            }

            }
    }
    //inicializar la matriz para el aux;
    //for(int h=0; h<fil;h++){
    //    col=gramatica
   // }


    //cuando en reglas introducidas se tiene A-->b y se genero A4-->b entonces se deja la que le ingreso el usuario
    int cont2=0;
        for(int f=0; f<fil;f++){
        col=gramatica[f].length();
        for(int c=0; c<col;c++){
                if((gramatica[f][4] ==NULL) && (gramatica[f][3]==norm[f][c]) && (cont2==0)){

                aux=x3;
                cont2++;
                cout<<"la repetida es: "<<aux<<endl;
                }
        }
//)
        }

        //cuando en las reglas se intruduce 2 a , ya no se debe generar una regla para cada a
        int cont3=0;
        for(int f=0; f<fil; f++){
            col=gramatica[f].length();
            for(int c=0;c<col;c++){
                if((((gramatica[f][c]==gramatica[f][c])||(gramatica[f][c]==gramatica[f][c+1]) || (gramatica[f][c]== gramatica[f][c-1])) == norm[f][c]) && (cont3==0)){
                    aux2[f][c]=norm[f][2];
                    cont3++;
                }
            }
        }
        //sustiruir las minusculas respetando lo demás
       for(int f=0; f<fil; f++){
            col=gramatica[f].length();
            for(int c=0; c<col;c++){
                int cast;
            cast=(int) gramatica[f][c];
            //si es minuscula, la cambia por el valor generado
            if((cast>=96 && cast<=122)&& ((gramatica[f][4] ==NULL) && (gramatica[f][3]==norm[f][c]) && (cont2==0)) ){
                    nuevM[f][c]=gramatica[f][3];
            }else if((cast>=96 && cast<=122) && ((gramatica[f][4] ==NULL) && (gramatica[f][3]==norm[f][c]) && (cont2==0)) ){
                    nuevM[c][f]=norm[f][2];
            }else{
            //si no es minuscula, deja lo que tenga mi gramatica dada.
            nuevM[f]=gramatica[f];
            }
           // cout<<nuevM[f][c];
        }
        }
}

int main(void){
    ///menu-----------
    int opc;
    chomy c;
    do{
        cout<<"Introdusca en numero de accion a realizar: "<<endl;
        cout<<"1.- Introducir nueva produccion\n2.- Imprimir gramatica limpia\n3.- Imprimir forma normal de chomsky\n4.- salir..."<<endl;
        cout<<"Que opcion eliges: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                c.llenar();
                break;
            case 2:
                c.mostrar_limpia();
                break;
            case 3:
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }

    }while(opc !=4);
    ///termina menu------
}


