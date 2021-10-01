#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include <random>
using namespace std;
random_device rd;
mt19937 mersenne(rd());

char letter;                     //letter - буква
int b=0,G=1;     //G -  пока не 0 игра повторяется               //Делается +1 за каждую правильную букву
int sum=0; // сколько строчек выведет  виселицы 
string s,s1,l,Sum,Point,bb;
string copy_slovo;
string slovo,slovo1;
int point=9,a=0;//point - жизни

int Again(){
	int x;
	cout<<"\n\n\n\n\n"<<"Nachat snova - lubaia chifra"<<endl;
	cout<<"Zakonchit igry - 0"<<endl;
	cin>>x;
	if(x>0) {  
	G=1;
	system("cls");
	cout<<"Nagmite ENTER";
	}
	else G=0;
	return 0;
}

int Life(){
	cout<<"Lifes - "<<point<<endl;
	return 0;
}

int Win(){                     //вывод картинки при угадывании слова
	ifstream F("WIN.txt");
			for(int i=0;i<=13;i++){
			getline(F,l);
			cout<<l<<endl;
		}
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
	a=rd()%1774;                   //вводим № слова из списка
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
int New_game(){
	for(int i=0;i<s.length();i++){   // выделяем массив под слово
		slovo[i]='_';
	}
	
	cout<<"Zamenite pustie mesta na bukvi: --->>   "; 
	Stroka();
	cout<<"\n\n";
	
	cout<<"Slovo: "<<s<<"\n"<<"-----------------------------";
	cout<<endl;
	cout<<"Najmite ENTER dla prodoljenia";
	return 0;
}


int main(){
	int k;
	while(G){
	ifstream SLOVO1 ("slovo.txt");
	getline(SLOVO1,slovo);
	ifstream S1 ("s.txt");
	getline(S1,s);
	
	if(slovo==s){
	point=9;
	ofstream D("s.txt");
	Word();
    New_game();
    D<<s; //Вывод СЛОВА
	}
	
	else{
		int k;
		cout<<"Ne zakochenaia igra :"<<endl;
		cout<<"nachat novyu - 1"<<endl;
		cout<<"prodoljit staryu - 2"<<endl;
		cin>>k;

		if(k==2){
    	ifstream SUM1("sum.txt");
    	getline(SUM1,Sum);
    	sum = atoi(Sum.c_str()); 
    	ifstream POINT1("point.txt");
    	getline(POINT1,Point);
    	point =  atoi(Point.c_str()); 
    	ifstream B1("b.txt");
    	getline(B1,bb);
    	b =  atoi(bb.c_str());
		}
		else {
			Word();
			point=9;
	        ofstream D("s.txt");
	        New_game();
	        D<<s; //Вывод СЛОВА
		}
	}
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
    		if(s[i]==letter && slovo[i]!=letter){
			    slovo[i]=letter;
				a++;
				b++;
			}
			if(slovo[i]==letter) a++;
		}
			if(a==0){
			    point--;
			    sum++;
			    	cout<<endl<<"there is no such letter (-1 life) "<<letter<<endl;
			}
			
		 
		Stroka();
		cout<<"Najmite ENTER dla prodoljenia"<<endl;
		
		ofstream SLOVO("slovo.txt");
    	SLOVO<<slovo.c_str();
    	SLOVO.close();
    	ofstream SUM("sum.txt");
    	SUM<<sum;
    	SUM.close();
    	ofstream POINT("point.txt");
    	POINT<<point;
    	POINT.close();
    	ofstream B("b.txt");
    	B<<b;
		B.close();
	}
	if(point!=-1){
		system("cls");
		cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!YOU SAVE HIM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
		Win();
		ofstream SLOVO("slovo.txt");
		SLOVO<<"";
		ofstream D("s.txt");
		D<<"";
		
		Again();
		
	    getch();
	}
	else {
		system("cls");
		Gallow();
	    cout<<endl<<"YOU LOOSE SRY"<<endl;
	    cout<<"This Word - "<<s;
	    ofstream SLOVO("slovo.txt");
		SLOVO<<"";
		ofstream D("s.txt");
		D<<"";
	    
	    Again();
	    
	    getch();
	}
}
	return 0;
}