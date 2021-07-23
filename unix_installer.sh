#!/bin/bash

#il primo argomento passato serve a definire il sistema operativo scelto
#1 per debian
#2 per redhat
#3 per slackware

# definisco variabile percorso_eseguibili

percorso_eseguibili=''
percorso_lista=''

case $1 in
    a)
        scelta='debian';;
    b)
        scelta='redhat';;
    c)
        scelta='slackware';;
    *)  
        echo 'terminazione in corso; errore di inserimento parametro'
        return 2;;
esac

# Nella prima parte si richiede all'utente di selezionare il percorso dal quale caricare i pacchetti .deb

echo "-------------------Per favore inserisci il percorso completo dal quale caricare i pacchetti-------"
# il codice per ora non tiene conto di eventuali errori di immissione percorso
read percorso_eseguibili

case $scelta in
    debian)
        echo S | apt install $percorso_eseguibili/$scelta/*.deb;;
    redhat)
        echo S | apt install $percorso_eseguibili/$scelta/*.rpm;;
    slackware)    
        echo S | apt install $percorso_eseguibili/$scelta/*.tgz.gz;;
esac

echo "-------------------Per favore inserisci il percorso completo del file .txt contenente i nomi pacchetti in formato-------"
# il codice per ora non tiene conto di eventuali errori di immissione percorso
read percorso_lista
while IFS= read -r line
do
  echo S | sudo apt install $line*
done < $percorso_lista/$scelta.txt








