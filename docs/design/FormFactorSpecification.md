---
MeridianEP: XXXX
Title: Hardware Interface Specification of Robot Controller
Author: k-yokoyama
Status: Draft
Type: Standards Track
Content-Type: text/markdown
Created: 2024-06-01
Post-History: 2024-06-01
---

## Abstract

このEPではMeridian向けコントローラーのハードウェアインターフェース規格について定める。

## Motivation

ロボットのハードウェア構成要素は、一般にアクチュエーター、センサー、コントローラー、そしてこれらをつなげるフレームによって成り立っている。
ロボット向けのアクチュエーターは主にラジコン向けパーツから発展したサーボモータが用いられ、様々なメーカーが販売している。
センサーは電子工作向けのパーツを利用することが多く、サーボモータよりも多くの種類が存在している。

一方で既存のロボット向けのコントローラーは、ロボットキットの製作メーカーがセット品として販売しており、かつコントローラーのプログラムもメーカーが開発しているため、メーカーにサポートされたデバイスしか使用できない。
そこで、コントローラーの規格化によりデバイス間の相互運用性を担保し、ユーザーが多様なセンサーやアクチュエーターを自由に選べる環境が必要になる。
これにより、使用する製品の選択肢が広がり、ユーザー体験が向上する。
また、標準的なコネクタやプロトコルを複数採用することで、デバイスの接続や設定が簡単になり、初心者でも手軽にロボットの製作に挑戦できる。
さらに、コントローラーの規格化によって互換性を維持した関連製品の製作が可能となり、新たな製品であってもユーザーの導入の障壁が下がることから、メーカーにとってもロボットに自社製品の利用を促すことができる。

## Rational

コントローラーのハードウェア規格の策定にあたって、検討すべき内容を次に示す。

- 物理的な規格：搭載容量やマウント用の穴位置を決めることで、異なるコントローラーに載せ替えた場合でも相互運用がしやすくなる。
- 提供するペリフェラル：ユーザー提供するペリフェラルを定めることで、同じ規格に準拠したコントローラーであれば同等の機能を提供できる。
- 使用可能なペリフェラル：採用するCPUや開発ボードの仕様を考慮することで、規格に準拠したコントローラーを作る場合でも機能性や価格の選択肢が増える。

### 既存ロボットコントローラーとの比較

- KONDO
  - RCB-3, RCB-3HV
  - RCB-4
  - RCB-4 Mini
- VSC003

### 既存のマイコンボード規格

コントローラーは内部で計算処理するためにCPUやMCUを搭載する。
電子工作向けにはCPUやMCUのプログラム開発を容易にするため、ボードとしてパッケージ化し、開発環境も含めて提供しているキット製品がある。
Meridianでは初心者やプロトタイプでの利用を想定しているため、内部のCPUも開発が容易なキット製品を介した使用を前提にする。

#### Arduino

Arduinoは電気工作向けのMCU開発キットとして普及している製品として知られる。
本来は開発環境やプログラミングツールも含めた呼称であるが、本節ではハードウェア仕様を示す。
<!-- TODO: 出荷台数など根拠 -->

Arduinoは大きさやボードの種類によっていくつかの製品ファミリーに別れる。

| ボード名 | デジタルピン (I/O) | アナログピン (I/O) | PWMピン | UART | SPI | I2C | その他 |
|---|---|---|---|---|---|---|---|
| Arduino Uno | 14  | 6 | 6 | 1 | 1 | 1 | - |
| Arduino Nano | 14 | 6 | 6 | 1 | 1 | 1 | - |
| Arduino Duemilanove | 14 | 6 | 6 | 1 | 1 | 1 | - |
| Arduino Mega 2560 | 54 | 16 | 15 | 4 | 3 | 1 | - |
| Arduino Leonardo | 14 | 12 | 10 | 1 | 1 | 1 | - |
| Arduino Micro | 12 | 12 | 5 | 1 | 1 | 1 | - |
| Arduino Nano 33 BLE Sense | 14 | 14 | 8 | 1 | 1 | 1 | 9軸IMUセンサー、Bluetooth Low Energy |
| Arduino Mega 2560 WiFi | 54 | 16 | 15 | 4 | 3 | 1 | WiFi |
| Arduino MKR1000 | 14 | 6 | 6 | 1 | 1 | 1 | WiFi、Bluetooth Low Energy |
| Arduino MKR ZERO | 6 | 4 | 2 | 1 | 1 | 1 | WiFi、Bluetooth Low Energy |
| Arduino MKR WAN | 14 | 6 | 6 | 1 | 1 | 1 | LoRaWAN |
| Arduino MKR GSM | 12 | 12 | 5 | 1 | 1 | 1 | GSM |
| Arduino MKRVID Fire | 14 | 6 | 6 | 1 | 1 | 1 | WiFi、カメラ |
| Arduino Nano 33 IoT | 14 | 14 | 8 | 1 | 1 | 1 | WiFi、Bluetooth Low Energy |
| Arduino Nano RP2040 Connect | 26 | 17 | 12 | 1 | 2 | 1 | WiFi、Bluetooth Low Energy |
| Arduino Forma | 12 | 6 | 6 | 1 | 1 | 1 | ジェスチャーセンサー、加速度センサー |
| Arduino Ion | 14 | 6 | 6 | 1 | 1 | 1 | - |
| Arduino NightHawk | 14 | 6 | 6 | 1 | 1 | 1 | 天文観測用センサー |

!!! note
    2024年6月1日時点のArduino® 公式サイトより参照

#### Raspberry Pi Hardware Attached on Top (HAT)

### 既存の電子工作向けデバイス規格

#### Servo

#### Grove

#### Qwiic

## Specification

### Physical

大きさとマウント穴をセットとして定義し、物理的な規格名を与える。

### Peripheral

ハードウェア外部仕様としてのペリフェラルを定義する。
ペリフェラルはそれぞれ求める機能性によって提供すべき機能が異なる。
そこでマイコンにおける一般的なハードウェア機能に対し、サポートの度合いによってクラスを分ける。
これらは最小限の機能セットの定義であり、機能が多くなる分には問題ない。

| ハードウェア機能 | Minimal | Standalone | Connect |
|:---------------|:--------|:-----------|:--------|
| シリアルサーボ (TTL) | 4port x 1ch | 4port x 2ch | 4port x 2ch |
| シリアルサーボ (RS485) | - | - | - |
| PWMサーボ | 4port | 4port (*1) | 4port (*1) |
| GPIO | - | 4port (*1) | 4port (*1) |
| ADC | - | 4port | 4port |
| I2C | - | 1ch | 1ch |
| SPI | - | 1ch | 1ch |
| SD | 1ch | 1ch | 1ch |
| WiFi | - | - | 1ch |
| Bluetooth Classic | - | - | 1ch (*2) |
| BLE | - | - | 1ch (*2) |
| USB Debug Port (CDC) | 1ch | 1ch | 1ch |
| USB Host | - | 1ch | 1ch |
| コンピュータとの接続 | USB Debug Port | USB Debug Port | USB Debug Port, WiFi |
| コントローラーとの接続 | - | USB Host | USB Host, Bluetooth Classic/BLE |

*1: PWMピンおよびGPIOピンは重複していてもよい。
*2: Bluetooth ClassicとBLEの機能はどちらか片方が有効ならよい。接続できるデバイスやコントローラーが変わるため注意する。

単位について

- ch: チャンネル数を示し、ハードウェアまたはソフトウェア上別系統として独立に認識・処理できるもの
- port: ハードウェア機能を提供する物理的なポートの数を示す。機能を実現のためのピンが1ポートごとに必要となる。

<!-- 既存ボードの中でArduino Nanoファミリーがペリフェラルでは最小セットとなる。

* WiFi：Mustとする。ボードに搭載されている、もしくはペリフェラルから使用可能な仕組みを提供すること。
* Bluetooth：Wantとする。UARTなどで外付けできるケースも多いためである。
* USB：Wantとする。
* UART：Mustとする。
* I2C：Mustとする。
* SPI：Wantとする。
* PWM：Wantとする。
* ADC：Wantとする。 -->

<!-- ## What\'s allowed

## What\'s not allowed -->

## Checking Compatibility

## Future-proofing

## References

## Copyright

This document has been placed in the public domain.

###

> Local Variables: mode: indented-text indent-tabs-mode: nil
> sentence-end-double-space: t fill-column: 70 coding: utf-8 End:

    (<http://www.ros.org/wiki/StackVersionPolicy>)
