/******************************************************
** Program: game.cpp
** Author: Adilbek bazarkulov
** Date: 05/20/2020
** Description: This program is a game "Hunt the wumpus", it accepts command
line arguments integer for size of the grid and true/false for using debugg mode,
with debug mode user can see the location of events.
** Input: Users input, command line arguments.
** Output: The grid, events.
******************************************************/
#include "game.h"

using namespace std;
/*********************************************************************
** Function: game()
** Description: Default constructor for game class
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Game::Game()
{
    size = 0;
    player_x = 0; 
    player_y = 0; 
    wumpus_x = 0; 
    wumpus_y = 0;
    arrows = 0;
    
    mode = "";
    pos1 = "";
    pos2 = "";
    pos3 = "";
    arrow1 = "";
    arrow2 = "";
}
/*********************************************************************
** Function: Game
** Description: non-default constructor for Game class
** Parameters: int new_size, string new_mdoe
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
Game::Game(int new_size, string new_mode)
{
   mode = new_mode;
   size = new_size;
   arrows = 3;
   wumpus = false;
   gold = false;
   alive = true;
   pos1 = "gold[completed] Wumpus [dead] YOU WON!";
   pos2 = "gold[completed] Wumpus [alive]";
   pos3 = "gold[find the gold!] Wumpus [kill wumpus!]";
   arrow1 = "arrows: 0, Wumpus [alive] GAME OVER!";
   arrow2 = "arrows: 0, Wumpus [dead]";

   grid.resize(size);

   for (int i = 0; i<size; i++){
       grid[i].resize(size);
   }
}
/*********************************************************************
** Function: void print grid
** Description: this function prints out grid using false mode, which 
is normal mode where user can't see positions of events
** Parameters: none
** Pre-Conditions: size cannot be less than 4
** Post-Conditions: prints information
*********************************************************************/ 
void Game::print_grid()
{
   
   for(int i = 0; i < size; i++)
   {
    cout<<"#";
        
        for(int k = 0; k < size; k++)
        {
         
         cout << "-----";
         cout << "#";
         
        }
    
    cout<<"\n";
       
       for(int j = 0; j < size; j++)
       {
           switch(grid[i][j].get_player())
           {
               case 0:
                   cout << "|";
                   cout << "     ";
                   break;
               case 1:
                   cout << "|";
                   cout << "  *  ";
                   break;
                default:
                   cout << "|";
                   cout << "     ";
                   break;
           }
       }
       cout<<"|";
       cout<<"\n";
   }
   cout << "#";

   for(int i = 0; i < size; i++)
   {
   cout << "-----";
   cout << "#";
   }
   cout << "\n";
}
/*********************************************************************
** Function: void print_grid_debugg
** Description: this function prints out grid using true mode, which 
is cheat mode where user can see positions of events
** Parameters: none
** Pre-Conditions: size cannot be less than 4
** Post-Conditions: prints information
*********************************************************************/
void Game::print_grid_debugg()
{
    for(int i = 0; i < size; i++)
   {
    cout<<"#";
        
        for(int k = 0; k < size; k++)
        {
         
         cout << "-----";
         cout << "#";
         
        }
    
    cout<<"\n";
       
       for(int j = 0; j < size; j++)
       {
           switch(grid[i][j].get_event_type())
           {
               case 1:
                   if(grid[i][j].get_player() == true)
                   {
                       cout << "|";
                       cout << "  *  ";
                   }
                   else if (grid[i][j].get_player() == false)
                   {
                       cout << "|";
                       cout << "     ";
                   }
                   
                   break;
               case 2:
                   cout << "|";
                   cout << "  W  ";
                   break;
               case 3:
                   cout << "|";
                   cout << "  G  ";
                   break;
               case 4:
                   cout << "|";
                   cout << "  P  ";
                   break;
               case 5:
                   cout << "|";
                   cout << "  B  ";
                   break;
               default:
                   cout<< "|";
                   cout<< "     ";
           }
       }

       cout<<"|";
       cout<<"\n";
   }
   cout << "#";

   for(int i = 0; i < size; i++)
   {
   cout << "-----";
   cout << "#";
   }
   cout << "\n";

}
/*********************************************************************
** Function: load_data
** Description: this function calls non-default constructor for game
and also calls function set_grid and gameplay
** Parameters: int size, string mode
** Pre-Conditions: int size cannot be less than 4, mode can be only "true" or "false"
** Post-Conditions: dynamically allocates memory, populates events, set grid.
*********************************************************************/ 
void Game::load_data(int size, string mode)
{
    if(mode == "true"||mode == "false")
    {
        
        Game g1(size, mode);
        g1.set_grid();
        g1.gameplay(mode);
        
    }
    else
    {
        cout<< "Invalid command line"<<endl;
    }
    
    
}
void Game::gameplay(string input)
{
        int option = 0;
        do{
        if(input == "true")
        {
        print_grid_debugg();
        }
        else if(input == "false")
        {
        print_grid();
        }
        print_event();
        cout<<"(1)Move \n(2)Shoot \n(3)Exit"<<endl;
        cout<<":";
        cin>>option;
        cin.clear();
        cin.ignore(256,'\n');
        if(option == 1){
        char direction = ' ';
        cout<<"where you move want? (up) (down) (left) (right)"<<endl;
        cout<<"w/a/s/d: ";
        cin>>direction;
        cout<<"\n\n\n\n";
        cin.clear();
        cin.ignore(256,'\n');
        move_player(direction); 
        }
        else if(option == 2)
        {
            if(arrows>=1){
            string direction;
            cout<<"What direction? SPACE and w/a/s/d\n:";
            getline(cin,direction);
            if(direction==" w"
            ||direction==" s"
            ||direction==" a"
            ||direction==" d"){
            shoot_arrow(direction);
            }
            else{cout<<"Invalid direction for arrow"<<endl;}
            }
            else
            {
                cout<<"You don't have any arrows left"<<endl;
            }
            
        }
        else if(option == 3)
        {
            //quit
        }
        else 
        {
            cout<<"INVALID INPUT"<<endl;
        }
        print_status();
        }while(option!=3&&alive==true);
}
/*********************************************************************
** Function: print_status
** Description: this function prints out the information about
current status of the player in the game
** Parameters: none
** Pre-Conditions: arrows, gold, wumpus
** Post-Conditions: depends of pre conditions
*********************************************************************/ 
void Game::print_status()
{
    if(gold == true && wumpus == true)//win
    {
        cout<<"CURRENT PROGRESS:"<<endl;
        cout << pos1 << "\n\n";
        alive = false;
        
    }
    else if(arrows <= 0 && wumpus == false)
    {
        cout <<arrow1<<endl;
        alive = false;
    }
    else if(arrows <= 0 && wumpus == true)
    {
        cout <<arrow1<<endl;
    }
    else if(gold == false && wumpus == true)//need gold
    {
        cout<<"CURRENT PROGRESS:"<<endl;
        cout << pos3 << "\n\n";
        
    }
    else if(gold == true && wumpus == false)//kill wumpus
    {
        cout<<"CURRENT PROGRESS:"<<endl;
        cout << pos2 << "\n\n";
    }
}
//Getter for wumpus
bool Game::get_wumpus()
{
    return wumpus;
}
/*********************************************************************
** Function: pop_event
** Description: This function depending on the tyoe of the events
dynamically allocates memory and position on the grid, also uses 
random generated number for choosing the future position for event
** Parameters: int type
** Pre-Conditions: event type from 0 to 5
** Post-Conditions: dynamically allocated event
*********************************************************************/ 
void Game::pop_event(int type)
{
    srand(time(NULL));
    int posX, posY;
    bool pos = false;
    while (pos == false)
    {
        posX = rand()%size;
        posY = rand()%size;
        if(grid[posX][posY].get_event_type() == 0)
        {
            grid[posX][posY].set_event_type(type);
            pos = true;
        }
    }
    if (type == 1)
    {
        player_x = posX;
        player_y = posY;
        grid[player_x][player_y].set_player(true);
    }
    if(type == 2)
    {
        wumpus_x = posX;
        wumpus_y = posY;
    }
    
}
/*********************************************************************
** Function: set_grid
** Description: This function calls pop event function in order to
dynamically set the grid, populate each room with event or make it empty,
depending on random generated number from pop event function
** Parameters: none
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/ 
void Game::set_grid()
{
    pop_event(1);
    pop_event(2);
    pop_event(3);
    
    for (int j = 0; j < 2; j++)
    {
        pop_event(5);
    }
    for (int i = 0; i < 2; i++)
    {
        pop_event(4);
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(grid[i][j].get_event_type() !=1)
                grid[i][j].set_event(grid[i][j].get_event_type());
        }
        
    }
    
}
/*********************************************************************
** Function: move_player 
** Description: This is important function for the gameplay, 
it takes user's input which can be w/a/s/d then depending on
this input it move the position of the player.
** Parameters: char direction
** Pre-Conditions: only w,a,s,d
** Post-Conditions: change position of the player 
*********************************************************************/ 
void Game::move_player(char direction)
{
    if(direction == 'w' && (player_x-1)>=0 && (player_x-1)<size) //up
    {
        grid[player_x][player_y].set_player(false);
        (player_x-=1);
        grid[player_x][player_y].set_player(true);
        
        if(grid[player_x][player_y].get_event_type() == 0||
        grid[player_x][player_y].get_event_type() == 1)
        {
            grid[player_x][player_y].set_event_type(1);
        }
        else
        {
            encounter();
            //grid[player_x][player_y].get_in();
        } 
    }
    else if(direction == 's' && (player_x+1)>=0 && (player_x+1)<size) //down
    {
        grid[player_x][player_y].set_player(false);
        (player_x+=1);
        grid[player_x][player_y].set_player(true);
        if(grid[player_x][player_y].get_event_type() == 0||
        grid[player_x][player_y].get_event_type() == 1)
        {
            grid[player_x][player_y].set_event_type(1);
        }
        else
        {
            encounter();
            //grid[player_x][player_y].get_in();
        }
    }
    else if(direction == 'a' && (player_y-1)>=0 && (player_y-1)<size) //left
    {
        grid[player_x][player_y].set_player(false);
        (player_y-=1);
        grid[player_x][player_y].set_player(true);
        if(grid[player_x][player_y].get_event_type() == 0||
        grid[player_x][player_y].get_event_type() == 1)
        {
            grid[player_x][player_y].set_event_type(1);
        }
        else
        {
            encounter();
            //grid[player_x][player_y].get_in();
        }
    }
    else if(direction == 'd' && (player_y+1)>=0 && (player_y+1)<size) //right
    {
        grid[player_x][player_y].set_player(false);
        (player_y+=1);
        grid[player_x][player_y].set_player(true);
        if(grid[player_x][player_y].get_event_type() == 0||
        grid[player_x][player_y].get_event_type() == 1)
        {
            grid[player_x][player_y].set_event_type(1);
        }
        else
        {
            encounter();
            grid[player_x][player_y].get_in();
        }
    }
    else
    {
        cout<< "INVALID MOVE, TRY AGAIN"<<endl;
    }

}
/*********************************************************************
** Function: print_event
** Description: This function filling out the grid with
populated events.
** Parameters: none
** Pre-Conditions: dynamically allocated events
** Post-Conditions: pritns out the events
*********************************************************************/ 
void Game::print_event()
{
    wumpus_near = false;
    cout<<"~~~~~~~~~~~~~~~~~"<<endl;
    if((player_x+1) < size && grid[player_x+1][player_y].get_event_type()!=1)
    {
        cout << grid[player_x+1][player_y].get_event() << endl;

            if (grid[player_x+1][player_y].get_event_type() == 2)
            {
                wumpus_near = true;
            }
            
    }
    if((player_x-1) >= 0 && grid[player_x-1][player_y].get_event_type()!=1)
    {
        cout << grid[player_x-1][player_y].get_event() << endl;

            if (grid[player_x-1][player_y].get_event_type() == 2)
            {
                wumpus_near = true;
            }
            
    }
    if((player_y+1) < size && grid[player_x][player_y+1].get_event_type()!=1)
    {
        cout << grid[player_x][player_y+1].get_event() << endl;

            if (grid[player_x][player_y+1].get_event_type() == 2)
            {
                wumpus_near = true;
            }
            
    }
    if((player_y-1) >=0 && grid[player_x][player_y-1].get_event_type()!=1)
    {
        cout << grid[player_x][player_y-1].get_event() << endl;

            if (grid[player_x][player_y-1].get_event_type() == 2)
            {
                wumpus_near = true;
            }
            
    }
    cout<<"~~~~~~~~~~~~~~~~~"<<endl;
}
/*********************************************************************
** Function: encounter
** Description: this function prints out the events near the player
** Parameters: none
** Pre-Conditions: the position of the player at the moment
** Post-Conditions: none
*********************************************************************/ 
void Game::encounter()
{
    if(arrows == 0 && wumpus == false)
    {
        cout << arrow1 << "\n\n";
        //return false;
    }
    else if(arrows == 0 && wumpus == true)
    {
        cout << arrow2 << "\n\n";
    }
    
    switch (grid[player_x][player_y].get_event_type())
    {
    case 1:
        
        break;
    case 2:
        cout << grid[player_x][player_y].get_in() << "\n\n";
        
        alive = false;
        //return false;
        break;
    case 3:
        cout << grid[player_x][player_y].get_in() << "\n\n";
        gold = true;
        grid[player_x][player_y].set_player(false);
        grid[player_x][player_y].set_player(true);
        grid[player_x][player_y].set_event_type(1);
        //remove(player_x,player_y);
        //return true;
        break;
    case 4: 
        cout << grid[player_x][player_y].get_in() << "\n\n";
        alive = false;
        //return false;
        break;
    case 5:
        cout << grid[player_x][player_y].get_in() << "\n\n";
        bat_move();
        //return true;
        break;
    
    default:
        break;
    }
    //return true;
}
/*********************************************************************
** Function: bat_move
** Description: this function will be called if player enters room with bats,
bats take the player to another any random room
** Parameters: none 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Game::bat_move()
{
    grid[player_x][player_y].set_player(false);
    int pos_x, pos_y;
    bool position = false;
    while (position == false)
    {
        pos_x = rand()%size;
        pos_y = rand()%size;
            
        if(grid[pos_x][pos_y].get_event_type()==2||
        grid[pos_x][pos_y].get_event_type()==3||
        grid[pos_x][pos_y].get_event_type()==4)
        {
        player_x = pos_x;
        player_y = pos_y;
        grid[player_x][player_y].set_player(false);
        grid[player_x][player_y].set_player(true);
        encounter();
        position = true;
        }
        else if(grid[pos_x][pos_y].get_event_type()==1||
        grid[pos_x][pos_y].get_event_type()==0)
        {
        player_x = pos_x;
        player_y = pos_y;
        grid[player_x][player_y].set_player(false);
        grid[player_x][player_y].set_player(true);
        grid[player_x][player_y].set_event_type(1);
        position = true;
        }
        else
        {
            position = false;
        }
        
    }
}
/*********************************************************************
** Function: wumpus_move
** Description: This funciton is wumpus move, if player
shoots a arrow and misses the wumpus has 75% to wake an move.
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Game::wumpus_move()
{
    cout << "You missed your shoot"<<endl;
    arrows --;
    cout << "Arrows left: "<< arrows <<endl;
    int wumpus_rand = rand()%4;
    if(wumpus_rand != 4)
    {
        cout << "Wumpus awake and he is moving"<<endl;
        grid[wumpus_x][wumpus_y].set_event_type(0);
        //grid[wumpus_x][wumpus_y].set_event(0);
        pop_event(2);
        //grid[wumpus_x][wumpus_y].set_event(2);

    }
}
/*********************************************************************
** Function: shoot_arrow
** Description: This function is shooting an arrow, the player can
choose to shoot an arrow up to 3 times. It travels untill it hits the wall
or trough 3 rooms.
** Parameters: string where
** Pre-Conditions: space and direction
** Post-Conditions: arrow flies
*********************************************************************/ 
void Game::shoot_arrow(string where)
{
    int pos_x = player_x;
    int pos_y = player_y;

    if(wumpus == true)
    {
        cout<<"Wumpus already killed"<<endl;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (where == " w" && (pos_x-1)>=0)
        {
            pos_x--;
        }
        else if (where == " s" && (pos_x+1) < size)
        {
            pos_x++;
        }
        else if (where == " a" && (pos_y-1) >= 0)
        {
            pos_y--;
        }
        else if (where == " d" && (pos_y+1) <size)
        {
            pos_y++;
        }  
        if(grid[pos_x][pos_y].get_event_type() == 2)
        {
            cout<< "Your arrow reached Wumpus head"<<endl;
             //remove(wumpus_x,wumpus_y);
            grid[pos_x][pos_y].set_event_type(0);
            wumpus = true;
        }
    }
    if (wumpus == false)
    {
        wumpus_move();
    }
}
void Game::restart(bool &input)
{
    char yesno;
    cout<< "Do you want to restart the game? y/n\n:"<<endl;
    cin>>yesno;
    cin.clear();
    cin.ignore(256,'\n');
    if(yesno == 'y' || yesno == 'Y')
    {
        input = true;
    }
    else if(yesno == 'n' || yesno == 'N')
    {
        input = false;
    }
    else
    {
        cout<<"Invalid input"<<endl;
        input = false;
    }
    
}
Game::~Game()
{
    
    
}

