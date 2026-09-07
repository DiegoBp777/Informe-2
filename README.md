# Informe 2 / Programación y simulación del microcontrolador PIC18F45K22

* Diego Alexander Barón Pacheco / 140932
* Fredy Vicente Patiño Garzon / 140753
* Santiago Escamilla Marquez / 140843
---

## Índice

1. [Introducción](#1-introducción)
2. [Objetivos](#2-objetivos)
3. [Marco teórico](#3-marco-teórico)
4. [Herramientas utilizadas](#4-herramientas-utilizadas)
5. [Microcontrolador PIC18F45K22](#5-microcontrolador-pic18f45k22)
6. [Configuración del proyecto en MPLAB X](#6-configuración-del-proyecto-en-mplab-x)
7. [Desarrollo del programa](#7-desarrollo-del-programa)
8. [Simulación en Proteus](#8-simulación-en-proteus)
9. [Funcionamiento del programa](#9-funcionamiento-del-programa)
10. [Evidencias](#10-evidencias)
11. [Resultados](#11-resultados)
12. [Dificultades encontradas](#12-dificultades-encontradas)
13. [Conclusiones](#13-conclusiones)

---

## 1. Introducción

En este laboratorio se realizó la programación y simulación del microcontrolador **PIC18F45K22**, utilizando de manera conjunta los programas **MPLAB X IDE** y **Proteus**.

El objetivo principal fue desarrollar un programa en lenguaje C utilizando el compilador XC8, configurar el oscilador interno del microcontrolador a una frecuencia de 1 MHz y utilizar uno de los pines del puerto D como salida digital.

Para comprobar el funcionamiento del programa, el código desarrollado en MPLAB fue compilado para generar el archivo necesario para la simulación. Posteriormente, dicho programa fue cargado en el modelo del PIC18F45K22 dentro de Proteus.

La aplicación desarrollada consiste en controlar un LED conectado al pin **RD0**. El LED se enciende durante 500 ms y posteriormente se apaga durante otros 500 ms, generando un parpadeo periódico.

De esta manera, el laboratorio permitió integrar el desarrollo del software del microcontrolador con su representación y simulación del circuito electrónico en Proteus.

---

## 2. Objetivos

### 2.1 Objetivo general

Programar y simular el funcionamiento del microcontrolador PIC18F45K22 utilizando MPLAB X IDE y Proteus.

### 2.2 Objetivos específicos

- Crear un proyecto para el PIC18F45K22 en MPLAB X IDE.
- Configurar el microcontrolador utilizando el compilador XC8.
- Configurar el oscilador interno a una frecuencia de 1 MHz.
- Configurar el pin RD0 del puerto D como salida digital.
- Controlar un LED mediante el pin RD0.
- Implementar retardos de 500 ms utilizando las funciones de XC8.
- Compilar el programa desarrollado en MPLAB.
- Cargar el programa compilado en el microcontrolador dentro de Proteus.
- Comprobar mediante simulación el funcionamiento del programa.

## 3. Marco teórico

### 3.1 Microcontroladores

Un microcontrolador es un dispositivo electrónico que integra en un solo circuito una unidad de procesamiento, memoria y diferentes periféricos de entrada y salida.

Estos dispositivos permiten desarrollar sistemas embebidos capaces de controlar LEDs, motores, sensores, displays, comunicaciones y diferentes dispositivos electrónicos.

En este laboratorio se utiliza el microcontrolador PIC18F45K22 como unidad principal del sistema.

---

### 3.2 PIC18F45K22

El PIC18F45K22 pertenece a la familia de microcontroladores PIC18 de Microchip.

El dispositivo cuenta con diferentes puertos de entrada y salida digitales, entre ellos los puertos A, B, C, D y E.

En el desarrollo de este laboratorio se utiliza específicamente el **PORTD**, debido a que el pin RD0 será utilizado para controlar el LED.

El datasheet indica que PORTD es un puerto bidireccional de 8 bits y que sus pines pueden configurarse individualmente como entradas o salidas mediante el registro TRISD. :contentReference[oaicite:2]{index=2}

---

### 3.3 Oscilador interno

El PIC18F45K22 dispone de un sistema de oscilador interno que permite seleccionar diferentes frecuencias de funcionamiento.

El datasheet especifica que el registro `OSCCON` controla diferentes aspectos relacionados con el reloj del dispositivo y que los bits `IRCF` permiten seleccionar la frecuencia del oscilador interno. :contentReference[oaicite:3]{index=3}

Para este laboratorio se utiliza una frecuencia de:

```text
1 MHz
```
La frecuencia se establece mediante la configuración del oscilador interno.

---

### 3.4 Registro TRISD

El registro *TRISD* permite determinar si los pines del PORTD funcionarán como entradas o salidas.

La configuración utilizada en el laboratorio es:

```text
TRISD0 = 0
```
Cuando un bit de TRISD se establece en **0**, el pin correspondiente funciona como salida. Cuando se establece en **1**, funciona como entrada.
Por lo tanto:
```text
TRISD0 = 0
```
permite utilizar RD0 para controlar el LED.

---

### 3.5 Registro ANSELD

El registro **ANSELD** permite configurar los pines del puerto D para trabajar como entradas analógicas o digitales.

Para utilizar RD0 como salida digital se desactivan las funciones analógicas del puerto mediante:
```text
ANSELD = 0;
```
El datasheet muestra que los pines del PORTD poseen funciones digitales y analógicas multiplexadas, por lo que es necesario realizar la configuración correspondiente para utilizar el pin como salida digital.

---

### 3.6 Registro LATD

El registro LATD permite controlar el estado de salida del PORTD.

En este laboratorio se utiliza:

```text
LATDbits.LATD0
```

para establecer el estado lógico del pin RD0.

Cuando:
```text
LATDbits.LATD0 = 1;
```
el pin RD0 se coloca en nivel lógico bajo.

El datasheet describe LATD como el registro de latch de salida asociado al PORTD.

---

## 4. Herramientas utilizadas

Para el desarrollo del laboratorio se utilizaron las siguientes herramientas:

| Herramienta | Función |
|---|---|
| MPLAB X IDE | Desarrollo y compilación del programa |
| XC8 | Compilador utilizado para el código en lenguaje C |
| Proteus | Diseño y simulación del circuito |
| PIC18F45K22 | Microcontrolador utilizado |
| Computador | Plataforma para el desarrollo del laboratorio |

---

## 5. Microcontrolador PIC18F45K22

El componente principal utilizado en la simulación es el **PIC18F45K22**.

En Proteus se seleccionó el modelo correspondiente al microcontrolador y se configuró para ejecutar el programa generado desde MPLAB.

---

### 5.1 Pin utilizado

Para este laboratorio se utilizó el pin:

```text
RD0
```

Este pin pertenece al PORTD del microcontrolador.

La documentación del PIC18F45K22 identifica RD0 como una de las líneas del PORTD y permite configurarla como salida digital mediante el registro TRISD.

---

### 5.2 Funcionamiento del pin RD0

El pin RD0 se utiliza como salida para controlar un LED.

La lógica implementada es:

```text
RD0 = 1  → LED encendido

RD0 = 0  → LED apagado
```
---

## 6. Configuración del proyecto en MPLAB X

El programa fue desarrollado utilizando MPLAB X IDE y el compilador XC8.

Para realizar el proyecto se seleccionó el microcontrolador:

```text
PIC18F45K22
```

Posteriormente se creó el archivo principal:

```text
main.c
```
En este archivo se incluyeron las configuraciones necesarias para el oscilador y el funcionamiento del puerto D.

---

### 6.1 Configuración del oscilador

Se utilizaron los siguientes bits de configuración:
```text
#pragma config FOSC = INTIO67
#pragma config WDTEN = OFF
#pragma config LVP = OFF
```
La configuración:
```text
FOSC = INTIO67
```
permite utilizar el oscilador interno.

El watchdog fue desactivado mediante:
```text
WDTEN = OFF
```
y la programación en baja tensión fue desactivada mediante:
```text
LVP = OFF
```
---

### 6.2 Frecuencia utilizada

Se definió:
```text
#define _XTAL_FREQ 1000000
```
Esto indica al compilador que la frecuencia de reloj utilizada por el programa es de:
```text
1 MHz
```
Esta definición es importante para que las funciones de retardo de XC8, como __delay_ms(), puedan calcular correctamente los tiempos.

---

## 7. Desarrollo del programa

El programa utilizado durante la práctica fue el siguiente:
```text
#include <xc.h>

// Configuración del oscilador interno a 1 MHz
#pragma config FOSC = INTIO67
#pragma config WDTEN = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 1000000

void main(void) {

    // Configuración del oscilador a 1 MHz
    OSCCON = 0b10000000;

    // Configuración del pin RD0 como salida digital
    ANSELD = 0;
    TRISDbits.TRISD0 = 0;

    while(1) {

        LATDbits.LATD0 = 1;
        __delay_ms(500);

        LATDbits.LATD0 = 0;
        __delay_ms(500);
    }

    return;
}
```
---

### 7.1 Inclusión de la librería

La primera línea del programa es:
```text
#include <xc.h>
```
Esta librería permite utilizar las definiciones y registros específicos del microcontrolador seleccionado.

---

### 7.2 Configuración del oscilador

El programa utiliza:
```text
OSCCON = 0b10000000;
```
para configurar el funcionamiento del oscilador interno.

El PIC18F45K22 dispone de un bloque de oscilador interno y el datasheet indica que la frecuencia puede seleccionarse mediante los bits de selección de frecuencia del sistema.

---

### 7.3 Configuración del puerto

Primero se deshabilitan las funciones analógicas:
```text
ANSELD = 0;
```
Posteriormente se configura RD0 como salida:
```text
TRISDbits.TRISD0 = 0;
```
De esta manera, RD0 queda preparado para controlar el LED.

---

### 7.4 Encendido del LED

Dentro del ciclo infinito se establece:
```text
LATDbits.LATD0 = 1;
```
Esto coloca RD0 en nivel lógico alto.

Después se ejecuta:
```text
__delay_ms(500);
```
generando un retardo de 500 milisegundos.

---

### 7.5 Apagado del LED

Posteriormente se ejecuta:
```text
LATDbits.LATD0 = 0;
```
con lo cual RD0 pasa a nivel lógico bajo.

Después se vuelve a realizar un retardo:
```text
__delay_ms(500);
```
El ciclo vuelve a comenzar debido al while(1).

---

## 8. Simulación en Proteus

Una vez desarrollado y compilado el programa en MPLAB X, el archivo generado por el compilador fue utilizado para programar virtualmente el PIC18F45K22 dentro de Proteus.

El circuito de simulación contiene el microcontrolador y los elementos necesarios para observar el comportamiento de la salida RD0.

---

### 8.1 Carga del programa

En las propiedades del PIC18F45K22 dentro de Proteus se seleccionó el archivo generado por MPLAB.

De esta manera, Proteus ejecuta el programa compilado dentro del modelo virtual del microcontrolador.

---

### 8.2 Circuito utilizado

El pin RD0 se conecta al LED utilizado como elemento de visualización.

La estructura básica del sistema es:

```text
             PIC18F45K22
                  │
                  │ RD0
                  │
                  ▼
                 LED
                  │
                 GND
```
---

## 9. Funcionamiento del programa

El funcionamiento del sistema puede resumirse mediante la siguiente secuencia:
```text    
INICIO
   │
   ▼
Configurar oscilador
a 1 MHz
   │
   ▼
Configurar RD0
como salida digital
   │
   ▼
Encender LED
   │
   ▼
Esperar 500 ms
   │
   ▼
Apagar LED
   │
   ▼
Esperar 500 ms
   │
   └──────────────► Repetir
```

Por lo tanto, el LED permanece aproximadamente:
```text  
500 ms encendido
+
500 ms apagado
```
produciendo un ciclo completo de aproximadamente:
```text 
1 segundo
```
y una frecuencia de parpadeo aproximada de:
```text 
1 Hz
```
---

## 10. Evidencias

### 10.1 Microcontrolador PIC18F45K22 en Proteus

En la siguiente evidencia se muestra la selección y configuración del microcontrolador PIC18F45K22 dentro de Proteus.

<img src="Imagenes/pic18f45k22_proteus.png" width="800">

**Figura 1. Microcontrolador PIC18F45K22 configurado en Proteus.**

---

### 10.2 Código desarrollado en MPLAB X

En esta evidencia se presenta el código desarrollado en MPLAB X IDE utilizando el compilador XC8.

<img src="Imagenes/codigo_mplab.png" width="800">

**Figura 2. Código desarrollado en MPLAB X IDE.**

---

## 11. Resultados

Los resultados obtenidos durante la simulación permitieron comprobar el funcionamiento correcto del programa desarrollado.

El microcontrolador ejecutó las instrucciones programadas y utilizó el pin RD0 como salida digital.

El comportamiento observado fue:

| Estado | RD0 | LED |
|---|---:|---|
| Encendido | 1 | Encendido |
| Apagado | 0 | Apagado |

El cambio entre los dos estados se realiza cada 500 ms, obteniendo un ciclo completo de aproximadamente un segundo.

De esta manera se verificó que la configuración del oscilador, la configuración del puerto y las instrucciones de retardo funcionan correctamente en la simulación.

---

## 12. Dificultades encontradas

Durante el desarrollo de la práctica fue necesario prestar especial atención a la configuración del microcontrolador tanto en MPLAB X como en Proteus.

Una de las principales dificultades consistió en comprender la relación entre el código desarrollado en MPLAB y el modelo del microcontrolador utilizado en Proteus.

También fue necesario configurar correctamente la frecuencia de operación mediante el oscilador interno y definir `_XTAL_FREQ`, ya que esta información es utilizada por las funciones de retardo del compilador XC8.

Otra dificultad fue configurar correctamente el pin RD0 como salida digital. Para ello fue necesario deshabilitar las funciones analógicas mediante `ANSELD` y configurar el bit correspondiente de `TRISD`.

Finalmente, fue necesario comprobar que el archivo generado después de la compilación en MPLAB fuera correctamente cargado en el microcontrolador de Proteus.

---

## 13. Conclusiones

El desarrollo de este laboratorio permitió comprender el proceso básico de programación de un microcontrolador PIC18F45K22 utilizando MPLAB X IDE y el compilador XC8.

Se logró configurar el oscilador interno del microcontrolador a una frecuencia de 1 MHz y utilizar el pin RD0 como salida digital para controlar un LED.

La utilización conjunta de MPLAB y Proteus permitió relacionar el desarrollo del programa con el comportamiento físico del circuito, ya que el código generado en MPLAB pudo ser ejecutado posteriormente dentro de la simulación.

La práctica también permitió comprender la importancia de configurar correctamente los registros del microcontrolador, especialmente `OSCCON`, `ANSELD`, `TRISD` y `LATD`.

Finalmente, se comprobó mediante simulación que el LED puede ser controlado mediante software, encendiéndose durante 500 ms y apagándose durante 500 ms de manera repetitiva.
