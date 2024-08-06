#include <ctime>
#include <iostream>
using namespace std;



class Player{

  public:
  int health = 100;

  int minDamage = 20;
  int maxDamage = 30;

  int minHealing = 30;
  int maxHealing = 50;

  Player(){

    cout<<"Hi my name is Letho! We need to save princess Barbara and get her back"<<endl;
    cout<<"Here are some stats that might be useful for you going ahead"<<endl<<endl;

    cout<<"Letho's health is: "<<health<<endl;
    cout<<"_____________________________"<<endl<<endl;
    cout<<"Letho's attack range is between: "<<minDamage<<"-"<<maxDamage<<"."<<endl;
    cout<<"_____________________________"<<endl<<endl;
    cout<<"Letho's healing range is between: "<<minHealing<<"-"<<maxHealing<<endl;
    cout<<"_____________________________"<<endl<<endl<<endl;
  }

  int GetHealth(){

    return health;
  }

  void TakeDamage(int damage){

      cout<<"Ohh no, the enemy is attacking you, you have taken "<<damage<<" damage"<<endl;

      health = health - damage;

    if(health <=0){
      cout<<"Enemy died, Our hero Letho is the winner"<<endl;
    }
    else{
      cout<<"Letho's current health after taking damage is: "<<health<<endl<<endl<<endl;

      cout <<"_________________________"<<endl<<endl;
    }

  }

  int GiveDamage(){

    srand(time(0));
    int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);


    return randomDamage;
  }

  void heal(){
    srand(time(0));
    int randomHealing = (rand() % (maxHealing - minHealing + 1) + minHealing);

    health = health + randomHealing;

    cout<<"Letho healed himself with "<<randomHealing<<" health"<<endl;

    cout <<"After healing, Letho's health is: "<<health<<endl<<endl<<endl;;

    cout<<"______________________"<<endl<<endl;

  }






};

class Enemy{

private:
int health = 100;

int minDamage = 15;
int maxDamage = 25;


public:
Enemy(){
  cout<<"Enemy said"<<endl;
  cout<<"Do you have an idea who i am, I am the God of the darkness"<<endl;

  cout<<"I am the one who kidnapped Barbara and now I am Going to kill you and destroy  the entire kingdom. Ha Ha Ha"<<endl;

  cout<<"Bring it on"<<endl<<endl<<endl;

  cout<<"_____________________"<<endl<<endl;
}

int GetHealth(){

  return health;
}

void TakeDamage(int damage){


   cout<<"Yeah come on Letho you can do it"<<endl;
   cout<<"Letho is attacking enemy, Enemy have taken "<<damage<<" damage"<<endl;


    health = health - damage;


  if(health <=0){
    cout<<"Enemy died, Our hero Letho is the winner"<<endl;
  }
  else{
    cout<<"Enemy's current health after taking damage is: "<<health<<endl<<endl<<endl;

    cout<<"_____________________"<<endl<<endl;
  }


}

int GiveDamage(){

  srand(time(0));
  int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);


  return randomDamage;
}


};

void GameStory(){

  cout << "\n__________________________\n";
  cout << "\n| Letho: A True Hero |";
  cout << "\n__________________________\n";
  cout << "\nOnce upon a time, there was a kingdom full of happiness. The king named Garelt had a beautiful princess named Barbara. "<<endl;
  cout << "\n__________________________\n";
  cout << "\nUnfortunately, on one evil day, the Hollow Knight kidnapped Barbara.\nNow the entire kingdom is at stake. Hollow Knight is a ruler of the dark world.\nMany brave knights had attempted to free Barbara, but none prevailed.\nNow as the Hollow Knight, it's up to you to stop him and save the princess."<<endl;
  cout << "\n__________________________\n";
}

void BattleLoop(Player player, Enemy enemy){


  do{
    char playerInput;
    cout << "Press A to attack or H to heal" << endl;
    cin >> playerInput;

    if(playerInput == 'A' || playerInput == 'a'){

      enemy.TakeDamage(player.GiveDamage());
      if(enemy.GetHealth() > 0){

        cout << "Ha ha ha, you fool now its my turn." << endl;

        player.TakeDamage(enemy.GiveDamage());
      }

    }
    else if (playerInput == 'H' || playerInput == 'h'){
      player.heal();

      if(enemy.GetHealth() > 0){

        cout << "Ha ha ha, you fool now its my turn." << endl;

        player.TakeDamage(enemy.GiveDamage());
      }

    }
    else{
      cout<<"Invalid Input";
    }


  }while(player.GetHealth() >0 && enemy.GetHealth() > 0);

}

int main() {
  GameStory();
  char input;
  do{
    cout<<"Press S to start the game or any other key to exit!"<<endl;
    cin >> input;

    if(input == 'S' || input == 's'){

      Player playerOBJ;
      Enemy enemyOBJ;
      BattleLoop(playerOBJ,enemyOBJ);
    }
    else{
      cout<<"Thanks for playing the game, see you soon!"<<endl;
    }

  }while(input == 'S' || input == 's');


}



