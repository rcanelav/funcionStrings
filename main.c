#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void limpiarScanf()
{
    char descartado;
    scanf("%c", &descartado);
    while(descartado!= '\n')
        scanf("%c", &descartado);
}

void transMayuscula(char cad3[], char letra[])
{
    int i=0;

    if(letra[0]==-61)
        while(cad3[i])
        {
            if(cad3[i] == letra[1])
            {
                cad3[i]=letra[1]-32;


//                    switch(letra[1]){
//                        case -79:
//                            cad[i]=-111;
//                            break;
//                        case -95:
//                            cad[i]=-127;
//                            break;
//                        case -87:
//                            cad[i]=-119;
//                            break;
//                        case -83:
//                            cad[i]=-115;
//                            break;
//                        case -77:
//                            cad[i]=-109;
//                            break;
//                        case -70:
//                            cad[i]=-102;
//                            break;
//                        case -68:
//                            cad[i]=-100;
//                            break;
//                    }
            }
            i++;
        }
    else
    {
        while(cad3[i])
        {
            if(cad3[i]==letra[0])
                cad3[i]=toupper(letra[0]);
            i++;
        }
    }
}

int main()
{
    int i = 0;
    char cad[100]="";
    char cad2[100]="";


    printf("Inserte una frase:\n");
    scanf("%[^\n]s", cad);
    limpiarScanf();
    system("clear");
    printf("Frase introducida en minusculas:\n");
    while(cad[i])
        putchar(tolower(cad[i++]));

    i = 0;
    printf("\n");
    printf("Frase introducida en mayusculas:\n");
    while(cad[i])
        putchar(toupper(cad[i++]));

//---------------------------------------------------
    printf("\n\n---------------------------------------\n\n");
    printf("Introduce un numero: \n");
    scanf("%[^\n]s", cad);
    limpiarScanf();
    int nDec = 0, nPun = 0, nGui = 0;
    i = 0;

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
    if(nDec==i && nDec>0)
        printf("El texto \"%s\" es un numero entero\n",cad);
    else if(nDec+1 == i && nPun == 1 && nDec>=2 && isdigit(cad[0]))
        printf("El texto \"%s\" es un numero real\n",cad);
    else if(nDec == i-1 && nGui == 1 && nDec>0)
        printf("El texto \"%s\" es un numero entero negativo",cad);
    else if(nDec+2 == i && nPun==1 && nGui == 1 && nDec>=2 && isdigit(cad[1]))
        printf("El texto \"%s\" es un numero real negativo",cad);
    else
        printf("El texto \"%s\" no es un numero\n",cad);


//---------------------------------------------------
    printf("\n\n---------------------------------------\n\n");

//Se pide una cadena y un caracter a poner en mayusculas
    strcpy(cad,"");
    strcpy(cad2,"");

    i=0;

    while(getchar()!='\n'); //vacia buffer teclado
    printf("Introduce una cadena de texto:\n");
    scanf("%[^\n]s", cad);

    while(getchar()!='\n'); //vacia buffer teclado
    printf("Introduce un caracter:\n");
//caracter=getchar();
    scanf("%[^\n]s", cad2);

    while(cad[i])
       printf("%d ", cad[i++]);

    printf("\n");
    i=0;
    while(cad2[i])
        printf("%d ", cad2[i++]);
    printf("\n");

    transMayuscula(cad, cad2);
    printf("%s %s\n", cad, cad2);
    if(cad2[0]==-61){
        printf("\"%c",cad2[0]);
        printf("%c\"\n",cad2[1]);
    }else
        printf("\"%c\"\n", cad2[0]);



//---------------------------------------------------
    printf("\n\n---------------------------------------\n\n");

    strcpy(cad, "Hola ");
    strcpy(cad2, "Mundo");
    char cad3[strlen(cad)];
    strcpy(cad3, "");

    printf("\nInicio:\nCad%s\ncad2:%s\nCad3: %s\nLenght: %ld\n",cad, cad2, cad3, strlen(cad));

    strcpy(cad3, cad);
    strcat(cad, cad2);
    strcat(cad3, cad);

    printf("\nFinal:\nCad: %s\ncad2: %s\nCad3: %s\nLenght: %ld\n",cad, cad2, cad3, strlen(cad));

    //---------------------------------------------------
    printf("\n\n---------------------------------------\n\n");

    char nomCom[200];
    strcpy(cad, "Ángel");
    strcpy(cad2, "Vázquez");

    sprintf(nomCom, "%s %s",cad, cad2);
    printf("\nNombre completo: %s", nomCom);

      //---------------------------------------------------
    printf("\n\n---------------------------------------\n\n");

    strcpy(cad, "");
    strcpy(cad2, "");




    while(getchar()!='\n');
    printf("Introduce una cadena de texto:\n");
    scanf("%[^\n]s",cad);

    while(getchar()!='\n');
    printf("Introduce una subcadena de texto a comprobar:\n");
    scanf("%[^\n]s",cad2);

    char *b =strstr(cad,cad2);



    if(b!=NULL){
        printf("\nb: %p\nb: %c", b, *b);
        printf("\ncad: %p\ncad: %c", cad, *cad);
        printf("\nPosicion: %i", (int)(b-cad));
        printf("\nSí contenine\n");
    }
    else
        printf("\nNo contenine\n");

    return 0;
}
