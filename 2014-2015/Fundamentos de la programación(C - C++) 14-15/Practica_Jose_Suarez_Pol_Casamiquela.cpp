// Retornar tipus de la casella (f,c)
// Jose Suárez Weaver, Pol Casamiquela Vazquez 
#include "lectura.h"
#include "Material.h"
#include "Itinerari.h"
#include "Mapa.h"
#include "ArrayInt.h"
#include <stdio.h>

EMaterial Mapa_ConsultarMaterial(const Mapa& mapa, int f, int c)
{

	int element = (f*mapa.C) + c;
	return mapa.dades[element];
	//[COMPLETAR]



}

/* Alliberar tota la memoria reservada pel mapa */


/*Llegir valors d'stdin i inicialitzar el mapa.
- TOTS els valors a llegir son de tipus int.

Format:
#F #C #R
R0.min_f R0.min_c R0.max_f R0.max_c R0.min_c R0.tipus
R1.min_f R1.min_c R1.max_f R1.max_c R1.min_c R1.tipus
...

Exemple (test0.txt) (comentaris NO formen part de les dades)
5 10 2           //5 files, 10 columnes, 2 rectangles
1 1 2 4 2        //R0 = min = (1,1), max = (2,5), tipus = 2 (herba, '/')
2 3 3 6 3        //R1 = min = (2,3), max = (3,6), tipus = 3 (fang, '#')
...
*/
void Mapa_LlegirStdin(Mapa& mapa)
{
	mapa.F = readint();
	mapa.C = readint();
	int R = readint();
	//ArrayInt C;
	//AI_Crear(C);
	//C.dades = new int[mapa.C*mapa.F];
	//AI_Longitud(C);
	//AI_DadesEnIndex(C, mapa.F*mapa.C);
	//AI_AfegirAlFinal(C, mapa.F*mapa.C);
	mapa.dades = new EMaterial[mapa.F*mapa.C];
	EMaterial material = Convertir_Int_A_Material(0);//creamos una variable de material eBuit param llenar el mapa de este material

	for (int i = 0; i < mapa.F*mapa.C; i++)
	{

		mapa.dades[i] = material; //llenamos el mapa con el material eBuit.

	}

	for (int i = 0; i < R; i++)
	{
		//leemos los datos del rectángulo.
		int minf1 = readint();
		int minc1 = readint();
		int maxf2 = readint();
		int maxc2 = readint();
		int mat = readint();
		for (int i = minf1; i <= maxf2; i++)
		{
			for (int j = minc1; j <= maxc2; j++)
			{
				int element = (i*mapa.C) + j;

				mapa.dades[element] = Convertir_Int_A_Material(mat);//colocamos el material en el intevalo que hay entre los puntos del rectángulo.

			}
		}

	}

	//delete C.dades;



	//[COMPLETAR]
}

void Mapa_Destruir(Mapa& mapa)
{
	delete[] mapa.dades;
	//[COMPLETAR]
}

//----------------------------------------------------------------
// Mapa: Funcions [DONADES]
//----------------------------------------------------------------
void Mapa_Crear(Mapa& mapa)
{
	mapa.F = 0;
	mapa.C = 0;
	mapa.dades = 0;
}

/* Escriure matriu de F*C caracters que representin el tipus de cada casella (i,j) del mapa.
- Usar la funcio Convertir_Material_A_Char() per convertir d'EMaterial a char

Exemple (test0.txt)
..........
.////.....
.//####...
...####...
..........
*/
void Mapa_EscriureStdout(const Mapa& mapa)
{
	for (int f = 0; f<mapa.F; f++)
	{
		for (int c = 0; c<mapa.C; c++)
			putchar(Convertir_Material_A_Char(Mapa_ConsultarMaterial(mapa, f, c)));
		putchar('\n');
	}
}

//----------------------------------------------------------------
// Itinerari: Funcions [COMPLETAR]
//----------------------------------------------------------------
void Itinerari_Destruir(Itinerari& itinerari)
{
	delete[] itinerari.array_f.dades;
	delete[] itinerari.array_c.dades;
	//[COMPLETAR]
}
int Itinerari_Longitud(const Itinerari& itinerari)
{
	//[COMPLETAR]
	return AI_Longitud(itinerari.array_f);
}

/* Llegir P > 3 punts (f,c) que formen un itinerari tancat.
- TOTS els valors a llegir son de tipus int.
- A les dades d'entrada l'ultim punt es EXACTAMENT igual al primer.
- El primer i l'ultim punt guardats a l'Itinerari HAN de ser iguals.
- NO sabeu, a priori, quants punts hi ha.

Exemple:
-Entrada (test0.txt)
...
0 0
3 5
0 9
0 0
-Sortida (test0.out)
...
(2) Llegint itinerari...
(0,0)->(3,5)->(0,9)->(0,0)
...
*/
void Itinerari_LlegirStdin(Itinerari& itinerari)
{
	
	int f = readint();
	int c = readint();
	int f2 = readint();// cogemos los valores siguientes.
	int c2 = readint();
	AI_AfegirAlFinal(itinerari.array_f, f);// lo añadimos al ArrayInt
	AI_AfegirAlFinal(itinerari.array_c, c);

	while ((f2 != f) || (c2 != c)) // hasta que no llegue al final del ArrayInt
	{
		AI_AfegirAlFinal(itinerari.array_f, f2);// añadimos los valores al AI
		AI_AfegirAlFinal(itinerari.array_c, c2);
		f2 = readint(); // cogemos valores siguientes y hasta que no se repitan los puntos no se acaba el itinerari
		c2 = readint();
	}
	AI_AfegirAlFinal(itinerari.array_f, f2); //añadimos los valores finales.
	AI_AfegirAlFinal(itinerari.array_c, c2);
	//[COMPLETAR]
}

/* Calcula itinerari detallat equivalent on cada casella es
immediatament adjacent a l'anterior.
[PISTES]
- Usar la funcio Itinerari_CalcularMoviment() per anar generant
CADASCUNA de les caselles entre un punt de l'itinerari base i el
seguent, INCLOSOS, i afegir-les a l'itinerari_detallat.
- Heu d'escriure 2 bucles ennierats, un d'exterior per als
punts d'itinerari i un d'interior per als punts
intermitjos d'itinerari_detallat generats.

Exemple:
-Entrada (test0.txt)
...
0 0
3 5
0 9
0 0
-Sortida (test0.out)
...
(3) Detallant itinerari...
(0,0)->(0,1)->(0,2)->(0,3)->(1,3)->(1,4)->(2,4)->(2,5)->(3,5)->(3,6)->(3,7)->(2,7)->(2,8)->(1,8)->(1,9)->(0,9)->(0,8)->(0,7)->(0,6)->(0,5)->(0,4)->(0,3)->(0,2)->(0,1)->(0,0)
...
*/
void Itinerari_Detallar(const Itinerari& itinerari, Itinerari& itinerari_detallat)
{
	int f1;
	int f2;
	int c1;
	int c2;
	for (int i = 0; i < (itinerari.array_c.longitud - 1); i++)
	{
	
		//cogemos las coordenadas del itinerari inicial
		f1 = itinerari.array_f.dades[i];
		c1 = itinerari.array_c.dades[i];
		f2 = itinerari.array_f.dades[i + 1];
		c2 = itinerari.array_c.dades[i + 1];

		while ((f1 != f2) || (c1 != c2))
		{
			// metemos las coordenadas  al itinerari detallat
			AI_AfegirAlFinal(itinerari_detallat.array_f, f1);
			AI_AfegirAlFinal(itinerari_detallat.array_c, c1);
			Itinerari_CalcularMoviment(f1, c1, f2, c2);// calculamos el movimiento del coche hasta que ya no se mueva
		}
	}

AI_AfegirAlFinal(itinerari_detallat.array_f, f1);
AI_AfegirAlFinal(itinerari_detallat.array_c, c1);
	

	//[COMPLETAR]
}

//----------------------------------------------------------------
// Itinerari: Funcions [DONADES]
//----------------------------------------------------------------
void Itinerari_Crear(Itinerari& itinerari)
{
	AI_Crear(itinerari.array_f);
	AI_Crear(itinerari.array_c);
}

void Itinerari_EscriureStdout(const Itinerari& itinerari)
{
	if (Itinerari_Longitud(itinerari) == 0) return;
	printf("(%d,%d)", AI_DadesEnIndex(itinerari.array_f, 0), AI_DadesEnIndex(itinerari.array_c, 0));
	for (int i = 1; i<Itinerari_Longitud(itinerari); i++)
		printf("->(%d,%d)", AI_DadesEnIndex(itinerari.array_f, i), AI_DadesEnIndex(itinerari.array_c, i));
	printf("\n");
}

/* Calcula coordenades MODIFICADES resultants de moure's una casella
des de (f,c) cap a (target_f,target_c), sense permetre moviment
diagonal i prioritzant moviment horitzontal (en c)
- Si ja es al target no es mou!
*/
void Itinerari_CalcularMoviment(int& f, int& c, int target_f, int target_c)
{
	int diff_f = target_f - f;
	int diff_c = target_c - c;
	int abs_diff_f = (diff_f < 0) ? -diff_f : diff_f;
	int abs_diff_c = (diff_c < 0) ? -diff_c : diff_c;
	if (abs_diff_f != 0 || abs_diff_c != 0)
	{
		if (abs_diff_f <= abs_diff_c)
			c = (diff_c < 0) ? c - 1 : c + 1;
		else //( abs_diff_f > abs_diff_c )
			f = (diff_f < 0) ? f - 1 : f + 1;
	}
}

//----------------------------------------------------------------
// Altres Funcions [DONADES]
//----------------------------------------------------------------
void EscriureStdout_Itineraris_Sobre_Mapa(const Mapa& mapa, const Itinerari& itinerari, const Itinerari& itinerari_detallat)
{
	if (mapa.F*mapa.C == 0) return;
	char* text = new char[mapa.F*mapa.C];
	for (int f = 0; f<mapa.F; f++)
		for (int c = 0; c<mapa.C; c++)
			text[f*mapa.C + c] = Convertir_Material_A_Char(Mapa_ConsultarMaterial(mapa, f, c));
	for (int i = 0; i<Itinerari_Longitud(itinerari_detallat); i++)
	{
		int f = AI_DadesEnIndex(itinerari_detallat.array_f, i);
		int c = AI_DadesEnIndex(itinerari_detallat.array_c, i);
		text[f*mapa.C + c] = 'i';
	}
	for (int i = 0; i<Itinerari_Longitud(itinerari); i++)
	{
		int f = AI_DadesEnIndex(itinerari.array_f, i);
		int c = AI_DadesEnIndex(itinerari.array_c, i);
		text[f*mapa.C + c] = 'I';
	}
	for (int f = 0; f<mapa.F; f++)
	{
		for (int c = 0; c<mapa.C; c++)
			putchar(text[f*mapa.C + c]);
		putchar('\n');
	}
	delete[] text;
}


//----------------------------------------------------------------
// Altres Funcions [COMPLETAR]
//----------------------------------------------------------------
/* Calcular temps total de l'itinerari.
- Sumar el temps de totes les caselles de l'itinerari
- Usar la funcio Convertir_Material_A_Temps() per obtenir el temps d'una casella a partir del seu tipus.
- Si l'itinerari passa per una casella de tipus ePunxes, totes les caselles posteriors dupliquen el seu temps.
- Si despres passa per altres caselles ePunxes l'efecte NO s'acumula (mai es quadruplica el temps)
- El temps de la primera casella de l'itinerari nomes s'ha de comptar 1 cop, a l'INICI.
*/
int CalcularTempsItinerari(const Mapa& mapa, const Itinerari& itinerari)
{



	int tiempo = 0;
	int pinch = 0;
	for (int i = 0; i < (itinerari.array_f.longitud - 1); i++)
	{
		//int pinch = 0;

		int f = itinerari.array_f.dades[i];
		int c = itinerari.array_c.dades[i];
		int mat = Mapa_ConsultarMaterial(mapa, f, c);
		int tiempcas = Convertir_Material_A_Temps(Convertir_Int_A_Material(mat));
		if (mat != 4 && pinch == 0)
		{
			tiempo += tiempcas;

		}
		else if (mat == 4 && pinch == 0)
		{
			tiempo += tiempcas;
			pinch = 1;

		}
		else if (pinch == 1)
		{
			tiempo += (2 * tiempcas);

		}
		//[COMPLETAR]
		/*
		}

		/* Programa principal [DONADES]
		- NO CAL canviar res
		- Les crides a funcions a [COMPLETAR] estan indicades explicitament.
		- Si canvieu la sortida la correccio fallara!
		*/

	}

	return tiempo;
}

int main()
{
	// Llegir Mapa
	printf("\n");
	printf("(1) Llegint mapa...\n");
	Mapa mapa;
	Mapa_Crear(mapa); //[DONADA]
	Mapa_LlegirStdin(mapa); //[COMPLETAR]
	Mapa_EscriureStdout(mapa); //[DONADA]

	// Llegir Itinerari
	Itinerari itinerari;
	printf("(2) Llegint itinerari...\n");
	Itinerari_Crear(itinerari); //[DONADA]
	Itinerari_LlegirStdin(itinerari); //[COMPLETAR]
	Itinerari_EscriureStdout(itinerari); //[DONADA]

	// Detallar itinerari
	printf("(3) Detallant itinerari...\n");
	Itinerari itinerari2;
	Itinerari_Crear(itinerari2); //[DONADA]
	Itinerari_Detallar(itinerari, itinerari2); //[COMPLETAR]
	Itinerari_EscriureStdout(itinerari2); //[DONADA]

	// Visualitzar itineraris sobre el mapa
	printf("(4) Visualitzant itinerari sobre el mapa...\n");
	EscriureStdout_Itineraris_Sobre_Mapa(mapa, itinerari, itinerari2); //[DONADA]

	// Temps itinerari
	printf("(5) Calculant temps itinerari...\n");
	int temps = CalcularTempsItinerari(mapa, itinerari2); //[COMPLETAR]
	printf("Temps = %d\n", temps);

	// Alliberar memoria
	printf("(6) Finalitzant...\n");
	Mapa_Destruir(mapa); //[COMPLETAR]
	Itinerari_Destruir(itinerari); //[COMPLETAR]
	Itinerari_Destruir(itinerari2); //[COMPLETAR]
	return 0;
}
