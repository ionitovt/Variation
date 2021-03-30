#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int n;
	int* Masiv;
}Set;

Set* func(int);
int* random_generator(int);
void Swap(Set *myset, unsigned index1, unsigned index2);
void print(Set * set, unsigned end);
void variations(Set* myset, unsigned index, unsigned n, unsigned p);
int factoriel(int n);



int main(){
	int k;
	srand(time(0));
	Set* set;
	printf("Enter number of variations: ");
	scanf("%d", &k);

	set = func(k);

	printf("{");
	for (int i = 0; i < set->n; i++) {
		printf("%d", set->Masiv[i]);
		if (i + 1 == set->n) {
			break;
		}
		//Ifа го слагам за да махна последната запетая
		printf(",");
	}
	printf("}\n"); //Принтирам създаденото множество

	printf("The number of permutations is : %d\n", factoriel(k));
	//Пресмятам броя на всички възможни пермутации
	variations(set, 0, set->n - 1, k);
	return 0;
}



Set* func(int N){
	Set* PSet;
	PSet = (Set*)malloc(sizeof(Set)* N);
	PSet->Masiv = random_generator(N);
	PSet->n = N;
	return PSet;
}

int* random_generator(int num){
	int* Masiv, i;
	Masiv = (int*)malloc(sizeof(int)* num);
	for (i = 0; i < num; i++) {
		Masiv[i] = rand() % 10;
	}
	return Masiv;
}

void variations(Set* myset, unsigned index, unsigned n, unsigned p){
	if (index == n)
		print(myset, p);
	else
	{
		for (int i = index; i <= n; i++)
		{

			//Разменяме елемента от индекса с текущия елемент
			Swap(myset, index, i);

			//Извикваме рекурсия, като увеличаваме индекса
			variations(myset, index + 1, n, p);

			//Възтановяваме началната позиция
			Swap(myset, index, i);
		}
	}
}

void Swap(Set *myset, unsigned index1, unsigned index2){
	int i = myset->Masiv[index1];
	myset->Masiv[index1] = myset->Masiv[index2];
	myset->Masiv[index2] = i;
}

void print(Set * set, unsigned end){
	for (int i = 0; i < end; i++) {
		printf("%d", set->Masiv[i]);
	}
	printf("\n");
}

int factoriel(int n) {
	int p = n, sum = 1;
	for (int i = 0; i < n; i++) {
		sum *= p;
		p--;
	}
	return sum;
}