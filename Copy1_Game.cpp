#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string s;


int Word(){
	ifstream F("All_Words.txt");
	int a;
	cin>>a;//вводим № слова из списка
	for(int i=0;i<a;i++){
		getline(F, s);
	}
	return 0;
}



int main(){
	Word();
	string copy_slovo;
	string slovo;
	
	int point=2;//point - жизни
	char letter; //letter - буква
	for(int i=0;i<s.length();i++){// выделяем массив под слово
		slovo[i]='_';
	}
	
	cout<<"Zamenite pustie mesta na bukvi: "<<endl;
	
	for(int i=0;i<s.length();i++){//вводим ( _ ) вместо букв слова
		cout<<slovo[i]<<" ";
	}
	cout<<endl;
	
//НАПИСАТЬ ЦИКЛ ДЛЯ ПРОВЕРКИ БУКВЫ И ДОБАВИТЬ ЖИЗНИ
    while(point>0 || slovo!=s){
    	cin>>letter;
    	copy_slovo=slovo;
    	for(int i=0;i<s.length();i++){
    		if(s[i]==letter){ 
			    slovo[i]=letter;
			}
		}
			if(slovo==copy_slovo){
			point--;
			cout<<"there is no such letter - "<<letter<<endl; // буквы нет(ТУТ ОШИБКА)
			}
		for(int i=0;i<s.length();i++){//вводим ( _ ) вместо букв слова
		    cout<<slovo[i]<<" ";
	}
	cout<<endl;
	
	}
    cout<<"Congratulation)";
	return 0;
}