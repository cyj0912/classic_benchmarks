/*     gcc dhry1.c cpuidc64.o cpuida64.o -m64 -lrt -lc -lm -o dhry1
 *
 *      "DHRYSTONE" Benchmark Program for PCs
 *      #define Version not used
 */
 // VERSION
               
 #ifdef CNNT
    #define options   "Non-optimised"
 #else
//    #define options   "Optimised"
    #define options   "Opt 3 64 Bit"
 #endif

#define structassign(d, s)      d = s

typedef enum    {Ident1, Ident2, Ident3, Ident4, Ident5} Enumeration;

typedef int     OneToThirty;
typedef int     OneToFifty;
typedef char    CapitalLetter;
typedef char    String30[31];
typedef int     Array1Dim[51];
typedef unsigned long     Array2Dim[51][51];

struct  Record
{
        struct Record           *PtrComp;
        Enumeration             Discr;
        Enumeration             EnumComp;
        OneToFifty              IntComp;
        String30                StringComp;
};

typedef struct Record   RecordType;
typedef RecordType *    RecordPtr;
typedef int             booleans;

/* #define      NULL            0 */
#define TRUE            1
#define FALSE           0


void Proc0();
void Proc1(RecordPtr PtrParIn);
void Proc2(OneToFifty *IntParIO);
void Proc3(RecordPtr *PtrParOut);
void Proc4();
void Proc5();
void Proc6(Enumeration EnumParIn, Enumeration *EnumParOut);
void Proc7(OneToFifty IntParI1, OneToFifty IntParI2, OneToFifty *IntParOut);
void Proc8(Array1Dim Array1Par, Array2Dim Array2Par, OneToFifty IntParI1,
                                                OneToFifty IntParI2);
extern Enumeration  Func1(CapitalLetter CharPar1, CapitalLetter CharPar2);
extern booleans      Func2(String30 StrParI1, String30 StrParI2);
booleans Func3(Enumeration EnumParIn);


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include "cpuidh.h"

 
/*
 * Package 1
 */
int             IntGlob;
booleans         BoolGlob;
char            Char1Glob;
char            Char2Glob;
Array1Dim       Array1Glob;
Array2Dim       Array2Glob;
RecordPtr       PtrGlb;
RecordPtr       PtrGlbNext;



main(int argc, char *argv[])
{
    int nopause = 1;

    if (argc > 1)
     {
        switch (argv[1][0])
         {
             case 'N':
                nopause = 0;
                break;
             case 'n':
                nopause = 0;
                break;
         }
      }
 
    Proc0();
    if (nopause)
    {
       printf(" Press Enter\n\n");
       int g = getchar();
    }
    exit(0);
}

void Proc0()
{
    OneToFifty              IntLoc1;
    OneToFifty              IntLoc2;
    OneToFifty              IntLoc3;
    char                    CharIndex;
    Enumeration             EnumLoc;
    String30                String1Loc;
    String30                String2Loc;
    unsigned long         Loops;
    
    double                  Microseconds,
                            Dhrystones_Per_Second,
                            Vax_Mips;
                      
    double                  benchtime;
        
    register unsigned long  i;

    int         endit;
    unsigned long count = 10;
    FILE        *Ap;

     /* Initializations */
 
    if ((Ap = fopen("Dhry.txt","a+")) == NULL)
     {
        printf("Can not open Dhry.txt\n\n");
        printf(" Press Enter\n\n");
        i = getchar();
        exit(1);
     }
     
/***********************************************************************
 *         Change for compiler and optimisation used                   *
 ***********************************************************************/
       
    PtrGlbNext = (RecordPtr) malloc(sizeof(RecordType));
    PtrGlb = (RecordPtr) malloc(sizeof(RecordType));
    PtrGlb->PtrComp = PtrGlbNext;
    PtrGlb->Discr = Ident1;
    PtrGlb->EnumComp = Ident3;
    PtrGlb->IntComp = 40;
    strcpy(PtrGlb->StringComp, "DHRYSTONE PROGRAM, SOME STRING");
    strcpy(String1Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

    getDetails();
    for (i=1; i<10; i++)
    {
        printf("%s\n", configdata[i]);
    }
    printf("\n");

    fprintf (Ap, " #####################################################\n\n");                     
    for (i=1; i<10; i++)
    {
        fprintf(Ap, "%s \n", configdata[i]);
    }
    fprintf (Ap, "\n");
 
    printf("##########################################\n"); 

    printf ("\n");
    printf ("Dhrystone Benchmark, Version 1.1 (Language: C or C++)\n");
    printf ("\n");

    printf ("Optimisation    %s\n", options);
    printf ("\n");
    
    Loops = 5000;

   do
   {

       Loops = Loops * 2;
       count = count - 1;
       Array2Glob[8][7] = 10;

        start_time();        
        for (i = 0; i < Loops; ++i)
        {
                Proc5();
                Proc4();
                IntLoc1 = 2;
                IntLoc2 = 3;
                strcpy(String2Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
                EnumLoc = Ident2;
                BoolGlob = ! Func2(String1Loc, String2Loc);
                while (IntLoc1 < IntLoc2)
                {
                        IntLoc3 = 5 * IntLoc1 - IntLoc2;
                        Proc7(IntLoc1, IntLoc2, &IntLoc3);
                        ++IntLoc1;
                }
                Proc8(Array1Glob, Array2Glob, IntLoc1, IntLoc3);
                Proc1(PtrGlb);
                for (CharIndex = 'A'; CharIndex <= Char2Glob; ++CharIndex)
                        if (EnumLoc == Func1(CharIndex, 'C'))
                                Proc6(Ident1, &EnumLoc);
                IntLoc3 = IntLoc2 * IntLoc1;
                IntLoc2 = IntLoc3 / IntLoc1;
                IntLoc2 = 7 * (IntLoc3 - IntLoc2) - IntLoc1;
                Proc2(&IntLoc1);
        }
        end_time();
        benchtime = secs;
        
        printf ("%12.0f runs %6.2f seconds \n",(double) Loops, benchtime);
        if (benchtime > 2)
        {
              count = 0;
        }
        else
        {
              if (benchtime < 0.05)
              {
                   Loops = Loops * 5;
              }
        }
   }   /* calibrate/run do while */
   while (count >0);
   
   for (i = 0; i < Loops; ++i)
        {
           count = count +1;
        }
        
    printf ("\n");
  
    printf ("Array2Glob8/7: ");
    if (Array2Glob[8][7] == count + 10)
                           printf ("O.K.  ");
    else                   printf ("WRONG ");
    printf ("%12.0f\n", (double) Array2Glob[8][7]);
       
    Microseconds = benchtime * 1000000 / (double) Loops;
    Dhrystones_Per_Second = (double) Loops / benchtime;
    Vax_Mips = Dhrystones_Per_Second / 1757.0;
    
    printf ("\n"); 
    printf ("Microseconds for one run through Dhrystone: ");
    printf ("%12.2lf \n", Microseconds);
    printf ("Dhrystones per Second:                      ");
    printf ("%10.0lf \n", Dhrystones_Per_Second);
    printf ("VAX  MIPS rating =                          ");
    printf ("%12.2lf \n",Vax_Mips);
    printf ("\n");

    
/************************************************************************
 *                Add results to output file Dhry.txt                   *
 ************************************************************************/
    local_time();


    fprintf (Ap, " #####################################################\n\n");                     

    fprintf (Ap, " Dhrystone Benchmark  1.1 %s via C/C++ %s\n", options, timeday);
    fprintf (Ap, " VAX MIPS rating:      %12.2lf\n\n",Vax_Mips);
   
   
   if (Array2Glob[8][7] == Loops + 10) fprintf (Ap, " Correct result\n\n");
   else                                fprintf (Ap, " WRONG result\n\n");

   fclose(Ap);    
}

void Proc1(RecordPtr PtrParIn)
{
#define NextRecord      (*(PtrParIn->PtrComp))

        structassign(NextRecord, *PtrGlb);
        PtrParIn->IntComp = 5;
        NextRecord.IntComp = PtrParIn->IntComp;
        NextRecord.PtrComp = PtrParIn->PtrComp;
        Proc3(&NextRecord.PtrComp);
        if (NextRecord.Discr == Ident1)
        {
                NextRecord.IntComp = 6;
                Proc6(PtrParIn->EnumComp, &NextRecord.EnumComp);
                NextRecord.PtrComp = PtrGlb->PtrComp;
                Proc7(NextRecord.IntComp, 10, &NextRecord.IntComp);
        }
        else
                structassign(*PtrParIn, NextRecord);

#undef  NextRecord
}

void Proc2(OneToFifty *IntParIO)
{
        OneToFifty              IntLoc;
        Enumeration             EnumLoc;

        IntLoc = *IntParIO + 10;
        for(;;)
        {
                if (Char1Glob == 'A')
                {
                        --IntLoc;
                        *IntParIO = IntLoc - IntGlob;
                        EnumLoc = Ident1;
                }
                if (EnumLoc == Ident1)
                        break;
        }
}

void Proc3(RecordPtr *PtrParOut)
{
        if (PtrGlb != NULL)
                *PtrParOut = PtrGlb->PtrComp;
        else
                IntGlob = 100;
        Proc7(10, IntGlob, &PtrGlb->IntComp);
}

void Proc4()
{
        booleans BoolLoc;

        BoolLoc = Char1Glob == 'A';
        BoolLoc |= BoolGlob;
        Char2Glob = 'B';
}

void Proc5()
{
        Char1Glob = 'A';
        BoolGlob = FALSE;
}

extern booleans Func3();

void Proc6(Enumeration EnumParIn, Enumeration *EnumParOut)
{
        *EnumParOut = EnumParIn;
        if (! Func3(EnumParIn) )
                *EnumParOut = Ident4;
        switch (EnumParIn)
        {
        case Ident1:    *EnumParOut = Ident1; break;
        case Ident2:    if (IntGlob > 100) *EnumParOut = Ident1;
                        else *EnumParOut = Ident4;
                        break;
        case Ident3:    *EnumParOut = Ident2; break;
        case Ident4:    break;
        case Ident5:    *EnumParOut = Ident3;
        }
}

void Proc7(OneToFifty IntParI1, OneToFifty IntParI2, OneToFifty *IntParOut)
{
        OneToFifty      IntLoc;

        IntLoc = IntParI1 + 2;
        *IntParOut = IntParI2 + IntLoc;
}

void Proc8(Array1Dim Array1Par, Array2Dim Array2Par, OneToFifty IntParI1,
                                                OneToFifty IntParI2)
{
        OneToFifty      IntLoc;
        OneToFifty      IntIndex;

        IntLoc = IntParI1 + 5;
        Array1Par[IntLoc] = IntParI2;
        Array1Par[IntLoc+1] = Array1Par[IntLoc];
        Array1Par[IntLoc+30] = IntLoc;
        for (IntIndex = IntLoc; IntIndex <= (IntLoc+1); ++IntIndex)
                Array2Par[IntLoc][IntIndex] = IntLoc;
        ++Array2Par[IntLoc][IntLoc-1];
        Array2Par[IntLoc+20][IntLoc] = Array1Par[IntLoc];
        IntGlob = 5;
}

Enumeration Func1(CapitalLetter CharPar1, CapitalLetter CharPar2)
{
        CapitalLetter   CharLoc1;
        CapitalLetter   CharLoc2;

        CharLoc1 = CharPar1;
        CharLoc2 = CharLoc1;
        if (CharLoc2 != CharPar2)
                return (Ident1);
        else
                return (Ident2);
}

booleans Func2(String30 StrParI1, String30 StrParI2)
{
        OneToThirty             IntLoc;
        CapitalLetter           CharLoc;

        IntLoc = 1;
        while (IntLoc <= 1)
                if (Func1(StrParI1[IntLoc], StrParI2[IntLoc+1]) == Ident1)
                {
                        CharLoc = 'A';
                        ++IntLoc;
                }
        if (CharLoc >= 'W' && CharLoc <= 'Z')
                IntLoc = 7;
        if (CharLoc == 'X')
                return(TRUE);
        else
        {
                if (strcmp(StrParI1, StrParI2) > 0)
                {
                        IntLoc += 7;
                        return (TRUE);
                }
                else
                        return (FALSE);
        }
}

booleans Func3(Enumeration EnumParIn)
{
        Enumeration     EnumLoc;

        EnumLoc = EnumParIn;
        if (EnumLoc == Ident3) return (TRUE);
        return (FALSE);
}



