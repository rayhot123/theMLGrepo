#include <iostream>
#include <string>

using namespace std;

int main()
{
    
    int a, b, aux, d, e, i, j, cont2;
    float cont;
    string N;
    cont=0; cont2=0;
    bool R;
    R=false;
    //leyendo tamaño de la matriz
    do{
       cin>>a>>b;
       if ((a<=1)||(a>20)||(b>20)||(b<=1)) {cout<<"Dato errado"<<endl;}
       } while ((a<=1)||(a>20)||(b>20)||(b<=1));
    //inicializando matriz
    char Mat[a][b];
		for ( i = 0; i<b; i++)
			for ( j = 0; j< b; j++)
			    Mat[i][j]='#';
			    i=0;
			    j=0;
       //ingresando el mapa		    
   for ( i = 0; i<b; i++)
    {for ( j = 0; j<b; j++){
         do {
             cin>>Mat[i][j];
             if ((Mat[i][j]=='R') && (cont2==1)) { cout<<"Error ya hay 1 robot"<<endl; Mat[i][j]='-';};
             if (Mat[i][j]=='R') {d=i; e=j; cont2=cont2+1;}
             if (Mat[i][j]=='S') {d=i; e=j;}
             
             } while ((Mat[i][j]!='R')&&(Mat[i][j]!='S')&&(Mat[i][j]!='@')&&(Mat[i][j]!='*')&&(Mat[i][j]!='#')&&(Mat[i][j]!='/'));
             }}
         
    do {
        
  
    for ( i = 0; i<b; i++)
    {for ( j = 0; j<b; j++){
             cout<<Mat[i][j]<<" ";
   
         }
         cout<<endl;
         }
         
         do{
        cout<<"Ingrese norte, sur, este, oeste, noroeste, noreste, sureste o suroeste y la cantidad de pasos"<<endl;
        cin>> N >> aux;
        if ((N!="norte")&& (N!="sur")&& (N!="este")&& (N!="oeste")&& (N!="noroeste")&& (N!="noreste")&& (N!="sureste") && (N!="suroeste")) {cout<<"Error"<<endl;}
        if (aux<=0) {cout<<"La cantidad de pasos debe ser mayor a 0"<<endl;}
        } while (((N!="norte")&& (N!="sur")&& (N!="este")&& (N!="oeste")&& (N!="noroeste")&& (N!="noreste")&& (N!="sureste")&&  (N!="suroeste"))||(aux<=0));
    
         if (N=="norte") {
                        d=d-aux;
                        if (d<0) {cout<<"Error"<<endl; d=d+aux;}
                        else { d=d+aux;
                        for (i=0;i<aux; i++) {
                                         if (Mat[d-1][e]=='/') {cout <<"Intente de nuevo"<<endl;}
                                         else if (Mat[d-1][e]=='S') {R=true;}
                                         else if (Mat[d-1][e]=='*') {Mat[d][e]='-'; Mat[d-1][e]='R'; d-=d-1; cont=cont+2;}
                                         else if (Mat[d-1][e]=='-') {Mat[d][e]='-'; d=d-1; Mat[d][e]='R';}
                                         else if (Mat[d-1][e]=='#') {Mat[d][e]='-'; d=d-1; Mat[d][e]='R'; cont=cont+1;}
                                         else if (Mat[d-1][e]=='@') {Mat[d][e]='-'; d=d-1; Mat[d][e]='R'; cont=cont+1.5;}
                                         }}}
         else if (N=="sur") {
                           d=d+aux;
                        if (d>=a) {cout<<"Intente de nuevo"<<endl; d=d+aux;}
                        
                        else {d=d-aux; 
                        
                        for (i=0;i<aux; i++) {
                         if (Mat[d+1][e]=='/') {cout<< "Error"<<endl;}
                                         else if (Mat[d+1][e]=='S') {R=true;}
                                         else if (Mat[d+1][e]=='*') {Mat[d][e]='-'; Mat[d+1][e]='R'; d=d+1; cont=cont+2;}
                                         else if (Mat[d+1][e]=='-') {Mat[d][e]='-'; d=d+1; Mat[d][e]='R';}
                                         else if (Mat[d+1][e]=='#') {Mat[d][e]='-'; d=d+1; Mat[d][e]='R'; cont=cont+1;}
                                         else if (Mat[d+1][e]=='@') {Mat[d][e]='-'; d=d+1; Mat[d][e]='R'; cont=cont+1.5;}
                                         }
                                         } }

         else if (N=="este") {
                           e=e+aux;
                        if (e>=b) {cout<<"Error"<<endl; e=e+aux;}
                      
                        else {   e=e-aux;
                        
                        for (i=0;i<aux; i++) {
                        if (Mat[d][e+1]=='/') {cout <<"error"<<endl;}
                                         else if (Mat[d][e+1]=='S') {R=true;}
                                         else if (Mat[d][e+1]=='*') {Mat[d][e]='-'; Mat[d][e+1]='R'; e=e+1; cont=cont+2;}
                                         else if (Mat[d][e+1]=='-') {Mat[d][e]='-'; e=e+1; Mat[d][e]='R';}
                                         else if (Mat[d][e+1]=='#') {Mat[d][e]='-'; e=e+1; Mat[d][e]='R'; cont=cont+1;}
                                         else if (Mat[d][e+1]=='@') {Mat[d][e]='-'; e=e+1; Mat[d][e]='R'; cont=cont+1.5;}
                                         }}}
         
         else if (N=="oeste") {
                           e=e-aux;
                        if (e<0) {cout<<"Error"<<endl; e=e+aux;}
                      
                        else {   e=e+aux;
                        
                        for (i=0;i<aux; i++) {
                        if (Mat[d][e-1]=='/') {cout <<"error"<<endl;}
                                         else if (Mat[d][e-1]=='S') {R=true;}
                                         else if (Mat[d][e-1]=='*') {Mat[d][e]='-'; Mat[d][e-1]='R'; e=e-1; cont=cont+2;}
                                         else if (Mat[d][e-1]=='-') {Mat[d][e]='-'; e=e-1; Mat[d][e]='R';}
                                         else if (Mat[d][e-1]=='#') {Mat[d][e]='-'; e=e-1; Mat[d][e]='R'; cont=cont+1;}
                                         else if (Mat[d][e-1]=='@') {Mat[d][e]='-'; e=e-1; Mat[d][e]='R'; cont=cont+1.5;}
                                         }
                     } }

         else if (N=="noroeste") {
                           e=e-aux;
                           d=d-aux;
                        if ((e<0) || (d<0)) {cout<<"Error"<<endl; e=e+aux; d=d+aux;}
                      
                        else {   e=e+aux; d=d+aux;
                        
                        for (i=0;i<aux; i++) {
                        if (Mat[d-1][e-1]=='/') {cout <<"error"<<endl;}
                                         else if (Mat[d-1][e-1]=='S') {R=true;}
                                         else if (Mat[d-1][e-1]=='*') {Mat[d][e]='-'; Mat[d-1][e-1]='R'; e=e-1; d=d-1; cont=cont+2;}
                                         else if (Mat[d-1][e-1]=='-') {Mat[d][e]='-'; e=e-1; d=d-1; Mat[d][e]='R';}
                                         else if (Mat[d-1][e-1]=='#') {Mat[d][e]='-'; e=e-1; d=d-1; Mat[d][e]='R'; cont=cont+1;}
                                         else if (Mat[d-1][e-1]=='@') {Mat[d][e]='-'; e=e-1; d=d-1; Mat[d][e]='R'; cont=cont+1.5;}
                                         }  } }
                        
                        
         else if (N=="noreste") {
                           e=e+aux;
                           d=d-aux;
                        if ((e>=b) || (d<0)) {cout<<"Error "<<endl; e=e-aux; d=d+aux;}
                      
                        else {   e=e-aux; d=d+aux;
                        
                        for (i=0;i<aux; i++) {
                        if (Mat[d-1][e+1]=='/') {cout <<"error"<<endl;}
                                         else if (Mat[d-1][e+1]=='S') {R=true;}
                                         else if (Mat[d-1][e+1]=='*') {Mat[d][e]='-'; Mat[d-1][e+1]='R'; e=e+1; d=d-1; cont=cont+2;}
                                         else if (Mat[d-1][e+1]=='-') {Mat[d][e]='-'; e=e+1; d=d-1; Mat[d][e]='R';}
                                         else if (Mat[d-1][e+1]=='#') {Mat[d][e]='-'; e=e+1; d=d-1; Mat[d][e]='R'; cont=cont+1;}
                                         else if (Mat[d-1][e+1]=='@') {Mat[d][e]='-'; e=e+1; d=d-1; Mat[d][e]='R'; cont=cont+1.5;}
                                         }
                                  }
                        }
                        
       else if (N=="sureste") {
                           e=e+aux;
                           d=d+aux;
                        if ((e>=b) || (d>=a)) {cout<<"Error"<<endl; e=e-aux; d=d-aux;}
                      
                        else {   e=e-aux; d=d-aux;
                        
                        for (i=0;i<aux; i++) {
                        if (Mat[d+1][e+1]=='/') {cout <<"error"<<endl;}
                                         else if (Mat[d+1][e+1]=='S') {R=true;}
                                         else if (Mat[d+1][e+1]=='*') {Mat[d][e]='-'; Mat[d+1][e+1]='R'; e=e+1; d=d+1; cont=cont+2;}
                                         else if (Mat[d+1][e+1]=='-') {Mat[d][e]='-'; e=e+1; d=d+1; Mat[d][e]='R';}
                                         else if (Mat[d+1][e+1]=='#') {Mat[d][e]='-'; e=e+1; d=d+1; Mat[d][e]='R'; cont=cont+1;}
                                         else if (Mat[d+1][e+1]=='@') {Mat[d][e]='-'; e=e+1; d=d+1; Mat[d][e]='R'; cont=cont+1.5;}
                                         }
                       
                                              }
                        }
                        
                        
       else if (N=="suroeste") {
                           e=e-aux;
                           d=d+aux;
                        if ((e<0) || (d>=a)) {cout<<"Error"<<endl; e=e+aux; d=d-aux;}
                      
                        else {   e=e+aux; d=d-aux;
                        
                        for (i=0;i<aux; i++) {
                        if (Mat[d+1][e-1]=='/') {cout <<"error"<<endl;}
                                         else if (Mat[d+1][e-1]=='S') {R=true;}
                                         else if (Mat[d+1][e-1]=='*') {Mat[d][e]='-'; Mat[d+1][e-1]='R'; e=e-1; d=d+1; cont=cont+2;}
                                         else if (Mat[d+1][e-1]=='-') {Mat[d][e]='-'; e=e-1; d=d+1; Mat[d][e]='R';}
                                         else if (Mat[d+1][e-1]=='#') {Mat[d][e]='-'; e=e-1; d=d+1; Mat[d][e]='R'; cont=cont+1;}
                                         else if (Mat[d+1][e-1]=='@') {Mat[d][e]='-'; e=e-1; d=d+1; Mat[d][e]='R'; cont=cont+1.5;}
                                         }
                       
                                              }
                        }  
        else {cout<<"Nada"<<endl;}                      
  
        } while (R==false);
        
        for ( i = 0; i<b; i++)
    {for ( j = 0; j<b; j++){
             cout<<Mat[i][j]<<" ";
   
         }
         cout<<endl;
         }
    cout<<"Recolecto: "<<cont<<" puntos"<<endl;


    return 0;
}
