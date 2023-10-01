# acceptor-936-mincovnik-arduino-czk

### Mincovník "acceptor-936" 

 Po vhození přednastavené částky se vypíše zpráva a může se například sepnout relé (či načíst webová adresa - GET)

> [!NOTE]  
>Tento kód funguje tak, že při detekci mince se aktivuje přerušení (funkce preruseniPriVhozuMince), což zvýší celkový počet detekovaných mincí. V hlavní smyčce loop kontrolujeme, zda uplynul dostatečný čas od poslední detekce a zda současný zůstatek dosáhl požadované ceny. Pokud ano, posíláme zprávu a vynulujeme současný zůstatek a celkový počet detekovaných mincí.


> [!IMPORTANT]  
> Arduino UNO R3 Wifi, Arduino UNO R4 Wifi: musíte napájet 12V kvůli mincovníku (nestačí USB) 


### 🟦Zapojení mincovníku
- (Mincovník) DC 12 (červený drát)  --> V in (arduino)
- (Mincovník) GND (černý drát)      --> GND (arduino)
- (Mincovník) COIN (bílí drát)
  - --> digital pin 2
  - --> REZISTOR 10KΩ --> 5V
  

> [!WARNING]  
> Přerušte drát a vložte ------REZISTOR 10KΩ-----------  



### 🟪Nastavení mincovníku "acceptor-936" 

#### 🟣Základní nastavení 

Nastavení mincovníku vyvoláte přidržením tlačítek ADD + MINUS

H,P,F opakujte podle E nastavených počtu druhů mincí:

- E počet druhů mincí které budou akceptovány
- H počet vzorků mincí
- P počet impulsů
- F přesnost snímání - doporučeno výrobcem: 8

#### 🟣Impulsy - P
- 5 impuls = 5 CZK
- 10 impuls = 10 CZK
- 20 impuls = 20 CZK
- 50 impuls = 50 CZK

#### 🟣Párování - snímání mincí  SET
- Stiskněte SET 2x
- Vhoďtě 5 CZK do mincovníku (opakujte podle H) 
- Stiknětě SET 1x
- Vhoďtě 10 CZK do mincovníku (opakujte podle H)
- Stiknětě SET 1x
- Vhoďtě 20 CZK do mincovníku (opakujte podle H)
- Stiknětě SET 1x
- Vhoďtě 50 CZK do mincovníku (opakujte podle H)



```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ text in purple (and bold)@@
```


🔴🟠🟡🟢🔵🟣🟤⚫⚪🔘🛑⭕

🟥🟧🟨🟩🟦🟪🟫⬛⬜🔲🔳⏹☑✅❎

❤️🧡💛💚💜💙🤎🖤🤍♥️💔💖💘💝💗💓💟💕❣️♡

🔺🔻🔷🔶🔹🔸♦💠💎💧🧊

🏴🏳🚩🏁

◻️◼️◾️◽️▪️▫️






$\mathcal{\color{purple}{this \ is \ a \ paragraph} \ \color{cyan}{in \ another \ font}}$

$\mathbb{\color{teal}{this \ is \ a } \ \color{magenta}{paragraph \ in \ another \ font}}$

$\mathscr{\color{red}{this} \ \ \color{blue}{is \ \ a \ \ paragraph} \ \ \color{yellow}{in \ \ another \ \ font}}$

$\mathfrak{\color{lime}{this \ is \ a \ paragraph \ in \ another \ font}}$

$\mathscr{\color{red}{mon}\color{white}{day}}$

$\textcolor{olive}{\TeX} \ \textcolor{darkgray}{workaround \ found \ by \ Dassalem \ Mohammed \ Yasser}$

$\textit{hello}$  #italic

$\text{hello}$    #normal

$\Large{hello}$$   #Bigger text size

$$\LaTeX$$



Text inside bordered Box 

$\fbox{Hello there}$



$\color[rgb]{1,0,1} hello$

$\color[RGB]{155,127,0} hello$

$\color[gray]{0.3} hello$
