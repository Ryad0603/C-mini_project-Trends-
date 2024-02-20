/*
Versie 1.0
Voor vak Trends
*/

#include <iostream>
#include <ctime>
using namespace std;

// Functie voor het negeren van de rest van de regel in de invoerstroom
void IgnoreLine() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Functie voor het weergeven van het submenu en het maken van vormen
void menu() {
	char keuze;
	cout << "Maak een keuze: " << endl;
	cout << "A. Maak een driehoek: " << endl;
	cout << "B. Maak een N-figuur: " << endl;
	cout << "C. Maak een omgekeerde N: " << endl;
	cout << "D. Maak een K-figuur: " << endl;
	cout << "E. Speel een spel" << endl;
	cout << "Q. Om te stoppen" << endl;
	cout << "Keuze: ";
	cin >> keuze;

	switch (toupper(keuze)) {
	case 'A': {
		int hoogte;
		cout << "Kies hoogte van driehoek: ";
		cin >> hoogte;

		while ((cin.fail()) || hoogte <= 3) {
			IgnoreLine();
			cout << "Foutieve invoer, probeer opnieuw! (Getal moet minstens 4 zijn, letters zijn niet toegelaten!): ";
			cin >> hoogte;
		}

		for (int i = 0; i < hoogte; i++) {
			for (int j = 0; j < i + 1; j++) {
				cout << "*";
			}
			cout << " " << endl;
		}
		break;
	}

	case 'B': {
		int hoogte_n;

		cout << "Kies de hoogte van de N-figuur (min 4): ";
		cin >> hoogte_n;

		while ((cin.fail()) || hoogte_n <= 3) {
			IgnoreLine();
			cout << "Foutieve invoer, probeer opnieuw! (Getal moet minstens 4 zijn, letters zijn niet toegelaten!): ";
			cin >> hoogte_n;
		}

		for (int i = 0; i < hoogte_n; i++) {
			for (int j = 0; j < hoogte_n; j++) {
				if (j == 0 || j == hoogte_n - 1 || i == j)
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
		}
		break;
	}

	case 'C': {
		int hoogte_om_n;

		cout << "Kies de hoogte voor de omgekeerde N-figuur (minstens 4): ";
		cin >> hoogte_om_n;

		while ((cin.fail()) || hoogte_om_n <= 3) {
			IgnoreLine();
			cout << "Foutieve invoer, probeer opnieuw! (Getal moet minstens 4 zijn, letters zijn niet toegelaten!): ";
			cin >> hoogte_om_n;
		}

		for (int i = 0; i < hoogte_om_n; i++) {
			for (int j = 0; j < hoogte_om_n; j++) {
				if (j == 0 || j == hoogte_om_n - 1 || j == hoogte_om_n - 1 - i)
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
		}
		break;
	}

	case 'D': {
		int hoogte_k;

		cout << "Kies de hoogte voor de K-figuur (minstens 5): ";
		cin >> hoogte_k;

		while ((cin.fail()) || hoogte_k <= 4) {
			IgnoreLine();
			cout << "Foutieve invoer, probeer opnieuw! (Getal moet minstens 5 zijn, letters zijn niet toegelaten!): ";
			cin >> hoogte_k;
		}

		if (hoogte_k % 2)
			hoogte_k++;

		for (int i = 0; i < hoogte_k; i++) {
			for (int j = 0; j < hoogte_k; j++) {
				if (j == 0 || j == hoogte_k / 2 - i || j == i - (hoogte_k / 2))
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
		}
		break;
	}

	case 'E': {
		// Speel het spel
		cout << "Speel het spel..." << endl;
		break;
	}

	case 'Q': {
		cout << "Bedankt voor uw bezoek, kom zeker nog eens langs!" << endl;
		exit(0); // Beëindig het programma
		break;
	}

	default:
		cout << "Ongeldige invoer, probeer opnieuw." << endl;
		break;
	}
}

int main() {
	srand(time(nullptr));

	while (true) {
		menu();
	}

	return 0;
}