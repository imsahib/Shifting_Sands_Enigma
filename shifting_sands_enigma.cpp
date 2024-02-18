#include<iostream>
#include<cstdlib>                             // FOR exit(0)
#include<unordered_set>
#include<ctime>                                // FOR srand() function to generate random numbers
#include<vector>                               // data structure
#include<conio.h>                              // helps for clearing screen
#include<windows.h>
#include<string>                               // predefined template class
# define RED "\033[1;31m"                           // DEFINING MACROS FOR COLORS
# define NORMAL_RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[1;34m"
# define GREEN "\033[0;32m"
# define CIAN "\033[1;36m"
# define PURPLE "\33[1;35m "
# define WHITE "\033[1;37m "
#define RESET "\033[0m"
using namespace std;
void flow_of_game(string name,int tries);           // HOW THE GAME FLOWS
class Game
{
    private:
        int arr[4][4], tries,matrix_size,target_arr[4][4];              // ARRAY OF 4x4 SIZE, NUMBER OF TRIES, MATRIX SIZE
        string name ;                                  // NAME OF PLAYER

    public:
        Game(string name,int tries,int matrix_size)   // PARAMETRIZED CONSTRUCTOR
        {
            this->name=name;
            this->tries=tries;
            this->matrix_size;
        }
        int get_tries()
        {
            return tries;                          // GIVES NUMBER OF TRIES REMANING
        }
        void tries_updation()
        {
            tries--;                               // DECREASE NUMBER OF TRIES AFTER VALID MOVE
          //  captions();
            if(tries==0)
                End_Of_Game();                   // GAME ENDS HERE
        }
        void rules_of_game_play();              // RULES FOR PLAYING GAME
        void create_Game();                     // CREATES THE MATRIX OF GAME PLAY
        void target_Matrix();
        void display_Game();                    // DISPLAY THAT MATRIX ON SCREEN
        void captions();                       // DISPLAY  COMMENTS ON EVERY VALID MOVE

        // scan code operations
        int up_key();                             // ACTION RELATED TO UP KEY PRESSED
        int down_key();                          //  ACTION RELATED TO DOWN KEY PRESSED
        int left_key();                         // ACTION RELATED TO LEFT KEY PRESSED
        int right_key();                       // ACTION RELATED TO RIGHT KEY PRESSED
        vector<int> detect_pointer();         // DETECTS THE BLANK SPACE IN A MATRIX

        // getInput
        int read_key();                      // READ THE INPUT KEY

        // result

        void End_Of_Game();                // ACTION WHEN PLAYER LOOSE THE GAME
        int Winning_Condition();           // CHECKING THE WINNING CONDITION AFTER EVERY VALID MOVE

};

void Game:: create_Game()                  // MATRIX CREATION
{
    fflush(stdin);
    int n=16,i,j,num;
    unordered_set<int> s;                 // DATA STRUCTURE USE FOR INSERTING NUMBERS
    for(int i=0;i<n;i++)
        s.insert(i);                    // WE INSERT NUMBERS FROM 0 TO 15 IN A UNORDERED SET S
    srand(time(NULL));                   // TO GENERATE RANDOM VALUES UNIQUELY EVERY TIME, AND TIME IS THAT QUANTITY WHICH CHANGES EVERY SECOND.
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            while(!s.empty())           // TILL UNORDERED SET IS NOT EMPTY
            {
                 num = rand()%(n+1);       //  IT WILL GENERATE NUMBERS FROM 0 TO 15
                if(s.find(num)!=s.end())  // IF NUMBER FOUND IN SET
                 {
                      arr[i][j]=num;      // IT GET INSERT INTO THAT ITERATION
                      s.erase(num);       // WE REMOVE THAT NUMBER FROM UNORDERED SET THEN
                      break;              // TERMINATE THE INNER LOOP.
                 }
                else
                   continue;              // IF NUMBER NOT FOUND WE LOOK FOR ANOTHER NUMBER TILL UNORDERED SET IS NOT EMPTY.
            }

        }
    }

}


void Game:: display_Game()                      // DISPLAYING GAME
{
    cout<<endl<<CIAN<<"W e l c o m e    "<<RESET;
    cout<<YELLOW;
    for(char x: name)
        cout<<x<<" ";
    cout<<RESET;
    cout<<CIAN<<" ,   R e m a i n i n g   M o v e s  : "<<RESET<<YELLOW<<tries<<RESET<<endl<<endl;
    cout<<CIAN;
   //system("color 0B");
    //this->display_Target_Matrix();

    cout<<GREEN;
    cout<<endl<<endl<<"\t\tYour Target"<<endl<<endl;
    cout<<RESET;
      cout<<BLUE;

    int i=0,j=0;
      for(int i=0;i<13;i++)
        cout<<"--";
    cout<<"-";
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"|";
        for(int j=0;j<4;j++)
        {
                if(target_arr[i][j]!=0)
                {
                    if(target_arr[i][j]/10==0)
                      cout<<" "<<target_arr[i][j]<<"  |  ";
                    else
                      cout<<" "<<target_arr[i][j]<<" |  ";
                }
                else
                     cout<<"  "<<"  |  ";               // WE INSERT SPACE INSTEAD OF 0 TO MAKE IT BLANK


        }
        cout<<endl;
        if(i!=3)
          cout<<"|----|------|------|------|";       // FOR LAYOTING PURPOSE
        else
       {
           for(int i=0;i<13;i++)
                cout<<"--";
            cout<<"-";
       }
       cout<<endl;
    }

     cout<< RESET;



    cout<<endl<<endl;
    for(int i=0;i<30;i++)
        cout<<"--";
    cout<<YELLOW;
    cout<<endl<<endl<<"\t\tLet's Play!"<<endl<<endl;
    cout<<RESET;
    for(int i=0;i<13;i++)
        cout<<"--";
    cout<<"-";
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"|";
        for(int j=0;j<4;j++)
        {
                if(arr[i][j]!=0)
                {
                    if(arr[i][j]/10==0)
                      cout<<" "<<arr[i][j]<<"  |  ";
                    else
                      cout<<" "<<arr[i][j]<<" |  ";
                }
                else
                     cout<<"  "<<"  |  ";               // WE INSERT SPACE INSTEAD OF 0 TO MAKE IT BLANK


        }
        cout<<endl;
        if(i!=3)
          cout<<"|----|------|------|------|";       // FOR LAYOTING PURPOSE
        else
       {
           for(int i=0;i<13;i++)
                cout<<"--";
            cout<<"-";
       }
       cout<<endl;
    }
    cout<<RESET;
}
void Game:: captions()                     // SHOW CAPTIONS ON EVERY VALID MOVE
{
        int num;
        vector<string> s1;
        srand(time(NULL));
        cout<<YELLOW;
        s1.push_back("GOOD GOING!");
        s1.push_back("NICE MOVE!");
        s1.push_back("U R GOING TO LOOSE!");
        s1.push_back("NOT BAD!");
        s1.push_back("PLAYING WELL!");
        s1.push_back("PLAY SMARTLY!");
        s1.push_back("THINK BEFORE YOU MOVE!");
        s1.push_back("KEEP GOING!");

        num = s1.size();
        num = rand()%(num);                     // GENERATE RANDOM NUMBERS
        cout<<endl<<endl<<s1.at(num);            // STRING WHICH IS STORED AT THAT INDEX WILL GET DISPLAYED
        cout<<RESET;

}
int Game::Winning_Condition()          // CHECKS THE WINNING CONDITION MATCHES OR NOT AFTER EVERY VALID MOVE
{

    int flag=0;
    for(int i=0;i<4;i++)
    {

        for(int j=0;j<4;j++)
        {

            if(target_arr[i][j]!=arr[i][j])
            {
                flag=1;
                return 1;
            }
        }
    }



    if(flag==0)
    {
      system("cls");                  // TO CLEAR A SCREEN
      cout<<"\n\n\n\n\n\n";
      cout<<CIAN;
      cout<<" P L A Y E R :  ";
      for(char x: name)
        cout<<x<<" ";
      cout<<RESET;
      cout<<YELLOW<<"\n\n\n   Y O U   W O N !"<<RESET<<endl<<endl;
      getch();
      return 0;
    }
}
void Game:: End_Of_Game()            // WHEN PLAYER LOOSES A GAME
{
    int key;
    system("cls");
    cout<<"\n\n\n\n\n\n";
    cout<<CIAN;
    cout<<" \t\t\t\tP L A Y E R  : ";
    for(char x: name)
        cout<<x<<" ";
    cout<<RESET;
    cout<<RED<<"\n\n\n\n     \t\t\t\t Y O U   L O O S E !"<<RESET<<endl<<endl;
    cout<<YELLOW<<"\n\n     \t\t\t B E T T E R   L U C K   N E X T   T I M E !  "<<RESET<<endl<<endl;

    cout<<GREEN<<endl<<"  TO PLAY AGAIN PRESS 'Y' OR 'y'"<<RESET<<endl<<endl;
    cout<<RED<<endl<<"  ENTER ANY OTHER KEY TO EXIT"<<RESET<<endl<<endl;
    key=read_key();
     if(key==89 || key==121)
        flow_of_game(name,10);
    else
        exit(0);


}
vector<int> Game:: detect_pointer()           // DETECT THE EMPTY POSITION OR SPACE IN A MATRIX AT GIVEN TIME
{
    vector<int>index;
    for(int i=0;i<4;i++)
    {    for(int j=0;j<4;j++)
          {
              if(arr[i][j]==0)
            {
                index.push_back(i);
                index.push_back(j);
                return index;               // WE STORE i and j value in index vector array
            }
          }
    }
    return index;
}
int Game:: read_key()           // READ THE INPUT KEY
{
    int ch;
    ch= _getch();
    if(ch==0)
        ch=_getch();           // FOR SCAN CODE WE NEED TO DO THIS TWICE
    return ch;                // RETURNING THE ASCII VALUE OR SCAN CODE
}
int Game:: up_key()            // UP KEY IS ENTERED
{
    int temp;
    vector<int> index;
   index= detect_pointer();
   if(index[0]==3)  // Failure of operation
        return 0;
   else
   {
        int i=index[0];
        int j= index[1];
        // swap
        temp= arr[i][j];
        arr[i][j]= arr[i+1][j];
        arr[i+1][j]=temp;
        return 1;

   }

}
int Game:: down_key()                        // DOWN KEY IS ENTERED
{
    int temp;
    vector<int> index;
    index= detect_pointer();
   if(index[0]==0)  // Failure of operation
        return 0;
   else
   {
        int i=index[0];
        int j= index[1];
        // swap
        temp= arr[i][j];
        arr[i][j]= arr[i-1][j];
        arr[i-1][j]=temp;
        return 1;

   }

}

int Game:: left_key()                            // LEFT KEY IS ENTERED
{
    int temp;
    vector<int> nullindex;
    nullindex= detect_pointer();
   if(nullindex[1]==3)  // Failure of operation
        return 0;
   else
   {
        int i=nullindex[0];
        int j= nullindex[1];
        // swap
        temp= arr[i][j];
        arr[i][j]= arr[i][j+1];
        arr[i][j+1]=temp;
        return 1;

   }

}

int Game:: right_key()                           // RIGHT KEY IS ENTERED
{
    int temp;
    vector<int> nullindex;
    nullindex= detect_pointer();
   if(nullindex[1]==0)  // Failure of operation
        return 0;
   else
   {
        int i=nullindex[0];
        int j= nullindex[1];
        // swap
        temp= arr[i][j];
        arr[i][j]= arr[i][j-1];
        arr[i][j-1]=temp;
        return 1;

   }
}
void Game::target_Matrix()
{

    int n=16,i,j,num;
    unordered_set<int> s;                 // DATA STRUCTURE USE FOR INSERTING NUMBERS
    for(int i=0;i<n;i++)
        s.insert(i);                    // WE INSERT NUMBERS FROM 0 TO 15 IN A UNORDERED SET S
    srand(time(NULL));                   // TO GENERATE RANDOM VALUES UNIQUELY EVERY TIME, AND TIME IS THAT QUANTITY WHICH CHANGES EVERY SECOND.
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            while(!s.empty())           // TILL UNORDERED SET IS NOT EMPTY
            {
                 num = rand()%(n+1);       //  IT WILL GENERATE NUMBERS FROM 0 TO 15
                if(s.find(num)!=s.end())  // IF NUMBER FOUND IN SET
                 {
                      target_arr[i][j]=num;      // IT GET INSERT INTO THAT ITERATION
                      s.erase(num);       // WE REMOVE THAT NUMBER FROM UNORDERED SET THEN
                      break;              // TERMINATE THE INNER LOOP.
                 }
                else
                   continue;              // IF NUMBER NOT FOUND WE LOOK FOR ANOTHER NUMBER TILL UNORDERED SET IS NOT EMPTY.
            }

        }
    }


}

void Game:: rules_of_game_play()           // GAME PLAY RULES
{
    system("cls");
    cout<<endl<<CIAN <<"S H I F T I N G   S A N D S   E N I G M A"<<RESET <<endl<<endl<<endl;
    cout<<endl<<RED<<"R U L E S  O F   G A M E   P L A Y  : "<<RESET<<endl;
    cout<<endl<<YELLOW<<"1.You can move only 1 step at a time by arrow key"<<endl;
    cout<<endl<<"\t Move Up     : by Up arrow key "<<endl;
    cout<<endl<<"\t Move Down   : by down arrow key "<<endl;
    cout<<endl<<"\t Move Left   : by left arrow key "<<endl;
    cout<<endl<<"\t Move Right  : by right arrow key "<<endl;

    cout<<endl<<"2.You can move number at empty position only "<<endl;
    cout<<endl<<"3.For each valid move : your total number of move will decreased by 1"<<endl;
    cout<<endl<<"4.You need to win this game under the number of tries given "<<RESET<<endl;
    cout<<endl<<RED<<"5. W i n ni n g   s i t u a t i o n   c o m e s   w h e n  : "<<RESET<<endl;
    cout<<endl<<CIAN<<" 4 * 4   M A T R I X   I S   I N   O R D E R E D   F O R M   F R O M   1   T O   15  "<<RESET<<endl;
    cout<<endl<<RED<<"6.YOU CAN EXIT GAME  ANYTIME BY PRESSING 'Esc' key "<<RESET<<endl;
    cout<<endl<<endl<<YELLOW<<"\t\t W I N N I N G   C O N D I T I O N  :"<<RESET<<endl<<endl;
    cout<<BLUE;

    int i=0,j=0;
      for(int i=0;i<13;i++)
        cout<<"--";
    cout<<"-";
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"|";
        for(int j=0;j<4;j++)
        {
                if(target_arr[i][j]!=0)
                {
                    if(target_arr[i][j]/10==0)
                      cout<<" "<<target_arr[i][j]<<"  |  ";
                    else
                      cout<<" "<<target_arr[i][j]<<" |  ";
                }
                else
                     cout<<"  "<<"  |  ";               // WE INSERT SPACE INSTEAD OF 0 TO MAKE IT BLANK


        }
        cout<<endl;
        if(i!=3)
          cout<<"|----|------|------|------|";       // FOR LAYOTING PURPOSE
        else
       {
           for(int i=0;i<13;i++)
                cout<<"--";
            cout<<"-";
       }
       cout<<endl;
    }

     cout<< RESET;
    cout<<endl<<endl<<GREEN<<"E N T E R   A N Y   K E Y   T O   S T A R T   T H E   G A M E !"<<RESET<<endl;
    getch();
    system("cls");
}

void flow_of_game(string name,int tries)       // HOW GAMES FLOWS WITH THE PAYER
{
    int key,remaning,valid;
    Game player(name,tries,4);
    player.target_Matrix();
    player.rules_of_game_play();
    player.create_Game();
    player.display_Game();

    while( player.Winning_Condition())
    {
        if(key==72 || key==80 || key==75 || key==77)
               player.captions();

       remaning=player.get_tries();
         if(remaning==0)
        {
             player.End_Of_Game();
             exit(0);
        }
        key=player.read_key();
        cout<<key;
        switch(key)
        {
            case 72 :                                 // scan code of up key
                    valid= player.up_key();
                    if(valid==1)
                        player.tries_updation();
                    system("cls");
                    player.display_Game();
                    break;
            case 80 :                                 // scan code of down key
                    valid= player.down_key();
                    if(valid==1)
                       player.tries_updation();
                    system("cls");
                    player.display_Game();
                    break;
            case 75 :                                  // scan code of left key
                    valid= player.left_key();
                        if(valid==1)
                            player.tries_updation();
                    system("cls");
                    player.display_Game();
                    break;
            case 77:                                    // scan code of right  key
                    valid = player.right_key();
                        if(valid==1)
                            player.tries_updation();
                    system("cls");
                    player.display_Game();
                    break;
            case 27:                                      // ascii code of 'esc' key
                    exit(0);

        }
    }
}


int main()
{
    int key=0;
    string name;
    int tries=50,valid,remaning;
    system("Color 0A");
    cout<<endl<<endl<<endl<<CIAN<<"\t\t\t\tS H I F T I N G  S A N D S  E N I G M A"<<RESET;
    cout<<GREEN;
    cout<<endl<<endl<<"\t\t\t\t\t50 SWAPS TO GLORY !"<<endl;
     cout<<RESET;                 // THIS IS TO STOP THE EFFECT OF COLOR ON SCREEN
     for(int i=0;i<5;i++)
        cout<<endl;
    cout<<RED<<"\t\t\t\tE N T E R   P L A Y E R   N A M E !"<<RESET<<endl;
    cout<<endl<<endl<<endl<<BLUE"\t\tP L A Y E R   N A M E :  "<<RESET;
    cout<<YELLOW;            // THIS IS TO START THIS COLOR EFFECT ON SCREEN
    getline(cin,name);       // TAKE THE NAME OF PLAYER
    cout<<RESET;
    cout<<endl<<endl;
    flow_of_game(name,tries);
    return 0;
}
