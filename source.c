//Jakub Migala
#include <stdio.h>
#include <stdlib.h>

//NAGLOWKI FUNKCJI
void AFR(int w, int*** struktura, int** lengths, int* rows);
void ALR(int w, int*** struktura, int** lengths, int* rows);
void AFC(int h, int*** struktura, int** lengths, int* rows);
void ALC(int h, int*** struktura, int** lengths, int* rows);
void IBR(int r, int w, int*** struktura, int** lengths, int* rows);
void IAR(int r, int w, int*** struktura, int** lengths, int* rows);
void IBC(int c, int h, int*** struktura, int** lengths, int* rows);
void IAC(int c, int h, int*** struktura, int** lengths, int* rows);
void SWR(int r, int s, int*** struktura, int** lengths, int* rows);
void SWC(int c, int d, int*** struktura, int** lengths, int* rows);
void DFR(int*** struktura, int** lengths, int* rows);
void DLR(int*** struktura, int** lengths, int* rows);
void DFC(int*** struktura, int** lengths, int* rows);
void DLC(int*** struktura, int** lengths, int* rows);
void RMR(int r, int*** struktura, int** lengths, int* rows);
void RMC(int c, int*** struktura, int** lengths, int* rows);
void ISB(int r, int c, int h, int w, int*** struktura, int** lengths, int* rows);
void RMB(int r, int h, int c, int w, int*** struktura, int** lengths, int* rows);
void PRT(int** struktura,int* lengths, int rows);
int maximum(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int minimum(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main() {				//MAIN
	char* command = malloc(sizeof(char)*4);
	int rows = 0;
	int* lengths = (int*)malloc(sizeof(int)*rows);	//dlugosci kolejnych wierszy
	int** struktura = (int**)malloc(rows*sizeof(int*));	//glowna struktura
	while(1==1)
	{			
		scanf("%s", command);
		if(strcmp(command,"AFR")==0)
		{
			int w;
			scanf("%i",&w);
			AFR(w,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"ALR")==0)
		{
			int w;
			scanf("%i",&w);
			ALR(w,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"AFC")==0)
		{
			int h;
			scanf("%i",&h);
			AFC(h,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"ALC")==0)
		{
			int h;
			scanf("%i",&h);
			ALC(h,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"IBR")==0)
		{
			int r,w;
			scanf("%i%i",&r,&w);
			IBR(r,w,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"IAR")==0)
		{
			int r,w;
			scanf("%i%i",&r,&w);
			IAR(r,w,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"IBC")==0)
		{
			int c,h;
			scanf("%i%i",&c,&h);
			IBC(c,h,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"IAC")==0)
		{
			int c,h;
			scanf("%i%i",&c,&h);
			IAC(c,h,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"SWR")==0)
		{
			int r,s;
			scanf("%i%i",&r,&s);
			SWR(r,s,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"SWC")==0)
		{
			int c,d;
			scanf("%i%i",&c,&d);
			SWC(c,d,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"DFR")==0)
		{
			DFR(&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"DLR")==0)
		{
			DLR(&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"DFC")==0)
		{
			DFC(&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"DLC")==0)
		{
			DLC(&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"RMR")==0)
		{
			int r;
			scanf("%i",&r);
			RMR(r,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"RMC")==0)
		{
			int c;
			scanf("%i",&c);
			RMC(c,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"ISB")==0)
		{
			int r,c,h,w;
			scanf("%i%i%i%i",&r,&c,&h,&w);
			ISB(r,c,h,w,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"RMB")==0)
		{
			int r,h,c,w;
			scanf("%i%i%i%i",&r,&h,&c,&w);
			RMB(r,h,c,w,&struktura,&lengths,&rows);
		}
		else if(strcmp(command,"PRT")==0)
		{
			PRT(struktura,lengths,rows);
		}
		else if(strcmp(command,"END")==0)		
		{		
			int i;
			free(command);
			for(i=0;i<rows;i++)
				free(*(struktura+i));
			free(struktura);
			free(lengths);						
			break;
		}
		
		
	}
	
	return 0;
}				//FUNKCJE
void AFR(int w, int*** struktura, int** lengths, int* rows)		//OK
{
	int i = 0;	
	int j = 0;
	int input;
	*(rows) = *(rows) + 1;
	int** str = (int**)malloc((*rows)*sizeof(int*));
	int* len = (int*)malloc((*rows)*sizeof(int));
	for(i = 0; i < *(rows)-1; i++)	//kopiowanie do nowej struktury
	{
			
		*(len + i + 1) = *(*(lengths)+i);
		*(str + i + 1) = (int*)malloc(*(len + i + 1)*sizeof(int));
		for(j = 0; j < *(len + i + 1); j++)
		{
			*(*(str + i + 1) + j) = *(*(*(struktura) + i) + j);
		}
		
	}
	*(len) = w;
	*(str) = (int*)malloc(w*sizeof(int));
	for(j=0;j<w;j++)	//dodawany wiersz
	{
		scanf("%i",&input);
		*(*(str) + j) = input;
	}
	for(i = 0; i < (*rows)-1; i++)
	{
		free(*(*(struktura) + i));
	}
	free(*struktura);
	free(*lengths);
	*(lengths) = len;
	*(struktura) = str;

	
}
void ALR(int w, int*** struktura, int** lengths, int* rows)		//OK
{
	int i = 0;	
	int j = 0;
	int input;
	*(rows) = *(rows) + 1;
	int** str = (int**)malloc((*rows)*sizeof(int*));
	int* len = (int*)malloc((*rows)*sizeof(int));
	for(i = 0; i < *(rows)-1; i++)	//kopiowanie do nowej struktury
	{
			
		*(len + i) = *(*(lengths)+i);
		*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
		for(j = 0; j < *(len + i); j++)
		{
			*(*(str + i) + j) = *(*(*(struktura) + i) + j);
		}
		
	}
	*(len+i) = w;
	*(str+i) = (int*)malloc(w*sizeof(int));
	for(j=0;j<w;j++)	//dodawany wiersz
	{
		scanf("%i",&input);
		*(*(str+i) + j) = input;
	}
	for(i = 0; i < (*rows)-1; i++)
	{
		free(*(*(struktura) + i));
	}
	free(*struktura);
	free(*lengths);
	*(lengths) = len;
	*(struktura) = str;
	
}
void AFC(int h, int*** struktura, int** lengths, int* rows)		//OK
{
	int i = 0;
	int j = 0;
	int input;
	int old_rows = *(rows);
	*(rows) = maximum(*(rows),h);
	int** str = (int**)malloc((*rows)*sizeof(int*));
	int* len = (int*)malloc((*rows)*sizeof(int));
	for(i = 0; i<*(rows);i++)	//kopiowanie
	{
		if(i<h&&i<old_rows)
		{		
			*(len + i) = *(*(lengths)+i)+1;
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0;j<*(len+i)-1;j++)
			{
				*(*(str + i) + j + 1) = *(*(*(struktura) + i) + j);
			}
		}
		else if(i<h&&i>=old_rows)
		{
			*(len + i) = 1;
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
		}
		else	//H MNIEJSZE NIZ LICZBA WIERSZY
		{
			*(len + i) = *(*(lengths)+i);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0;j<*(len+i);j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i) + j);
			}
		}
	}

	for(i = 0;i<h;i++)	//NOWA KOLUMNA
	{
		scanf("%i",&input);
		*(*(str + i)) = input;
	}
	for(i = 0; i < old_rows; i++)
	{
		free(*(*(struktura) + i));
	}
	free(*struktura);
	free(*lengths);
	*(lengths) = len;
	*(struktura) = str;
}
void ALC(int h, int*** struktura, int** lengths, int* rows)		//OK
{
	int i = 0;
	int j = 0;
	int input;
	int old_rows = *(rows);
	*(rows) = maximum(*(rows),h);
	int** str = (int**)malloc((*rows)*sizeof(int*));
	int* len = (int*)malloc((*rows)*sizeof(int));
	for(i = 0; i<*(rows);i++)	//kopiowanie
	{
		if(i<h&&i<old_rows)
		{		
			*(len + i) = *(*(lengths)+i)+1;
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0;j<*(len+i);j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i) + j);
			}
		}
		else if(i<h&&i>=old_rows)
		{
			*(len + i) = 1;
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
		}
		else		//H MNIEJSZE NIZ LICZBA WIERSZY
		{
			*(len + i) = *(*(lengths)+i);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0;j<*(len+i);j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i) + j);
			}
		}
	}

	for(i = 0;i<h;i++)	//NOWA KOLUMNA
	{
		scanf("%i",&input);
		*(*(str + i) + *(len + i ) - 1) = input;
	}
	for(i = 0; i < old_rows; i++)
	{
		free(*(*(struktura) + i));
	}
	free(*struktura);
	free(*lengths);
	*(lengths) = len;
	*(struktura) = str;
}
void IBR(int r, int w, int*** struktura, int** lengths, int* rows)		//OK
{
	if(r<=*(rows)-1&&r>=0)
	{
		int i = 0;
		int j = 0;
		int input;
		*(rows) = *(rows) + 1;
		int** str = (int**)malloc((*rows)*sizeof(int*));
		int* len = (int*)malloc((*rows)*sizeof(int));
		for(i = 0;i<r;i++)
		{
			*(len + i) = *(*(lengths)+i);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0;j<*(len+i);j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i) + j);
			}
		}
		*(len + r) = w;
		*(str + r) = (int*)malloc(*(len + r)*sizeof(int));
		for(j = 0; j < *(len + r);j++)		//NOWOWSTAWIANY WIERSZ
		{
			scanf("%i",&input);
			*(*(str + r) + j) = input;
		}
		for(i = r+1;i < *(rows);i++)	//PO WSTAWIONYM WIERSZU
		{
			*(len + i) = *(*(lengths) + i - 1);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0;j<*(len+i);j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i - 1) + j);
			}
		}
		for(i = 0; i < (*rows) - 1; i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);
		*(lengths) = len;
		*(struktura) = str;
			
	}
}
void IAR(int r, int w, int*** struktura, int** lengths, int* rows)		//OK
{
	if(r<=*(rows)-1&&r>=0)
	{
		int i = 0;
		int j = 0;
		int input;
		*(rows) = *(rows) + 1;
		int** str = (int**)malloc((*rows)*sizeof(int*));
		int* len = (int*)malloc((*rows)*sizeof(int));
		for(i = 0;i<=r;i++)
		{
			*(len + i) = *(*(lengths)+i);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0;j<*(len+i);j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i) + j);
			}
		}
		*(len + r + 1) = w;
		*(str + r + 1) = (int*)malloc(*(len + r + 1)*sizeof(int));
		for(j = 0; j < *(len + r + 1);j++)		//NOWOWSTAWIANY WIERSZ
		{
			scanf("%i",&input);
			*(*(str + r + 1) + j) = input;
		}
		for(i = r + 2; i < *(rows);i++)	//PO WSTAWIONYM WIERSZU
		{
			*(len + i) = *(*(lengths) + i - 1);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0;j<*(len+i);j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i - 1) + j);
			}
		}
		for(i = 0; i < (*rows) - 1; i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);
		*(lengths) = len;
		*(struktura) = str;
			
	}
}
void IBC(int c, int h, int*** struktura, int** lengths, int* rows)
{
	if(c>=0)
	{
		int i = 0;
		int j = 0;
		int input;
		int old_rows = *(rows);
		*(rows) = maximum(*(rows),h);
		int** str = (int**)malloc((*rows)*sizeof(int*));
		int* len = (int*)malloc((*rows)*sizeof(int));
		for(i = 0; i<*(rows);i++)	//kopiowanie
		{
			if(i<h&&i<old_rows)
			{		
				*(len + i) = *(*(lengths)+i)+1;
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
				for(j = 0;j<*(len+i);j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
			}
			else if(i<h&&i>=old_rows)
			{
				*(len + i) = 1;
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			}
			else	//H MNIEJSZE NIZ LICZBA WIERSZY
			{
				*(len + i) = *(*(lengths)+i);
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
				for(j = 0;j<*(len+i);j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
			}
		}		
		for(i = 0;i<h;i++)	//NOWA KOLUMNA
		{			
			scanf("%i",&input);
			if(c < *(len+i)&&i<old_rows)		//ISTNIEJE TAKI NUMER KOLUMNY W DANYM WIERSZU
			{
				for(j = 0; j < c; j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
				*(*(str + i) + c) = input;
				for(j = c + 1; j<*(len + i);j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j - 1);
				}
			}
			else if(c >= *(len + i)&&i<old_rows)	//NA KONIEC WIERSZY, KTORE JUZ ISTNIEJA
			{
				*(*(str + i) + *(len + i ) - 1) = input;
			}		
			else		//NOWE WIERSZE
			{				
				*(*(str + i)) = input;
			}
		}
		for(i = 0; i < old_rows; i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);
		*(lengths) = len;
		*(struktura) = str;
	}
}
void IAC(int c, int h, int*** struktura, int** lengths, int* rows)
{
	if(c>=0)
	{
		int i = 0;
		int j = 0;
		int input;
		int old_rows = *(rows);
		*(rows) = maximum(*(rows),h);
		int** str = (int**)malloc((*rows)*sizeof(int*));
		int* len = (int*)malloc((*rows)*sizeof(int));
		for(i = 0; i<*(rows);i++)	//kopiowanie
		{
			if(i<h&&i<old_rows)
			{		
				*(len + i) = *(*(lengths)+i)+1;
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
				for(j = 0;j<*(len+i);j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
			}
			else if(i<h&&i>=old_rows)
			{
				*(len + i) = 1;
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			}
			else	//H MNIEJSZE NIZ LICZBA WIERSZY
			{
				*(len + i) = *(*(lengths)+i);
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
				for(j = 0;j<*(len+i);j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
			}
		}		
		for(i = 0;i<h;i++)	//NOWA KOLUMNA
		{			
			scanf("%i",&input);
			if(c < *(len+i) - 1&&i<old_rows)		//ISTNIEJE TAKI NUMER KOLUMNY W DANYM WIERSZU
			{
				for(j = 0; j <= c; j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
				*(*(str + i) + c + 1) = input;
				for(j = c + 2; j<*(len + i);j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j - 1);
				}
			}
			else if(c >= *(len + i) - 1&&i<old_rows)	//NA KONIEC WIERSZY, KTORE JUZ ISTNIEJA
			{
				*(*(str + i) + *(len + i ) - 1) = input;
			}		
			else		//NOWE WIERSZE
			{				
				*(*(str + i)) = input;
			}
		}
		for(i = 0; i < old_rows; i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);
		*(lengths) = len;
		*(struktura) = str;
	}
}
void SWR(int r, int s, int*** struktura, int** lengths, int* rows)	//OK?
{
	if(r<*(rows)&&s<*(rows)&&r!=s)
	{
		int i;
		int swapper;
		int* holder1 = (int*)malloc(*(*(lengths)+r)*sizeof(int));
		int* holder2 = (int*)malloc(*(*(lengths)+s)*sizeof(int));
		for(i = 0;i<*(*(lengths)+r);i++)
			*(holder1 + i) = *(*(*(struktura) + r) + i);
		for(i = 0;i<*(*(lengths)+s);i++)
			*(holder2 + i) = *(*(*(struktura) + s) + i);
		swapper = *(*(lengths)+r);
		*(*(lengths) + r) = *(*(lengths) + s);
		*(*(lengths) + s) = swapper;
		free(*(*(struktura) + r));
		free(*(*(struktura) + s));
		*(*(struktura) + r) = holder2;
		*(*(struktura) + s) = holder1;
	}
}
void SWC(int c, int d, int*** struktura, int** lengths, int* rows)	//OK?
{
	if(c!=d)
	{
		int i;
		int holder;
		for(i = 0;i < *(rows);i++)
		{
			if(!(c >= *(*(lengths) + i)||d >= *(*(lengths) + i)))
			{
				holder = *(*(*(struktura) + i) + c);
				*(*(*(struktura) + i) + c) = *(*(*(struktura) + i) + d);
				*(*(*(struktura) + i) + d) = holder;
			}
		}
	}
}
void DFR(int*** struktura, int** lengths, int* rows)		//OK?
{
	if(*(rows)>0)
	{
		int i = 0;	
		int j = 0;
		*(rows) = *(rows) - 1;
		int** str = (int**)malloc((*rows)*sizeof(int*));
		int* len = (int*)malloc((*rows)*sizeof(int));
		for(i = 0; i < *(rows); i++)	//kopiowanie do nowej struktury
		{
			
			*(len + i) = *(*(lengths) + i + 1);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0; j < *(len + i); j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i + 1) + j);
			}
			
		}
		for(i = 0; i <= (*rows); i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);
		*(lengths) = len;
		*(struktura) = str;	
	}
}
void DLR(int*** struktura, int** lengths, int* rows)		//OK?
{
	if(*(rows)>0)
	{
		int i = 0;	
		int j = 0;
		*(rows) = *(rows) - 1;
		int** str = (int**)malloc((*rows)*sizeof(int*));
		int* len = (int*)malloc((*rows)*sizeof(int));
		for(i = 0; i < *(rows); i++)	//kopiowanie do nowej struktury
		{
			
			*(len + i) = *(*(lengths) + i);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0; j < *(len + i); j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i) + j);
			}
			
		}
		for(i = 0; i <= (*rows); i++)
			{
				free(*(*(struktura) + i));
			}
		free(*struktura);
		free(*lengths);
		*(lengths) = len;
		*(struktura) = str;	
	}
}
void DFC(int*** struktura, int** lengths, int* rows)		//OK?
{
	if(*(rows)>0)
	{	
		int i;
		int j;
		int jednoelementowe = 0;
		int iterator = 0;
		for(i = 0; i < *(rows);i++)	//ZLICZAM, ILE JEST JEDNOELEMENTOWYCH WIERSZY, ONE ZOSTANA USUNIETE
		{
			if(*(*(lengths) + i) == 1)
				jednoelementowe++;
		}
		int** str = (int**)malloc(((*rows)-jednoelementowe)*sizeof(int*));
		int* len = (int*)malloc(((*rows)-jednoelementowe)*sizeof(int));
		for(i = 0; i < (*rows);i++)
		{
			if(*(*(lengths) + i) > 1)
			{
				*(len + iterator) = *(*(lengths) + i) - 1;
				*(str + iterator) = (int*)malloc(*(len + iterator)*sizeof(int));
				for(j = 0; j < *(len + iterator); j++)
				{
					*(*(str + iterator) + j) = *(*(*(struktura) + i) + j + 1);
				}
				iterator++;
			}		
		}
		for(i = 0; i < (*rows); i++)
			{
				free(*(*(struktura) + i));
			}
			free(*struktura);
			free(*lengths);
			*(rows) = *(rows) - jednoelementowe;
			*(lengths) = len;
			*(struktura) = str;
	}
}
void DLC(int*** struktura, int** lengths, int* rows)		//OK?
{
	if(*(rows)>0)
	{	
		int i;
		int j;
		int jednoelementowe = 0;
		int iterator = 0;
		for(i = 0; i < *(rows);i++)	//ZLICZAM, ILE JEST JEDNOELEMENTOWYCH WIERSZY, ONE ZOSTANA USUNIETE
		{
			if(*(*(lengths) + i) == 1)
				jednoelementowe++;
		}
		int** str = (int**)malloc(((*rows)-jednoelementowe)*sizeof(int*));
		int* len = (int*)malloc(((*rows)-jednoelementowe)*sizeof(int));
		for(i = 0; i < (*rows);i++)
		{
			if(*(*(lengths) + i) > 1)
			{
				*(len + iterator) = *(*(lengths) + i) - 1;
				*(str + iterator) = (int*)malloc(*(len + iterator)*sizeof(int));
				for(j = 0; j < *(len + iterator); j++)
				{
					*(*(str + iterator) + j) = *(*(*(struktura) + i) + j);
				}
				iterator++;
			}		
		}
		for(i = 0; i < (*rows); i++)
			{
				free(*(*(struktura) + i));
			}
			free(*struktura);
			free(*lengths);
			*(rows) = *(rows) - jednoelementowe;
			*(lengths) = len;
			*(struktura) = str;
	}
}
void RMR(int r, int*** struktura, int** lengths, int* rows)		//OK?
{
	if(r<*(rows))
	{
		int i;
		int j;
		*(rows) = *(rows) - 1;
		int** str = (int**)malloc(((*rows))*sizeof(int*));
		int* len = (int*)malloc(((*rows))*sizeof(int));
		for(i = 0;i < r; i++)
		{
			*(len + i) = *(*(lengths) + i);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0; j < *(len + i); j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i) + j);
			}
		}
		for(i = r; i <*(rows);i++)
		{
			*(len + i) = *(*(lengths) + i + 1);
			*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
			for(j = 0; j < *(len + i); j++)
			{
				*(*(str + i) + j) = *(*(*(struktura) + i + 1) + j);
			}
		}
		for(i = 0; i <= (*rows); i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);	
		*(lengths) = len;
		*(struktura) = str;
		
	}
}
void RMC(int c, int*** struktura, int** lengths, int* rows)		//OK?
{
	if(c==0)
	{
	int i;
	int j;
	int jednoelementowe = 0;
	int iterator = 0;
	for(i = 0; i < *(rows);i++)	//ZLICZAM, ILE JEST JEDNOELEMENTOWYCH WIERSZY, ONE ZOSTANA USUNIETE
	{
		if(*(*(lengths) + i) == 1)
			jednoelementowe++;
	}
	int** str = (int**)malloc(((*rows)-jednoelementowe)*sizeof(int*));
	int* len = (int*)malloc(((*rows)-jednoelementowe)*sizeof(int));
	for(i = 0; i < (*rows);i++)
	{
		if(*(*(lengths) + i) > 1)
		{
			*(len + iterator) = *(*(lengths) + i) - 1;
			*(str + iterator) = (int*)malloc(*(len + iterator)*sizeof(int));
			for(j = 0; j < *(len + iterator); j++)
			{
				*(*(str + iterator) + j) = *(*(*(struktura) + i) + j + 1);
			}
			iterator++;
		}		
	}
	for(i = 0; i < (*rows); i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);
		*(rows) = *(rows) - jednoelementowe;
		*(lengths) = len;
		*(struktura) = str;
	}
	else if(c > 0)
	{
		int i;
		int j;
		int** str = (int**)malloc((*rows)*sizeof(int*));
		int* len = (int*)malloc((*rows)*sizeof(int));
		for(i = 0; i < *(rows);i++)
		{
			if(c<*(*(lengths) + i))
			{
				*(len + i) = *(*(lengths) + i) - 1;
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
				for(j = 0;j < c;j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
				for(j = c;j < *(len + i);j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j + 1);
				}
			}
			else
			{
				*(len + i) = *(*(lengths) + i);
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
				for(j = 0; j < *(len + i); j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
			}
		}
		for(i = 0; i < (*rows); i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);
		*(lengths) = len;
		*(struktura) = str;
		
	}
}
void ISB(int r, int c, int h, int w, int*** struktura, int** lengths, int* rows)
{
	if(r>*(rows))
		r = *(rows);
	int i;
	int realc;
	int j;
	int input;
	int old_rows = *(rows);
	*(rows) = maximum((r+h),*(rows));
	int** str = (int**)malloc((*rows)*sizeof(int*));
	int* len = (int*)malloc((*rows)*sizeof(int));
	for(i = 0;i < r; i++)		//WIERSZE PRZED WSTAWIANYM BLOKIEM
	{
		*(len + i) = *(*(lengths) + i);
		*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
		for(j = 0; j < *(len + i); j++)
		{
			*(*(str + i) + j) = *(*(*(struktura) + i) + j);
		}
	}
	for(i = r; i< r + h;i++)		//WIERSZE UWZGLEDNIONE W PODANYM BLOKU
	{
		if(i<old_rows)
		{
			*(len + i) = *(*(lengths) + i) + w;
			if(c >= *(len + i) - w)
				realc = *(len + i) - w;
			else
				realc = c;		
		}
		else
		{		
			*(len + i) = w;
		}
		*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
		if(i<old_rows)		//BADANIE WIERSZA
		{		
				for(j = 0; j < realc; j++)	//KOLUMNY PRZED BLOKIEM
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
			
			for(j = realc;j < realc + w; j++)	//KOLUMNY Z BLOKU
			{
				scanf("%i",&input);
				*(*(str + i) + j) = input;
			}
			for(j = realc + w;j < *(len + i);j++)	//KOLUMNY PO BLOKU
			{
				*(*(str + i) + j) = *(*(*(struktura) + i) + j - w);		
			}
		}
		else		
		{
			for(j = 0; j < w; j++)	
				{
					scanf("%i",&input);
					*(*(str + i) + j) = input;
				}
		}
	}
	for(i = r + h;i < *(rows);i++)	//WIERSZE PO BLOKU
	{
		*(len + i) = *(*(lengths) + i);
		*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
		for(j = 0 ; j < *(len + i); j++)
		{
			*(*(str + i) + j) = *(*(*(struktura) + i) + j);
		}
		
	}
	for(i = 0; i < old_rows; i++)
		{
			free(*(*(struktura) + i));
		}
		free(*struktura);
		free(*lengths);
		*(lengths) = len;
		*(struktura) = str;
	
}
void RMB(int r, int h, int c, int w, int*** struktura, int** lengths, int* rows)
{
	if(r<*(rows)&&*(rows)>0&&h>0&&w>0)
	{		
		if(c==0)
		{
				int i = 0;
				int j = 0;
				int remover = 0;
				int iterator = 0;
				int old_rows = *(rows);
				int last_row = minimum((r + h),*(rows));
				for(i = r; i < last_row; i++)
				{
					if(w >= *(*(lengths) + i))
						remover++;
				}
				int** str = (int**)malloc(((*rows) - remover)*sizeof(int*));
				int* len = (int*)malloc(((*rows) - remover)*sizeof(int));
				for(i = 0; i < r; i++)		//KOPIOWANIE WIERSZY SPRZED BLOKU
				{
					*(len + i) = *(*(lengths) + i);
					*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
					for(j = 0 ; j < *(len + i); j++)
					{
						*(*(str + i) + j) = *(*(*(struktura) + i) + j);
					}
					
				}
				iterator = r;
				for(i = r; i < last_row; i++)	//WIERSZE W BLOKU
				{
					if(*(*(lengths) + i) > w)
					{
						*(len + iterator) = *(*(lengths) + i) - w;
						*(str + iterator) = (int*)malloc(*(len + iterator)*sizeof(int));
						for(j = 0; j<*(len + iterator);j++)
						{
							*(*(str + iterator) + j) = *(*(*(struktura) + i) + j + w);
						}
						iterator++;
					}
					
				}
				for(i = last_row; i < old_rows; i++)	//WIERSZE PO BLOKU
				{								
						*(len + iterator) = *(*(lengths) + i);
						*(str + iterator) = (int*)malloc(*(len + iterator)*sizeof(int));
						for(j = 0; j<*(len + iterator);j++)
						{
							*(*(str + iterator) + j) = *(*(*(struktura) + i) + j);
						}
						iterator++;				
				}
				for(i = 0; i <old_rows; i++)
			{
				free(*(*(struktura) + i));
			}
			free(*struktura);
			free(*lengths);
			*(rows) = old_rows - remover;
			*(lengths) = len;
			*(struktura) = str;
		}
		else
		{
			int i = 0;
			int j = 0;
			int last_row = minimum((r + h),*(rows));
			int** str = (int**)malloc((*rows)*sizeof(int*));
			int* len = (int*)malloc((*rows)*sizeof(int));
			for(i = 0; i<r; i++)	//WIERSZE PRZED BLOKIEM - KOPIOWANIE
			{
				*(len + i) = *(*(lengths) + i);
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
				for(j = 0 ; j < *(len + i); j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
			}
			for(i = r; i < last_row; i++)	//WIERSZE W BLOKU
			{
				if(c < *(*(lengths) + i))
				{
					if(w >= *(*(lengths) + i) - c)
						*(len + i) = c;
					else
						*(len + i) = *(*(lengths) + i)  - w;
					*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
					for(j = 0; j < c;j++)	//POCZATKOWE KOLUMNY
					{										
						*(*(str + i) + j) = *(*(*(struktura) + i) + j);
					}
					for(j = c; j < *(len + i); j++)
					{						
						*(*(str + i) + j) = *(*(*(struktura) + i) + j + w);
					}
				}
				else
				{
					*(len + i) = *(*(lengths) + i);
					*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
					for(j = 0; j< *(len + i);j++)
					{
						*(*(str + i) + j) = *(*(*(struktura) + i) + j);
					}
				}
			}
			for(i = last_row;i < *(rows);i++)		//KOLUMNY PO BLOKU
			{
				*(len + i) = *(*(lengths) + i);
				*(str + i) = (int*)malloc(*(len + i)*sizeof(int));
				for(j = 0; j< *(len + i);j++)
				{
					*(*(str + i) + j) = *(*(*(struktura) + i) + j);
				}
			}		
			for(i = 0; i <*(rows); i++)
			{
				free(*(*(struktura) + i));
			}
			free(*struktura);
			free(*lengths);
			*(lengths) = len;
			*(struktura) = str;
		}
	}
}
void PRT(int** struktura, int* lengths, int rows)
{
	int i = 0;
	int j = 0;
	for(i;i<rows;i++)
	{
		for(j;j<*(lengths+i);j++)
		{
			printf("%i ",*(*(struktura + i)+j));
		}
		printf("\n");
		j = 0;
	}

}
