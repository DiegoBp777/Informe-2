# Informe 2 / Programación y simulación del microcontrolador PIC18F45K22

**Materia:** Microprocesadores  
**Práctica:** Programación y simulación de un microcontrolador  
**Integrantes:** Los Makias

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

- ## 3. Marco teórico

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
