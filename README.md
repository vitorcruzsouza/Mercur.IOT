EN-US: This content was written in both English and Portuguese. To access content in English, [clique here](#enus)

PT-BR: Este conteúdo foi escrito em Inglês e em Português. Para acessar o conteúdo em Português, [clique aqui](#ptbr)

---

# EN/US
MercurIOT - Sensor Data Transmitter via GSM

## Contents

<!-- toc -->

- [1. Description](#description)
  - [Objective](#objective)
  - [Behind the name](#behind-the-name)
- [2. Plataform](#platform)
  - [Concepts](#concepts)
  - [Technical Specifications](#technical-specifications)
- [3. Circuit Schematic](#circuit-schematic)
- [. ]()
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

Para realizar o envio de informações do sensor à distância, foi escolhido utilizar de tecnologia GSM, a mesma utilizada para comunicação 3G/4G em telefonia móve, devido ao fácil acesso à infraestrutura nacional brasileira de redes móveis e, portanto, alta capacidade de transmissão de dados à longas distâncias.

### Technical Specifications

#### Electronics

##### Control
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

## Circuit Schematic

---
  
# PT/BR
# MercurIOT - Transmissor de Dados de Sensor via GSM

## Conteúdos

<!-- toc -->

- [1. Descrição](#descrição)
  - [Objetivo](#objetivo)
  - [Por trás do nome](#por-trás-do-nome)
- [2. Plataforma](#plataforma)
  - [Conceitos](#conceitos)
  - [Especificações Técnicas](#especificações-técnicas)
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

Para realizar o envio de informações do sensor à distância, foi escolhido utilizar de tecnologia GSM, a mesma utilizada para comunicação 3G/4G em telefonia móve, devido ao fácil acesso à infraestrutura nacional brasileira de redes móveis e, portanto, alta capacidade de transmissão de dados à longas distâncias.

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

## Esquemático do Circuito

---
