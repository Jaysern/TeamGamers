#include <stdio.h>
#include<math.h>
#include<string.h>
#include<cmath>
#include<iostream>
#include <cstring> 
#include <string>
#include<conio.h>
#include<fstream>
#include<algorithm>
using namespace std;
char input[100], str[100]; // space detection
char line2[200] = "\n***********************************************************************************************************************\n";
char line[200] = "\n========================================================================================================================\n";
int cont, number;
float total;
int rebegin, tryagain;
int malaytype = 0;
int mamaktype = 0;
int beveragetype = 0;
int koreantype = 0;
int japanesetype = 0;
void spacedetection();
void repeating();
void choicestall();
void Malaystall();
void Mamakstall();
void Beveragestall();
void Koreanstall();
void Japanesestall();
void recommedfood();
void faq();
void onlineservice();
void chart();
void ending();
void paymenttime();
string selectedstall;
string select;
int goback;
string optfororder;
string onlineselection;




int main() {
	printf(line);
	printf("\t\t\t\t\t\tChatbot by Team gamers\n");
	printf("\t\t\t\t\t\t-------Members-------\n");
	printf("\t\t\t\t\t\tChow Jay Sern(20204002)\n");
	printf("\t\t\t\t\t\tTeng Kong King(20203935)\n");
	printf("\t\t\t\t\t\tGan Xiang Yong(20198004)\n");
	printf(line);
	system("pause");
	rebegin = 1;
	while (rebegin == 1) {
		rebegin++;
		printf(line);
		printf("\t\t\t\t\t\tWelcome to Nott-A-Cafe food store\n");
		printf(line);
		printf("input the options below:\n");
		printf("1. About us\n2. Menu\n3. FAQ\n4. Order\n5. Exit\n\n");
		printf("Key in here: ");
		cin.getline(input, 500);
		spacedetection();
		if (tryagain == 1) {
			printf("\nPlease try again.....\n Insert only numbers between 1 to 5. No Alphabets allowed\n");
			rebegin = 1;
		}
		else {
			if (strcmp(str, "1") == 0) { //About us
				printf(line);
				printf("\t\t\t\t\t\t\tAbout Us\n");
				printf(line);
				printf("\Nott-A-Cafe is a online food store that will receieved foods order from users and will be delivered to the user ");
				printf("location without any physical contact at all\n\n ");
				system("pause");
				rebegin = 1;
				continue;
			}
			else if (strcmp(str, "2") == 0) { //Menu
				printf("choicestall");
				choicestall();
				system("pause");
				rebegin = 1;
				continue;
			}
			else if (strcmp(str, "3") == 0) { //faq
				faq();
				system("pause");
				rebegin = 1;
			}
			else if (strcmp(str, "4") == 0) { //ordering
				total = 0;
				char nama[30];
				char nom[100];
				char buffera[100];
				int amount;
				printf("\nPlease enter your name: "); //Storing buyer information
				scanf(" %[^\n]", nama);
				printf("\nPlease enter your phone number: ");
				scanf(" %s", &nom);
				printf("\n\n");
				FILE* pFile;
				pFile = fopen("receipt.txt", "w");
				fputs("----------RECEIPT----------\n", pFile);
				fputs("Name: ", pFile);
				fputs(nama, pFile);
				fputs("\n", pFile);
				fputs("Phone number: ", pFile);
				fputs(nom, pFile);
				fputs("\n", pFile);
				fputs("Customer service phone number\n016-3424209 (Mr.King)\n", pFile);
				fclose(pFile);
				int hehe = 1;
				while (hehe <= 1) { // Asking for the needs of food transportation
					hehe++;
					printf("\n");
					printf(line);
					printf("\nKindly Please provide us the information below :\n\n");
					printf("1.Self pickup\t\t2.Food delivery\n");
					printf(line);
					printf("Key in here: ");
					cin >> optfororder;
					if (optfororder == "1") {
						printf("\n");
						onlineservice();
						break;
					}
					if (optfororder == "2") {
						printf("\n\nPlease do noted that there some foods not available for online delivery\n"); \
							printf("Would you like to proceed?\n\n");
						printf("1. Yes take me there !  2. No I would like to go back\n\n");
						printf("Key in here: ");
						cin >> onlineselection;
						if (onlineselection == "1") {
							char namb[1000];
							printf("\nPlease enter your address: "); //User home address
							scanf(" %[^\n]", namb);
							FILE* pFile;
							pFile = fopen("receipt.txt", "a");
							fputs("Customer Address: ", pFile);
							fputs(namb, pFile);
							fputs("\n", pFile);
							fclose(pFile);
							hehe = 10;
							system("pause");
							onlineservice();
							break;
						}
						else if (onlineselection == "2") { //Return to main menu
							hehe = 10;
							rebegin = 1;
						}
						else { // User input Errors for onlineselection
							hehe = 1;
							printf("Error!\nKindly try again by choosing a number between '1' or '2' only\n");
							system("pause");
							continue;
						}
					}
					else { // User input errors for optfororder
						hehe = 1;
						printf("\n");
						printf(line2);
						printf("Error!\nKindly try again by choosing a number between '1' or '2' only\n");
						printf(line2);
						system("pause");
					}
				}
			}
			else if (strcmp(str, "5") == 0) { //Exit the program
				printf(line);
				printf("Thank you for using Nott-A-Cafe online food service !!!\nWe Hope To See You Again soon !\n");
				printf(line);
				break;
			}
			else {  //User input not 1-5 
				int e = 1;
				while (e <= 1) {
					e++;
					repeating();
					if (tryagain == 1) {
						printf("\nError got alphabet");
						printf("\ntry again:\n");
						e = 1;
					}
					else {
						if (strcmp(str, "1") == 0) {
							rebegin = 1;
							continue;
						}
						else {
							printf(line);
							printf("Thank you for using TeamA food service !!!\nWe Hope To See You Again soon !\n");
							printf(line);
							break;
						}
					}
				}

			}
		}

	}
	return 0;
}

void spacedetection() {
	int i, j;
	int c, d;
	tryagain = 0;


	for (i = 0, j = 0; input[i] != '\0'; i++) {
		if (input[i] != ' ') {
			str[j++] = input[i];
		}
	}
	str[j] = '\0';
	d = 0;
	c = 0;
	for (i = 0; str[i] != '\0'; i++)
	{

		// check for alphabets
		if (isalpha(str[i]) != 0) {
			c++;
		}

		// check for decimal digits
		else if (isdigit(str[i]) != 0)
			d++;
	}
	if (c != 0) {
		tryagain = 1;
	}
	else {

	}
}

void repeating() {  // main function error detection
	printf(line2);
	printf("Kindly select numbers between 1 to 5\n");
	printf("Do you wish to continue ? \n\n1.YES\n2.NO\n");
	printf(line2);
	printf("Key in here: ");
	cin.getline(input, 500);
	spacedetection();
}
void choicestall() { // Menu from main function
	int choicestalll = 0;
	while (choicestalll == 0) {
		choicestalll++;
		printf(line);
		printf("\t\t\t\t\t\tHere are the list of foods provided by us:\n");
		printf(line);
		printf("1. Malay Stall\n");
		printf("2. Mamak Stall\n");
		printf("3. Beverage Stall\n");
		printf("4. Korean Stall\n");
		printf("5. Japanese Stall\n");
		printf("6. Recommendation Foods\n");
		printf("7. Go back to main menu\n\n");
		printf("Key in here: ");
		tryagain = 0;
		cin.getline(input, 500);
		spacedetection();
		if (tryagain == 1) {

			printf("please pick a number between 1 to 7\n");
			system("pause");
			choicestalll = 0;
		}
		else {
			if (strcmp(str, "1") == 0) { // Selected Malay Stall Menu
				printf("\n");
				printf(line);
				printf("\t\tListed foods for Malay Stall\n");
				Malaystall();
				printf("\n");
				system("pause");
				choicestalll = 0;
			}
			else if (strcmp(str, "2") == 0) { // Selected Mamak Stall Menu
				printf("\n");
				printf(line);
				printf("\t\tListed food for Mamak Stall\n");
				Mamakstall();
				printf("\n");
				system("pause");
				choicestalll = 0;
			}
			else if (strcmp(str, "3") == 0) { //Selected Beverage Stall Menu
				printf("\n");
				printf(line);
				printf("\t\tListed food for Beverage Stall\n");
				Beveragestall();
				printf("\n");
				system("pause");
				choicestalll = 0;
			}
			else if (strcmp(str, "4") == 0) { //Selected Korean Stall Menu
				printf("\n");
				printf(line);
				printf("\t\tListed food for Korean Stall\n");
				Koreanstall();
				printf("\n");
				system("pause");
				choicestalll = 0;
			}
			else if (strcmp(str, "5") == 0) { //Selected Japanese Stall Menu
				printf("\n");
				printf(line);
				printf("\t\tListed food for Japanese Stall\n");
				Japanesestall();
				printf("\n");
				system("pause");
				choicestalll = 0;
			}
			else if (strcmp(str, "6") == 0) {  //Selected To View Recommendation Foods
				printf("\nThese are the recommened foods from us :\n");
				recommedfood();
				printf("\n");
				system("pause");
				choicestalll = 0;
			}
			else if (strcmp(str, "7") == 0) { // Selected To Exit to Main menu
				printf(line2);
				printf("\nreturning to main menu\n");
			}
		}

	}
}

void Malaystall() { // Menu for Malay Stall
	printf(line);
	printf("No.\tFood\t\t\tprice(RM)\tdelivery service\n");
	printf(line2);
	printf("1.\tNasi Lemak\t\t2.00\t\tyes\n");
	printf("2.\tNasi goreng kampung\t6.00\t\tyes\n");
	printf("3.\tNasi goreng Tomyam\t6.50\t\tyes\n");
	printf("4.\tNasi goreng ikan masin\t6.50\t\tyes\n");
	printf("5.\tNasi goreng paprik\t7.00\t\tyes\n");
	printf("6.\tNasi goreng USA\t\t7.00\t\tyes\n");
	printf("7.\tNasi goreng pattaya\t7.00\t\tyes\n");
	printf("8.\tNasi goreng biasa\t5.00\t\tyes\n");
	printf("9.\tIkan goreng\t\t5.00\t\tyes\n");
	printf("10.\tAyam goreng\t\t3.00\t\tyes\n");
	printf("11.\tSatay\t\t\t1.20\t\tyes\n");
	printf("12.\tKuih talam\t\t0.70\t\tNO\n");
	printf("13.\tKuih koci\t\t0.40\t\tNO\n");
	printf(" 0.\tExit\n");
}


void Mamakstall() { // Menu for Mamak Stall
	printf(line);
	printf("No.\tFood\t\t\tprice(RM)\tdelivery service\n");
	printf(line2);
	printf("1.\tRoti canai\t\t1.20\t\tno\n");
	printf("2.\tRoti telur\t\t2.30\t\tno\n");
	printf("3.\tRoti cheese\t\t2.50\t\tno\n");
	printf("4.\tRoti boom\t\t2.20\t\tno\n");
	printf("5.\tRoti planta\t\t2.20\t\tno\n");
	printf("6.\tRoti susu\t\t2.20\t\tno\n");
	printf("7.\tRoti tisu\t\t3.20\t\tno\n");
	printf("8.\tTosai\t\t\t1.20\t\tno\n");
	printf("9.\tMee goreng\t\t5.00\t\tyes\n");
	printf("10.\tMaggi goreng\t\t5.00\t\tyes\n");
	printf("11.\tMaggi soup\t\t4.00\t\tyes\n");
	printf("12.\tTeh tarik ais\t\t2.20\t\tno\n");
	printf("13.\tTeh tarik panas\t\t1.80\t\tno\n");
	printf("14.\tMilo ais\t\t2.50\t\tno\n");
	printf("15.\tMilo panas\t\t2.20\t\tno\n");
	printf("16.\tCincau\t\t\t2.50\t\tno\n");
	printf("17.\tLimao ais\t\t1.80\t\tno\n");
	printf("18.\tLimao panas\t\t1.50\t\tno\n");
	printf("19.\tBandung ais\t\t2.00\t\tno\n");
	printf(" 0.\tExit\n");
}
void Beveragestall() { // Menu for Beverage Stall
	printf(line);
	printf("No.\tFood\t\t\t\tprice(RM)\tdelivery service\n");
	printf(line2);
	printf("1.\tApple juice\t\t\tRM 5\t\tno\n");
	printf("2.\tOrange juice\t\t\tRM 5\t\tno\n");
	printf("3.\tWatermelon juice\t\tRM 5\t\tno\n");
	printf("4.\tCucumber juice\t\t\tRM 5\t\tno\n");
	printf("5.\tPineapple juice\t\t\tRM 5\t\tno\n");
	printf("6.\tCarrot juice\t\t\tRM 5\t\tno\n");
	printf("7.\tEspresso\t\t\tRM 6\t\tyes\n");
	printf("8.\tHot Americano\t\t\tRM 7\t\tyes\n");
	printf("9.\tIced Americano\t\t\tRM 8\t\tyes\n");
	printf("10.\tHot Latte\t\t\tRM 9\t\tyes\n");
	printf("11.\tIced Latte\t\t\tRM 10\t\tyes\n");
	printf("12.\tHot Cappucino\t\t\tRM 10\t\tyes\n");
	printf("13.\tIced Cappuccino\t\t\tRM 10\t\tyes\n");
	printf("14.\tHot Mocha\t\t\tRM 9\t\tyes\n");
	printf("15.\tIced Mocha\t\t\tRM 10\t\tyes\n");
	printf(" 0.\tExit\n");
}
void Koreanstall() { // Menu for Korean Stall
	printf(line);
	printf("No.\tFood\t\t\tprice(RM)\tdelivery service\n");
	printf(line2);
	printf("1.\tTteok\t\t\tRM 2\t\tyes\n");
	printf("2.\tKimchi\t\t\tRM 4\t\tyes\n");
	printf("3.\tGimbap\t\t\tRM 4.50\t\tyes\n");
	printf("4.\tTteokbokki\t\tRM 5\t\tyes\n");
	printf("5.\tHobakjuk\t\tRM 6\t\tyes\n");
	printf("6.\tRamyun\t\t\tRM 6.5\t\tyes\n");
	printf("7.\tKimchi Fried Rice\tRM 7\t\tyes\n");
	printf("8.\tBulgogi\t\t\tRM 7\t\tyes\n");
	printf("9.\tJjajangmyeon\t\tRM 7\t\tyes\n");
	printf("10.\tKongguksu\t\tRM 7.50\t\tyes\n");
	printf("11.\tJapchae\t\t\tRM 8\t\tyes\n");
	printf("12.\tBulgogi with rice\tRM 8\t\tyes\n");
	printf("13.\tNaengmyeon\t\tRM 8.50\t\tyes\n");
	printf("14.\tBibimbap\t\tRM 9\t\tyes\n");
	printf("15.\tSundubu Jjigae\t\tRM 10\t\tyes\n");
	printf(" 0.\tExit\n");
}

void Japanesestall() { // Menu for Japanese Stall
	printf(line);
	printf("No.\tFood\t\t\t\t\t\tprice(RM)\tdelivery service\n");
	printf(line2);
	printf("1.\tMiso Soup\t\t\t\t\tRM 1.50\t\tyes\n");
	printf("2.\tChawanmushi\t\t\t\t\tRM 1.50\t\tyes\n");
	printf("3.\tGyoza\t\t\t\t\t\tRM 5\t\tyes\n");
	printf("4.\tTempura\t\t\t\t\t\tRM 5\t\tyes\n");
	printf("5.\tTamagoyaki (Egg Roll)\t\t\t\tRM 1.50\t\tyes\n");
	printf("6.\tTeriyaki Chicken Bento\t\t\t\tRM 8\t\tyes\n");
	printf("7.\tTeriyaki Vegetable Bento\t\t\tRM 6.50\t\tyes\n");
	printf("8.\tSeafood Bento\t\t\t\t\tRM 9\t\tyes\n");
	printf("9.\tChicken Katsu Don\t\t\t\tRM 8\t\tyes\n");
	printf("10.\tTempura Soba\t\t\t\t\tRM 7\t\tyes\n");
	printf("11.\tChicken Yaki Soba\t\t\t\tRM 7\t\tyes\n");
	printf("12.\tVegetable Yaki Soba\t\t\t\tRM 6\t\tyes\n");
	printf("13.\tZaru Soba\t\t\t\t\tRM 6\t\tyes\n");
	printf("14.\tZaru Soba + Tempura\t\t\t\tRM 7\t\tyes\n");
	printf("15.\tTempura Udon\t\t\t\t\tRM 7\t\tyes\n");
	printf("16.\tChicken Yaki Udon\t\t\t\tRM 7\t\tyes\n");
	printf("17.\tVegetable Yaki Udon\t\t\t\tRM 6\t\tyes\n");
	printf("18.\tZaru Udon\t\t\t\t\tRM 6\t\tyes\n");
	printf("19.\tZaru Udon + Tempura\t\t\t\tRM 7\t\tyes\n");
	printf("20.\tChicken Teriyaki Lunch Set (Miso Soup)\t\tRM 10\t\tyes\n");
	printf("21.\tTempura Lunch Set (Miso Soup)\t\t\tRM 9\t\tyes\n");
	printf("22.\tVegetarian Lunch Set (Miso Soup)\t\tRM 8\t\tyes\n");
	printf("23.\tChicken Teriyaki Dinner Set (Chawanmushi)\tRM 10\t\tyes\n");
	printf("24.\tTempura Dinner Set (Chawanmushi)\t\tRM 9\t\tyes\n");
	printf("25.\tVegetarian Dinner Set (Chawanmushi)\t\tRM 8\t\tyes\n");
	printf(" 0.\tExit\n");
}

void recommedfood() { // User asked for recommend foods from the main function
	printf(line);
	printf("\n\t\t\t\t\t\tRECOMMENDATIONS\t\t");
	printf(line);
	printf("\n");
	printf("-----MALAY STORE-----\n");
	printf("1) Nasi lemak RM2\n");
	printf("2) Nasi goreng kampung RM6\n");
	printf("3) Nasi goreng USA RM7\n");
	printf("\n");
	printf("-----MAMAK STORE-----\n");
	printf("1) Roti canai RM1.2\n");
	printf("2) Roti boom RM2.2\n");
	printf("3) Roti tisu RM3.2\n");
	printf("\n");
	printf("-----BEVERAGE STORE-----\n");
	printf("1) Iced latte RM10\n");
	printf("2) Apple juice RM5\n");
	printf("3) Orange juice RM5\n");
	printf("\n");
	printf("-----KOREAN STORE-----\n");
	printf("1) Bulgogi RM7\n");
	printf("2) Bibimbap RM9\n");
	printf("3) Ramyun Rm6.5\n");
	printf("\n");
	printf("-----JAPANESE STORE-----\n");
	printf("1) Tempura Lunch Set (Miso Soup) RM9\n");
	printf("2) Chicken Teriyaki Dinner Set (Chawanmushi) RM10\n");
	printf("3) Vegetarian Dinner Set (Chawanmushi) RM 8\n");
	printf("\n");
}
void faq() {  //FAQ from main function
	printf(line);
	printf("\n\t\t\t\t\t\tFAQ\t\t\n");
	printf(line);
	printf("\n");
	printf("Q: Is there a delivery time limit.\n");
	printf("A: Yes, every store comes with a 30-minute guarantee from the time an order is placed. If the time taken to deliver to meal is more that 30 minutes, the food becomes free.\n");
	printf("\nQ: Health and Safety\n");
	printf("A: Our workers are trained to follow our standard operating procedure strictly. Any rule breaker can be report to the respective stores.\n");
	printf("\nQ: Are our food Halal?\n");
	printf("A: While some stores have halal certifications, every food in our menu is pork free.\n");
	printf("\nQ: What happens if I am late for my pickup?\n");
	printf("A: Call the stores to inform them that you will be late.\n");
	printf("\nQ: How do I cancel an paid order.\n");
	printf("A: All paid orders cannot be cancelled/refunded.\n");
	printf("\nQ: What if the food or beverage was damaged during the delivery.\n");
	printf("A: The condition of our food/drinks and their containers are checked before the delivery. Damages can be reported to the respective stores.\n");
	printf("\nQ: Can I customize menu items?\n");
	printf("A: No.\n");
	printf("\nQ: Does the store have an allergen warning.\n");
	printf("A: No. We cannot guarantee that any item on our menus is allergen free. However we can warn customers if it is requested.\n");
	printf("\nQ: Are the eggs served by the stores free range?\n");
	printf("\nA: Free range eggs can be requested if the stores offers them.\n");
	printf("\nQ: Do I need to wear a mask for pickup?\n");
	printf("A: Yes, All customers must follow the SOP by the goverment of Malaysia when entering our stores.\n\n");
}

void onlineservice() { // Program under ordering function 
	printf("\n");
	printf(line2);
	printf("\nPlease do note that these prices are only the prices for the foods but not included with any taxes and transport fees");
	printf("\n\n");
	printf(line2);
	printf("\n");
	system("pause");
	float price = 0;
	int selection3 = 0;
	int rail = 1;

	while (rail <= 1) {
		malaytype = 0;
		mamaktype = 0;
		beveragetype = 0;
		koreantype = 0;
		japanesetype = 0;
		rail++;
		printf("\nSelect the food you would like to order from:\n");
		printf("1. Malay Stall\n");
		printf("2. Mamak Stall\n");
		printf("3. Beverage Stall\n");
		printf("4. Korean Stall\n");
		printf("5. Japanese Stall\n");
		printf("6. Submit to payment\n");
		printf("7. Quit and back to menu\n\n");
		printf("Key in here: ");
		scanf("%d", &selection3);
		if (selection3 == 1) { // User selected ordering food from Malay Store
			int malayerror = 1;
			int again = 0;
			while (malayerror <= 1) {
				Malaystall();
				printf("\nKindly select the number from the menu listed : ");
				scanf("%d", &malaytype);
				if (malaytype >= 0 && malaytype <= 13) {
					chart();
					printf("\nContinue Order from this store?\n\n");
					printf("1. Yes  2. No\n");
					printf("Key in here: ");
					scanf("%d", &again);
					if (again == 1) { // User continue purchasing from the same stall
						malayerror = 1;
					}
					else {
						malayerror++;
						rail = 1;
					}
				}
				else { // Input Error (input value invalid)
					printf("\nPlease choose a number between 1 to 13\n");
					system("pause");
					malayerror = 1;
				}
			}
		}
		if (selection3 == 2) { // User selected ordering food from Mamak Store
			int mamakerror = 1;
			int again = 0;
			while (mamakerror <= 1) {
				Mamakstall();
				printf("\nKindly select the number from the menu listed : ");
				scanf("%d", &mamaktype);
				if (mamaktype > 0 && mamaktype <= 19) {
					chart();
					printf("\nContinue Order from this store?\n\n");
					printf("1. Yes  2. No\n");
					printf("Key in here: ");
					scanf("%d", &again);
					if (again == 1) { // User continue purchasing from the same stall
						mamakerror = 1;
					}
					else {  // User continue purchasing from a different stall
						mamakerror++;
						rail = 1;
					}
				}
				else {  // Input Error (input value invalid)
					printf("\nPlease choose a number between 1 to 19\n");
					system("pause");
					mamakerror = 1;
				}
			}

		}
		if (selection3 == 3) { // User selected ordering food from Beverage Store
			int beverageerror = 1;
			int again = 0;
			while (beverageerror <= 1) {
				Beveragestall();
				printf("\nKindly select the number from the menu listed : ");
				scanf("%d", &beveragetype);
				if (beveragetype > 0 && beveragetype <= 15) {
					chart();
					printf("\nContinue Order from this store?\n\n");
					printf("1. Yes  2. No\n");
					printf("Key in here: ");
					scanf("%d", &again);
					if (again == 1) { // User continue purchasing from the same stall
						beverageerror = 1;
					}
					else {
						beverageerror++;
						rail = 1;
					}
				}
				else { // Input Error (input value invalid)
					printf("\nPlease choose a number between 1 to 15\n");
					system("pause");
					beverageerror = 1;
				}
			}

		}
		
		if (selection3 == 4) { // User selected ordering food from Korean Store
			int koreanerror = 1;
			int again = 0;
			while (koreanerror <= 1) {
				Koreanstall();
				printf("\nKindly select the number from the menu listed : ");
				scanf("%d", &koreantype);
				if (koreantype > 0 && koreantype <= 15) {
					chart();
					printf("\nContinue Order from this store?\n\n");
					printf("1. Yes  2. No\n");
					printf("Key in here: ");
					scanf("%d", &again);
					if (again == 1) { // User continue purchasing from the same stall
						koreanerror = 1;
					}
					else {
						koreanerror++;
						rail = 1;
					}
				}
				else { // Input Error (input value invalid)
					printf("\nPlease choose a number between 1 to 15\n");
					system("pause");
					koreanerror = 1;
				}
			}

		}

		if (selection3 == 5) { // User selected ordering food from Japanese Store
			int japaneseerror = 1;
			int again = 0;
			while (japaneseerror <= 1) {
				Japanesestall();
				printf("\nKindly select the number from the menu listed : ");
				scanf("%d", &japanesetype);
				if (japanesetype > 0 && japanesetype <= 25) {
					chart();
					printf("\nContinue Order from this store?\n\n");
					printf("1. Yes  2. No\n");
					printf("Key in here: ");
					scanf("%d", &again);
					if (again == 1) { // User continue purchasing from the same stall
						japaneseerror = 1;
					}
					else {
						japaneseerror++;
						rail = 1;
					}
				}
				else { // Input Error (input value invalid)
					printf("\nPlease choose a number between 1 to 25\n");
					system("pause");
					japaneseerror = 1;
				}
			}
		}
		else if (selection3 == 6) { // User is done selected foods to be ordering 
			paymenttime(); //process to payment 
			break; // end the program for the next user
		}
		else if (selection3 == 7) {
			rebegin = 1;
		}
		else {
			printf(line);
			printf("Error!\nKindly try again by choosing a number between '1' to '7' only\n");
			printf(line);
			rail = 1;
		}
	}


}
void chart() { // A program that puts user selected foods, amounts, and total prices kept into a text file
	int amount = 0;
	char buffer[100];
	if (malaytype == 1) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		total = (total + (amount * 2));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Nasi Lemak", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
		printf("%d Nasi Lemak has been added to cart\n", amount);
	}
	else if (malaytype == 2) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Nasi Goreng Kampung has been added to cart\n", amount);
		total = (total + (amount * 6));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Nasi Goreng Kampung", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);

	}
	else if (malaytype == 3) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Nasi Goreng Tomyam has been added to cart\n", amount);
		total = (total + (amount * 6.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Nasi Goreng Tomyam", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 4) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Nasi Goreng Ikan Masin has been added to cart\n", amount);
		total = (total + (amount * 6.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Nasi Goreng Ikan Masin", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 5) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Nasi Goreng Paprik has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Nasi Goreng Paprik", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 6) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Nasi Goreng USA has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Nasi Goreng USA", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 7) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Nasi Goreng Pattaya has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Nasi Goreng Pattaya", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 8) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Nasi Goreng biasa has been added to cart\n", amount);
		total = (total + (amount * 5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Nasi Goreng biasa", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 9) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Ikan Goreng has been added to cart\n", amount);
		total = (total + (amount * 3.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Ikan Goreng", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 10) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Ayam Goreng has been added to cart\n", amount);
		total = (total + (amount * 3));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Ayam Goreng", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 11) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Satay has been added to cart\n", amount);
		total = (total + (amount * 1.2));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Satay", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}
	else if (malaytype == 12) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Kuih Talam has been added to cart\n", amount);
			total = (total + (amount * 0.7));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Kuih Talam", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}
	else if (malaytype == 13) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Kuih Koci has been added to cart\n", amount);
			total = (total + (amount * 0.4));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Kuih Koci", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}
	else if (mamaktype == 1) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Roti Canai has been added to cart\n", amount);
			total = (total + (amount * 1.2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Roti Canai", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}
	else if (mamaktype == 2) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Roti Telur has been added to cart\n", amount);
			total = (total + (amount * 2.3));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Roti Telur", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}
	else if (mamaktype == 3) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Roti Cheese has been added to cart\n", amount);
			total = (total + (amount * 2.5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Roti Cheese", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}

	}
	else if (mamaktype == 4) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Roti Boom has been added to cart\n", amount);
			total = (total + (amount * 2.2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Roti Boom", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}

	}
	else if (mamaktype == 5) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Roti Planta has been added to cart\n", amount);
			total = (total + (amount * 2.2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Roti Planta", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}
	else if (mamaktype == 6) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Roti susu a has been added to cart\n", amount);
			total = (total + (amount * 2.2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Roti susu", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}
	else if (mamaktype == 7) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Roti Tisu has been added to cart\n", amount);
			total = (total + (amount * 3.2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Roti Tisu", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 8) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Tosai has been added to cart\n", amount);
			total = (total + (amount * 1.2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Tosai", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 9) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Mee Goreng has been added to cart\n", amount);
		total = (total + (amount * 5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Mee Goreng", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (mamaktype == 10) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Maggie Goreng has been added to cart\n", amount);
		total = (total + (amount * 5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Maggie Goreng", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (mamaktype == 11) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Maggie Soup has been added to cart\n", amount);
		total = (total + (amount * 4));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Maggie Soup", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (mamaktype == 12) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Teh Tarik Ais has been added to cart\n", amount);
			total = (total + (amount * 2.2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Teh Tarik", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 13) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Teh Tarik Panas has been added to cart\n", amount);
			total = (total + (amount * 1.8));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Teh Tarik", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 14) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Milo Ais has been added to cart\n", amount);
			total = (total + (amount * 2.5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Milo Ais", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 15) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Milo Panas has been added to cart\n", amount);
			total = (total + (amount * 2.2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Milo Panas", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 16) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Cincau has been added to cart\n", amount);
			total = (total + (amount * 2.5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Cincau", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 17) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Limau Ais has been added to cart\n", amount);
			total = (total + (amount * 1.8));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Limau Ais", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 18) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Limau Panas has been added to cart\n", amount);
			total = (total + (amount * 1.8));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Limau Panas", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (mamaktype == 19) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Bandung Ais has been added to cart\n", amount);
			total = (total + (amount * 2));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Bandung Ais", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (beveragetype == 1) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Apple Juice has been added to cart\n", amount);
			total = (total + (amount * 5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Apple Juice", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (beveragetype == 2) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Orange Juice has been added to cart\n", amount);
			total = (total + (amount * 5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Orange Juice", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (beveragetype == 3) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Watermelon Juice has been added to cart\n", amount);
			total = (total + (amount * 5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Watermelon Juice", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (beveragetype == 4) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Cucumber Juice has been added to cart\n", amount);
			total = (total + (amount * 5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Cucumber Juice", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (beveragetype == 5) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Pineapple Juice has been added to cart\n", amount);
			total = (total + (amount * 5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Pineapple Juice", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (beveragetype == 6) {
		if (optfororder == "1") {
			printf(" \nAmount ?\n");
			scanf("%d", &amount);
			printf("%d Carrot Juice has been added to cart\n", amount);
			total = (total + (amount * 5));
			FILE* pFile;
			int n;
			n = sprintf(buffer, "%d Carrot Juice", amount);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fclose(pFile);
		}
		else if (optfororder == "2") {
			printf(line2);
			printf("Sorry for the inconvienent but this food is not available for delivery\n");
		}
	}

	else if (beveragetype == 7) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Espresso has been added to cart\n", amount);
		total = (total + (amount * 6));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Espresso", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (beveragetype == 8) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Hot Americano has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Hot Americano", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (beveragetype == 9) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Iced Americano has been added to cart\n", amount);
		total = (total + (amount * 8));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Iced Americano", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (beveragetype == 10) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Hot Latte has been added to cart\n", amount);
		total = (total + (amount * 9));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Hot Latte", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (beveragetype == 11) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Iced Latte has been added to cart\n", amount);
		total = (total + (amount * 10));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Iced Latte", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (beveragetype == 12) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Hot Cappuccino has been added to cart\n", amount);
		total = (total + (amount * 9));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Hot Cappuccino", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (beveragetype == 13) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Iced Cappucino has been added to cart\n", amount);
		total = (total + (amount * 10));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Iced Cappucino", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (beveragetype == 14) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Hot Mocha has been added to cart\n", amount);
		total = (total + (amount * 9));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Hot Mocha", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (beveragetype == 15) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Iced Mocha has been added to cart\n", amount);
		total = (total + (amount * 10));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Iced Mocha", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 1) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Tteok has been added to cart\n", amount);
		total = (total + (amount * 2));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Tteok", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 2) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Kimchi has been added to cart\n", amount);
		total = (total + (amount * 4));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Kimchi", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 3) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Gimbap has been added to cart\n", amount);
		total = (total + (amount * 4.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Gimbap", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 4) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Tteokbokki has been added to cart\n", amount);
		total = (total + (amount * 5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Tteokbokki", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 5) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Hobakjuk has been added to cart\n", amount);
		total = (total + (amount * 6));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Hobakjuk", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 6) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Ramyun has been added to cart\n", amount);
		total = (total + (amount * 6.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Ramyun", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 7) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Kimchi Fried Rice has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Kimchi Fried Rice", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 8) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Bulgogi has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Bulgogi", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 9) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Jjajangmyeon has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Jjajangmyeon", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 10) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Kongguksu has been added to cart\n", amount);
		total = (total + (amount * 7.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Kongguksu", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 11) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Japchae has been added to cart\n", amount);
		total = (total + (amount * 8));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Japchae", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 12) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Bulgogi with Rice has been added to cart\n", amount);
		total = (total + (amount * 8));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Bulgogi with Rice", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 13) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Naengmyeon has been added to cart\n", amount);
		total = (total + (amount * 8));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Naengmyeon", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 14) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Bibimbap has been added to cart\n", amount);
		total = (total + (amount * 9));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Bibimbap", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (koreantype == 15) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Sundubu Jjigae has been added to cart\n", amount);
		total = (total + (amount * 10));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Sundubu Jjigae", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 1) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Miso Soup has been added to cart\n", amount);
		total = (total + (amount * 1.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Miso Soup", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 2) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Chawanmushi has been added to cart\n", amount);
		total = (total + (amount * 1.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Chawanmushi", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 3) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Gyoza has been added to cart\n", amount);
		total = (total + (amount * 5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Gyoza", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 4) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Tempura has been added to cart\n", amount);
		total = (total + (amount * 5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Tempura (Egg Roll)", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 5) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Tamagoyaki (Egg Roll) has been added to cart\n", amount);
		total = (total + (amount * 1.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Tamagoyaki (Egg Roll)", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 6) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Teriyaki Chicken Bento has been added to cart\n", amount);
		total = (total + (amount * 8));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Teriyaki Chicken Bento", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 7) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Teriyaki Vegetable Bento has been added to cart\n", amount);
		total = (total + (amount * 6.5));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Teriyaki Vegetable Bento", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 8) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Seafood Bento has been added to cart\n", amount);
		total = (total + (amount * 9));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Seafood Bento", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 9) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Chicken Katsu Don has been added to cart\n", amount);
		total = (total + (amount * 8));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Chicken Katsu Don", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 10) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Tempura Soba has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Tempura Soba", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 11) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Chicken Yaki Soba has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Chicken Yaki Soba", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 12) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Vegetable Yaki Soba has been added to cart\n", amount);
		total = (total + (amount * 6));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Vegetable Yaki Soba", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 13) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Zaru Soba has been added to cart\n", amount);
		total = (total + (amount * 6));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Zaru Soba", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 14) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Zaru Soba + Tempura has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Zaru Soba + Tempura", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 15) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Tempura Udon has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Tempura Udon", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 16) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Chicken Yaki Udon has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Chicken Yaki Udon", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 17) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Vegtable Yaki Udon has been added to cart\n", amount);
		total = (total + (amount * 6));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Vegtable Yaki Udon", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 18) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Zaru Udon has been added to cart\n", amount);
		total = (total + (amount * 6));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Zaru Udon", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 19) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Zaru Udon + Tempura has been added to cart\n", amount);
		total = (total + (amount * 7));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Zaru Udon + Tempura", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 20) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Chicken Teriyaki Lunch Set (Miso Soup) has been added to cart\n", amount);
		total = (total + (amount * 10));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Chicken Teriyaki Lunch Set (Miso Soup)", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 21) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Tempura Lunch Set (Miso Soup) has been added to cart\n", amount);
		total = (total + (amount * 9));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Tempura Lunch Set (Miso Soup)", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 22) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Vegetable Lunch Set (Miso Soup) has been added to cart\n", amount);
		total = (total + (amount * 8));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Vegetable Lunch Set (Miso Soup)", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 23) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Chicken Teriyaki Dinner Set (Chawanmushi) has been added to cart\n", amount);
		total = (total + (amount * 10));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Chicken Teriyaki Dinner Set (Chawanmushi)", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 24) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		printf("%d Tempura Dinner Set (Chawanmushi) has been added to cart\n", amount);
		total = (total + (amount * 9));
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Tempura Dinner Set (Chawanmushi)", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
	}

	else if (japanesetype == 25) {
		printf(" \nAmount ?\n");
		scanf("%d", &amount);
		FILE* pFile;
		int n;
		n = sprintf(buffer, "%d Vegetarian Dinner Set (Chawanmushi)", amount);
		pFile = fopen("receipt.txt", "a");
		fputs("\n", pFile);
		fputs(buffer, pFile);
		fclose(pFile);
		printf("%d Vegetarian Dinner Set (Chawanmushi) has been added to cart\n", amount);
		total = (total + (amount * 8));
	}
}

void paymenttime() {  // Calculation for the user's total amount spend for the entire order
	float totalpayment = 0;
	float taxes = 0;
	taxes = (total * .6);
	total = total + taxes;
	if (optfororder == "1") { //self delivery
		if (total == 0) {
			printf("\nySorry, you did not make any purchases with us hence your total payment is RM %.2f\n\n", total);
		}
		else {
			printf("\nYour total payment is RM %.2f\n", total);
			printf("\n");
			FILE* pFile;
			char buffer[1000];
			int n;
			n = sprintf(buffer, "Total amount: RM %.2f", total);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fputs("\n", pFile);
			fputs("---------------------------\n", pFile);
			fclose(pFile);
			char ch;
			fstream fp;
			fp.open("receipt.txt", fstream::in);
			while (fp >> noskipws >> ch)
				cout << ch;
			fp.close();
			cout << endl;
		}
	}
	else if (optfororder == "2") { // Food Delivery
		float transportfee = 0;
		if (total == 0) {
			printf("\nyou did not make any purchases with us hence your total payment is RM %.2f\n", total);
		}
		else {
			printf("Delivery fee will be added with an additional of fixed price of RM10.....\n");
			transportfee = 10;
			total = total + transportfee;
			FILE* pFile;
			char buffer[1000];
			int n;
			n = sprintf(buffer, "Total amount:RM %.2f", total);
			pFile = fopen("receipt.txt", "a");
			fputs("\n", pFile);
			fputs(buffer, pFile);
			fputs("\n", pFile);
			fputs("---------------------------\n", pFile);
			fclose(pFile);
			printf("\nYour total payment is RM %.2f\n", total);
			char chaa;
			fstream fp;
			fp.open("receipt.txt", fstream::in);
			while (fp >> noskipws >> chaa)
				cout << chaa;
			fp.close();
			cout << endl;
		}
	}
	system("pause");
	ending();
}

void ending() { // Ending sentences before exiting the entire program
	printf("\n");
	printf(line);
	printf("Thank you for choosing Nott-A-Cafe online food store :D\n");
	printf("We hope to see you again soon !\n");
	printf(line);
	system("pause");
}