#include <stdio.h>
int main()
{
double Type1Cost, Type2Cost;
int Type1Amount, Type2Amount,Type1Volume, Type2Volume, TotalVolume, RemainingVolume;
int Length, Width, Height, Volume;
int Type2Available;

Length = 40;
Width = 8;
Height = 8;
//Volume of The Shipping Container
Volume = (Length * Width * Height);

//Volumes of Type1 and Type2 + Costs per type
Type1Volume = 1;
Type2Volume = 4;
Type1Cost = 20.00;
Type2Cost = 35.00;

//Asks how many boxes of which types. Informs you of how many you chose.
printf("Please enter an amount of Type1 Boxes ");
scanf("%i",&Type1Amount);
printf("You entered an amount of %d Type1 Boxes " , Type1Amount);

//Calculate Space Remaining for type2Boxes. 
RemainingVolume = Volume - (Type1Amount * Type1Volume);
Type2Available = RemainingVolume/Type2Volume;
printf("\nYou can have an amount of %d Type2 Boxes with the space available " , Type2Available);

//Asks for Type2 Amount input and returns entered. 
printf("\nPlease enter an amount of Type2 Boxes ");
scanf("%i",&Type2Amount);
printf("You entered an amount of %d Type2 Boxes " , Type2Amount);

//Inform of  the number of cubic feet in a shipping container. 
printf("\nThe volume of the Shipping Container is %d Feet" , Volume);

//Calculate the total cubic footage for the boxes they want to ship
TotalVolume = (Type1Volume * Type1Amount) + (Type2Volume * Type2Amount);
printf("\nThe volume of the all boxes in total is %d Feet" , TotalVolume);

//If the Cubic footage is greater than the available space, inform the user. 




}
