#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#include<fstream>
int calcmaximum(int& maxim, int sizeofwords[], ifstream& TASK1IN2)
{
    maxim = 2; int counter = 0;
    while (!TASK1IN2.eof())
    {
        string a;
        getline(TASK1IN2, a);
        sizeofwords[counter] = a.length();

        if (a.length() > maxim)
            {maxim = a.length();}

            counter++;
    }


    return counter;
}
char** createtemparray(int rows,ifstream& TASK1IN)
{

    char** tempba = new char* [rows];
    int i = 0;

    while (!TASK1IN.eof())
    {
        string puzzlename;
        TASK1IN >> puzzlename;

        int l = puzzlename.length();

        *(tempba + i) = new char[l];
        for (int j = 0; j < l; j++)
        {
            tempba[i][j] = puzzlename[j];

        }
        tempba[i][l] = '\0';

        i++;

    }
    return tempba;
}


void printgrid(char** base, int rows, int cols, ofstream& OUT, string name2)
{
    for (int o = 0; o < rows; o++)
    {
        for (int p = 0; p < cols; p++)
        {
            char a=base[o][p];

            if(base[o][p] > 96 && base[o][p]<126)
           {
                a=base[o][p]-32;
           }
        cout<<a<<" ";
        OUT<<a;
        OUT<<" ";
        }
        cout << endl;
        OUT<<endl;
    }
cout<<endl<<endl<<"Output file created successfully with name "<<name2<<endl<<endl;

}

char** createarray1( int rows,int cols)
{

    char** ba = new char* [rows];

    for (int i = 0; i < cols; i++)
    {
        ba[i] = new char[cols];

    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            ba[i][j] = 32;

    }


    return ba;
}


void placerandom(char **b , int row, int col)
{
int w=65;
     for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            {
                if(w>90)
                    w=65;

                if(b[i][j] == 32)
                {
                    b[i][j]=w;
                }
                w+=2;
            }

    }

}



void placewords(char** base, char** tempbase, int cols, int rows, int sizeofwords[])
{
    int counter=0;

    int c = 0, sizec = 0;

    for ( int i=0  ; i < rows; i++)
    {

    potato:
        for (int j = 0; j < cols; j++)
        {

            if (base[i][j] == 32)
            {


                //for diagonal

                c = 0;

                for (int k = j, l = i; l < rows  && k < cols ; l++, k++)
                {

                    if (base[l][k] == 32)
                    {
                        c++;
                    }
                    else{break;}

                }


                if (c == sizeofwords[sizec])
                {
                    c = 0;
                    for (int k = j, l = i; l < sizeofwords[sizec] + i && k < sizeofwords[sizec] + j; k++, c++, l++)
                    {
                        base[l][k] = tempbase[sizec][c];

                    }

                    sizec++;
                counter++;

                   goto potato;


                }

                //for horizontal

                               c=0;

                            for(int k = j ; k<20; k++)
                                {

                                    if(base[i][k]==32)
                                    {
                                        c++;
                                    }
                                    else{break;}
                                }

                            if(c==sizeofwords[sizec])
                            {
                                c=0;
                                for(int k = j ; k<sizeofwords[sizec] + j ; k++,c++)
                                {
                                    base[i][k]=tempbase[sizec][c];

                                }
                                counter++;
                                sizec++;
                             break;
                            }



            //for vertical

            c = 0;

             for (int k = i; k < cols; k++)
             {

                 if (base[k][j] == 32 )
                 {
                     c++;
                 }
                 else{break;}

             }

             if (c == sizeofwords[sizec])
             {

                 c = 0;
                 for (int k = i; k < sizeofwords[sizec] + i; k++, c++)
                 {
                     base[k][j] = tempbase[sizec][c];

                 }
                    counter++;
                 sizec++;
                    break;
             }


            }

        }


    }


}

int calcmax(int& maxim, ifstream& IN1 )
{
    maxim = 2; int counter = 0;
    while (!IN1.eof())
    {

        string a;
        getline(IN1, a);


        if (a.length() > maxim)
            {maxim = a.length();}

            counter++;

    }
maxim=maxim/2;

    return counter-1;
}

char ** createarray(int r, int c, ifstream& IN1)
{
    char **b= new char* [r];

    for(char **y=b; y<b+r ; y++)
    {
        *y=new char [c];
    }

    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            IN1>>b[i][j];
        }

    }

return b;

}
char ** create(int r, int c)
{
    char **b= new char* [r];

    for(char **y=b; y<b+r ; y++)
    {
        *y=new char [c];
    }

    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            b[i][j]=32;
        }

    }




return b;

}
void printarray(char**b, int r , int c)
{
     for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

}
void createcopy(char **des, char **base, int drow , int dcol)
{
    for(int i=0 ;i<drow ; i++)
    {
        for(int j =0 ;j<dcol ; j++)
        {
            des[i][j]=base[i][j];
        }

    }



}



//ALL FUNCTIONS TO CHECK WORDS IN DESIRED ARRAY

bool H_lefttoright(int f, int i, int j,char**desired,int lengthofwords[],string words[], int cols)
{
               //   cout<<"Left to right horiz"<<endl;
                    int c=1;
                    int oh=1;

                    for( int  y=j+1 ; y<lengthofwords[f]+j && y<cols ; y++,c++)
                    {
                            if(desired[i][y]==words[f][c])
                            {

                                oh++;


                            if(oh==lengthofwords[f])
                                {
                                    cout<<endl<<words[f]<<" is HORIZONTAL LEFT to RIGHT starting from: ["<<i<<" , "<<j<<" ] and ending at ["<<i<<" , "<<j+lengthofwords[f]-1<<" ]"<<endl;

                                    return true;
                                }

                            }
                            else{ return false; }

                    }

           return false;

}

bool H_righttoleft(int f, int i, int j,char**desired,int lengthofwords[],string words[])
{
                 // cout<<"right to left horiz"<<endl;
                    int c=1;
                    int oh=1;

                for( int  y=j-1 ; y>=0  ; y--,c++)
                    {
                            if(desired[i][y]==words[f][c])
                            {
                                oh++;
                                 if(oh==lengthofwords[f])
                                {

                                    cout<<endl<<words[f]<<" is HORIZONTAL RIGHT to LEFT starting from: ["<<i<<" , "<<j<<" ] and ending at ["<<i<<" , "<<j+1-lengthofwords[f]<<" ]"<<endl;
                                    return true;
                                }

                            }
                            else
                            {
                                return false;

                            }
                    }

                return false;



}

bool V_uptodown(int f, int i, int j,char**desired,int lengthofwords[],string words[], int rows)
{
//    cout<<"V up to down"<<endl;
                    int c=1;
                    int oh=1;


                    for(int  y=i+1 ; c<lengthofwords[f] && y<rows ; y++,c++)
                    {
                            if(desired[y][j]==words[f][c])
                            {
                                oh++;


                                if(oh==lengthofwords[f])
                                {
                                    cout<<endl<<words[f]<<" is vertical up to down starting from: ["<<i<<" , "<<j<<" ] and ending at ["<<i-1+lengthofwords[f]<<" , "<<j<<" ]"<<endl;
                                    return true;
                                }
                            }

                            else
                            {
                                    return false;
                            }

                    }

                return false;


}
bool V_downtoup(int f, int i, int j,char**desired,int lengthofwords[],string words[])
{
  //        cout<<"V down to up"<<endl;
                    int c=1;
                     int oh=1;


                for( int  y=i-1 ; y>=0 ; y--,c++)
                    {
                            if(desired[y][j]==words[f][c])
                            {
                                oh++;


                             if(oh==lengthofwords[f])
                            {

                                    cout<<endl<<words[f]<<" is vertical down to up starting from: ["<<i<<" , "<<j<<" ] and ending at ["<<i+1-lengthofwords[f]<<" , "<<j<<" ]"<<endl;
                                    return true;
                                }
                            }
                            else
                            {
                                    return false;
                            }

                    }

                return false;

}

bool D_uplefttobottomright(int f,int i, int j, char** desired,int lengthofwords[],string words[] , int rows)
{
    //cout<<"Dia Lft to Btm"<<endl;
	int oh = 0;
	int c=0;
	for (int l = i, m = j; l < rows ; l++,m++, c++)
	{
		if (words[f][c] == desired[l][m])
		{
			oh++;
			if (oh == lengthofwords[f])
			{
			    cout<<endl<<words[f]<<" is diagonal up left to bottom right from: ["<<i<<" , "<<j<<" ] and ending at ["<<i+lengthofwords[f]-1<<" , "<<j+lengthofwords[f]-1<<" ]"<<endl;
				return true;
			}
		}
		if (words[f][c] != desired[l][m])
		{
			return false;
		}

	}
	return false;
}

bool D_uprighttobottomleft(int f,int i, int j, char** desired,int lengthofwords[],string words[] , int Rows)
{
    //cout<<"D up right to bottom"<<endl;
  int oh=0;
  int c=0;

	for (int l = i, m = j; l < Rows && m>=0 ; l++,m--, c++)
	{
		if (words[f][c] == desired[l][m])
		{
			oh++;
			if (oh == lengthofwords[f])
			{
			    cout<<endl<<words[f]<<" is diagonal up right to bottom left: ["<<i<<" , "<<j<<" ] and ending at ["<<i+lengthofwords[f]-1<<" , "<<j-lengthofwords[f]+1<<" ]"<<endl;
				return true;
			}
		}
		if (words[f][c] != desired[l][m])
		{
			return false;
		}

	}
	return false;
}

bool D_bottomlefttoupright(int f,int i, int j, char** desired,int lengthofwords[],string words[] , int Rows, int cols)
{


    int oh=0;
    int c=0;

	for (int l = i, m = j; l >=0  && m<=cols  ; l-- ,m++, c++)
	{
		if (words[f][c] == desired[l][m])
		{
			oh++;
			if (oh == lengthofwords[f])
			{
			    cout<<endl<<words[f]<<" is diagonal bottom left to up right: ["<<i<<" , "<<j<<" ] and ending at ["<<i-lengthofwords[f]+1<<" , "<<j+lengthofwords[f]-1<<" ]"<<endl;
				return true;
			}
		}
		if (words[f][c] != desired[l][m])
		{
			return false;
		}

	}
	return false;


}
bool D_bottomrighttoupleft(int f,int i, int j, char** desired,int lengthofwords[],string words[] , int Rows)
{
//cout<<"bottom righ to up left"<<endl;

    int oh=0;
    int c=0;

	for (int l = i, m = j; l > 0 && m>0  && c<lengthofwords[f] ; l--,m--, c++)
	{
		if (words[f][c] == desired[l][m])
		{
			oh++;
			if (oh == lengthofwords[f])
			{
			    cout<<words[f]<<endl<<" is diagonal bottom right to up left: ["<<i<<" , "<<j<<" ] and ending at ["<<i-lengthofwords[f]+1<<" , "<<j-lengthofwords[f]+1<<" ]"<<endl;
				return true;
			}
		}
		if (words[f][c] != desired[l][m])
		{
			return false;
		}

	}
	return false;
}

//FUNCTIONS ENDING


void seewordsinarray(char**desired, int rows,int cols,string words[],int lengthofwords[],int totalw)
{

    bool trueorfalse[20]={};

bool check= false;
for(int f=0 ; f<totalw ; f++)
    {
         for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<cols ; j++)
            {

                if(desired[i][j]==words[f][0])
                {

                         check= false;
                       if(H_lefttoright(f,i,j,desired,lengthofwords,words,cols)==true)
                        {   check=true;
                            goto changef;
                        }

                        else if(H_righttoleft(f,i,j,desired,lengthofwords,words)==true)
                        {
                            check=true;
                            goto changef;
                        }
                        else if (V_uptodown(f, i, j,desired,lengthofwords,words, rows)==true)
                        {
                            check=true;
                            goto changef;
                        }

                        else if (V_downtoup(f, i, j,desired,lengthofwords,words)==true)
                        {
                            check=true;
                            goto changef;
                        }

                        else if (D_uplefttobottomright(f, i, j,desired,lengthofwords,words, rows)==true)
                        {
                            check=true;
                            goto changef;
                        }
                        else if (D_uprighttobottomleft(f, i, j,desired,lengthofwords,words, rows)==true)
                        {
                            check=true;
                            goto changef;
                        }
                        else if (D_bottomlefttoupright(f, i, j,desired,lengthofwords,words, rows, cols)==true)
                        {
                            check=true;
                            goto changef;
                        }

                         else if (D_bottomrighttoupleft(f, i, j,desired,lengthofwords,words, rows)==true)
                        {
                            check=true;
                            goto changef;
                        }


                }


            }

        }
         if(check==false)
            {
               cout<<endl<<words[f]<<" not found : / "<<endl;
            }
        changef:;
    }


}



char menumejao()
{

char choice;
cout<<"Enter 'C' to create grid"<<endl;
cout<<"Enter 'Q' to quit"<<endl;
cout<<"Enter 'S' to search words"<<endl;


cin>>choice;

return choice;


}

int main()
{
ifstream TASK1IN;
ifstream TASK1IN2;
ifstream TASK1IN3;
ofstream OUT;
ifstream IN;
ifstream IN1;
ifstream IN2;
string name, name2;
int sizeofwords[20],cols,rows,n,n1,r=0,c=0;
int desrow,descol,totalwords;
char a;

againmenu:
a=menumejao();

char** base= nullptr;
char** desired=nullptr;
char** baseofwhole=nullptr;
char** tempbase=nullptr;

int lengthofwords[20];
string words[20];

switch (a)
{
        case 'C':
            {

                cout<<endl<<"Name a file where list of words are present: ";

                 cin>>name;
                 TASK1IN.open(name);
                 TASK1IN2.open(name);
                 TASK1IN3.open(name);

                cout<<endl<<"Enter the number of words in file: ";
                cin>>n;

                cout<<endl<<"Enter desired rows of grid: ";
                cin>>n;

                cout<<endl<<"Enter desired cols of grid: ";
                cin>>n1;

                cout<<endl<<"Enter name of output file: ";
                cin>>name2;
                OUT.open(name2);

                rows = calcmaximum(cols, sizeofwords, TASK1IN2);


                if(n<=cols && n1<=cols)
                {
                    cout<<endl<<"Grid cannot be formed."<<endl;
                    system("pause");
                    goto againmenu;

                }
                else
                {
                    rows=n;
                    cols=n1;
                       base = createarray1(rows, cols);

                    tempbase = createtemparray(rows, TASK1IN);

                    placewords(base, tempbase, cols, rows, sizeofwords);

                    //printarray(tempbase,rows,cols);
                    //    printgrid(base,rows,cols);


                    placerandom(base,rows,cols);

                    printgrid(base,rows, cols, OUT, name2);

                    TASK1IN.close();
                    TASK1IN2.close();
                    TASK1IN3.close();

                }

                break;

            }

        case 'S':
               {
                    cout<<"Name of the input file which has a grid in it: ";
                    cin>>name;
                    name2=name;
                    IN.open(name);
                    IN1.open(name);

                    cout<<"Name of the file with input to be searched: ";
                    cin>>name2;

                    IN2.open(name2);
                    IN2>>desrow;
                    IN2>>descol;
                    IN2>>totalwords;

                    r=calcmax(c,IN);
                    baseofwhole=createarray(r,c, IN1);
                    printarray(baseofwhole,r,c);

                    //task2 is the base address of cropped array
                        desired=create(desrow,descol);
                    //printarray(desired,desrow,descol);
                        cout<<endl;

                        createcopy(desired,baseofwhole, desrow, descol );
                        printarray(desired,desrow,descol);

                        for(int i=0 ; i<totalwords ; i++)
                        {
                            string a;

                            IN2>>a;

                            words[i]=a;
                            lengthofwords[i]=a.length();
                        }

                        seewordsinarray(desired,desrow,descol,words,lengthofwords, totalwords);

               }

            case 'Q':
                {
                    cout<<"-----------------------------------BYE-------------------------------------------"<<endl;
                    return 0;
                }

}

goto againmenu;





}
