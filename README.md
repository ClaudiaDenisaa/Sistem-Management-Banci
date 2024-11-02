# Sistem-Management-Banci
Proiect de programare (C)


Fiecare persoană poate să dețină 1 sau mai multe conturi la o bancă. O persoană este identificată în mod
unic prin NUME și PRENUME. Fiecare cont este caracterizat prin:
- IBAN (șir de caractere unic, nu există 2 conturi cu același IBAN)
- Deținător (Persoană)
- Monedă (RON / EUR / USD)
- Valută (un număr întreg reprezentând suma deținută în cont)

  
Dacă o persoană deține un cont, aceasta are acces deplin, adică poate:
- CREA CONTUL
- EDITA CONTUL 

o Modificare date cont (IBAN / VALUTĂ / MONEDĂ)
- ȘTERGE CONTUL
- VIZUALIZA CONTUL

  
O persoană poate crea tranzacții între oricare 2 conturi, cât timp ea deține contul sursă. O tranzacție este
definită prin:
- IBAN cont sursă
- IBAN cont destinație
- Sumă (număr între ce reprezintă suma transferată).
- !CONVERSIA: daca se face transfer de euro catre un cont in ron atunci se face conversia..


  
Funcționalități:

- LOGARE (de pe linia de comandă)
  
o Prin introducerea argumentelor login [NUME] [PRENUME]

- EDITARE CONT
  
o Din meniu, se poate face pentru orice cont deținut de persoană

- ȘTERGERE CONT
  
o Din meniu, se poate face pentru orice cont deținut de persoană

- VIZUALIZARE CONT
  
o Din meniu, se poate face pentru orice cont deținut

- EFECTUARE TRANZACȚII
  
o Din meniu, se poate face respectând restricția menționată mai sus
