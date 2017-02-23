#include <iostream>
#include <vector>
using namespace std;

// Strukturen
struct Waffe
{
    string waffentyp;
    int schaden;
};


struct Puppe
{
    string puppentyp;
    int puffer;
};


struct Held
{
    string heldenname;
    string geschlecht; // "m" / "w"
    int alter;         // in Jahren
    int gewicht;       // in kg
};


int check_int(int x)
{
    while (1)
    {
        if (cin >> x)
        {
            break;
        } else
        {
            cout << "Eingabe ungueltig! Bitte wiederholen: ";
            cin.clear();
            while (cin.get() != '\n') ;
        }
    }
    return x;
}


string check_string(string x)
{
    while (1)
    {
        if (cin >> x)
        {
            break;
        } else
        {
            cout << "Eingabe ungueltig! Bitte wiederholen: ";
            cin.clear();
            while (cin.get() != '\n') ;
        }
    }
    return x;
}


// Funktionen
void uebung(Held spieler, Waffe waffe, Puppe puppe)
{
    int anzahl_schlaege = 0;
    int zugefuegter_schaden = 0;
    int max_puffer = puppe.puffer;

    // Kampfberechnung // Dialog hinzufuegen?
    while (puppe.puffer > 0)
    {
        puppe.puffer = puppe.puffer - waffe.schaden;
        anzahl_schlaege = ++anzahl_schlaege;
        zugefuegter_schaden = zugefuegter_schaden + waffe.schaden;
    }

    // Verhindern von Schaden groesser als Target Puffer
    if (zugefuegter_schaden > max_puffer)
    {
        zugefuegter_schaden = max_puffer;
    }

    // Kampf Statistik
    cout << spieler.heldenname << " greift " << puppe.puppentyp << " an!" << endl;
    cout << "Anzahl der Schlaege: " << anzahl_schlaege << endl;
    cout << "Zugefuegter Schaden: " << zugefuegter_schaden << endl;
    cout << "Waffe: " << waffe.waffentyp << endl;
    cout << "Puppe: " << puppe.puppentyp << endl << endl;
    do
    {
    cout << "Eingabe zum Fortsetzen drücken.. ";
    cin.get();
    } while (cin.get() != '\n');
    cout << endl;
}


void menu(Held spieler, vector<Waffe> waffen, vector<Puppe> puppen)
{
    bool display_menu = true;

    // Vorgabewerte
    Held selected_held = spieler;
    Waffe selected_waffe = waffen[0];
    Puppe selected_puppe = puppen[0];

    while (display_menu == true)
    {
        cout << "|======= Menu ========|" << endl;
        cout << "| Held erstellen....1 |" << endl;
        cout << "| Waffenwahl........2 |" << endl;
        cout << "| Puppenwahl........3 |" << endl;
        cout << "| Uebung............4 |" << endl;
        cout << "| Exit..............5 |" << endl;
        cout << "|=====================|" << endl;
        cout << ">>> ";

        int menu_select = 0;
        int selection = 0;
        menu_select = check_int(menu_select);
        cout << endl;
        switch (menu_select) // Handling von falschen Datentypen bei Benutzereingabe?
        {
            case 1:
                do
                {
                    cout << "Neuer Heldenname (maximal 20 Zeichen): ";
                    spieler.heldenname = check_string(spieler.heldenname);
                } while (spieler.heldenname.length() > 20);
                do
                {
                    cout << "Neues Geschlecht (m/w): ";
                    spieler.geschlecht = check_string(spieler.geschlecht);
                } while (spieler.geschlecht != "m" && spieler.geschlecht != "w");
                do
                {
                    cout << "Neues Alter (6-120): ";
                    spieler.alter = check_int(spieler.alter);
                } while (spieler.alter < 6 || spieler.alter > 120);
                do
                {
                    cout << "Neues Gewicht (20-220): ";
                    spieler.gewicht = check_int(spieler.gewicht);
                } while (spieler.gewicht < 20 || spieler.gewicht > 220);
                selected_held = spieler;
                cout << endl;
                continue;
            case 2:
                cout << "Waffe auswaehlen:" << endl;
                for (int i = 0; i < (waffen.size()); i++)
                {
                    string dots = string((18 - waffen[i].waffentyp.length()), '.');
                    cout << waffen[i].waffentyp << dots << i + 1 << endl;
                }
                cout << ">>> ";

                selection = check_int(selection);
                cout << endl;
                selected_waffe = waffen[selection - 1];
                continue;
            case 3:
                cout << "Puppe auswaehlen:" << endl;
                for (int i = 0; i < (puppen.size()); i++)
                {
                    string dots = string((18 - puppen[i].puppentyp.length()), '.');
                    cout << puppen[i].puppentyp << dots << i + 1 << endl;
                }
                cout << ">>> ";

                selection = check_int(selection);
                cout << endl;
                selected_puppe = puppen[selection - 1];
                continue;
            case 4:
                uebung(selected_held, selected_waffe, selected_puppe);
                continue;
            case 5: // Exit
                display_menu = false;
                break;
            default:
                cout << "Eingabe ungueltig: " << menu_select << endl;
        }
    }
}


int main() {
    // Held initialisieren
    Held spieler;
    spieler.heldenname = "Spieler";
    spieler.geschlecht = "m";
    spieler.alter = 30;
    spieler.gewicht = 70;

    // Waffen initialisieren
    Waffe dolch, knueppel, schwert;
    dolch.waffentyp = "Dolch";
    dolch.schaden = 5;
    knueppel.waffentyp = "Knueppel";
    knueppel.schaden = 7;
    schwert.waffentyp = "Schwert";
    schwert.schaden = 10;
    vector<Waffe> waffen = {dolch, knueppel, schwert};

    // Puppen initialisieren
    Puppe strohpuppe, holzpuppe, eisenpuppe;
    strohpuppe.puppentyp = "Strohpuppe";
    strohpuppe.puffer = 20;
    holzpuppe.puppentyp = "Holzpuppe";
    holzpuppe.puffer = 50;
    eisenpuppe.puppentyp = "Eisenpuppe";
    eisenpuppe.puffer = 500;
    vector<Puppe> puppen = {strohpuppe, holzpuppe, eisenpuppe};

    menu(spieler, waffen, puppen);
}
