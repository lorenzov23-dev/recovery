

/*
 * Questo è il branch di Matteo Mori. Può modificare tutto quello che vuole ma non ci saranno problemi a mantenere le versioni sul branch sviluppatori.
    Con questo script ci si propone di creare un programma in grado di settare da 0 un sistema operativo UNIX appena installato
    Lo script funzionerà sulle architetture software seguenti: Debian, RedHat e Slackware.
    Tre fasi:
     - selezionare il sistema operativo installato;
     - selezionare il percorso dal quale caricare eventuali pacchetti;
     - installare e configurare il software
*/

/*
    La funzione controlla che l'input da tastiera sia corretto per prevenire eccezioni'
*/

#include <iostream>
#include <stdio.h>

// Settaggio variabili globali contenenti i percorsi da cui caricare i pacchetti software


using namespace std;

int main ()
{

    bool esci=false;
    char scelta = 'k';
    while (!esci)
        {
            cout <<"------------------Per favore seleziona un sistema operativo scegliendo di seguito:---------------- \n \n a)Debian (Ubuntu e simili); \n b)RedHat (CentOS e simili); \n c)Slackware (Arch e simili); \n"<< endl;
            try 
                {
                    cin >> scelta;
                }   
            catch(exception e)
                {
                    cout << "--------------------Non hai inserito un carattere tra quelli disponibili------------------\n----------------------riprova scegliendo tra------------------\n -------------------------------  a  -----------------------\n----------------------------- b -----------------------------\n-------------------------- c ----------------------" << endl; 
                    scelta = 'k';               
                }
            switch(scelta)
                {
                    case 'a': 
                        {
                            cout <<"Hai scelto Debian" << endl;
                            system("sudo -S ./unix_installer.sh a");
                            esci = true;
                            break;
                        }
                   case 'b': 
                        {
                            cout << "Hai scelto RedHat" << endl;
                            system("sudo -S ./unix_installer.sh b");
                            esci = true;
                            break;
                        }
                   case 'c': 
                        {
                            cout << "Hai scelto Slackware" << endl;
                            system("sudo -S ./unix_installer.sh c");
                            esci = true;
                            break;
                        }
                   default: 
                        {
                            cout << "Hai scelto male, riprova" << endl;
                        }
                }
            scelta = 0;
        }

    return 0;
}
