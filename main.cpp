#include "linkedlist.cpp"


int main()
{
  LinkedList<Player>tm;
  int choice=1, pos;
   
  cout<<"\n-------------------  Player Management System  ------------------- ";
  do
  {
    cout<<"\n\t1.Display Data";
    cout<<"\n\t2.Store Data";
    cout<<"\n\t3.Search Player by Jersey Number";
    cout<<"\n\t4.Search Player by Player Name";
    cout<<"\n\t5.Update Details";
    cout<<"\n\t6.Delete Player";
    cout<<"\n\t7.Sort Data";
    cout<<"\n\t10.Exit";
    cout<<"\n---------------------------------------------------------------\n ";
    cout<<"\n\n\tEnter your Choice: ";
    cin>>choice;
    
    switch(choice)
    {
      case 1:
        {
          tm.displayPlayer();
        }
        break;
        
      case 2:
        {
          int jerseyNumber;
          char playerName[50]; 
          int runs, wickets,matchesPlayed;
          
          cout<<"\nEnter Jersey Number: ";
          cin>>jerseyNumber;
          cin.ignore();
          fflush(stdin);
          cout<<"\nEnter Player Name:";
          cin.getline(playerName, 50);
          
         // fflush(stdin);
          cout<<"\nEnter Runs:";
          cin>>runs;
          
          //fflush(stdin);
          cout<<"\nEnter Wickets:";
          cin>>wickets;
          
          cout<<"\nEnter Matches Played:";
          cin>>matchesPlayed;
          
          Player p1(jerseyNumber, playerName,matchesPlayed,runs, wickets);
          
          cout<<"\nEnter Which position do you want to insert Player: ";
          cin>>pos;
          
          tm.storeData(p1, pos);
          
          cout<<"\nInserted Player Details At Given Position Succesfully!!!\n";
        }
        break;
        
      case 3:
        {
          int jno;
          cout<<"\nEnter Jersey Number: ";
          cin>>jno;
          tm.searchByJerseyNumber(jno);
        }
        break;
        
      case 4:
        {
          char playerName[50];
          cout<<"\nEnter Player Name: ";
          cin>>playerName;
          tm.searchByPlayerName(playerName);
        }
        break;
        
        
      case 5:
        {
          int jno;
          cout<<"\nEnter Jersey Number to update: ";
          cin>>jno;
          tm.updateDetails(jno);
        }
        break;
        
      case 6:
        {
          int jno;
          cout<<"\nEnter Jersey Number: ";
          cin>>jno;
          tm.deletePlayer(jno);
          cout<<"\nJersey Number deleted successfully";
        }
        break;
        
      case 7:
        tm.sortData();
        break;
        
      case 10:
        cout<<"\n\nThank You!!\n";
        break;
      
      default:
        cout<<"\n\tInvalid Choice.\n";
    }
  }while(choice != 10);
  return 0;
}