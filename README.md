EN-US: This content was written in both English and Portuguese. To access content in English, [clique here](#enus)

PT-BR: Este conteúdo foi escrito em Inglês e em Português. Para acessar o conteúdo em Português, [clique aqui](#ptbr)

---

# EN/US
# MercurIOT - Sensor Data Transmitter via GSM
readme v1.6

## Contents

<!-- toc -->

- [1. Description](#description)
  - [Objective](#objective)
  - [Behind the name](#behind-the-name)
- [2. Plataform](#platform)
  - [Conceptualization - Electronics](#conceptualization---electronics)
  - [Conceptualization - Code](#conceptualization---code)
  - [Technical Specifications](#technical-specifications)
  - [Bill of Materials](#bill-of-materials)
- [3. Circuit Schematic](#circuit-schematic)
  - [Full System](#full-system)
  - [Power Supply](#power-supply-and-battery-charging)
  - [Microcontroller](#microcontroller)
  - [GSM Communication](#gsm-communication)
  - [Sensor 16-bit ADC](#sensor-16bit-adc)
- [4. Printed Circuit Board (PCB)](#printed-circuit-board-pcb)
  - [2D Visualization of All Layers](#2d-visualization-of-all-layers)
  - [2D Visualization of Top Layer](#2d-visualization-of-top-layer)
  - [2D Visualization of Bottom Layer](#2d-visualization-of-bottom-layer)
- [5. 3D Render of the PCB](#3d-render-of-the-pcb)
  - [Top View](#top-view)
  - [Bottom View](#bottom-view)
  - [Isometric View](#isometric-view)


- [About me](#about-me)

<!-- tocstop -->

## Description

#### Objective
Fully developing a wireless data transmission solution for industrial applications, capable of sending 500kB of sensing data remotely to be used in machine operation conditions monitoring.

The scope of this project encopasses the development of both the PCB and firmware required for operation of the microcontrollers utilized.

#### Behind the name
Inspired by the greek god Mercury, son of Zeus and messenger of the gods, MercurIOT was developed with the purpose of delivering a flexible platform, upon which multiple IOT communication solutions can be created.


## Platform 

### Conceptualization - Electronics:

To send sensor information to a distant receiver, the **GSM tecnology** was selected - the same used for 3G/4G mobile data plans - due to the ease of access to nacional brazillian infrastructure to mobile network systems (where this project was conceived), thus high capacity for long distance tranmissions.

Therefore, the **SIM7600EH** GSM communication chip was chosen, since it presents an easy to use yet powerful list of commands, high market availability and broad documentation.

For controlling the whole system and being responsible for converting the sensor data into commands the SIM7600 can understand, the Atmel **ATMEGA8U2-MU** was selected as a suitable microcontroller. Aside from having very broad documentation and market availability for being one the chips used by Arduino boards, the ATMEGA8 is specially handy for having integrated USB communication, simplifying the final board layout. Its 16MHz clock shall be sufficient to execute all of the communication with no major delays.

One of the limitations of the ATMEGA8, however, is the relatively low resolution of its ADC (Analog to Digital Converter chip), which has a 10 bit resolution (maximum of 1024 individual values in any readings). Therefore, an accompanying **ADS1115** chip was selected to improve the data quality the MercurIOT board can supply. This IC has a 16 bit resolution (max. 65,536 values) for analog readings, it can communicate in I2C protocol with other chips in its network, and can support up to 4 individual analog inputs. For this project, however, we're only going to use one.

Finally, to power the whole system, a **18650 Lithium-Ion** cell was selected, since this type of battery chemistry is very common and is currently one of the best options on Power Density to Price and/or size. Utilizing Li-Ion cells in this project allows it to be recharged, but adds a degree of complexity by requiring some battery monitoring and protection features. For this, the **BQ29707DSET** battery management IC is being used (features include overcharge protection, overdischarge protection, overcurrent protection) in conjunction with the **MT3608** boost-converter for stabilizing a 5VDC supply rail to all other electronics.

### Conceptualization - Code:

To construct a wireless transmission solution, there are a few major things that have to be considered. The first is what information is going to be sent, the second is how it is going to be sent, and third but not least how it is going to be interpreted by what's receiving it.

This way, the first problem that need to be tackled is the **information source** itself. In this project, for demonstration purposes, a hypothetical, unspecified, pre-amplified analog sensor is going to be used, as this is encopasses almost any type of application that telemetry sensors can be used in, since most physical quantity sensing devices output analog (voltage or current) signals.

Since a 16-bit capabe Analog to Digital Converter (ADC) is being used to capture these sensed signals, these 16-bit values have to be processed accordingly. For that, the Adafruit_ADS1015.h library is used, to facilitate I2C communication between the microcontroller and the ADC unit and to interpret the information.

Assuming a server is going to receive sensed data and utilize it, this processed information need to be sent via some medium. For this, the SIM7600EH chip has a list of GSM commands to perform varying tasks. If sent from the microcontroller to the GSM IC via serial UART communication, these commands will each perform an action through the 3G/4G communication line. [Here's a full list of AT commands and instructions on how to use them here.](https://usermanual.wiki/Document/SIM7500SIM760020SeriesAT20Command20ManualV107.443047306/html)

The information that is going to be transmitted, however, needs to be encoded in a certain protocol, so that both parties of this system - client (transmitter) and server (receiver) - can understand what is being relayed; and more critically, know what to do with each information given.

For this, the MQTT (Message Queuing Telemetry Transport) is used. It is a protocol based on TCP/IP network communication that simplifies parallel data transmission between multiple parties, specially for IoT applications such as this one, while providing a light and simple framework for less powerful devices to run on. [Read this for more information on how the MQTT protocol works.](https://randomnerdtutorials.com/what-is-mqtt-and-how-it-works/)

Joining the AT (GSM) and MQTT communication formats, we can compile the data collected by whichever sensor is plugged into the MercurIOT transmitter, and send it to a MQTT topic dedicated to captured sensor data, which then can be subscribed to by any software or BI (Business Inteligence) suite that whishes to utilize or display that information.

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
- Library Adafruit_ADS1015.h (for I2C communication with the 16bit ADC)
- Library SoftwareSerial.h (for serial UART communication with the GSM and MQTT)
- Libraries Arduino.h, Wire.h e ArduinoLowPower.h (for using the native Arduino platform functionalities)
##### Software
- Development Environment: VSCode
- Platform: Plaform.io


### Bill of Materials

[Link to the Bill of Materials file, complete with links for ordering the parts used globally.](https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/blob/main/docs/BOM.md)


## Circuit Schematic
[Link to folder with circuit and PCB ECAD files.](https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/tree/main/hardware_sch/Mercurio_wirelessTransmitter)


### Full System
[Link to the full schematic file.](https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/blob/main/docs/Mercurio_SCHEMATIC-SHEET.pdf)
![circuit_fullTransmitter](https://user-images.githubusercontent.com/105023428/170516663-acb2df9d-1bf1-4365-934f-640ffca4a2db.png)

### Power Supply and Battery Charging
![circuit_powerSupply](https://user-images.githubusercontent.com/105023428/170517248-25ec00fd-fefd-4260-bd2e-e3bbc67df707.jpg)

The circuit above utilizes a BQ2970 battery management IC to monitor the lithium-ion battery's voltage and offer multiple protections. By utilizing a selection of multiple internal comparators, the IC monitors the voltage coming from the positive side of the battery through the "BAT" pin 5. Either when the voltage is too high (±4.2V), too low (±3.4V) or the current is too high (overcurrent or short-circuit), the IC deactivates of its "COUT" or "DOUT" outputs to disconnect the battery's negative side to Ground, through its two CSD16301Q2 MOSFET switches.

Through the use of the MT3608 boost converter IC, both the battery's and the USB port's voltage are steped-up and regulated to 5VDC, for supplying both the ATMEGA and the SIM7600 chips. By using a zener diode between the USB port and the battery, as well as one between the boost converter an all of the componentes supplied, the circuit can be both powered on by the USB port and charge the battery simultaneously without causing a power loop.

### Microcontroller
![circuit_microcontroller](https://user-images.githubusercontent.com/105023428/170516701-eb2a85f5-869c-4f55-81ec-7cdb06461e7c.jpg)

Together with the microcontroller are a couple of passive components to allow its basic functioning, like a 16MHz clock crystal and accompanying oscillating capacitors, varistors for USB power protection and a ferrite bead for filtering, a 500mA fuse between the power circuit and the VCC port of the ATMEGA chip, a RESET button and 6 open pins (ICSP) for connecting configuration signals, such as boot loading and resetting once again.

### GSM Communication
![circuit_GSM](https://user-images.githubusercontent.com/105023428/170516924-0f5be159-4d96-4755-9af3-4f805baac944.jpg)

In this schematic, two S8050 transistors can be observed in series with the TXD and RXD transmission lines that are used to connect the SIM7600E-H and the ATMEGA8U-MU via UART. This is used to decouple both chips while no data is being transmitted, since the very TXD and RXD lines activate the transistors that let the data bits pass, so that these wires do not act as antennas and pickup any interference, stopping any of the two ICs accidentally interpret noise as information.

Pins 17 - 20 are connected to the SIM card slot and therefore the SIM card inserted, and pin 82 is connected to a SMA antenna connector, so that any type or size of antenna desired can be used.

The "PWRKEY" and "RESET" are pulled to ground so that the IC is always active. One improvement this circuit design could benefit from is having the microcontroller, via a switching device, have the option to activate or deactivate both the Reset and Power-Key pins so that the IC can be rebooted or turned off completely for power saving measures.

### Sensor 16bit ADC
![circuit_ADC](https://user-images.githubusercontent.com/105023428/170517353-3410a878-1fdd-434f-bc95-4db8422f6607.jpg)

Last but not least, the ADS1115 16-bit ADC is connected to the SCL and SCA pins of the ATMEGA microcontroller, through which the ADC relays the sensed analog  signals through I2C serial communication. The sensor, whichever one may be chosen for the application, can be connected to the J4 screw terminal following the "VCC, Signal, GND" pinout standard.

## Printed Circuit Board (PCB)

### 2D Visualization of All Layers
![PCB_2D_all-layers](https://user-images.githubusercontent.com/105023428/170519094-61a02150-1d5c-445a-834e-b6d0c90607b1.png)

For information all data lines excluding the antenna line, the traces were set to 10 mils (0.254 mm). For all other lines (power lines and antenna), the traces were set to 20 mils (0.5 mm), so that a maximum of 1.5 A can be supplied to all components and used for more power-intensive LTE data transmission.

### 2D Visualization of Top Layer
![PCB_2D_top-layer](https://user-images.githubusercontent.com/105023428/170519120-30f621f9-4eb5-49f6-9e1c-a1094c294fae.png)


### 2D Visualization of Bottom Layer
![PCB_2D_bottom-layer](https://user-images.githubusercontent.com/105023428/170519145-8132a9ec-7010-4afc-81d5-780540f8dbac.png)

## 3D Render of the PCB

### Top View
![PCB_3D_top](https://user-images.githubusercontent.com/105023428/170576988-4409c4e1-7735-4c61-aefd-b54d3322d514.png)


### Bottom View
![PCB_3D_bottom](https://user-images.githubusercontent.com/105023428/170577000-cf88dd5f-4d19-4837-893f-6bca912a0154.png)

### Isometric View
![PCB_3D_isometric](https://user-images.githubusercontent.com/105023428/170577027-161c6428-ceea-4df5-9858-79c2b94e7935.png)


## About me

### Contact info:
<p>Vitor Cruz Souza<br>
São Paulo, SP, Brazil<br>
E-mail: vitor.cruz.souza.2001@gmail.com</p>

---

[Back to the top.](#contents)

---

  
# PT/BR
# MercurIOT - Transmissor de Dados de Sensor via GSM
readme v1.52

(Esta sessão ainda não foi totalmente traduzida).

## Conteúdos

<!-- toc -->

- [1. Descrição](#descrição)
  - [Objetivo](#objetivo)
  - [Por trás do nome](#por-trás-do-nome)
- [2. Plataforma](#plataforma)
  - [Conceitualização](#conceitualização)
  - [Especificações Técnicas](#especificações-técnicas)
  - [Lista de Materiais](#lista-de-materiais)
- [3. Esquemático do Circuito](#esquemático-do-circuito)
  - [Sistema Completo](#sistema-completo)
  - [Alimentação e Bateria](#alimentação-e-bateria)
  - [Microcontrolador](#microcontrolador)
  - [Comunicação GSM](#comunicação-gsm)
  - [ADC 16bits do Sensor](#adc-16bits-do-sensor)
- [4. Placa de Circuito Impresso (PCI)](#placa-de-circuito-impresso-pci)
  - [Visualização 2D de Todas as Camadas](#visualização-2d-de-todas-as-camadas)
  - [Visualização 2D da Camada Superior](#visualização-2d-da-camada-superior)
  - [Visualização 2D da Camada Inferior](#visualização-2d-da-camada-inferior)
- [5. Renderização 3D da PCI](#renderização-3d-da-pci)
  - [Vista Superior](#vista-superior)
  - [Vista Inferior](#vista-inferior)
  - [Vista Isométrica](#vista-isométrica)

- [Sobre mim](#sobre-mim)

<!-- tocstop -->

## Descrição

#### Objetivo
O objetivo do projeto MercurIOT é desenvolver uma solução completa de transmissão de dados para aplicações industriais, capaz de enviar 500kB de dados de sensoriamento remotamente, a serem usados no monitoramento de condições de operação de máquinas.

O escopo deste projeto abriga o desenvolvimento de ambos PCI e firmware necessário para operação dos microcontroladores utilizados.

#### Por trás do nome
Inspirado no deus greco-romano Mercúrio, filho de Zeus e mensageiro dos deuses, o MercurIOT foi desenvolvido com o propósito de entregar uma plataforma flexível, sobre a qual múltiplas soluções de comunicação IOT possam ser criadas.

## Plataforma

### Conceitualização

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
- Biblioteca Adafruit_ADS1015.h (para comunicação I2C com o ADC de 16bits)
- Biblioteca SoftwareSerial.h (para comunicação serial UART com o GSM e MQTT)
- Bibliotecas Arduino.h, Wire.h e ArduinoLowPower.h (para uso de funcionalidades nativas da plataforma Arduino)

##### Software
- Ambiente de Desenvolvimento: VSCode
- Plataforma: Plaform.io


### Lista de Materiais

[Link para a Lista de Materiais contendo também links para compra internacional dos componentes usados.](https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/blob/main/docs/BOM.md)


## Esquemático do Circuito
[Link para pasta com arquivos ECAD do circuito e PCB.](https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/tree/main/hardware_sch/Mercurio_wirelessTransmitter)

### Sistema Completo
[Link para o arquivo do esquemático completo.](https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/blob/main/docs/Mercurio_SCHEMATIC-SHEET.pdf)
![circuit_fullTransmitter](https://user-images.githubusercontent.com/105023428/170516663-acb2df9d-1bf1-4365-934f-640ffca4a2db.png)

### Alimentação e Bateria
![circuit_powerSupply](https://user-images.githubusercontent.com/105023428/170517248-25ec00fd-fefd-4260-bd2e-e3bbc67df707.jpg)

### Microcontrolador
![circuit_microcontroller](https://user-images.githubusercontent.com/105023428/170516701-eb2a85f5-869c-4f55-81ec-7cdb06461e7c.jpg)

### Comunicação GSM
![circuit_GSM](https://user-images.githubusercontent.com/105023428/170516924-0f5be159-4d96-4755-9af3-4f805baac944.jpg)

### ADC 16bits do Sensor
![circuit_ADC](https://user-images.githubusercontent.com/105023428/170517353-3410a878-1fdd-434f-bc95-4db8422f6607.jpg)


## Placa de Circuito Impresso (PCI)
[Link para pasta com arquivos ECAD do circuito e PCB.](https://github.com/vitorcruzsouza/Mercur.IOT_TRACTIAN/tree/main/hardware_sch/Mercurio_wirelessTransmitter)

### Visualização 2D de Todas as Camadas
![PCB_2D_all-layers](https://user-images.githubusercontent.com/105023428/170519094-61a02150-1d5c-445a-834e-b6d0c90607b1.png)


### Visualização 2D da Camada Superior
![PCB_2D_top-layer](https://user-images.githubusercontent.com/105023428/170519120-30f621f9-4eb5-49f6-9e1c-a1094c294fae.png)


### Visualização 2D da Camada Inferior
![PCB_2D_bottom-layer](https://user-images.githubusercontent.com/105023428/170519145-8132a9ec-7010-4afc-81d5-780540f8dbac.png)

## Renderização 3D da PCI

### Vista Superior
![PCB_3D_top](https://user-images.githubusercontent.com/105023428/170576988-4409c4e1-7735-4c61-aefd-b54d3322d514.png)


### Vista Inferior
![PCB_3D_bottom](https://user-images.githubusercontent.com/105023428/170577000-cf88dd5f-4d19-4837-893f-6bca912a0154.png)

### Vista Isométrica
![PCB_3D_isometric](https://user-images.githubusercontent.com/105023428/170577027-161c6428-ceea-4df5-9858-79c2b94e7935.png)

## Sobre mim

### Informações de contato:
<p>Vitor Cruz Souza<br>
São Paulo, SP, Brasil<br>
E-mail: vitor.cruz.souza.2001@gmail.com</p>


---

[Ir para o topo.](#conteúdos)
