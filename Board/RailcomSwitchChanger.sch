EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5FEB1027
P 1200 1300
F 0 "J1" H 1118 975 50  0000 C CNN
F 1 "RAIL_IN" H 1118 1066 50  0000 C CNN
F 2 "footprint:TB111-2" H 1200 1300 50  0001 C CNN
F 3 "~" H 1200 1300 50  0001 C CNN
	1    1200 1300
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 5FEB1A72
P 3500 1300
F 0 "J2" H 3418 975 50  0000 C CNN
F 1 "RAIL_OUT" H 3418 1066 50  0000 C CNN
F 2 "footprint:TB111-2" H 3500 1300 50  0001 C CNN
F 3 "~" H 3500 1300 50  0001 C CNN
	1    3500 1300
	1    0    0    1   
$EndComp
$Comp
L Device:R R9
U 1 1 5FEB6A41
P 5200 5200
F 0 "R9" H 5270 5246 50  0000 L CNN
F 1 "104" H 5270 5155 50  0000 L CNN
F 2 "footprint:R_1608" V 5130 5200 50  0001 C CNN
F 3 "~" H 5200 5200 50  0001 C CNN
	1    5200 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:D D4
U 1 1 5FEB6D42
P 1150 4350
F 0 "D4" V 1104 4430 50  0000 L CNN
F 1 "GS1010FL" V 1195 4430 50  0000 L CNN
F 2 "footprint:SOD-123FL" H 1150 4350 50  0001 C CNN
F 3 "~" H 1150 4350 50  0001 C CNN
	1    1150 4350
	0    1    1    0   
$EndComp
$Comp
L Device:D D3
U 1 1 5FEB716B
P 1500 3950
F 0 "D3" H 1500 3733 50  0000 C CNN
F 1 "GS1010FL" H 1500 3824 50  0000 C CNN
F 2 "footprint:SOD-123FL" H 1500 3950 50  0001 C CNN
F 3 "~" H 1500 3950 50  0001 C CNN
	1    1500 3950
	-1   0    0    1   
$EndComp
$Comp
L Device:CP C1
U 1 1 5FEB74D6
P 1850 4350
F 0 "C1" H 1968 4396 50  0000 L CNN
F 1 "220uF" H 1968 4305 50  0000 L CNN
F 2 "footprint:CAP_TH_6.3x11" H 1888 4200 50  0001 C CNN
F 3 "~" H 1850 4350 50  0001 C CNN
	1    1850 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5FEB7B49
P 1850 5050
F 0 "C2" H 1968 5096 50  0000 L CNN
F 1 "100uF" H 1968 5005 50  0000 L CNN
F 2 "footprint:CAP_TH_5x11" H 1888 4900 50  0001 C CNN
F 3 "~" H 1850 5050 50  0001 C CNN
	1    1850 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5FEB7E4A
P 1150 5050
F 0 "R3" H 1220 5096 50  0000 L CNN
F 1 "221" H 1220 5005 50  0000 L CNN
F 2 "footprint:R_1608" V 1080 5050 50  0001 C CNN
F 3 "~" H 1150 5050 50  0001 C CNN
	1    1150 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5FEB828F
P 2200 5500
F 0 "R4" V 1993 5500 50  0000 C CNN
F 1 "221" V 2084 5500 50  0000 C CNN
F 2 "footprint:R_1608" V 2130 5500 50  0001 C CNN
F 3 "~" H 2200 5500 50  0001 C CNN
	1    2200 5500
	0    1    1    0   
$EndComp
$Comp
L Device:D D5
U 1 1 5FEB8743
P 3100 5050
F 0 "D5" V 3146 4970 50  0000 R CNN
F 1 "GS1010FL" V 3055 4970 50  0000 R CNN
F 2 "footprint:SOD-123FL" H 3100 5050 50  0001 C CNN
F 3 "~" H 3100 5050 50  0001 C CNN
	1    3100 5050
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C4
U 1 1 5FEB9FFB
P 3100 4350
F 0 "C4" H 3215 4396 50  0000 L CNN
F 1 "104" H 3215 4305 50  0000 L CNN
F 2 "footprint:C_1005" H 3138 4200 50  0001 C CNN
F 3 "~" H 3100 4350 50  0001 C CNN
	1    3100 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 5FEBA38D
P 3550 4350
F 0 "C3" H 3668 4396 50  0000 L CNN
F 1 "100uF" H 3668 4305 50  0000 L CNN
F 2 "footprint:CAP_TH_5x11" H 3588 4200 50  0001 C CNN
F 3 "~" H 3550 4350 50  0001 C CNN
	1    3550 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5FEBA767
P 5200 5900
F 0 "R10" H 5270 5946 50  0000 L CNN
F 1 "102" H 5270 5855 50  0000 L CNN
F 2 "footprint:R_1608" V 5130 5900 50  0001 C CNN
F 3 "~" H 5200 5900 50  0001 C CNN
	1    5200 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 6050 5200 6250
Wire Wire Line
	5200 5350 5200 5550
Connection ~ 5200 5550
Wire Wire Line
	5200 5550 5200 5750
$Comp
L Comparator:LM339 U2
U 3 1 5FEBCC96
P 6800 5050
F 0 "U2" H 6800 5417 50  0000 C CNN
F 1 "LM339" H 6800 5326 50  0000 C CNN
F 2 "footprint:SOIC-14" H 6750 5150 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 6850 5250 50  0001 C CNN
	3    6800 5050
	1    0    0    -1  
$EndComp
$Comp
L Comparator:LM339 U2
U 4 1 5FEBD273
P 6800 5650
F 0 "U2" H 6800 6017 50  0000 C CNN
F 1 "LM339" H 6800 5926 50  0000 C CNN
F 2 "footprint:SOIC-14" H 6750 5750 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 6850 5850 50  0001 C CNN
	4    6800 5650
	1    0    0    -1  
$EndComp
Text GLabel 5200 4550 1    50   Input ~ 0
RAIL+
$Comp
L Device:D_Schottky D1
U 1 1 5FEC031E
P 2250 1550
F 0 "D1" H 2250 1767 50  0000 C CNN
F 1 "SR54F" H 2250 1676 50  0000 C CNN
F 2 "footprint:SMBF" H 2250 1550 50  0001 C CNN
F 3 "~" H 2250 1550 50  0001 C CNN
	1    2250 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D2
U 1 1 5FEC0827
P 2250 1900
F 0 "D2" H 2250 1683 50  0000 C CNN
F 1 "SR54F" H 2250 1774 50  0000 C CNN
F 2 "footprint:SMBF" H 2250 1900 50  0001 C CNN
F 3 "~" H 2250 1900 50  0001 C CNN
	1    2250 1900
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5FEC130B
P 2250 2250
F 0 "R1" V 2043 2250 50  0000 C CNN
F 1 "3R60" V 2134 2250 50  0000 C CNN
F 2 "footprint:R_3225" V 2180 2250 50  0001 C CNN
F 3 "~" H 2250 2250 50  0001 C CNN
	1    2250 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5FEC1986
P 2250 2600
F 0 "R2" V 2043 2600 50  0000 C CNN
F 1 "3R60" V 2134 2600 50  0000 C CNN
F 2 "footprint:R_3225" V 2180 2600 50  0001 C CNN
F 3 "~" H 2250 2600 50  0001 C CNN
	1    2250 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	2100 1550 1900 1550
Wire Wire Line
	1900 1550 1900 1900
Wire Wire Line
	1900 2600 2100 2600
Wire Wire Line
	2100 2250 1900 2250
Connection ~ 1900 2250
Wire Wire Line
	1900 2250 1900 2600
Wire Wire Line
	2100 1900 1900 1900
Connection ~ 1900 1900
Wire Wire Line
	1900 1900 1900 2250
Wire Wire Line
	2400 1550 2600 1550
Wire Wire Line
	2600 1550 2600 1900
Wire Wire Line
	2600 2600 2400 2600
Wire Wire Line
	2400 2250 2600 2250
Connection ~ 2600 2250
Wire Wire Line
	2600 2250 2600 2600
Wire Wire Line
	2400 1900 2600 1900
Connection ~ 2600 1900
Wire Wire Line
	2600 1900 2600 2250
Wire Wire Line
	2600 1300 2600 1550
Connection ~ 2600 1550
Wire Wire Line
	1900 1300 1900 1550
Connection ~ 1900 1550
Wire Wire Line
	1400 1300 1900 1300
Wire Wire Line
	1900 2700 1900 2600
Connection ~ 1900 2600
Wire Wire Line
	2600 1200 2600 1000
Wire Wire Line
	2600 1000 2800 1000
Text GLabel 2800 1000 2    50   Output ~ 0
RAIL+
Text GLabel 2800 2600 2    50   Output ~ 0
RAIL-
Wire Wire Line
	2800 2600 2600 2600
Connection ~ 2600 2600
Connection ~ 2600 1200
Wire Wire Line
	1400 1200 2600 1200
Wire Wire Line
	2600 1200 3300 1200
Wire Wire Line
	2600 1300 3300 1300
Wire Wire Line
	5200 4550 5200 5050
Text GLabel 6300 5750 0    50   Input ~ 0
N18mv
Text GLabel 6300 4950 0    50   Input ~ 0
P18mv
Wire Wire Line
	5200 5550 5650 5550
Wire Wire Line
	5650 5550 5650 5150
Connection ~ 5650 5550
Wire Wire Line
	7100 5050 7300 5050
Wire Wire Line
	7300 5050 7300 5350
Wire Wire Line
	7300 5650 7100 5650
Wire Wire Line
	1350 3950 1150 3950
Text GLabel 1150 3850 1    50   Input ~ 0
RAIL+
Wire Wire Line
	2250 3950 1850 3950
Wire Wire Line
	1850 4200 1850 3950
Wire Wire Line
	1850 4500 1850 4700
Wire Wire Line
	1850 4700 2550 4700
Wire Wire Line
	2550 4700 2550 4250
Wire Wire Line
	3100 4200 3100 3950
Wire Wire Line
	3100 3950 2850 3950
Wire Wire Line
	3100 3950 3550 3950
Wire Wire Line
	3550 3950 3550 4200
Connection ~ 3100 3950
Wire Wire Line
	2550 4700 3100 4700
Wire Wire Line
	3100 4700 3100 4500
Connection ~ 2550 4700
Wire Wire Line
	3100 4700 3550 4700
Wire Wire Line
	3550 4700 3550 4500
Connection ~ 3100 4700
Wire Wire Line
	1650 3950 1850 3950
Connection ~ 1850 3950
Wire Wire Line
	3100 3850 3100 3950
Wire Wire Line
	1150 3850 1150 3950
Wire Wire Line
	2550 4800 2550 4700
Wire Wire Line
	1850 4900 1850 4700
$Comp
L power:VSS #PWR0106
U 1 1 5FEF05A4
P 2550 5600
F 0 "#PWR0106" H 2550 5450 50  0001 C CNN
F 1 "VSS" H 2565 5773 50  0000 C CNN
F 2 "" H 2550 5600 50  0001 C CNN
F 3 "" H 2550 5600 50  0001 C CNN
	1    2550 5600
	-1   0    0    1   
$EndComp
Wire Wire Line
	1150 3950 1150 4200
Connection ~ 1150 3950
Connection ~ 1850 4700
Wire Wire Line
	2050 5500 1850 5500
Wire Wire Line
	1850 5200 1850 5500
Wire Wire Line
	1850 5500 1150 5500
Connection ~ 1850 5500
Wire Wire Line
	3100 4900 3100 4700
Wire Wire Line
	3100 5200 3100 5500
Wire Wire Line
	3100 5500 2550 5500
Wire Wire Line
	2550 5600 2550 5500
Connection ~ 2550 5500
Wire Wire Line
	2550 5500 2350 5500
Wire Wire Line
	1150 4500 1150 4900
Wire Wire Line
	1150 5200 1150 5500
$Comp
L Comparator:LM339 U2
U 1 1 5FF1FC3F
P 6800 1750
F 0 "U2" H 6800 1383 50  0000 C CNN
F 1 "LM339" H 6800 1474 50  0000 C CNN
F 2 "footprint:SOIC-14" H 6750 1850 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 6850 1950 50  0001 C CNN
	1    6800 1750
	1    0    0    1   
$EndComp
$Comp
L Comparator:LM339 U2
U 2 1 5FF20793
P 6800 2750
F 0 "U2" H 6800 2383 50  0000 C CNN
F 1 "LM339" H 6800 2474 50  0000 C CNN
F 2 "footprint:SOIC-14" H 6750 2850 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 6850 2950 50  0001 C CNN
	2    6800 2750
	1    0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5FF2787C
P 5200 1400
F 0 "R5" H 5270 1446 50  0000 L CNN
F 1 "274" H 5270 1355 50  0000 L CNN
F 2 "footprint:R_1608" V 5130 1400 50  0001 C CNN
F 3 "~" H 5200 1400 50  0001 C CNN
	1    5200 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5FF27CBB
P 5200 1900
F 0 "R6" H 5270 1946 50  0000 L CNN
F 1 "102" H 5270 1855 50  0000 L CNN
F 2 "footprint:R_1608" V 5130 1900 50  0001 C CNN
F 3 "~" H 5200 1900 50  0001 C CNN
	1    5200 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1550 5200 1650
Wire Wire Line
	5200 1650 5550 1650
Connection ~ 5200 1650
Wire Wire Line
	5200 1650 5200 1750
Wire Wire Line
	5550 1650 5550 1850
Wire Wire Line
	5550 1850 5750 1850
Connection ~ 5550 1650
Text GLabel 5750 1850 2    50   Output ~ 0
P18mv
Wire Wire Line
	5550 1650 6500 1650
Wire Wire Line
	6500 1850 6300 1850
Wire Wire Line
	5200 2050 5200 2250
$Comp
L Device:R R7
U 1 1 5FF36A69
P 5200 2600
F 0 "R7" H 5270 2646 50  0000 L CNN
F 1 "821" H 5270 2555 50  0000 L CNN
F 2 "footprint:R_1608" V 5130 2600 50  0001 C CNN
F 3 "~" H 5200 2600 50  0001 C CNN
	1    5200 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5FF36F57
P 5200 3100
F 0 "R8" H 5270 3146 50  0000 L CNN
F 1 "333" H 5270 3055 50  0000 L CNN
F 2 "footprint:R_1608" V 5130 3100 50  0001 C CNN
F 3 "~" H 5200 3100 50  0001 C CNN
	1    5200 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 2950 5200 2850
Wire Wire Line
	5200 2850 5550 2850
Connection ~ 5200 2850
Wire Wire Line
	5200 2850 5200 2750
Wire Wire Line
	5550 2850 5550 3050
Wire Wire Line
	5550 3050 5750 3050
Connection ~ 5550 2850
Wire Wire Line
	5550 2850 6500 2850
Text GLabel 5750 3050 2    50   Output ~ 0
N18mv
Wire Wire Line
	6500 2650 6300 2650
Wire Wire Line
	6300 1850 6300 2250
Wire Wire Line
	6300 2250 6100 2250
Connection ~ 6300 2250
Wire Wire Line
	6300 2250 6300 2650
Text GLabel 6100 2250 0    50   Input ~ 0
RAIL-
Wire Wire Line
	5200 3250 5200 3350
Wire Wire Line
	5200 1250 5200 1150
$Comp
L power:VSS #PWR0108
U 1 1 5FF48600
P 5200 3350
F 0 "#PWR0108" H 5200 3200 50  0001 C CNN
F 1 "VSS" H 5215 3523 50  0000 C CNN
F 2 "" H 5200 3350 50  0001 C CNN
F 3 "" H 5200 3350 50  0001 C CNN
	1    5200 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	5200 2250 4900 2250
Wire Wire Line
	4900 2250 4900 2450
Connection ~ 5200 2250
Wire Wire Line
	5200 2250 5200 2450
$Comp
L Device:R R11
U 1 1 5FF4BD1C
P 7250 1450
F 0 "R11" H 7320 1496 50  0000 L CNN
F 1 "103" H 7320 1405 50  0000 L CNN
F 2 "footprint:R_1608" V 7180 1450 50  0001 C CNN
F 3 "~" H 7250 1450 50  0001 C CNN
	1    7250 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5FF4BFB3
P 7600 1450
F 0 "R12" H 7670 1496 50  0000 L CNN
F 1 "103" H 7670 1405 50  0000 L CNN
F 2 "footprint:R_1608" V 7530 1450 50  0001 C CNN
F 3 "~" H 7600 1450 50  0001 C CNN
	1    7600 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 1750 7250 1750
Wire Wire Line
	7250 1750 7250 1600
Wire Wire Line
	7100 2750 7600 2750
Wire Wire Line
	7600 2750 7600 1600
Connection ~ 7250 1750
Wire Wire Line
	7600 2750 7850 2750
Connection ~ 7600 2750
Wire Wire Line
	7250 1300 7250 1150
Wire Wire Line
	7600 1300 7600 1150
$Comp
L Comparator:LM339 U2
U 5 1 5FF2143D
P 2000 6800
F 0 "U2" H 1958 6846 50  0000 L CNN
F 1 "LM339" H 1958 6755 50  0000 L CNN
F 2 "footprint:SOIC-14" H 1950 6900 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/lm139.pdf" H 2050 7000 50  0001 C CNN
	5    2000 6800
	1    0    0    -1  
$EndComp
$Comp
L power:VSS #PWR0115
U 1 1 5FF8AC04
P 1900 7400
F 0 "#PWR0115" H 1900 7250 50  0001 C CNN
F 1 "VSS" H 1915 7573 50  0000 C CNN
F 2 "" H 1900 7400 50  0001 C CNN
F 3 "" H 1900 7400 50  0001 C CNN
	1    1900 7400
	-1   0    0    1   
$EndComp
Wire Wire Line
	1900 7400 1900 7100
Wire Wire Line
	1900 6500 1900 6200
Text GLabel 10600 1750 2    50   Output ~ 0
BiDi_RXD
Wire Wire Line
	10600 1750 10400 1750
Text Notes 6350 4100 0    100  Italic 0
Railcom Cutout Detector
Text Notes 1850 3450 0    100  Italic 0
Power Circuit
Text Notes 1550 800  0    100  Italic 0
DCC Rail Connection
Text Notes 6350 800  0    100  Italic 0
Railcom Comm Receiver
$Sheet
S 4200 7300 500  150 
U 60016BBB
F0 "rsc_mcu" 100
F1 "rsc_mcu.sch" 100
$EndSheet
Wire Wire Line
	6500 5750 6300 5750
Wire Wire Line
	5650 5550 6500 5550
Wire Wire Line
	5650 5150 6500 5150
Wire Wire Line
	6500 4950 6300 4950
$Comp
L Device:R R15
U 1 1 5FEFA2C5
P 9500 1450
F 0 "R15" H 9570 1496 50  0000 L CNN
F 1 "102" H 9570 1405 50  0000 L CNN
F 2 "footprint:R_1608" V 9430 1450 50  0001 C CNN
F 3 "~" H 9500 1450 50  0001 C CNN
	1    9500 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q1
U 1 1 5FF2D221
P 8550 2750
F 0 "Q1" H 8754 2796 50  0000 L CNN
F 1 "SSM3K7002BFU" H 8754 2705 50  0000 L CNN
F 2 "footprint:SC-70" H 8750 2850 50  0001 C CNN
F 3 "~" H 8550 2750 50  0001 C CNN
	1    8550 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q2
U 1 1 5FF2E7CF
P 9400 2250
F 0 "Q2" H 9604 2296 50  0000 L CNN
F 1 "SSM3K7002BFU" H 9604 2205 50  0000 L CNN
F 2 "footprint:SC-70" H 9600 2350 50  0001 C CNN
F 3 "~" H 9400 2250 50  0001 C CNN
	1    9400 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 2250 8150 2250
Wire Wire Line
	7250 1750 7250 2250
Wire Wire Line
	8650 2950 8650 3150
Wire Wire Line
	8650 3150 9500 3150
Wire Wire Line
	9500 3150 9500 2450
Wire Wire Line
	8650 2550 8650 1750
Wire Wire Line
	8650 1750 9500 1750
Wire Wire Line
	9500 1750 9500 2050
Wire Wire Line
	9500 1600 9500 1750
Connection ~ 9500 1750
Wire Wire Line
	9500 1300 9500 1150
Connection ~ 9500 3150
Wire Wire Line
	10400 1750 9500 1750
Wire Wire Line
	9500 3350 9500 3150
Connection ~ 10400 1750
$Comp
L Regulator_Linear:L78L05_SOT89 U1
U 1 1 5FEF939A
P 2550 3950
F 0 "U1" H 2550 4192 50  0000 C CNN
F 1 "78L05" H 2550 4101 50  0000 C CNN
F 2 "footprint:SOT-89-3" H 2550 4150 50  0001 C CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/15/55/e5/aa/23/5b/43/fd/CD00000446.pdf/files/CD00000446.pdf/jcr:content/translations/en.CD00000446.pdf" H 2550 3900 50  0001 C CNN
	1    2550 3950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5FF22239
P 9050 6200
F 0 "H1" H 9150 6246 50  0000 L CNN
F 1 "3.2mm" H 9150 6155 50  0000 L CNN
F 2 "footprint:HOLE_3.2mm" H 9050 6200 50  0001 C CNN
F 3 "~" H 9050 6200 50  0001 C CNN
	1    9050 6200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5FF24B62
P 9550 6200
F 0 "H2" H 9650 6246 50  0000 L CNN
F 1 "3.2mm" H 9650 6155 50  0000 L CNN
F 2 "footprint:HOLE_3.2mm" H 9550 6200 50  0001 C CNN
F 3 "~" H 9550 6200 50  0001 C CNN
	1    9550 6200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5FF24E12
P 10050 6200
F 0 "H3" H 10150 6246 50  0000 L CNN
F 1 "3.2mm" H 10150 6155 50  0000 L CNN
F 2 "footprint:HOLE_3.2mm" H 10050 6200 50  0001 C CNN
F 3 "~" H 10050 6200 50  0001 C CNN
	1    10050 6200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5FF25231
P 10550 6200
F 0 "H4" H 10650 6246 50  0000 L CNN
F 1 "3.2mm" H 10650 6155 50  0000 L CNN
F 2 "footprint:HOLE_3.2mm" H 10550 6200 50  0001 C CNN
F 3 "~" H 10550 6200 50  0001 C CNN
	1    10550 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 5FF2BA4E
P 8000 2750
F 0 "R16" V 7793 2750 50  0000 C CNN
F 1 "331" V 7884 2750 50  0000 C CNN
F 2 "footprint:R_1608" V 7930 2750 50  0001 C CNN
F 3 "~" H 8000 2750 50  0001 C CNN
	1    8000 2750
	0    1    1    0   
$EndComp
$Comp
L Device:R R17
U 1 1 5FF2BC8F
P 8000 2250
F 0 "R17" V 7793 2250 50  0000 C CNN
F 1 "331" V 7884 2250 50  0000 C CNN
F 2 "footprint:R_1608" V 7930 2250 50  0001 C CNN
F 3 "~" H 8000 2250 50  0001 C CNN
	1    8000 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 2750 8350 2750
Wire Wire Line
	7250 2250 7850 2250
Wire Wire Line
	7300 5350 10400 5350
Wire Wire Line
	10400 1750 10400 5350
Connection ~ 7300 5350
Wire Wire Line
	7300 5350 7300 5650
$Comp
L power:+5VA #PWR0101
U 1 1 61B8F9DB
P 5200 1150
F 0 "#PWR0101" H 5200 1000 50  0001 C CNN
F 1 "+5VA" H 5215 1323 50  0000 C CNN
F 2 "" H 5200 1150 50  0001 C CNN
F 3 "" H 5200 1150 50  0001 C CNN
	1    5200 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR0102
U 1 1 61B8FFE1
P 9500 1150
F 0 "#PWR0102" H 9500 1000 50  0001 C CNN
F 1 "+5VA" H 9515 1323 50  0000 C CNN
F 2 "" H 9500 1150 50  0001 C CNN
F 3 "" H 9500 1150 50  0001 C CNN
	1    9500 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR0103
U 1 1 61B90F40
P 7600 1150
F 0 "#PWR0103" H 7600 1000 50  0001 C CNN
F 1 "+5VA" H 7615 1323 50  0000 C CNN
F 2 "" H 7600 1150 50  0001 C CNN
F 3 "" H 7600 1150 50  0001 C CNN
	1    7600 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR0104
U 1 1 61B9111D
P 7250 1150
F 0 "#PWR0104" H 7250 1000 50  0001 C CNN
F 1 "+5VA" H 7265 1323 50  0000 C CNN
F 2 "" H 7250 1150 50  0001 C CNN
F 3 "" H 7250 1150 50  0001 C CNN
	1    7250 1150
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR0105
U 1 1 61B919F0
P 3100 3850
F 0 "#PWR0105" H 3100 3700 50  0001 C CNN
F 1 "+5VA" H 3115 4023 50  0000 C CNN
F 2 "" H 3100 3850 50  0001 C CNN
F 3 "" H 3100 3850 50  0001 C CNN
	1    3100 3850
	1    0    0    -1  
$EndComp
$Comp
L power:+5VA #PWR0107
U 1 1 61B91E52
P 1900 6200
F 0 "#PWR0107" H 1900 6050 50  0001 C CNN
F 1 "+5VA" H 1915 6373 50  0000 C CNN
F 2 "" H 1900 6200 50  0001 C CNN
F 3 "" H 1900 6200 50  0001 C CNN
	1    1900 6200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0109
U 1 1 61B927D2
P 4900 2450
F 0 "#PWR0109" H 4900 2200 50  0001 C CNN
F 1 "GNDA" H 4905 2277 50  0000 C CNN
F 2 "" H 4900 2450 50  0001 C CNN
F 3 "" H 4900 2450 50  0001 C CNN
	1    4900 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0110
U 1 1 61B92E8B
P 1900 2700
F 0 "#PWR0110" H 1900 2450 50  0001 C CNN
F 1 "GNDA" H 1905 2527 50  0000 C CNN
F 2 "" H 1900 2700 50  0001 C CNN
F 3 "" H 1900 2700 50  0001 C CNN
	1    1900 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0111
U 1 1 61B935E9
P 2550 4800
F 0 "#PWR0111" H 2550 4550 50  0001 C CNN
F 1 "GNDA" H 2555 4627 50  0000 C CNN
F 2 "" H 2550 4800 50  0001 C CNN
F 3 "" H 2550 4800 50  0001 C CNN
	1    2550 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0112
U 1 1 61B93936
P 5200 6250
F 0 "#PWR0112" H 5200 6000 50  0001 C CNN
F 1 "GNDA" H 5205 6077 50  0000 C CNN
F 2 "" H 5200 6250 50  0001 C CNN
F 3 "" H 5200 6250 50  0001 C CNN
	1    5200 6250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0113
U 1 1 61B94377
P 9500 3350
F 0 "#PWR0113" H 9500 3100 50  0001 C CNN
F 1 "GNDA" H 9505 3177 50  0000 C CNN
F 2 "" H 9500 3350 50  0001 C CNN
F 3 "" H 9500 3350 50  0001 C CNN
	1    9500 3350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
