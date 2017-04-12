#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float reingresarX(float x){

    printf("Reingrese X: ");
    scanf("%g", &x);
    return x;
}

float reingresarY(float y){

    printf("Reingrese Y: ");
    scanf("%g", &y);
    return y;
}

float sumarXY(float x,float y){

	float resultado = x+y;
    return resultado;
}

float restarXY(float x,float y){

	float resultado = x-y;
    return resultado;
}

float divisionXY(float x,float y){

	float resultado = x/y;
    return resultado;
}

float multiplicarXY(float x,float y){

	float resultado = x*y;
    return resultado;
}

float factorialXY(float x,float y){

    float f = 1;
    for (float i = x ; i > 1 ; i--){
        f = f * i;
    }

    float f2 = 1;
    for (float i = y ; i > 1 ; i--){
        f2 = f2 * i;
    }

    return printf("#X Factorial de %g es %g \n#Y Factorial de %g es %g \n\n", x, f, y, f2);
}
#endif // FUNCIONES_H_INCLUDED
