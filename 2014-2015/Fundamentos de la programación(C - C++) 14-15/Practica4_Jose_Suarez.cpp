#include <iostream>
#include <stdio.h>

struct Mina
{
	int i; // coordenada x de la mina
	int j; // coordenada y de la mina
};
struct Excavacio
{
	int i; // coordenada x de l’excavació
	int j; // coordenada y de l’excavació
};
struct Tauler
{
	int F; // número de files del tauler
	int C; // número de columnes del tauler
	char* dadesEnunciat; // punter a array on es guarden les dades de
	//l’enunciat del joc, és a dir una matriu de dues dimensions amb ‘X’ on no hi ha
	//res i amb ‘M’ on hi ha mines
		char* dadesJoc; // punter a array on es guarden les dades de la partida,
	//és a dir una matriu de dues dimensions on en els llocs no descoberts hi ha ‘X’,
		//en els descoberts un número amb el número de mines adjacents i una ‘@’ si s’ha
		//excavat en una mina
		int casellesPendents; // número de caselles pendents de destapar per a
	//guanyar la partida
};
int ReadInteger()
{
	int i = 0;
	char c = getchar();
	char buffer[128];
	while (c == ' ' || c == '\n')c = getchar();
	while (c != ' ' && c != '\n' && c != EOF)
	{
		buffer[i] = c;
		i++;
		c = getchar();
	}
	buffer[i] = '\0';
	return atoi(buffer);
}
Mina* LlegirMines(int numMines)
{
	Mina* miina = new Mina[numMines];
	for (int i = 0; i < numMines; i++)
	{
		miina[i].i = ReadInteger();
		miina[i].j = ReadInteger();
	}
	return miina;
	
	
	/*Funció que llegeix les mines, les fica en un array dinàmic i retorna un
	punter que apunta a l’array*/
}
void DestruirMines(Mina* p_mina)
{
	delete p_mina;
	//Funció que allibera la memòria dinàmica reservada per a les mines
}
Excavacio* LlegirExcavacions(int numExcavacions)
{
	Excavacio* exca = new Excavacio[numExcavacions];
	for (int i = 0; i < numExcavacions; i++)
	{
		exca[i].i = ReadInteger();
		exca[i].j = ReadInteger();
		
	}
	return exca;

	//Funció que llegeix les excavacions, les fica en un array dinàmic i
	//retorna un punter que apunta a l'array
}
void DestruirExcavacions(Excavacio* p_excavacio)
{
	delete p_excavacio;
	//Funció que allibera la memòria dinàmica reservada per a les excavacions
}
Tauler* CrearTauler(int F, int C)
{
	Tauler* tauler = new Tauler;
	tauler->F = F;
	tauler->C = C;
	tauler->dadesEnunciat = new char[(F*C)];
	tauler->dadesJoc = new char[(F*C)];
	tauler->casellesPendents;
	return tauler;


	//Funció que reserva la memòria dinàmica per a un tauler i retorna un
	//punter que apunta al tauler creat
}
void DestruirTauler(Tauler* p_tauler)
{
	delete p_tauler;
	//Funció que allibera la memòria dinàmica reservada per al tauler
}
void ImprimirCasella(Tauler* p_tauler, char* dades, int fila, int columna)
{
	for (int i = 0; i < fila*columna; i++)
	{
		int numColumnes = p_tauler->C;
		int Element = (fila * numColumnes) + columna;
		printf("%c ", dades[Element]);

	}
	//Funció que imprimeix la casella situada a les coordenades [fila,
	//columna] de les dades i tauler indicat
}
void ModificarCasella(Tauler* p_tauler, char* dades, int fila, int columna, char valor)
{	
	int numColumnes = p_tauler->C;
	int Element = (fila*numColumnes) + columna;
	dades[Element] = valor;
	//Funció que aplica les mines a les dades de l'enunciat (substitueix les
	//'X' per 'M')
}
	
	

int CalcularMinesAdjacents(Tauler* p_tauler, int fila, int columna)
{
	int NumMinesAdjacents = 0;
	int numColumnes = p_tauler->C;

	for (int i = (fila - 1); i <= (fila + 1); i++)
	{
		for (int j = (columna - 1); j <= (columna + 1); j++)
		{
			if ((i >= 0 && j >= 0) && (i<p_tauler->F && j<p_tauler->C))// establecer parámetros
			{
				int Element = (i* numColumnes) + j;
				if (p_tauler->dadesEnunciat[Element] == 'M')
				{
					NumMinesAdjacents++;
				}
			}
		}
	}
	//printf("%d", numMinesAdjacents);
	return NumMinesAdjacents;
}
	
		
			//Funció que retorna el número de mines adjacents a una certa posició

void ImprimirTaulerDades(Tauler* p_tauler, char* dades)
{
	int columnas = 0;
	for (int i = 0; i < p_tauler->F*p_tauler->C; i++)
	{
		if (columnas == p_tauler->C)
		{
			printf("\n");
			columnas = 0;
		}
	
			printf("%c", dades[i]);
			printf(" ");
			columnas++;
		//Funció que imprimeix les dades indicades del tauler indicat


	}
	printf("\n");
}

	
	
void ActualitzarTaulerEnunciat(Tauler* tauler, Mina* mines, int numMines)
{
	for (int i = 0; i < numMines; i++)
	{
		ModificarCasella(tauler, tauler->dadesEnunciat, mines[i].i, mines[i].j, 'M');
	}
	tauler->casellesPendents = (tauler->C*tauler->F) - numMines;
	/*for (int i = 0; i < numMines; i++)
	{
		ModificarCasella(tauler, tauler->dadesJoc, mines[i].i, mines[i].j, 'M');
	}*/
	tauler->casellesPendents = (tauler->C*tauler->F) - numMines;
	//Funció que aplica les mines a les dades de l'enunciat (substitueix les
	//'X' per 'M')
}
void ActualitzarTaulerJoc(Tauler* tauler, Excavacio* excavacions, int
	numExcavacions)
{

	for (int i = 0; i < numExcavacions; i++)
	{
		int Element = ((excavacions[i].i)*(tauler->C)) + excavacions[i].j;
		if (i == numExcavacions - 1)
		{
			printf("YOU WIN\n");
		}
		if (tauler->dadesEnunciat[Element] == 'M')
		{
			ModificarCasella(tauler, tauler->dadesJoc, excavacions[i].i, excavacions[i].j, '@');
			printf("Game Over\n");
			break;
		}
		if (numExcavacions != tauler->casellesPendents)
		{
			printf("UNFINISHED GAME\n");
			break;
		}
		else
		{
			ModificarCasella(tauler, tauler->dadesJoc, excavacions[i].i, excavacions[i].j, 48 + CalcularMinesAdjacents(tauler, excavacions[i].i, excavacions[i].j));
			//Modificamos con el CalcularMinesAdjacents el array dadesJoc para dejar los números de minas cercanos, el 48 es debido al número de carácteres existentes, siendo el 48 = 0.
		}
		//Funció que aplica totes les jugades del fitxer d'entrada i indica quin
		//és el resultat de la partida	
	}
}
void InicialitzarTaulers(Tauler* tauler, int F, int C)
{

	for (int i = 0; i < F*C; i++)
	{
		tauler->dadesEnunciat[i] = 'X';
	}
	for (int i = 0; i < (tauler->F)*(tauler->C); i++)
	{
		tauler->dadesJoc[i] = 'X';
	}
	//Funció que inicialitza les dades de l'enunciat i del joc amb 'X' a tot
	//arreu
}
int main()
{
	int files = ReadInteger();
	int columnes = ReadInteger();
	int numMines = ReadInteger();
	int numExcavacions = ReadInteger();
	Tauler* tauler = CrearTauler(files, columnes);
	Mina* mines = LlegirMines(numMines);
	Excavacio* excavacions = LlegirExcavacions(numExcavacions);
	InicialitzarTaulers(tauler, files, columnes);
	ActualitzarTaulerEnunciat(tauler, mines, numMines);
	ActualitzarTaulerJoc(tauler, excavacions, numExcavacions);
	ImprimirTaulerDades(tauler, tauler->dadesEnunciat);
	printf("---\n");
	ImprimirTaulerDades(tauler, tauler->dadesJoc);
	DestruirTauler(tauler);
	DestruirMines(mines);
	DestruirExcavacions(excavacions);
	// Return correct
	return 0;
}



