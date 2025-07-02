# Regador Autônomo
Projeto feito para a matéria de Fundamentos Ciber-Físicos.

&emsp;&emsp; [Vídeo de explicação do projeto](https://www.youtube.com/watch?v=j0qeCLzuufM)
<details>
  <summary>Código</summary>

&emsp;&emsp; O [Código 1](https://github.com/larissaadames/RegadorAutonomo/blob/main/Logica1.ino) foi a primeira versão do projeto, com uma lógica limpa, o que facilita a compreensão. Porém o Tracker não funciona perfeitamente.

&emsp;&emsp; O [Código 2](https://github.com/larissaadames/RegadorAutonomo/blob/main/Logica2.ino) é a versão final do código, onde tudo funciona perfeitamente.
</details>
<details>
  <summary>Eletrônica</summary>
A parte de eficiência energética funciona com a alimentação do circuito com uma bateria sendo carregada pelo painel solar.
  
#### Sensor de Umidade

Sensor | Ligação
:--------- | :------
`VCC` | `5V L1`
`AOUT` | `A0`
`GND` | `GND`

</details>

<details>
<summary>Pinagem</summary>

  #### OBS: O projeto tem duas "linhas" 5v (positivo) e uma GND (negativo)
  Por que? A mini bombinha de agua submersível é uma "fominha" de energia, então quando ela é ligada na linha 5v principal do arduino e dos outros componentes ela pode causar vários tipos de intabilidade e problemas diferentes. 
  #### Logo: 
  * Quando for escrito "5V L1" (5V linha 1) significa que o componente está ligado na linha positiva do arduino, alimentado pelo cabo que liga o arduino.
  * Quando for escrito "5V L2" (5V linha 2) significa que o componente está ligado na segunda linha positiva, alimentada pela placa solar e pela bateria.
  
  
#### Sensor de Umidade

Sensor | Ligação
:--------- | :------
`VCC` | `5V L1`
`AOUT` | `A0`
`GND` | `GND`

#### LDR1 (Usanod o K853518)

Sensor | Ligação
:--------- | :------
`VCC` | `5V L1`
`OUT` | `A1`
`GND` | `GND`

#### LDR2 (Usanod o K853518)

Sensor | Ligação
:--------- | :------
`VCC` | `5V L1`
`AOUT` | `A2`
`GND` | `GND`

#### Servo Motor

Sensor | Ligação
:--------- | :------
`VCC` | `5V L1`
`OUT` | `3`
`GND` | `GND`

#### Relé (bomba)

Sensor | Ligação
:--------- | :------
`IN` | `8`
`GND` | `GND`
`VCC` | `5V L1`
`COM` | `5V L2`
`NO` | `+ Bomba`

#### Bomba

Bomba | Ligação
:--------- | :------
`Positivo` | `NO (relé)`
`Negativo` | `GND`

</details>

Créditos: 
* Código: [Larissa Adames Gonçalves](https://larissaadames.dev/)
* Vídeo de explicação: [Luis Quintiliano](https://github.com/quinticode)
* Desenvolvimento do projeto (físico e [digital](https://github.com/larissaadames/RegadorAutonomo/blob/main/Diagrama.pdf)): [Larissa Adames Gonçalves](https://www.linkedin.com/in/larissa-adames/)
* [Slides](https://www.canva.com/design/DAGrZZXKgNU/93rSna9evLE9B0h-tpZ4Zg/edit): [Graziele Claus](https://github.com/graziclaus)
