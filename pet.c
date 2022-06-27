#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
struct Pet {            //a structure, representing the stats of a pet
    int dev_stage;
    int happiness;
    int fullness;
    int age[2];
};


//you can change any stat value of the pet with this function
struct Pet update(struct Pet pet, int param, int value){ // 0 - dev_stage, 1 - happiness, 2 - fullness  
    
    if(param == 1) pet.happiness += value;
    if(param == 2) pet.fullness += value;
    return pet;
}


//feeding the pet
struct Pet feed(struct Pet pet){
    if(pet.fullness < 3) pet.fullness++;
    if(pet.fullness == 3){
        pet.fullness++;
        pet.happiness = 0;
    } 
}


//"creates" a new pet by setting its stats to default
struct Pet renew_stats(struct Pet pet){
    pet.dev_stage = 0;
    pet.happiness = 2;
    pet.fullness  = 3;
    pet.age[0] = 0;
    pet.age[1] = 0;

    return pet;
}

//prints stats
void print_stats(struct Pet pet){
    printf("\n%2d : %2d\n", pet.age[0], pet.age[1]);
    printf("dev_stage - %d\n", pet.dev_stage);
    printf("happiness - %d\n", pet.happiness);
    printf("fullness - %d\n", pet.fullness);
}

int main(){
    
    struct Pet pet; //a random saved pet
    pet.dev_stage = 2;
    pet.happiness = 2;
    pet.fullness  = 1;
    pet.age[0] = 2;
    pet.age[1] = 24;

    int ispet; // testing whether there has been a pet before
    int choise;
    printf("\nIs there a saved pet? 1/0 : ");
    scanf("%d", &ispet);
    if(ispet){
        printf("\nContinue or New? 1/0 : "); 
        scanf("%d", &choise);
        if(!choise){
            pet = renew_stats(pet);
        }
    }else{
        pet = renew_stats(pet);
    }
    
    print_stats(pet);

    int seconds = pet.age[0] * 60 + pet.age[1]; //total seconds = minutes * 60 + seconds
    while(1){
        
        system("clear"); //clears the screen
        seconds++; //adds a second
        pet.age[0] = seconds / 60; //writes down the amount of seconds, minutes
        pet.age[1] = seconds % 60; 
        
        if(seconds % 7 == 0){ 
            if(pet.happiness > 0) pet.happiness--;
        }
            
        if(seconds % 11 == 0){
            if(pet.fullness > 0) pet.fullness--;
        }
            
        if(!pet.fullness) pet.happiness = 0;

        if(seconds > 5) pet.dev_stage = 1;
        if(seconds > 35) pet.dev_stage = 2;

        

        print_stats(pet);
        sleep(1);
    }
    
    return 0;
}
