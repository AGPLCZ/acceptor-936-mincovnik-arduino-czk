# acceptor-936-mincovnik-arduino-czk

### Mincovník "acceptor-936" 

- po vhození přednastavené částky se vypíše zpráva a může se například sepnout relé (či načíst webová adresa - GET)


> [!IMPORTANT]  
> Arduino UNO R3 Wifi, Arduino UNO R4 Wifi: musíte napájet 12V kvůli mincovníku (nestačí USB) 


### Zapojení mincovníku
- (Mincovník) DC 12 (červený drát)  --> V in (arduino)
- (Mincovník) GND (černý drát)      --> GND (arduino)
- (Mincovník) COIN (bílí drát)
  - --> digital pin 2
  - --> REZISTOR 10KΩ --> 5V
  




### Nastavení mincovníku "acceptor-936" 

#### Základní nastavení 

Nastavení mincovníku vyvoláte přidržením tlačítek ADD + MINUS

H,P,F opakujte podle E nastavených počtu druhů mincí:

- E počet druhů mincí které budou akceptovány
- H počet vzorků mincí
- P počet impulsů
- F přesnost snímání - doporučeno výrobcem: 8

#### Impulsy - P
- 5 impuls = 5 CZK
- 10 impuls = 10 CZK
- 20 impuls = 20 CZK
- 50 impuls = 50 CZK

#### Párování - snímání mincí  SET
- Stiskněte SET 2x
- Vhoďtě 5 CZK do mincovníku (opakujte podle H) 
- Stiknětě SET 1x
- Vhoďtě 10 CZK do mincovníku (opakujte podle H)
- Stiknětě SET 1x
- Vhoďtě 20 CZK do mincovníku (opakujte podle H)
- Stiknětě SET 1x
- Vhoďtě 50 CZK do mincovníku (opakujte podle H)
