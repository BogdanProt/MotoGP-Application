# MotoGP-Application
### Tema aleasa:

Motorcycle Grand Prix

### Clasele implementate: 

***Motorcycle*** Contine specificatiile unei motociclete, si anume caii putere, capacitatea motorului, topspeed-ul, producatorul si modelul
                 Pentru aceasta clasa am implementat si operatorul de mutare, de copiere, cat si supraincarcarea operatorilor "=", "<<" si ">>"
<br>
<br>
***Track*** Contine detalii despre fiecare pista a sezonului 2023, si anume numele pistei, locatia, lungimea, numarul de viraje si numarul de locuri disponibile.
Pentru aceasta clasa am implementat si operatorul de mutare, cel de copiere, cat si supraincarcarea operatorilor "=", "<<" si ">>"
<br>
<br>
***Sponsor*** Contine detalii despre un sponsor al cursei, cum ar fi numele, serviciile oferite, si suma sponzorizarii.
Pentru aceasta clasa am supraincarcat operatorii "=", "<<" si ">>", dar am implementat si constructorii de copiere si de mutare.
<br>
<br>
***Race*** Contine detalii despre fiecare cursa in parte, cat si elementul de tip Track cu detaliile proprii. Totodata tin evidenta biletelor vandute, pretul biletului, numarul de sponsori si suma stransa de pe urma sponzorizarii.
Pentru aceasta clasa am supraincarcat operatorii "=", "<<", am implementat constructorul de copiere, si am adaugat functia add_sponsor() care primeste ca paramentru un sponsor si actualizeaza suma din urma sponsorizarii si numarul de sponsori ai cursei. In acelasi timp, am implementat si functii pentru vanzarea biletelor in limita numarului de locuri din fiecare pista.
<br>
<br>
***Team*** Contine detalii despre echipa, cum ar fi numele echipei, numele celor 2 piloti, si punctele acumulate in urma curselor pana in momentul de fata.
Pentru aceasta clasa am implementat constructorul de copiere si am supraincarcat operatorii "=" so "<<". In acelasi timp, am creat si o functie care adauga un numar de puncte pentru echipa respectiva.
<br>
<br>
***Rider*** Contine detalii despre pilot, si anume numele, varsta, nationalitate, numele echipei la care este, victoriile si numarul de campionate castigate, cat si un obiect de tip Motorcycle care reprezinta motocicleta pilotului respectiv. Pentru aceasta clasa am supraincarcat operatorii "=" si "<<".
<br>
<br>
### Functionalitati:
***Calculeaza profitul total in urma unei curse in functie de numarul de bilete vandute si de suma obtinuta in urma sponsorizarilor***
<br>
***Afiseaza leaderboard-ul actual al echipelor in functie de punctele obtinute de fiecare echipa in parte***
<br>
***Retine datele sezonului curent din MotoGP***