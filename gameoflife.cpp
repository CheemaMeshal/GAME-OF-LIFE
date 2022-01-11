//=====================================================================================================================
// Name        : gameoflife.cpp
// by          : Meshal Cheema
// roll no     : i191977
// section     : C (lab)
//=====================================================================================================================
#include <iostream>//function to invoke cin, cout
#include <fstream>//functtion to read,writefiles
#include <string>//function to handle character strings,lines,paras
#include <ctime>//for srand
#include <cstdlib> //for randomly generation of colours
#include <unistd.h>//for clear screen,slowing.
using namespace std;
void LETS_START_THE_GAME_OF_LIFE(); //defining first function
//cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                    //function for colour of stars
//function changes the colour of the stars on the grid randomly,there are 5 colurs that can be used to fill in ubuntu.They have colours range from 31 to 35
int Selecting_Colour(int colour) 
{
colour=rand()%(36-31)+31;
return colour;
}
//cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                   //function displays the rules of game of life.
void RULES()
{
cout<<"1) Any live cell with less than two live neighbors bites the dust, as though by underpopulation"<<endl<<"2)Any live cell with a few live neighbors lives on to the people to come"<<endl<<"3)Any live cell with in excess of three live neighbors bites the dust, as though by overpopulation"<<endl<<"4)Any dead cell with precisely three live neighbors turns into a live cell, as though by propagation"<<endl;
cout<<endl;
cout<<"1)R to Return                                 2)E to Exit"<<endl;
char x;
cin>>x;
if (x=='r' || x=='R')
{
  LETS_START_THE_GAME_OF_LIFE();//returning to game, so that game doesnot stop after entering rules
}
else if (x=='e' || x=='E')
{
cout<<"GAME ENDED"<<endl; //game endedd
}
} 
// function 8 end
//cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                      //function has the description of game of life.
void DESCRIPTION()
{ 
char x;
cout<<"The Game of Life, additionally referred to just as Life, is a phone machine conceived by the British mathematician John Horton Conway in 1970.[1] It is a zero-player game, implying that its advancement is dictated by its underlying state, requiring no additionally input. One connects with the Game of Life by making an underlying setup and seeing how it advances. It is Turing finished and can recreate a widespread constructor or some other Turing machine"<<endl;
cout<<"1)R to Return                                 2)E to Exit"<<endl;
cin>>x;
if (x=='r')
{
  LETS_START_THE_GAME_OF_LIFE(); //returning to game, so that game doesnot stop after entering description	
}
else if (x=='e' || x=='E')
{
   cout<<"GAME ENDED"<<endl;//game endedd
}
} 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                         //function that creates the grid Two, then equalizing it with our grid 1, then it finally     implements the rules of game of life mentioned above
int CELL_ALIVE_DEAD_MODE(int GridSize,int **GAMEOFLIFEGRID)
{
/*int **gridTwo=new int*[GridSize];//declaring 2darray dynamically for making grid no 1
for(int j=0;j<GridSize;j++)
{
gridTwo[j]=new int [GridSize];
}
for (int i=0;i<GridSize;i++)  //initializing each element of grid 1 to zero
{
 for (int j=0; j<GridSize;j++)
 {
  gridTwo[i][j]=0;
 }
}  */
cout<<"Coordinated are stored in output.txt"<<endl;
fstream nnfile;
nnfile.open("output.txt",ios::out);
{
int gridTwo[GridSize][GridSize];
for (int i=0;i<GridSize;i++)  //initializing each element of grid 2 to zero
{
 for (int j=0; j<GridSize;j++)
 {
  gridTwo[i][j]=0;
 }
}  
for (int i=0;i<GridSize;i++)
{                             //equalizing the both grid here
 for (int j=0;j<GridSize;j++)
 {   
   gridTwo[i][j]=GAMEOFLIFEGRID[i][j];
 }
} 
int neighbour_cells=0;
 for (int i=0;i<GridSize;i++)//loop for cheking neighbors on x the x coordinates
	{
		for (int j=0;j<GridSize;j++)//loop for cheking neighbors on y coordinates
		{
			if(gridTwo[i-1][j-1]==1)//cheking neighbors alive or dead.
				{
					neighbour_cells=neighbour_cells+1;//adding all neighbors together now
				}
			    if(gridTwo[i-1][j]==1)////cheking neighbors alive or dead.
				{
					neighbour_cells=neighbour_cells+1;//adding all neighbors together now 
				}
			    if(gridTwo[i][j-1]==1)////cheking neighbors alive or dead.
				{
					neighbour_cells=neighbour_cells+1;//adding all neighbors  together now
				}
			    if(gridTwo[i+1][j+1]==1)////cheking neighbors alive or dead.
				{
					neighbour_cells=neighbour_cells+1;//adding all neighbors  together now
				}
			    if(gridTwo[i][j+1]==1)//cheking neighbors alive or dead.
				{
					neighbour_cells=neighbour_cells+1;//adding all neighbors together now
				}
				if(gridTwo[i+1][j]==1)//cheking neighbors alive or dead.
				{
					neighbour_cells=neighbour_cells+1;//adding all neighbors  together now
				}
				if(gridTwo[i-1][j+1]==1)//cheking neighbors alive or dead.
				{
					neighbour_cells=neighbour_cells+1;//adding all neighborstogether now
				}
				if(gridTwo[i+1][j-1]==1)//cheking neighbors alive or dead.
				{
					neighbour_cells=neighbour_cells+1;//adding all neighbors together now
				}
		     if(neighbour_cells>3 || neighbour_cells<2)
		     {  //cheking neighbors alive or dead.
	       	         GAMEOFLIFEGRID[i][j]=0; 
	       	 }//equalizing grid to 0, if condition statisfies
		    else if( neighbour_cells==3)//cheking neighbors alive or dead.
			{
				GAMEOFLIFEGRID[i][j]=1;//equlaizing it to 1	
			}
			neighbour_cells=0;//declaring neighbors cells to zero now;
			
	    }
	     nnfile<<**gridTwo<<endl;//for writing end coordinated on the files
	    }
   }
nnfile.close();//closing output.txt
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                                       //the displaying function. recieves a pointer to the grid and grid size, where the value comes out to be true.the star is displayed, if false, then a space,moreover, int colour catches the colour we have to display for the star
int Display_GAMEOFLIFEGRID (int **GAMEOFLIFEGRID,int GridSize)
{
 for (int i=0;i<GridSize;i++)
 {

  for (int j=0; j<GridSize;j++) //displaying grid 1
  {
    int colour=Selecting_Colour(colour);//the colour function implemetation
   if (GAMEOFLIFEGRID[i][j]==1)//where the coordinates on the grid are
   {
      
     cout<<"\033[1;"<<colour<<"m*\033[0m";   //line for coloured text in linux. 
    //cout<<"*"; //when found printing a star else space
   }
   else 
   {
   cout<<"\033[1;"<<colour<<"m.\033[0m";
   //cout<<" ";//printing spaces on grid means nth is printed on grid
   }
 }
 cout<<endl;

}  
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                        //function for reading from the file ans toring those values to grid
                        //only plays when we enter the filemode
int **ReadFromFile_and_storingvalues (string filename,int **GAMEOFLIFEGRID)//use of pointer for paasing grid 1 to function
{
int movement=0,variable=0; //initializing variables to be passed in file
int GridCoordinateX=0, GridCoordinateY=0; //coordinates for grid 1
//cout<<"hello1"<<endl;
fstream file;//file declaratiom
file.open(filename.c_str());//opening file
if (!file)//incase user enters wrong file
{
cout<<"FILE OPENING FAILED"<<endl;
}
else//incase of right option
{ 
file>>movement;//passing variables to files
file>>variable;   
 for (int i=0;i<variable;i++)
 {
  file>>GridCoordinateX;
  file>>GridCoordinateY; //filling coordinates with values of file
  GAMEOFLIFEGRID[GridCoordinateX][GridCoordinateY]=1;
 }
file.close();//closing file
return GAMEOFLIFEGRID;//returning grid 1 to main function
}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
      //a function containg the functions display,working, slows our outout clears screem
void MAIN_IMPLEMENTATION(int GridSize,int **GAMEOFLIFEGRID)
{
Display_GAMEOFLIFEGRID(GAMEOFLIFEGRID,GridSize);//function for displaying grid
CELL_ALIVE_DEAD_MODE(GridSize,GAMEOFLIFEGRID);//function implementing rules of game of life
 unsigned int speedforsleep=100000;
	    usleep(speedforsleep);
	    std::system("clear");  
	    cout<<"\033[2J\033[1;1H";  //used in ubuntu for lsowing clearing
}
//cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
                            //taking file name form user
string taking_in_file_name_from_user()
{//function 2 start
string filename;//string for storing filenames
cout<<"Choose files, from the following, for the Gridsetup"<<endl;
cout<<endl;  // 7 files created, having coordinates wriiten in them
cout<<"* diehard.txt"<<endl;
cout<<endl;
cout<<"* test2.txt"<<endl;
cout<<endl;
cout<<"* toad.txt"<<endl;
cout<<endl;
cout<<"* aim.txt"<<endl;
cout<<endl;
cout<<"* beehive.txt"<<endl;
cout<<endl;
cout<<"* experiment.txt"<<endl;
cout<<endl;
cout<<"* test1.txt"<<endl;
cout<<endl;
cout<<"PLEASE ENTER : ";
cout<<endl;
cin>>filename;//taking input
return filename;  //returns filename to the starting game function
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                 //function that takes coordinaes from the user
int taking_input_from_user(int takingincells,int xcoordinate,int ycoordinate,int **GAMEOFLIFEGRID,int GridSize)
{
fstream filewrite;//for writing file
filewrite.open("myown.txt",ios::out|ios::in);//file write name

cout<<"Enter the total number  of the cells you want to write on file(myown.txt)"<<endl;//Taking input
cin>>takingincells;
for(int i=0;i<takingincells;i++)
 {
   cout<<"Enter the x coordinate  for cell "<<i+1<<" : ";
   cin>>xcoordinate;  //taking x coordinate on the grid
   filewrite<<xcoordinate<<" ";  //writing x coordinates on file
   cout<<"Enter the y coordinate  for cell "<<i+1<<" : ";
   cin>>ycoordinate;//taking y coordinate on grid
   filewrite<<ycoordinate;//writing y coordinates on file
   filewrite<<endl;
     while (xcoordinate>GridSize || ycoordinate>GridSize)//if our coordinated are larger in  value than our size 20 then user will agin enetr the coordinates
      {
    	cout<<"WRONG ENTERY"<<endl;//indicating the wrong entery
    	cout<<"Enter the x,y coordinates of the cell again "<<i+1<<" : "; 
    	cin>>xcoordinate>>ycoordinate;  //taking x y coordinates gain
    	filewrite<<xcoordinate<<" "<<ycoordinate;  //writing coordinates on file
    	GAMEOFLIFEGRID[xcoordinate][ycoordinate]=1; //initilaing it on the grid
      }
       
    GAMEOFLIFEGRID[xcoordinate][ycoordinate]=1;//where the coordinated match on grid, a star will be printed in display functiom
 }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
char function_for_other_choices(char choice) //taking char from starting the game function
{//if b pressed
if (choice == 'b' || choice == 'B')
{ 
  DESCRIPTION();  //description function
}//if c pressed
if (choice == 'c' || choice == 'C')
{ 
  RULES();//rules function function
} //if d pressed
if (choice == 'd' || choice == 'D')
{ 
   cout<<endl;
   cout<<"GAME ENDED"<<endl; //ends the game
}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                               //starting the gme function
void LETS_START_THE_GAME_OF_LIFE()
{
cout<<"                       WELCOME TO THE GAME OF LIFE"<<endl;
cout<<endl;//optionf for proceeding in game
cout<<"A)START"<<endl; //option A will start the game
cout<<endl;
cout<<"B)DESCRIPTION"<<endl; //option B will show u description
cout<<endl;
cout<<"C)RULES "<<endl; //option C will take u to rules
cout<<endl;
cout<<"D)EXIT"<<endl; //option 	D will stop your game
char choice,choice1;  //declaring char variables
int choice2;int x; //declarinng int variables
cout<<endl;
cout<<"Enter : ";  //taking very first input from user
cin>>choice;        //cin your choice
// if A is pressed
if (choice == 'a' || choice == 'A')
{
int takingincells,xcoordinate,ycoordinate;//declarinng int variables
const int GridSize=20;//a constant size for the two grids
int **GAMEOFLIFEGRID=new int*[GridSize];//declaring 2darray dynamically for making grid no 1
for(int j=0;j<GridSize;j++)
{
GAMEOFLIFEGRID[j]=new int [GridSize];
}
for (int i=0;i<GridSize;i++)  //initializing each element of grid 1 to zero
{
 for (int j=0; j<GridSize;j++)
 {
  GAMEOFLIFEGRID[i][j]=0;
 }
}  
cout<<endl;//two ways for starting game
cout<<"1)START GAME BY FILE READING"<<endl;  //select your file, has already wriiten coordinates
cout<<"2)START GAME BY ENTERING YOUR OWN COORDINATES"<<endl; //user can also start by entering his own coordinates
cout<<endl;
cout<<"Enter integer : ";
cin>>choice2;//taking second input
 if (choice2==1)  //by files
 {
  string filename=taking_in_file_name_from_user();//function for taking in the filename from user
  ReadFromFile_and_storingvalues(filename,GAMEOFLIFEGRID);//function to store values from the file to the grid
  cout<<endl;
  cout<<endl;
  cout<<"                   GRID IS SET! "<<endl;
  Display_GAMEOFLIFEGRID(GAMEOFLIFEGRID,GridSize); //grid display
  cout<<" PRESS S TO START "<<endl;  //pressing button S will start the game
  cin>>choice1;
    if (choice1 == 's' || 'S' )
    {
   
      while(1)
      {
     
         MAIN_IMPLEMENTATION(GridSize,GAMEOFLIFEGRID);  //function consisting of all the major functions, implemetation of game of life
    
      }
    }
   else 
  { 
   cout<<"GAME ENDED"<<endl;  //if s not entered game will end
  }
 }

 else if (choice2==2)  //by user
 {
   taking_input_from_user(takingincells,xcoordinate,ycoordinate,GAMEOFLIFEGRID,GridSize);//taking coordinates
   cout<<"                   GRID IS SET! "<<endl;
   Display_GAMEOFLIFEGRID(GAMEOFLIFEGRID,GridSize);//displaying grid
   cout<<" PRESS S TO START "<<endl;
   cin>>choice1;
    if (choice1 == 's' || 'S' )//pressing button S will start the game
    {
   
      while(1)
      {
       
        MAIN_IMPLEMENTATION(GridSize,GAMEOFLIFEGRID); //function consisting of all the major functions, implemetation of game of life
   
      }
    }
   else 
   { 
    cout<<"GAME ENDED"<<endl;//if s not entered game will end
   }
 }
delete []GAMEOFLIFEGRID;//deleting gameoflifegrid
} //choice a if end
//function taking us to other choices,if a not enterd
else 
{
  function_for_other_choices(choice);
}
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main ()//main function
{
LETS_START_THE_GAME_OF_LIFE(); //our main function consisting of only one function.
return 0;
}
