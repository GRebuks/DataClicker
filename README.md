# Data Clicker
Autors: Gundars Rēbuks  
## Apraksts
Spēle bāzēta uz 'clicker' pamata.  
Uzdevums ir krāt bitus (klikšķinot vai ģenerējot), kurus pēc tam pārdod, lai varētu atļauties jaunākas tehnoloģijas, lai varētu uzkrāt vairāk bitus.  
### Spēles pamata vienības
- Procesētās vienības  
Spēlētājs HDD/SSD uzkrās b - bitus (vēlāk B - baitus, kB - kilobaitus, MB - megabaitus utt.)  
Bitus būs iespējams ģenerēt, klikšķinot, pašam rakstot bitus, vai ar ģeneratora palīdzību, kas ģenerēs bitus spēlētāja vietā.  
Biti tiks uzkrāti atmiņas aparatūrā - HDD un/vai SSD. Biti tiks ģenerēti diskos līdz maksimālai ietilpībai. Kad tie tiks piepildīti, tos būs nepieciešams iztukšot, pārdodot datus, lai tajās var ģenerēt vairāk bitus.  
HDD - Hard Disc Drive - ietilpīgāks disks, taču lēnāk ģenerē bitus.  
SSD - Solid State Drive - mazāk ietilpīgs disks, taču ģenerē bitus daudz ātrāk.  

- Valūta  
ASV Dolāri - USD - $  
Dolārus būs iespējams iegūt, pārdodot ģenerētos datus. Ar dolāriem būs iespējams iegādāties jaunākas tehnoloģijas, ar kuru palīdzību var ģenerēt vairāk bitus.  

- Internets  
Pārdodot datus tie tiek pārsūtīti pār Internetu - tas aizņem laiku (bps - bits per second, kbps - kilobits per second, Mbps - megabits per second)  
Savienojuma kvalitāti būs iespējams uzlabot.  

- Prestige  
Prestige - tiek 'pārdota' visa iegūtā aparatūra, uzlabojumi un biti, atgriežot atpakaļ reputāciju.  
Prestige vērtība - reputācija  
Reputācija ietekmēs cenu, kādā būs iespējams pārdot datus. Reputācija bitu - dolāru konversijā strādās kā reizinātājs - pie 50 reputācijas punktiem bitu - dolāru konversija tiks pareizināta par 1.5x (piemēri vēlāk)  

## Pamata matemātiskais apraksts
Lai atbrīvotos no katras aparatūras uzlabojumu cenu piefiksēšanas, ir iespējams izmantot matemātiskas funkcijas, kas aprēķinās katru nākamo cenu.  
Viens no piemēriem:  
`nākamā_uzlabojuma_cena = sākuma_cena * (cenas_palielinājuma_reizinātājs)^uzlabojumu_skaits`  
`y = 20 * 1.10 ^x`  
y - Nākamā aprēķinātā uzlabojuma cena  
20 - Sākuma uzlabojuma cena  
1.10 - Cenas palielinājuma reizinātājs  
x - uzlabojumu skaits  
      
Lai aprēķinātu katra uzlabojuma bitu ģenerēšanas daudzumu sekundē, ir iespējams izmantot šādu formulu:  
`nākamā_uzlabojuma_ģenerēšana = sākuma_ģenerēšana * uzlabojumu_skaits * reizinātājs`  
`y = 1.6 * x * 1.5`  
y - Nākamā aprēķinātā uzlabojuma ģenerēšana  
1.6 - Sākuma uzlabojuma ģenerēšana (b/s)  
x - uzlabojumu skaits  
1.5 - reizinātājs*  
*Parasti reizinātājus izmanto, lai ģenerētu valūtu uzreiz. Tā kā šeit no bitiem uz dolāriem konvertēju vēlāk, reizinātāju šeit neizmantošu, bet gan bitu - dolāru konversijā.  
      
!! Bitu - Dolāru konversija iespējams mainīsies !!
`dolāri = bitu_skaits * 0.01 * reizinātājs`  
`1$ = 100b * 0.01 * 1`  
Reizinātājs (šajā gadījumā 1) ir Prestige vērtība - reputācija. Jo lielāka reputācija, jo labāka bitu - dolāru konversija. Reputācijas funkcija ir:  

!! Reputācijas funkcija iespējams (noteikti) mainīsies !!  
`reputacija = sqrt(bitu_kopsumma + 4/3) - sqrt(4/3)`  
Bitu kopskaits - kopējais bitu skaits vienas sesijas laikā (neieskaitot tēriņus)  
## Galvenās funkcijas
	- Klikšķināšana
	- Bitu ģenerēšana (online un offline)
	- Matemātiskās vērtības un funkcijas spēles gaitai
## Izmantotās tehnoloģijas
	- C++
	- SFML library
## Izmantotie avoti
	- [SFML dokumentācija](https://www.sfml-dev.org/style.php)
	- [Spēles aritmētika I](https://gameanalytics.com/blog/idle-game-mathematics/)
	- [Spēles aritmētika II](https://blog.kongregate.com/the-math-of-idle-games-part-iii/)
