#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <ctime>
using namespace std;


//declaring variables
 string name = "";
 string input = "";
 float HP = 20;
 float Armor = 1;
 float Attack = 3;
 float Shield = 0;
 float enemy_hp = 10;
 void Goblin_encounter();
 void Big_Goblin_encounter();
 void event_Town();
 void event_Blacksmith();
 void event_Inn();
 void event_Nothing();
 void event_Camp();
 void encounters();
 int encounter;
 bool In_town = 0;
 int dice;
 int enemy_attack;
 int Money = 0;
 float xp = 0;
 float xp0 = 0;
 int level = 0;
 
 //main loop
int main(){
	
	srand(time(0)); 
	
	//randomizing encounters
	encounter = (rand() % 10) + 1;
	//randomizing dice
	dice = (rand() % 20) + 1;
	
	//debug code for encounter
	//cout << encounter << "\n";
	
	//Player name
	cout << "Input your name!\n";
	cin >> name;
	
	//cheatcode
	if(name == "Leo"){
		Money = 10000;
		xp = 10000;
	}
	//starting the game
	cout << "Hello, " << name << "!\n";
	encounters();
	
}




//encounter for a Goblin
void Goblin_encounter(){
	
	//player hasn't escaped
	bool escaped = false;
	
	//declaring Goblin's attack power
	enemy_attack = 2;
	
	//checking if Goblin is alive or player hasn't escaped
	while (enemy_hp > 0 && HP > 0 && escaped == false) {
	cout << "You see a Goblin. Will you attack or escape(e)? y, n or e  \n";
		
		//player input
		cin >> input;
	
		//player attack
		if (input == "y"){
			system("cls");
			
			dice = (rand() % 20) + 1;
			
			cout << "Dice=" << dice << "\n";
		
			if (dice > (10 - level/5)) {
			enemy_hp = enemy_hp - Attack;
	
			cout << "You hit it. It's hp is now:" << enemy_hp << "\n";
			}
			else {
				HP = HP - (enemy_attack / Armor);
				cout << "You miss and goblin hits you.\n";
				cout << "Your hp is now:" << HP << "\n";
			}	
		}
		//Goblin attack
		else if(input == "n") {
			system("cls");
			HP = HP - (enemy_attack / Armor);
			cout << "You got hit by it. your hp is now:" << HP << "\n";
		}
		//Player escapes
		else if(input == "e"){
			system("cls");
			cout << "You escaped\n";
			escaped = true;
		}	
		//if player tries to do something creative
		else {
			cout << "You see a Goblin. Will you attack or escape(e)? y, n or e  \n";
	
			cin >> input;
	
	
		}
	}
	system("cls");
	//give money and xp when gobbo dead
	if(enemy_hp < 1 ){
		Money = Money + 25;
		xp = xp + 5;
	}
	//set enemy hp to full after the fight
	enemy_hp = 10;
}

//encounter for Big Goblin
void Big_Goblin_encounter(){
	
	//player hasn't escaped
	bool escaped = false;
	
	//declaring Goblin's hp & attack power
	enemy_hp = 40;
	enemy_attack = 4;
	
	//checking if Goblin is alive or player hasn't escaped
	while (enemy_hp > 0 && HP > 0 && escaped == false) {
	cout << "You see a massive goblin. Will you attack or escape(e)? y, n or e \n";
	
		//player input
		cin >> input;
	
		//player attack
		if (input == "y"){
			system("cls");
			dice = (rand() % 20) + 1;
			
			cout << "Dice=" << dice << "\n";
		
			if (dice > (6 - level/5)) {
			enemy_hp = enemy_hp - Attack;
	
			cout << "You hit it. It's hp is now:" << enemy_hp << "\n";
			}
			else {
				HP = HP - (enemy_attack / Armor);
				cout << "You miss and goblin hits you.\n";
				cout << "Your hp is now:" << HP << "\n";
			}	
		}
		//Goblin attack
		else if(input == "n") {
			system("cls");
			HP = HP - (enemy_attack / Armor);
			cout << "You got hit by it. your hp is now:" << HP << "\n";
		}
		//Player escapes
		else if(input == "e"){
			system("cls");
			cout << "You escaped\n";
			escaped = true;
		}	
		//if player tries to break the game
		else {
			cout << "You see a massive goblin. Will you attack or escape(e)? y, n or e \n";
	
			cin >> input;
	
	
		}
	}
	system("cls");
	//MONEYYYYYY
	if(enemy_hp < 1 ){
		Money = Money + 100;
		xp = xp + 25;
	}
	//enemy hp full and clear input?
	enemy_hp = 10;
	input = "";
}

//Town encounter
void event_Town(){
	//clear screen and some thing
	system("cls");
	In_town = 1;
	//Town loop until player leaves town
	while(In_town == 1){
		cout << "You arrive to a town\n";
		cout << "You can visit a Blacksmith(b), sleep at the Inn(i) or leave(l)\n";
		cout << "Your Level:" << level << "\n";
		cin >> input;
		if(input == "l"){
		In_town = 0;
		}
		else if(input == "b"){
		event_Blacksmith();
		}
		else if (input == "i"){
		event_Inn();
		}
	}
	system("cls");
}

//Blacksmith option in town
void event_Blacksmith(){
	system("cls");
	//Blacksmith menu
	cout << "You visit the blacksmith\n";
		cout << "Your money:" << Money << "\n";
		cout << "Your armor:" << Armor+Shield << "\n";
		cout << "Catalog:\n";
		cout << "(1) Sword\n";
		cout << "(2) Armor\n";
		cout << "(3) Shield\n";
		cout << "(l) Leave\n";
		cin >> input;
		
		//Sword option. adds attack level
		if(input == "1"){
			if(Attack >= 3 + 1.5*level){
				cout << "You already have that sword!\n";
				cin >> input;
				event_Blacksmith();
			}
			else if(Money > 24 ){
				Money = Money - 25;
				Attack = Attack + 1.5*level;
				cout << "you bought the sword\n";
				event_Blacksmith();
			}
			else {
				cout << "You don't hace enough money for that!\n";
				cin >> input;
				event_Blacksmith();
			}
		}
		//Armor option. adds armor level
		else if(input == "2"){
			if(Armor >= 1 + 0.25*level){
				cout << "You already have that armor\n";
				cin >> input;
				event_Blacksmith();
			}
			else if(Money > 24 ){
				Money = Money - 25;
				Armor = Armor + 0.25*level;
				cout << "you bought the armor\n";
				event_Blacksmith();
			}
			else {
				cout << "You don't hace enough money for that!\n";
				cin >> input;
				event_Blacksmith();
			}
		}
		//Shield option. adds armor level 
		else if(input == "3"){
			if (Shield >= 0.25*level){
				cout << "You already have that shield!!!\n";
				cin >> input;
				event_Blacksmith();
			}
			else if(Money > 24 ){
				Money = Money - 25;
				Shield = Shield + 0.25*level;
				cout << "you bought the shield\n";
			}
			else {
				cout << "You don't hace enough money for that!\n";
				cin >> input;
				event_Blacksmith();
			}
		}	
		//back to town
		else if(input == "l"){
			event_Town();
		}
		else{
			event_Blacksmith();
		}
}

//Inn option in town
void event_Inn(){
	system("cls");
	cout << "xp: " << xp << "\n";
	cout << "You are in the Inn.\n";
	cout << "You can rent a room for 5 coins, sleep and level up(s) or leave(l).\n";
	cin >> input;
	//sets player hp to full & adds level
	if(input == "s" && Money >= 5){
		Money = Money - 5;
		HP = 20;
		if(xp >= (xp0 + 10)){
			xp0 = xp0 + 10;
			level = level + 1;
			xp = xp - xp0;
			event_Inn();
		}
		else{
			event_Inn();
		}
	}
	//back to town
	else if(input == "l") {
		event_Town();
	}
	else {event_Inn();}
}

//Encounter for empty field
void event_Nothing(){
	system("cls");
	bool nothing = true;
	cout << "You don't see any signs of life. Do you want to set up a camp? y/n \n"; 
	cin >> input;
	while (nothing == true){
		if (input == "y"){
			system("cls");
			event_Camp();
		}
		else if(input == "n"){
			system("cls");
			input = "";
			cout << "you keep moving\n";
			system("pause");
			system("cls");
			encounters();
		}
		else {
			system("cls");
			event_Nothing();
		}
	}
	system("cls");
	input = "";
}

//Camp event
void event_Camp(){
	bool in_camp = true;
	cout << "You set up a camp\n";
	cout << "Sleep(s) or Leave(l)\n";
	cin >> input;
	while(in_camp == true ){
		if(input == "s"){
			system("cls");
			input = "";
			HP = 20;
			cout << "you slept\n";
			system("pause");
			in_camp = false;
			encounters();
		}
		else if(input == "l") {
			input = "";
			cout << "You leave the campsite\n";
			system("pause");
			in_camp = false;
			encounters();
		}
		else {
			system("cls");
			event_Camp();
		}
		
	}
	input = "";
}


//getting encounter case
void encounters(){
	
	//checking if player hasn't died
	while(HP != 0, HP > 0){
		
		//srand(time(0));
		
		//encounter randnum
		encounter = (rand() % 10);
		
		//DEBUG code
		//cout << "encounter=" << encounter << "\n";
		
		//different encounter options chosen by the encounter randnum
		switch(encounter) {
		case 1 :
		Goblin_encounter();
		break;
		case 2:
		event_Town();
		break;
		case 3:
		Goblin_encounter();
		break;
		case 4:
		Goblin_encounter();
		break;
		case 5:
		event_Town();
		break;
		case 6:
		event_Nothing();
		break;
		case 7:
		event_Nothing();
		break;
		case 8:
		Big_Goblin_encounter();
		break;
		case 9:
		event_Town();
		break;
		case 10:
		event_Nothing();
		break;
		
	}
	//game over
	while (HP == 0 || HP < 0) {
		cout << "You died\n";
		system("pause");
		exit(0);
	}
	}
	
}