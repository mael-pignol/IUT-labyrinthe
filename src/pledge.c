#include <stdio.h>
#include <unistd.h>
#include "labyrinthes.h"

int main(int argc, char* argv[]) {

  // Variables for starting position
  int startX = 0;
  int startY = 0;

  // Variables for goal
  int arrivalX = 8;
  int arrivalY = 8;

  // Load the labyrinth and set the starting and goal positions
  load_lab("/labyrinthe/lab/lab.fodaly");
  set_start(startX, startY);
  set_arrival(arrivalX, arrivalY);

  set_display_mode(1);
  exists_solution();
  // Display the lab
  display_lab();


  // Variables de position
  int x = startX;
  int y = startY;

  // Variable de direction: est (1), sud (2), ouest (3)
  int orientation = 0;

  int t = 0;

  int h = 0;



    if(exists_solution() == 0 ){
      printf("NOSOLUCE");
      submit("pignol", "IP", 0);
      getchar();
      close_lab();
        return 0;
  }
  // On se dirige vers le nord tant que possible
 while(!(x == arrivalX && y == arrivalY)){

   if(t == 0 && orientation == 0){
     if((is_valid_move(x,y))){
        move(x,y-1);
        y = y -1;
        display_lab();
        sleep(1);
     }

     else{
        orientation =1;
        t++;
     }

   }

   else{
    int nextX;
    int nextY;
    int leftX;
    int leftY;
    int moved = 0;
  switch(orientation){

    case(0):
      leftX = x-1;
      leftY = y;
      nextX = x;
      nextY = y-1;
      break;
    case(1):
      leftX = x;
      leftY = y-1;
      nextX = x+1;
      nextY = y;
      break;
    case(2):
      leftX = x+1;
      leftY = y;
      nextX = x;
      nextY = y+1;
      break;
    case(3):
      leftX = x;
      leftY = y+1;
      nextX = x-1;
      nextY = y;
      break;
    default :
      leftX = x;
      leftY = y+1;
      nextX = x-1;
      nextY = y;
  }



  if(is_valid_move(leftX,leftY)){
    move(leftX,leftY);
    x = leftX;
    y = leftY;
    orientation = (orientation -1 +4)%4;
    moved = 1;
    t--;
  } else if (is_valid_move(nextX,nextY)){
    move(nextX,nextY);
    x = nextX;
    y = nextY;
    moved = 1;
    }
   else {
     orientation = (orientation +1)%4;
     t++;
}

  // RETIRER LES COMMENTAIRES EN CAS DE PROBLEME
/*
printf("x= %d \n",x);
printf("y= %d \n",y);
printf("nextX= %d \n",nextX);
printf("nextY= %d \n",nextY);
printf("leftX= %d \n",leftX);
printf("leftY= %d \n",leftY);
printf("orientation= %d \n",orientation);
printf("moved= %d \n",moved);
printf("t= %d \n",t);
*/

   if(moved){
     h++;
     display_lab();
     int c = 1, d = 1;
      for ( c = 1 ; c <= 3 ; c++ )
            for ( d = 1 ; d <= 3 ; d++ )
               {}
   }
   if(h > 200){
     close_lab();
      printf("PAS DE RESULAT : ON PASSE AU RANDOM");

   }
}
   }






  // Wait until enter is pressed
  submit("pignol", "IP", 1);
  getchar();
  close_lab();
  return 0;

}
