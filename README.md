# acceptor-936-mincovnik-arduino-czk

### Mincovník "acceptor-936" 

 Po vhození přednastavené částky se vypíše zpráva a může se například sepnout relé či načíst webová adresa - GET uloží honotu za pomocí PHP

> [!NOTE]  
>Tento kód funguje tak, že při detekci mince se aktivuje přerušení (funkce preruseniPriVhozuMince), což zvýší celkový počet detekovaných mincí. V hlavní smyčce loop kontrolujeme, zda uplynul dostatečný čas od poslední detekce a zda současný zůstatek dosáhl požadované ceny. Pokud ano, posíláme zprávu a vynulujeme současný zůstatek a celkový počet detekovaných mincí.


> [!IMPORTANT]  
> Arduino UNO R3 Wifi, Arduino UNO R4 Wifi: musíte napájet 12V kvůli mincovníku (nestačí USB) 


### Zapojení mincovníku 🏴
- (Mincovník) DC 12 (červený drát)  --> V in (arduino)
- (Mincovník) GND (černý drát)      --> GND (arduino)
- (Mincovník) COIN (bílí drát)
  - --> digital pin 2
  - --> REZISTOR 10KΩ --> 5V
  

> [!WARNING]  
> Přerušte drát a vložte ------REZISTOR 10KΩ-----------  



### Nastavení mincovníku "acceptor-936" 💜

#### Základní nastavení 

Nastavení mincovníku vyvoláte přidržením tlačítek ADD + MINUS

H,P,F opakujte podle E nastavených počtu druhů mincí:

- **E** počet druhů mincí které budou akceptovány
- **H** počet vzorků mincí
- **P** počet impulsů
- **F** přesnost snímání - doporučeno výrobcem: 8

#### Impulsy - P
- 5 impuls = 5 CZK
- 10 impuls = 10 CZK
- 20 impuls = 20 CZK
- 50 impuls = 50 CZK

#### Párování - snímání mincí  SET
- Stiskněte **SET 2x**
- Vhoďte 5 CZK do mincovníku (opakujte podle H) 
- Stikněte **SET 1x**
- Vhoďte 10 CZK do mincovníku (opakujte podle H)
- Stikněte **SET 1x**
- Vhoďte 20 CZK do mincovníku (opakujte podle H)
- Stikněte **SET 1x**
- Vhoďte 50 CZK do mincovníku (opakujte podle H)

#### Impulsy - P EUR    /5   *5
- 2 impuls = 10 cent
- 5 impuls = 20 cent 
- 10 impuls = 50 cent
- 20 impuls = (100 cent) 1 EUR
- 40 impuls = (200 cent) 2 EUR

výslednou částku vynásobte:   celkova_castka * 5 
