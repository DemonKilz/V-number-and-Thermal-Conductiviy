# include<stdio.h>
# include<stdlib.h>
# include<math.h>
#define PI 3.14159265

int menu1(){
    printf("\n**********************************************************************************************************************************************************");
    printf("\n                                                            NUMERICALS ON OPTICS(MAINLY V-NUMBER)");
    printf("\n**********************************************************************************************************************************************************");
    printf("\nCHOOSE THE REQUIRED OPTION BELOW KNOWING OTHER PARAMETERS");
    printf("\n\n                 1.To Calculate V-Number");
    printf("\n                 2.To Calculate Number of Modes");
    printf("\n                 3.To Quit the Choice");
    printf("\n**********************************************************************************************************************************************************");

    return 0;
}

int menu2(){
    printf("\n**********************************************************************************************************************************************************");
    printf("\n                                                            NUMERICALS ON THERMAL PROPERTIES(MAINLY THERMAL CONDUCTIVITY)");
    printf("\n**********************************************************************************************************************************************************");
    printf("\nCHOOSE THE REQUIRED OPTION BELOW KNOWING OTHER PARAMETERS");
    printf("\n\n                 1.To Calculate Thermal Conductivity");
    printf("\n                 2.To Quit the Choice");
    printf("\n**********************************************************************************************************************************************************");
    return 0;
}

float Vno(float FA){
    int expo1,expo2,prefer;
    float d,num1,num2,lambda,NA,n1,n2;
    printf("\n Note : 1.Before calculating v-no make sure all Parameters are entered in their standard units\n\t2.Refractive index of core > Refractive index of cladding\n");
    printf("\nEnter the integer of Core Diameter of the Optical Fiber(in meters) :");
    scanf("%f", &num1);
    printf("Enter the exponent (10 power ?):");
    scanf("%d", &expo1);
    d = num1*pow(10,expo1);
    printf("Enter the integer of Wavelength of light propagation in the Optical Fiber (in meters) :");
    scanf("%f", &num2);
    printf("Enter the exponent (10 power ?):");
    scanf("%d", &expo2);
    lambda=num2*pow(10,expo2);
    printf("\n1.Numerical aperture is given");
    printf("\n2.Refractive index of both Core and Cladding is given\n");
    printf("\nEnter your preference : ");
    scanf("%d", &prefer);
    if (prefer ==1){
        printf("Enter Numerical Aperture : ");
        scanf("%f", &NA);
        FA= (PI*d*NA)/lambda;
    } 
    else if (prefer ==2){
        printf("Enter the Refractive index of the Core : ");
        scanf("%f", &n1);
        printf("Enter the Refractive index of the Cladding : ");
        scanf("%f", &n2);
        FA= (PI*d*sqrt(n1*n1-n2*n2))/lambda;
    }
    printf("\nThe V-Number for the given problem is found to be: %0.3f\nUnit: Dimensionless\n",FA);
    return FA;
}

int M(){
    int var;
    float vno,Form,FA;
    printf("\n1. IF V-Number is known to Us\n");
    printf("2. IF V-Number is not known to Us \n");
    printf("3. QUIT THE CHOICE\n");
    while (1){
        printf("Enter your choice : ");
        scanf("%d", &var);
        if (var==1){
            printf("\nEnter the V-Number : ");
            scanf("%f", &vno);
            if (vno>2.405){
                Form= (vno*vno)/2.0;
                printf("\nThe Number of supported modes of a step-index fiber for the given problem is found to be: %0.3f\nUnit: Dimensionless\n\n",Form);
            }
            else{
                Form= 1;
                printf("\nThe Number of supported modes of a step-index fiber for the given problem is found to be: %0.3f\nUnit: Dimensionless\n",Form);
            }
        }
        else if (var==2){
            Form=Vno(FA);
            if (Form>2.405){
                Form= (Form*Form)/2;
                printf("\nThe Number of supported modes of a step-index fiber for the given problem is found to be: %0.3f\nUnit: Dimensionless\n\n",Form);
            }
            else{
                FA= 1;
                printf("\nThus The Number of supported modes of a step-index fiber for the given problem is found to be: %0.3f\nUnit: Dimensionless\n",FA);
            }
        }
        else if (var==3)
        break;

        else{
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}

int Thermal()
{
    float K,Q,d,A,T;
    printf("\nEnter The heat absorbed or released(in Joules): ");
    scanf("%f",&Q);
    printf("Enter the Area(in metres square): ");
    scanf("%f",&A);
    printf("Enter the length of the conductor(in metres): ");
    scanf("%f",&d);
    printf("Enter the temperature difference: ");
    scanf("%f",&T);
    K=(Q*d)/(A*T);
    printf("Thermal conductivity K = %0.3f \nUnit: Kg/m/K\n",K);
    return 0;
}

int main(void)
{   
    int ch,opt,c=0;
    while (1)
    {
        printf("\n**********************************************************************************************************************************************************");
        printf("\n                                                            V-Number AND Thermal Conductivity");
        printf("\n**********************************************************************************************************************************************************");
        printf("\n1.Solve QNS on V-Number\n");
        printf("2.Solve QNS on Thermal Conductivity\n");
        printf("3.Quit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        while (1){
            if (ch==1){
                menu1();
                int opt;
                printf("\nEnter your choice: ");
                scanf("%d" , &opt);
                if (opt==1)
                Vno(c);
                else if (opt==2)
                M();
                else if (opt==3)
                break;
                else
                printf("Invalid choice\n");
            }
            else if(ch==2){
                menu2();
                int opt;
                printf("\nEnter your choice: ");
                scanf("%d" , &opt);
                if (opt==1)
                Thermal();
                else if (opt==2)
                break;
                else
                printf("Invalid choice\n");
            }
            else if(ch==3){        
                printf("\n*************************************************************************THANK YOU************************************************************************");
                exit(0);
            }
            else
            printf("Invalid Choice");
        }
    }
    return 0;
}


 


