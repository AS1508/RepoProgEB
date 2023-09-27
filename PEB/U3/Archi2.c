#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct datos{
    int numCuenta;
    char nomAp[50];
    float saldo;
};


int leeyvalida(int, int);
int busqueda(struct datos[], int, int);
float valida(float);

int main(){
    FILE *arch;
    struct datos vec[2000], aux;
    int nc, cop, i, x, vd[2000], vc[2000];
    float imp;

    arch=fopen("saldante.dat", "rb");

    if(arch=="NULL"){
        printf("Error");
        exit(1);
    }
    
    fread(&aux, sizeof(struct datos), 1, arch);
    while(!(feof(arch))){
        vec[i]=aux;
        i++;
        fread(&aux, sizeof(aux), 1, arch);
    }
    fclose(arch);

    printf("cliente: ");
    scanf("%d", &nc);

    while(nc!=0){
        x=busqueda(vec, nc, i);
        if(x!=-1){
            cop=leeyvalida(1, 2);
            imp=valida(0);
            if(cop==1){
                vec[x].saldo+=imp;
                vd[x]++;
            }else{
                vec[x].saldo=imp;
                vc[2000];
            }
            printf("numero cliente: ");
            scanf("%d", &nc);
        }
    }
    actualizar(vec, i);
    printf("cuentas sin movimientos\n");
    printf("nro de cuentas\tsaldo\n");
    for(int j=0; j<i; i++){
        if(vd[i]==0 && vc[i]==0){
            printf("%d\t%f\n", vec[i].numCuenta, vec[i].saldo);
        }
    }

    printf("Cuenta con mas de 5 extacciones:\n");
    for(int j=0; j<i; j++){
        if(vc[i]>5){
            printf("%d\n", vec[i].numCuenta);
        }
    }
    
    return 0;
}

int leeyvalida(int li, int ls){
    int x;
    do{
        scanf("%d", &x);

    }while(x<li || x>ls);
    return x;
}
int busqueda(struct datos V[], int x, int cantidad){
    int pos=-1, i=0;
    while(pos!=-1 && i<cantidad){
        if(V[i].numCuenta==x){
            pos=x;
        }else{
            i++;
        }
    }
    return pos;
}
float valida(float lim){
    float x;
    do{
        scanf("%d", &x);
    }while(x<=lim);
    return x;
}




/*
Un Banco tiene un archivo secuencial SALDANTE ordenado por 
numero de cliente con los saldos de sus casi mas de 2mil clientes
de caja de ahorro al inicio del mes.
cada estructura contiene : 
    numero de cuenta de ahorro 
    apellido-nombre
    saldo.
a continuacion se ingresa los siguientes datos con los movimientos del mes:
    numero de cuenta de ahorro
    codigo de operacion (1 deposito / 2 extraccion)
    importe

    Confeccionar un programa que 
        a)Actualice el archivo saldante con los movieminetos registrados
        b) informe las cuentas que en el mes no han tenido movimiento
        con sus respectivos saldos
        c) informe las cuentas que en el mes han realizado mas de 5 
        extracciones

*/ 