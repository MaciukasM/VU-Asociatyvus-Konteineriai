# VU-Asociatyvus-Konteineriai
Ši programa nuskaito duotą tekstinį failą ir į 3 tekstinius failus išveda rezultatus naudojant asociatyvius konteinerius 'map' ir 'multimap'.

## Versijos

* [v1.0](https://github.com/MantasM2001/VU-Asociatyvus-Konteineriai/releases/tag/v1.0) - Pradinė versija, nuskaitanti duotą tekstinį failą ir į 3 tekstinius failus išvedanti rezultatus naudojant asociatyvius konteinerius 'map' ir 'multimap'.
* [v1.1](https://github.com/MantasM2001/VU-Asociatyvus-Konteineriai/releases/tag/v1.1) - Pataisyta, kad rastų visokias nuorodas (pvz. vu.lt).

## Diegimas

Atsisiųskite programą iš repozitorijos releas'ų (prireikus iškelkite .cpp ir .h failus iš aplanko su pasirinkta programa, pvz. WinRar). Tuomet sukompiliuokite norimoje programoje ar aplinkoje (arba su kitais įrankiais):
```shell
g++ -o program main.cpp funkcijos.cpp
```
Svarbu, kad aplinkoje būtų palaikomas C++11 standartas. Galiausiai lieka tik paleisti .exe failą:
```shell
.\program.exe
```

## Programos veikimas

Paleidus programą, vartotojo bus prašoma įvesti tekstinio failo pavadinimą:
```shell
Iveskite duomenu failo pavadinima (pvz. 'pavadinimas.txt'): 
test1.txt
```
Įvedus failo pavadinimą, programa išves rezultatus į 3 tekstinius failus - 1.txt, 2.txt, 3.txt.

### Pavyzdinis variantas

Į 1-ąjį failą išveda visus žodžius (ir jų pasikartojimų skaičių), kurie pasikartojo daugiau nei vieną kartą, pavyzdžiui, čia ištrauka iš pavyzdinio varianto:
```shell
Zodziai ir ju pasikartojamu skaicius:

11032 - 3
11033 - 2
1500s - 2
1914 - 2
45 - 2
a - 21
all - 2
also - 2
always - 2
and - 24
are - 7
as - 4
at - 2
avoids - 2
bc - 2
be - 4
.
.
.
```

Į 2-ąjį failą išveda tų pačių (kaip iš pirmojo failo) žodžių pasikartojimo vietas, t.y. eilutes, kuriose jie pasikartoja, pavyzdžiui, čia ištrauka iš pavyzdinio varianto:
```shell
Zodziai ir ju pasikartojamu vieta:

11032: 17 20 22 
11033: 17 22 
1500s: 2 21 
1914: 23 32 
45: 14 18 
a: 2 3 7 7 7 8 11 13 14 16 18 20 26 28 29 33 38 40 40 41 46 
all: 27 32 
also: 3 22 
always: 30 50 
and: 1 3 5 10 11 12 16 17 18 22 33 33 33 38 42 42 44 44 45 46 47 48 48 49 
are: 22 24 26 36 42 44 46 
as: 9 10 28 45 
at: 8 14 
avoids: 35 41 
bc: 14 18 
be: 7 26 47 49 
.
.
.
```

Į 3-iąjį failą išveda visas tame faile esančias nuorodas, pavyzdžiui:
```shell
Teksto nuorodos:

1. https://www.vu.lt/
2. http://www.cplusplus.com/reference/string/string/find/
3. https://www.lipsum.com/
4. www.vu.lt
5. vu.lt
```

easter egg
