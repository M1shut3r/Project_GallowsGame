#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include <random>
using namespace std;

random_device rd;
mt19937 mersenne(rd());

int sum=0; // сколько строчек выведет  виселицы 
string s,l;
string copy_slovo;
string slovo;
int key, point=9,a=0;//point - жизни


int Life(){
	cout<<"Lifes - "<<point<<endl;
	return 0;
}

int Gallow(){                     //вывод картинки
	ifstream F("Lifes.txt");
			for(int i=0;i<=sum;i++){
			getline(F,l);
			cout<<l<<endl;
		}
	return 0;
}

int Word(){
	ifstream F("All_Words.txt");
	int a;
	a=rd()%100;                   //вводим № слова из списка
	for(int i=0;i<a;i++){
		getline(F, s);
	}
	return 0;
}

void Stroka(){
	for(int i=0;i<s.length();i++){   //вводим ( _ ) вместо букв слова
		cout<<slovo[i]<<" ";
	}
	cout<<endl;
}


int main(){
	int b=0;                         //Делается +1 за каждую правильную букву
	Word();
	
	char letter;                     //letter - буква
	
	for(int i=0;i<s.length();i++){   // выделяем массив под слово
		slovo[i]='_';
	}
	
	cout<<"Zamenite pustie mesta na bukvi: --->>   "; 
	Stroka();
	cout<<"\n\n";
	
	cout<<"Slovo: "<<s<<"\n"<<"-----------------------------";
	cout<<endl;
	cout<<"Najmite ENTER dla prodoljenia";
	
	
    while(point>=0 && b!=s.length()){
    	if(getch()) system("cls");
    	Life();
    	cout<<"otgadannie bukvi na dani moment ";
		Stroka();
		cout<<endl;
		if(point!=9)
			Gallow();              //выводит картинку виселицы
    	cout<<"\n\n\n";
    	cout<<"Vvedite bukvy : ";
    	if(point != 0)
    	cin>>letter;                  //ввод рандомного номера слова
    	cout<<endl;
    	copy_slovo=slovo;
    	a=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]==letter){
			    slovo[i]=letter;
				a++;
				b++;
			}
		}
			if(a==0){
			    point--;
			    sum++;
			    	cout<<endl<<"there is no such letter (-1 life) "<<letter<<endl;
			}
			
		 
		Stroka();
		cout<<"Najmite ENTER dla prodoljenia"<<endl;
	}
	if(point!=-1){
		system("cls");
		cout<<"GOOOOOOOOOOOOOOOOOOOD YOY SAVE HIM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	    getch();
	}
	else {
		system("cls");
		Gallow();
	cout<<endl<<"YOU LOOSE SRY";
	getch();}
	return 0;
}