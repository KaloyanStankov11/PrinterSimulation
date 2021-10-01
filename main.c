#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double Cyan=200, Magenta=200, Yellow=200, Black=200, UsedCyan, UsedMagenta, UsedYellow, UsedBlack, Used;
double Intensity;
int PaperType, Color, Content, Pages;
char command[7];

void REFILL(){
    Cyan=200; Magenta=200; Yellow=200; Black=200;
}

void Print(){

    if(PaperType==1){
        if(Content==0){
            if(Intensity<100)
                Used=Pages*(1-((double)1/10)-((double)(100-Intensity)/100));
            else if(Intensity>100)
                Used=Pages*(1-((double)1/10)+(((double)(Intensity-100)/100)));
            else if(Intensity==100)
                Used=Pages*(1-((double)1/10));
        }
        else if(Content==1){
            if(Intensity<100)
                Used=Pages*(1.35-((double)1/10)*1.35-(((double)((100-Intensity)/100)*1.35)));
            else if(Intensity>100)
                Used=Pages*(1.35-((double)1/10)*1.35+((((double)(Intensity-100)/100))*1.35));
            else if((Intensity==100))
                Used=Pages*(1.35-((double)1/10)*1.35);
        }
    }
    else if(PaperType==2){
        if(Content==0){
            if(Intensity<100)
                Used=Pages*(1-((double)(100-Intensity)/100));
            else if(Intensity>100)
                Used=Pages*(1+(((double)(Intensity-100)/100)));
            else if(Intensity==100)
                Used=Pages;
        }
        else if(Content==1){
            if(Intensity<100)
                Used=Pages*(1.35-(((double)(100-Intensity)/100)*1.35));
            else if(Intensity>100)
                Used=Pages*(1.35+((((double)(Intensity-100)/100))*1.35));
            else if((Intensity==100))
                Used=(double)Pages*1.35;
        }
    }
    else if(PaperType==3){
        if(Content==0){
            if(Intensity<100)
                Used=Pages*(1+((double)15/100)-((double)(100-Intensity)/100));
            else if(Intensity>100)
                Used=Pages*(1+((double)15/100)+(((double)(Intensity-100)/100)));
            else if(Intensity==100)
                Used=Pages*(1+((double)15/100));
        }
        else if(Content==1){
            if(Intensity<100)
                Used=Pages*(1.35+((double)15/100)*1.35-(((double)(100-Intensity)/100)*1.35));
            else if(Intensity>100)
                Used=Pages*(1.35+((double)15/100)*1.35+((((double)(Intensity-100)/100))*1.35));
            else if((Intensity==100))
                Used=Pages*(1.35+((double)15/100)*1.35);
        }
    }
}

int main()
{
    double CyanPercentage, MagentaPercentage, YellowPercentage, BlackPercentage;
    printf("Choose a command: ");
    scanf("%s", command);
    do{
    if(!strcmp(command, "PRINT")){
        printf("Color options (0 for Black, 1 for Full Color) ");
        scanf("%d", &Color);

        if(Color==1){
            printf("Enter colors percentage (Enter 0, if you don`t want to use the color)\n");
            printf("Cyan: "); scanf("%lf", &CyanPercentage);
            printf("Magenta: "); scanf("%lf", &MagentaPercentage);
            printf("Yellow: "); scanf("%lf", &YellowPercentage);
            printf("Black: "); scanf("%lf", &BlackPercentage);
        }

        printf("Enter the number of pages ");
        scanf("%d", &Pages);

        printf("Enter 0 if you print text only or 1 if you print text and pics: ");
        scanf("%d", &Content);

        printf("Choose what type of paper you want to use (1 for smooth, 2 for ordinary, 3 for rough): ");
        scanf("%d", &PaperType);

        printf("Enter the intensity in percentage: ");
        scanf("%lf", &Intensity);

        Print();
        if(Color==0){
            UsedBlack=Used;
            if(UsedBlack>Black){
                printf("ERROR Cartage need replacement ");
                scanf("%s", command);
                if(!(strcmp(command, "REFILL"))){
                    REFILL();
                    Black-=UsedBlack; printf("PAGE PRINTED \n");
                }
            }
            else{
                Black-=UsedBlack; printf("PAGE PRINTED \n");
            }
        }
        else if(Color==1){
            UsedCyan=Used*(CyanPercentage/100);
            UsedMagenta=Used*(MagentaPercentage/100);
            UsedYellow=Used*(YellowPercentage/100);
            UsedBlack=Used*(BlackPercentage/100);

            if((UsedCyan>Cyan)||(UsedMagenta>Magenta)||(UsedYellow>Yellow)||(UsedBlack>Black)){
                printf("ERROR Cartage need replacement ");
                scanf("%s", command);
                if(!(strcmp(command, "REFILL"))){
                    REFILL();
                    Cyan-=UsedCyan; Magenta-=UsedMagenta; Yellow-=UsedYellow; Black-=UsedBlack; printf("PAGE PRINTED \n");
                }
            }
            else{
                Cyan-=UsedCyan; Magenta-=UsedMagenta; Yellow-=UsedYellow; Black-=UsedBlack; printf("PAGE PRINTED \n");
            }
        }
    }
    printf("Choose a command: "); scanf("%s", command); system("cls");
    }while(strcmp(command, "EXIT")!=0);
    return 0;
}

