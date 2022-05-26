EN-US: This content was written in both English and Portuguese. To access content in English, [clique here](#enus)

PT-BR: Este conteúdo foi escrito em Inglês e em Português. Para acessar o conteúdo em Português, [clique aqui](#ptbr)

---

# EN/US
# MercurIOT - Sensor Data Transmitter via GSM
v1.4

## Contents

<!-- toc -->

- [1. Description](#description)
  - [Objective](#objective)
  - [Behind the name](#behind-the-name)
- [2. Plataform](#platform)
  - [Concepts](#concepts)
  - [Technical Specifications](#technical-specifications)
  - [Bill of Materials](#bill-of-materials)
- [3. Circuit Schematic](#circuit-schematic)
  - [Full System](#full-system)
  - [Power Supply](#power-supply)
  - [Microcontroller](#microcontroller)
  - [GSM Communication](#gsm-communication)
  - [Sensor 16-bit ADC](#sensor-16bit-adc)
- [4. Printed Circuit Board (PCB)](#printed-circuit-board-pcb)
  - [2D Visualization of All Layers](#2d-visualization-of-all-layers)
- [. ]()
- [. ]()

<!-- tocstop -->

## Description

#### Objective
Fully developing a wireless data transmission solution for industrial applications, capable of sending 500kB of sensing data remotely to be used in machine operation conditions monitoring.

The scope of this project encopasses the development of both the PCB and firmware required for operation of the microcontrollers utilized.

#### Behind the name
Inspired by the greek god Mercury, son of Zeus and messenger of the gods, MercurIOT was developed with the purpose of delivering a flexible platform, upon which multiple IOT communication solutions can be created.


## Platform 

### Concepts

To send sensor information to a distant receiver, the GSM tecnology was selected - the same used for 3G/4G mobile data plans - due to the ease of access to nacional brazillian infrastructure to mobile network systems (where this project was conceived), thus high capacity for long distance tranmissions.



### Technical Specifications

#### Electronics

##### Control
- Microcontrolador: ATmega8U2-MU
- IC USB Communication: ATmega8U2-MU
- IC GSM Communication: SIM7600E-H
##### Power supply
- IC Battery Management: BQ29707DSET
- IC Voltage Regulator: MT3608
- Battery: Li-Ion 18650 cell
##### Sensing
- IC 16-bits Analog-Digital Converter: ADS1115


#### Code

##### Software
- Development Environment: VSCode
- Platform: Plaform.io


### Bill of Materials

*(Link to the Bill of Materials (BOM) file)[https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/blob/main/docs/BOM.md]*

| Nº  |  COMPONENT  | VALUE | PACKAGE | QTY | DESIGNATOR |
| --- | ----------- | ----- | ------- | --- | ---------- |
|  1  | Cmpnt | Val | Pckg | Qty | Dsgntr |
|  2  | Cmpnt | Val | Pckg | Qty | Dsgntr |

## Circuit Schematic

*(Link to the full schematic file)[https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/blob/main/docs/Mercurio_SCHEMATIC-SHEET.pdf]*

### Full System
![circuit_fullTransmitter](https://user-images.githubusercontent.com/105023428/170516663-acb2df9d-1bf1-4365-934f-640ffca4a2db.png)

### Power Supply
![circuit_powerSupply](https://user-images.githubusercontent.com/105023428/170517248-25ec00fd-fefd-4260-bd2e-e3bbc67df707.jpg)

### Microcontroller
![circuit_microcontroller](https://user-images.githubusercontent.com/105023428/170516701-eb2a85f5-869c-4f55-81ec-7cdb06461e7c.jpg)

### GSM Communication
![circuit_GSM](https://user-images.githubusercontent.com/105023428/170516924-0f5be159-4d96-4755-9af3-4f805baac944.jpg)

### Sensor 16bit ADC
![circuit_ADC](https://user-images.githubusercontent.com/105023428/170517353-3410a878-1fdd-434f-bc95-4db8422f6607.jpg)


## Printed Circuit Board (PCB)

### 2D Visualization of All Layers
![PCB_2D_all-layers](https://user-images.githubusercontent.com/105023428/170519094-61a02150-1d5c-445a-834e-b6d0c90607b1.png)


### 2D Visualization of Top Layer
![PCB_2D_top-layer](https://user-images.githubusercontent.com/105023428/170519120-30f621f9-4eb5-49f6-9e1c-a1094c294fae.png)


### 2D Visualization of Bottom Layer
![PCB_2D_bottom-layer](https://user-images.githubusercontent.com/105023428/170519145-8132a9ec-7010-4afc-81d5-780540f8dbac.png)


---
  
# PT/BR
# MercurIOT - Transmissor de Dados de Sensor via GSM
v1.3

## Conteúdos

<!-- toc -->

- [1. Descrição](#descrição)
  - [Objetivo](#objetivo)
  - [Por trás do nome](#por-trás-do-nome)
- [2. Plataforma](#plataforma)
  - [Conceitos](#conceitos)
  - [Especificações Técnicas](#especificações-técnicas)
  - [Lista de Materiais](#lista-de-materiais)
- [3. Esquemático do Circuito](#esquemático-do-circuito)
- [. ]()
- [. ]()
- [. ]()

<!-- tocstop -->

## Descrição

#### Objetivo
O objetivo do projeto MercurIOT é desenvolver uma solução completa de transmissão de dados para aplicações industriais, capaz de enviar 500kB de dados de sensoriamento remotamente, a serem usados no monitoramento de condições de operação de máquinas.

O escopo deste projeto abriga o desenvolvimento de ambos PCI e firmware necessário para operação dos microcontroladores utilizados.

#### Por trás do nome
Inspirado no deus greco-romano Mercúrio, filho de Zeus e mensageiro dos deuses, o MercurIOT foi desenvolvido com o propósito de entregar uma plataforma flexível, sobre a qual múltiplas soluções de comunicação IOT possam ser criadas.

## Plataforma

### Conceitos

Para realizar o envio de informações do sensor à distância, foi escolhido utilizar de tecnologia GSM, a mesma utilizada para comunicação 3G/4G em telefonia móvel, devido ao fácil acesso à infraestrutura nacional brasileira de redes móveis (onde este projeto foi concebido) e, portanto, alta capacidade de transmissão de dados à longas distâncias.

### Especificações Técnicas


#### Eletrônica

##### Controle
- Microcontrolador: ATmega8U2-MU
- CI Comunicação USB: ATmega8U2-MU
- CI Comunicação GSM: SIM7600E-H
##### Alimentação
- CI Gerenciamento de Baterias: BQ29707DSET
- CI Regulador de Tensão: MT3608
- Bateria: Li-Ion 18650
##### Sensoriamento
- CI Conversor Analógico Digital 16-bits: ADS1115

#### Código

##### Software
- Ambiente de Desenvolvimento: VSCode
- Plataforma: Plaform.io


### Lista de Materiais

(Link para o arquivo de Lista de Materiais (BOM))[https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/blob/main/docs/BOM.md]

| Nº  |  COMPONENTE  | VALOR | PACOTE | QTD | DESIGNADOR |
| --- | ------------ | ----- | ------ | --- | ---------- |
|  1  | Cmpnt | Vlr | Pckt | Qtd | Dsgndr |
|  2  | Cmpnt | Vlr | Pckt | Qtd | Dsgndr |



## Esquemático do Circuito

---
