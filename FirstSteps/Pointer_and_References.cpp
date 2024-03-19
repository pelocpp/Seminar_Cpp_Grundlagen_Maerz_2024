void pointer_and_references()
{
    // C

    int n;

    int wieGross = sizeof (int);

    n = 123;

    // Adresse einer Variablen   // 1024
    int* ip;

    ip = &n;   // Adresse von n: Operator &

    // n den Wert 456 zuweisen -
    // ohne den Bezeichner 'n' dabei zu verwenden:
    // indirekte Zugriff: Operator *
    *ip = 456;

    // was geht noch mit Zeigern - und damit in C (und damit auch in C++)

    // Zeiger-Arithmetik

    ip++;

    // oder
    // ip = ip + 1;

    // Bei ++ und einem Zeiger auf int wird die Adresse um 4 inkrementiert !!!
    // Wieso 4:  sizeof (int) = 4 Bytes auf diesem Rechner

    // Frage: ip vorher:  1024   // ip nachher: 1028

   // *ip = 789;    // Geht das ???????????????????????????????  NEIN

    ip--;

    *ip = 789;
}

// why ???????????????????????????????????

void malZwei(int n)     //  Call-by-Value
{
    n = 2 * n;
}

void malZwei02(int* n)   //  Call-by-Address  // C - damit auch in C++
{
   // n = 2 * n;

    int tmp;

    tmp = *n;

    tmp = 2 * tmp;

    *n = tmp;

    // ginge auch kürzer:

    // *n = 2 * *n;
}

// C# - hier gibt es ein ref Schlüsselwort
//void malZwei02(ref int n)   //  Call-by-Address
//{
//    int tmp;
//
//    tmp = n;
//
//    tmp = 2 * tmp;
//
//    n = tmp;
//}





void pointer_and_references_02()
{
    // ================================================================
    // C

    int n = 123;

    // Variable vom Typ "Zeiger" / "Pointer" (Zeiger auf int)
    int* ip = nullptr;

    // Adresse von n: Adress-Operator & // "referenzieren"
    ip = &n;

    // Indirekter Variablen Zugriff // Adressvariable "dereferenzieren"
    *ip = 456;         // schreiben
    int value = *ip;   // lesen
    
    // ================================================================
    // C++

    int m = 123;

    // Variable vom Typ "Referenz"
    int& ri = m;

    ri = 456;
    int k = ri;

    int x = 999;

    ri = x;   // es wird KEIN neuer Alias gesetzt,
              // sondern der Wert von x an m zugewiesen
}


// ==========================================================
// ==========================================================

void MalZwei01 (int n)     //  Call-by-Value
{
    n = 2 * n;
}

void MalZwei02 (int* n)    //  Call-by-Address   // C - Stilistik
{
    int tmp = *n;
    tmp = 2 * tmp;
    *n = tmp;
}

void MalZwei03 (int& n)    //  Call-by-Reference // C++ - Stilistik
{
    n = 2 * n;
}


void pointer_and_references_anwendung_01()
{
    int x = 123;

    MalZwei01(x);      // Call-by-Value // Call-by-Copy

    malZwei02(&x);     // Call-by-Address 

    MalZwei03(x);      // Call-by-Reference
}
