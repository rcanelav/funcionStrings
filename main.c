#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SUBRAYADO "\e[4m"
#define POR_DEFECTO "\033[0m"

void transMayuscula(char cad3[], char letra[]);
void comprobarSubcadena();
void concatenarStrings();
void sustituirStrings();
void convMayusculas();
void verificarNumeros();
void fraseMayuscula();
char getUserInput();
void opcionesPrograma(char opcion);
void menu();
int main()
{
    char opcion;
    do{
        do{
        menu();
        opcion = getUserInput();
        }while(!opcion);
        opcionesPrograma(opcion);
        if(opcion != '7'){
            printf("\n\n\n\nPresiona cualquier tecla para continuar...\n");
            while(getchar()!='\n');
        }
    }while(opcion != '7');

    return 0;
}


void menu(){
    system("clear");
    printf("\t\t\t#########################################################\n");
    printf("\t\t\t#\t\tBienvenido a esta aplicacion\t\t#\n");
    printf("\t\t\t#\t\t\t\t\t\t\t#\n");
    printf("\t\t\t#\t\t    "SUBRAYADO"Selecciona una opcion"POR_DEFECTO"\t\t#\n");
    printf("\t\t\t#\t\t\t\t\t\t\t#\n");
    printf("\t\t\t#\t\t1.Convertir toLower y toUpper \t\t#\n");
    printf("\t\t\t#\t\t2.Verificacion de numeros\t\t#\n");
    printf("\t\t\t#\t\t3.Convertir letra toUpper\t\t#\n");
    printf("\t\t\t#\t\t4.Sustituir strings\t\t\t#\n");
    printf("\t\t\t#\t\t5.Concatenar strings\t\t\t#\n");
    printf("\t\t\t#\t\t6.Comprobar subcadenas\t\t\t#\n");
    printf("\t\t\t#\t\t7.Salir\t\t\t\t\t#\n");
    printf("\t\t\t#\t\t\t\t\t\t\t#\n");
    printf("\t\t\t#########################################################\n");
}

char getUserInput(){
        printf("\n\nIngrese un numero de opcion:\n");
        char opcion = getchar();
        while(getchar()!='\n');
        if(opcion < '1' || opcion > '7')
            opcion = '\0';

        return opcion;
}

void opcionesPrograma(char opcion){ //Si se convierte a bool, usar return true y false.
   switch(opcion){
    case '1':
        fraseMayuscula();
        break;
    case '2':
        verificarNumeros();
        break;
    case '3':
        convMayusculas();
        break;
    case '4':
        sustituirStrings();
        break;
    case '5':
        concatenarStrings();
        break;
    case '6':
        comprobarSubcadena();
        break;
    case '7':
        printf("Finalizando el programa...\n");
        break;
    default:
        break;
//        return false;

    }
//    return true;
}

void transMayuscula(char cad3[], char letra[])
{
    int j=0;
    if(letra[0]==-61)
        while(cad3[j])
        {
            if(cad3[j]==letra[1])
            {
                cad3[j]=letra[1]-32;  //Sustituye al switch de abajo
                /*				switch(letra[1]){
                					case -79:
                						cad3[j]=-111;
                						break;
                					case -95:
                						cad3[j]=-127;
                						break;
                					case -87:
                						cad3[j]=-119;
                						break;
                					case -83:
                						cad3[j]=-115;
                						break;
                					case -77:
                						cad3[j]=-109;
                						break;
                					case -70:
                						cad3[j]=-102;
                						break;
                					case -68:
                						cad3[j]=-100;
                						break;
                				}
                */
            }
            j++;
        }
    else
    {
        while(cad3[j])
        {
            if(cad3[j]==letra[0])
                cad3[j]=toupper(letra[0]);
            j++;
        }
    }
}

void comprobarSubcadena()
{

    char cad[100]="";
    char cad2[100]="";

    printf("Introduce una cadena de texto:\n");
    scanf("%[^\n]s", cad);
    while(getchar()!='\n');
    printf("Introduce una subcadena de texto a comprobar:\n");
    scanf("%[^\n]s", cad2);
    while(getchar()!='\n');
    char *b=strstr(cad, cad2);

    if(b!=NULL)
    {
        printf("\nb: %p\nb: %c", b, *b);
        printf("\ncad: %p\ncad: %c", cad, *cad);
        printf("\nPosición: %i", (int)(b-cad));
        printf("\nSí contiene\n");
    }
    else
        printf("\nNo contiene\n");
}

void concatenarStrings()
{

    char nomCom[250]="";
    char cad[100];
    char cad2[100];

    printf("Ingrese una frase principal:\n");
    scanf("%[^\n]s",cad);
    while(getchar()!='\n');

    printf("\nIngrese una frase secundaria para concatenar:\n");
    scanf("%[^\n]s",cad2);
    while(getchar()!='\n');

    sprintf(nomCom, "Su frase concatenada es:\n%s %s\n", cad, cad2);
    printf("\n%s\n", nomCom);

}

void sustituirStrings()
{

    char cad[100]="";
    char cad2[100]="";
    strcpy(cad, "Hola ");
    strcpy(cad2, "Mundo");
    char cad3[strlen(cad)];
    strcpy(cad3,"");

    printf("\nInicio:\ncad: \"%s\"\ncad2: \"%s\"\ncad3: \"%s\"\nLength: %ld\n", cad, cad2, cad3, strlen(cad));

    strcpy(cad3, cad);	//copia cad en cad3
    printf("\nIntermedio:\ncad: \"%s\"\ncad2: \"%s\"\ncad3: \"%s\"\n%ld\n", cad, cad2, cad3, strlen(cad));

    strcat(cad, cad2);	//contatena(añade) cad2 al final de cad
    strcat(cad3, cad);
    printf("\nFin:\ncad: \"%s\"\ncad2: \"%s\"\ncad3: \"%s\"\nLength: %ld\n", cad, cad2, cad3, strlen(cad));

}


void convMayusculas()
{

    char cad[100]="";
    char cad2[100]="";

    printf("Introduce una cadena de texto:\n");
    scanf("%[^\n]s", cad);
    while(getchar()!='\n');			//vacia buffer teclado
    printf("Introduce un caracter:\n");
    scanf("%[^\n]s", cad2);
    while(getchar()!='\n');

    transMayuscula(cad, cad2);
    printf("\"%s\" para el caracter ", cad);
    if(cad2[0]==-61)
    {
        printf("\"%c", cad2[0]);
        printf("%c\"\n", cad2[1]);
    }
    else
        printf("\"%c\"\n", cad2[0]);

}


void verificarNumeros()
{

    int nDec=0, nPun=0, nGui=0, i=0;
    char cad[100]="";
    char mensaje1[50];
    char mensajeTotal[200];

    printf("Introduce un numero: \n");
    scanf("%[^\n]s", cad);
    while(getchar()!='\n');
    while(cad[i])
    {
        if(isdigit(cad[i]))
            nDec++;
        else if(cad[i]=='.')
            nPun++;
        else if(cad[i]=='-' && i==0)
            nGui++;
        i++;
    }

    printf("\n--------------------------");
    printf("\nLinea de depuracion");
    printf("\nnDec=%d nPun=%d nGui=%d i=%d", nDec, nPun, nGui, i);
    printf("\n--------------------------\n\n");

    if(nDec==i && nDec>0)
        strcpy(mensaje1, "es un numero entero positivo\n");
    else if(nDec+1==i && nPun==1 && nDec>=2 && isdigit(cad[0]))
        strcpy(mensaje1, "es un numero real positivo\n");
    else if(nDec==i-1 && nGui==1 && nDec>0)
        strcpy(mensaje1, "es un numero entero negativo\n");
    else if(nDec+2==i && nPun==1 && nGui==1 && nDec>=2 && isdigit(cad[1]))
        strcpy(mensaje1, "es un numero real negativo\n");
    else
        strcpy(mensaje1, "no es un numero\n");

    sprintf(mensajeTotal, "El texto \"%s\" %s", cad, mensaje1);
    printf("%s", mensajeTotal);

}

void fraseMayuscula()
{
    char cad[100]="";
    int i=0;
    printf("Introduce una cadena de texto:\n");
    scanf("%[^\n]s", cad);
    while(getchar()!='\n');
    printf("Cadena introducida en minúsculas: ");
    while(cad[i])
        putchar(tolower(cad[i++]));
    printf("\n");

    i=0;
    printf("Cadena introducida en mayúsculas: ");
    while(cad[i])
        putchar(toupper(cad[i++]));
    printf("\n");

}



