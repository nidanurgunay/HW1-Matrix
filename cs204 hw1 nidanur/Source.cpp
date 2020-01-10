#include <iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include <string>



using namespace std;

bool movecheck(int x, int y,vector<vector<char>> &mat,vector<string> & move, bool & visitpre );
void Move (string &m, vector<vector<char>> & mat,int &x, int&y, bool & visitpre );
void Path (string &path, vector<string> & move ,vector<vector<char>> mat , bool &invalid );
void coordinate (int &x, int&y, vector<vector<char>>  mat, bool & invalid, bool & if1exist );
bool charcheck(char & ch);
bool matrixcheck (vector<vector<char>> & mat, int & row);
void Charvecstore (vector<char> & charvec, string & m,int x, int y ,vector<vector<char>>  mat,vector<string> & move );




void Move (string &m, vector<vector<char>> & mat,int &x, int&y, bool & visitpre )
{  
	if(m=="d")
	{ if(mat[x+1][y]=='_')
	visitpre=true;
		mat[x+1][y]='_';
		x++;			}
	else if (m=="u")
	{    if(mat[x-1][y]=='_')
	visitpre=true;
		mat[x-1][y]='_';
		x--;}
	else if (m=="l")
	{  if(mat[x][y-1]=='_')
	visitpre=true;
		mat[x][y-1]='_';
		y--;}
	else if(m=="r")
	{ if(mat[x][y+1]=='_')
	visitpre=true;
		mat[x][y+1]='_';
		y++;}

}

void Charvecstore (vector<char> & charvec, string & m,int x, int y ,vector<vector<char>>  mat,vector<string> & move )
{int newx=x;
int newy=y;
for(int i=0; i<move.size(); i++ )
{m=move[i];
if(m=="d")
{
	charvec.push_back(mat[newx+1][newy]);
	mat[newx+1][newy]='_';
	newx++;	}

else if (m=="u")
{  
	charvec.push_back(mat[newx-1][newy]);
	mat[newx-1][newy]='_';
	newx--;}

else if (m=="l")
{ 
	charvec.push_back(mat[newx][newy-1]);
	mat[newx][newy-1]='_';
	newy--;}

else if(m=="r")
{   
	charvec.push_back(mat[newx][newy+1]);
	mat[newx][newy+1]='_';
	newy++;}
}
}

/***********the function that controls the path if it is valid or not***********/
bool movecheck(int x, int y,vector<vector<char>> &mat,vector<string> & move, bool & visitpre )// move siniri ihlal etmiyorsa true dondurur
{int checkx=0;
int checky=0;
for(int i=0; i<move.size();i++)
{  string m=move[i];

if(m=="d")
{	if(mat[x+1][y]=='_')
	visitpre=true;
	checkx++;	}		
else if (m=="u")
	{ if(mat[x-1][y]=='_')
	visitpre=true;
		checkx--;
}
else if (m=="l")
{	if(mat[x][y-1]=='_')
	visitpre=true;
	checky--;}
else if(m=="r")
{if(mat[x][y+1]=='_')
	visitpre=true;
	checky++;}
}
int movex=x+checkx;
int movey= y+checky;
if (movex<0 ||movey<0 || movex>mat.size() || movey> mat[0].size())
{cout<<"Invalid path - out of range" <<endl<< endl;
for(int i=0;i<mat.size();i++)
{for(int j=0;j<mat[i].size();j++)
{cout<< mat[i][j]<< " ";
}
cout<<endl;
}
cout<< endl;
return false;}

else
	return true;
}

void Path (string &path, vector<string> & move ,vector<vector<char>> mat , bool &invalid )
{   invalid=false;
cout<< "Enter the path: " ;
cin >> path;
for(int i=0; i< path.size() ;i++)
{move.push_back(path.substr(i,1));
}
if (move.size()<2)
{cout<<"Invalid path - path too short"<< endl<< endl;
for(int i=0;i<mat.size();i++)
{for(int j=0;j<mat[i].size();j++)
{cout<< mat[i][j]<< " ";
}
cout<<endl;
}
cout<< endl;
invalid=true; }

for(int i=0; i<move.size() && !invalid; i++)
{while ((!(move[i]=="r" || move[i]=="d" || move[i]=="l" || move[i]== "u") )&& !invalid )
{cout<< "Invalid path - non-RLUD input ";
cout<< endl<< endl;
invalid=true;
for(int k=0;k<mat.size();k++)
{for(int j=0;j<mat[k].size();j++)
{cout<< mat[k][j]<< " ";
}
cout<<endl;
}
cout<< endl;
cin.clear();


}

}
}
/***************the function that checks the coordinate************/
void coordinate (int &x, int&y, vector<vector<char>>  mat, bool & invalid, bool & if1exist )//koordinat dogruysa true olarak cikar
{

	cout<< "Enter the starting location for word (x, y): " ;
	cin>> x>>y;
	if(x==-1||y==-1)
	{if1exist=true;}

	bool wrong =false;
	if((!(x>=0 && y>=0 && x<mat.size() && y< mat[0].size())&& !invalid) && !if1exist)
	{cout<< "Invalid coordinate - out of range"<< endl<< endl;
	for(int i=0;i<mat.size();i++)
	{for(int j=0;j<mat[i].size();j++)
	{cout<< mat[i][j]<< " ";
	}
	cout<<endl;
	}
	cout<< endl;
	cin.clear();
	wrong=true;
	}
	if(wrong)
		invalid=false;
	else 
		invalid=true;

}

/********** charlari kontrol ettigim fonksiyon *************/
bool charcheck(char & ch)
{
	char num='0';
	for(int i=0;i<9;i++){	
		if(ch==num+i)
		{cout<<"Invalid matrix - char not lowercase letter "<< endl;
		return false;}
	}

	char upper = 'A';
	for(int i=0; i<26;i++)
	{if (ch==upper+i)
	{cout<<"Invalid matrix - char not lowercase letter"<< endl;
	return false;
	}		
	}
	return true;
}

/**************matrisi check ettigim bolum ***********/
bool matrixcheck (vector<vector<char>> & mat, int & row)
{
	int a=0;
	for(int j=0; j<row;j++)
	{ int column=mat[j].size();

	for(int i=0; i<row;i++)
	{int column1=mat[i].size();
	if(column!=column1)
		a++;
	}
	}
	if(!a==0)
		return true;
	else
		return false;
}



int main(){

	ifstream puzzle;
	string filename;

	cout << "Please enter the name of the puzzle file: ";
	cin>> filename;
	puzzle.open(filename.c_str());
	/************puzzle filei actigim bolum*********/
	while(puzzle.fail()){
		cout<<  "File could not be opened."<< endl;
		cout <<  "Please enter the name of the puzzle file: ";
		cin>> filename;
		puzzle.open(filename.c_str());
	}
	bool nonchar=false;
	string line;
	int column=0;
	int row=0;
	vector<vector<char>> mat ;
	/************puzzle dosyasindaki matrsi char char okuyup vektore atadigim bolum***************/
	while(!puzzle.eof()){
		string line2;
		while(getline(puzzle,line)){
			istringstream iss(line);
			char ch;
			vector<char> c; // tum charlari depoladigim bir vector olusturdum
			while (iss>> line2){// oncesinde  >> c olarak okudum
				if (line2.size()>1)
					nonchar=true;

				ch=line2.at(0);// stringi chara cevir
				column++;
				c.push_back(ch);
				if(!charcheck(ch))
					return 0;

			}
			mat.push_back(c);
			row ++;}}
	if(nonchar)
	{
		cout<< "Invalid matrix - cell entry is not a char "	<< endl;
		return 0;
	}

	if(matrixcheck(mat, row))
	{cout<<"Invalid matrix - inconsistent dimensions"<< endl;
	return 0;}

	/*********** words file i actigim bolum**********/
	string words;
	ifstream wordsdat;
	cout<<"Please enter the name of the dictionary file: ";
	cin>>words;

	wordsdat.open(words.c_str());
	while(wordsdat.fail()){
		cout<<  "File could not be opened."<< endl;
		cout<<"Please enter the name of the dictionary file: ";
		cin>>words;
		wordsdat.open(words.c_str());
	}



	//****** The part that the store of the words in words.dat file ****//
	vector<string> dic;
	string dictionary;
	while(getline(wordsdat,dictionary)){
		istringstream iss(dictionary);
		string str;

		while (iss>> str){

			dic.push_back(str);
		}}

	cout<< endl;
	for(int i=0;i<mat.size();i++)
	{for(int j=0;j<mat[i].size();j++)
	{cout<< mat[i][j]<< " ";
	}
	cout<<endl;
	}
	cout<< endl;
	vector<vector<char>> matcopy;
	bool print=true;
	bool print2=false;
	/*************the rest of the code is looped to start the algprithm again in case of the game didnt finish****************/
	int mypoint=0;
	bool check = true;
	
	while(check)
	{  	bool invalid =true;
	bool if1exist=false;
	int x, y;
	string path;
	vector<string> move;
	bool breakwhile=true;
	

	vector <char> charvec;	
	string m;

		bool visitpre=false;

	while(invalid)
	{	invalid=false;
	bool moveloop =true;
	while (!invalid)
	{
		coordinate (x, y,  mat,  invalid, if1exist );// coordinate dogruysa true olarak cikacak

		if(if1exist)
		{cout<<endl<< "You didn't completely solve the puzzle." << endl;
		cout<< "Your final score is " << mypoint << endl;
		return 0;}



	}
	if (!invalid)
		moveloop=false;

	while (invalid && moveloop)
	{// buna girdiysem false
		Path (path, move,mat, invalid);// invalid path true cevirir // sikinti yoksa false

		if(invalid)
		{move.clear();
		moveloop=false;}
		if(!invalid  && !(movecheck(x,y,mat,move, visitpre)))//path loopundan false cikti ki buna girdi
		{// move checkde  sikinti varsa false  yoksa true
			move.clear();// buna girdiysem false
			invalid=true;
			moveloop=false;
		}
		
	}			
	}

	if( movecheck(x,y,mat,move,visitpre))
	{charvec.push_back(mat[x][y]);
	Charvecstore(charvec,m,x,y,mat,move);}
	
	int count =0;
	for (int i=0;i<charvec.size();i++)
	{
		if(charvec[i]=='_')
			count++;}


	if((count!=0) && !visitpre)
	{
		cout<< "Invalid path - cell visited twice "<< endl << endl;
		
		charvec.clear();
		invalid=true;
		for(int i=0;i<mat.size();i++)
		{
			for(int j=0;j<mat[i].size();j++)
			{
				cout<< mat[i][j] << " " ;
			}
			cout<<endl;
		}

		cout<<endl;
		breakwhile=false;
	}


	if(breakwhile)
	{
		int counts=0;
		string myword;
		for(int i=0; i<charvec.size(); i++)
		{ myword+= charvec[i];
			
		}

		
		bool trueword=false;
		 visitpre=false;
		for(int i=0; breakwhile && i<dic.size(); i++)
		{
			if (myword== dic[i])
			{trueword=true;
			
						matcopy=mat;

		   	string p;
			
				for(int i=0;i <move.size();i++)
				{mat[x][y]='_';
					p=move[i];
					Move(p,mat,x,y,visitpre);
							
				}
			
				if(visitpre)
			{cout <<"Invalid path - cell visited previously "<< endl << endl;
			breakwhile=false;
			mat=matcopy;
				for(int i=0;i<mat.size();i++)
		{
			for(int j=0;j<mat[i].size();j++)
			{
				cout<< mat[i][j] << " " ;
			}
			cout<<endl;
		}

		cout<<endl;
	
			}
				
				
				
				for(int i=0; !visitpre && i<mat.size();i++)// matrisin tum charlari bitti mi diye kontorl ettim eger bittiyse count 0
				{
					for(int j=0; j<mat[0].size(); j++)
					{
						if (mat[i][j] != '_')
						counts++;
					}

				}
						

			}
		}
			if(trueword){
		int point =myword.size()*myword.size();
				mypoint+=point;
				cout<< "Word found: " << myword << endl;
				cout<< "Word length: "<< myword.size() <<endl;
				cout<< "Points gained: " <<point <<endl;
				cout<<"Current score: "<<mypoint<< endl<<endl;
				if( counts!=0){	
					for(int i=0;i<mat.size();i++)
					{for(int j=0;j<mat[i].size();j++)
						{cout<< mat[i][j] << " " ;
						}
						cout<<endl;
					}cout<<endl;
					move.clear();
					charvec.clear();
				}}
		if(!trueword)
		{	cout<< "Invalid word - non-existent word " << "\""<< myword << "\"" << endl<<endl; 
			for(int i=0;i<mat.size();i++)
			{for(int j=0;j<mat[i].size();j++)
				{cout<< mat[i][j] << " " ;
				}
			cout<<endl;
			}cout<<endl;
			move.clear();
			charvec.clear();
			breakwhile=false;
		}


		if ((counts==0) &&  breakwhile)
		{cout<< "Congratulations, you have solved the puzzle perfectly!"<<endl;
			cout<< "Your final score is: " << mypoint<< endl;
		check=false;
			}		
	
	}
	
	}
	return 0;
}