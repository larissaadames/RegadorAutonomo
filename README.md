# Regador Autônomo
Projeto feito para a matéria de Fundamentos Ciber-Físicos.

<details>
<summary>Pinagem</summary>

  #### OBS: O projeto tem duas "linhas" 5v (positivo) e uma GND (negativo)
  Por que? A mini bombinha de agua submersível é uma "fominha" de energia, então quando ela é ligada na linha 5v principal do arduino e dos outros componentes ela pode causar vários tipos de intabilidade e problemas diferentes. 
  #### Logo: 
  * Quando for escrito "5V L1" (5V linha 1) significa que o componente está ligado na linha positiva do arduino, alimentado pelo cabo que liga o arduino.
  * Quando for escrito "5V L2" (5V linha 2) significa que o componente está ligado na segunda linha positiva, alimentada pela placa solar e pela bateria.
  
  
#### Sensor de Umidade

Sensor | Placa
:--------- | :------
`VCC` | `5V L1`
`AOUT` | `A0`
`GND` | `GND`

#### LDR1

Sensor | Placa
:--------- | :------
`VCC` | `5V L1`
`AOUT` | `A1`
`GND` | `GND`

#### LDR2

Sensor | Placa
:--------- | :------
`VCC` | `5V L1`
`AOUT` | `A2`
`GND` | `GND`

#### Servo Motor

Sensor | Placa
:--------- | :------
`VCC` | `5V L1`
`AOUT` | `3`
`GND` | `GND`
