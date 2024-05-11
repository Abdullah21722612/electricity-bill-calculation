#include <stdio.h>
#include <stdlib.h>

#define MAX_Input 1000

struct electrycity
{
    char name[50];
    int quantity;
    float Watt;
    float time;
    int day;
    int amount, kw, n;
};

void recharge_bill(struct electrycity e1);
void home(struct electrycity e1);
void Business(struct electrycity e1);
void bill_calculation(struct electrycity e1);
void covert();

int main()
{
    struct electrycity e1;

    int choice;

    do
    {
        printf("\n\n\t\t\t1. Recharge bill calculation:\n\n");
        printf("\t\t\t2. Device bill calculation \n\n");
        printf("\t\t\t3. covert to watt , amper, volat: \n\n");
        printf("\t\t\t4. Exit\n\n");
        printf("\t\t\tEnter a number: ");
        scanf("%d", &choice);
        system("clear");
        switch (choice)
        {
        case 1:
            recharge_bill(e1);
            break;
        case 2:
            bill_calculation(e1);
            break;

        case 3:
            covert();
            break;
        case 4:
            system("clear");
            printf("Exiting...\nThank you! Come again.\n");
            break;
        default:
            printf("\n\n\nInvalid choice. Please enter a number between 1 and 4.\n\n");
            break;
        }
    } while (choice != 4);
    return 0;
}

void bill_calculation(struct electrycity e1)
{
    char addMore = 'y';
    while (addMore == 'y')
    {
        printf("\n\t\t\tDevice name: ");
        scanf("%s", e1.name);

        printf("\n\t\t\tnumber of device: ");
        scanf("%d", &e1.quantity);

        printf("\n\t\t\tPower consumption (Watt): ");
        scanf("%f", &e1.Watt);

        printf("\n\t\t\tHours of use per day: ");
        scanf("%f", &e1.time);

        printf("\n\t\t\tNumber of Day: ");
        scanf("%d", &e1.day);

        float Energy_Used = (e1.Watt * e1.time * e1.day * e1.quantity) / 1000;
        float cal = Energy_Used * 7;

        printf("\n\n\nDevice (%s): Estimated bill = %.2f tk.\n", e1.name, cal);

        printf("\nDo you want to calculate for another device? (y/n): ");
        scanf(" %c", &addMore);
    }
}

void covert()
{
    float A, w, v, res = 1;
    int n;
    do
    {
        printf("\n\n\t\t\t1. input watt to volt: \n\n");
        printf("\t\t\t2. amper to watt: \n\n");
        printf("\t\t\t3. watt to volt: \n\n");
        printf("\t\t\t4. Exit\n\n");
        printf("\t\t\tEnter a number: ");
        scanf("%d", &n);
        system("clear");

        switch (n)
        {
        case 1:
        {
            printf("\t\t\tConvert watt to amper: ");
            printf("\n\n\t\t\tEnter watt: ");
            scanf("%f", &w);
            printf("\n\t\t\tEnter volt: ");
            scanf("%f", &v);

            A = w / v;
            printf("\n\n%0.2f watt to amper: %0.2f\n", w, A);

            break;
        }
        case 2:
        {
            printf("\t\t\tamper to watt: ");
            printf("\n\n\t\t\tEnter amper:");
            scanf("%f", &A);
            printf("\n\t\t\tEnter volt: ");
            scanf("%f", &v);

            w = A * v;
            printf("\n\n%0.2f watt to amper: %0.2f\n", A, w);

            break;
        }
        case 3:
        {
            system("clear");
            printf("\t\t\twatt to volt: ");
            printf("\n\n\t\t\tEnter watt: ");
            scanf("%f", &w);
            printf("\n\t\t\tEnter amper: ");
            scanf("%f", &A);

            v = w / A;
            printf("\n\n%0.2f watt to volt: %0.2f\n", w, v);

            break;
        }
        case 4:
            system("clear");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            break;
        }

    } while (n != 4);
}

void home(struct electrycity e1)
{
    float meter_rent = 40, demand_charge, vat, rebate, calculation = 0;

    printf("\n\nAmount: ");
    scanf("%d", &e1.amount);

    printf("\n\nhow much time recharge in this month: ");
    scanf("%d", &e1.n);

    vat = e1.amount * (5.0 / 105.0);
    rebate = e1.amount * (0.5 / 101);

    if (e1.n == 0)
    {
        printf("\n\nkilowatt: ");
        scanf("%d", &e1.kw);
        demand_charge = e1.kw * 42;
        printf("Meter rent = 40");
        printf("\n\ndemand charge: %0.2f\n\n", demand_charge);
        calculation = e1.amount - meter_rent - demand_charge - vat + rebate;
        printf("\n\nEnergy Cost: %0.2f\n\n\n", calculation);
    }
    else
    {
        demand_charge = e1.kw * 42;
        printf("\n\ndemand charge: %0.2f\n\n", demand_charge * 0);
        printf("\n\nMeter rent = 0");
        calculation = e1.amount - vat + rebate;
        printf("Energy Cost: %0.2f\n\n\n", calculation);
    }
    printf("revat: %0.2f\n\n", vat);
    printf("revat: -%0.2f\n\n", rebate);
}

void Business(struct electrycity e1)
{
    float meter_rent = 250, energy, vat, rebate, demand_charge, calculation = 0;

    printf("\n\nAmount: ");
    scanf("%d", &e1.amount);

    printf("\n\nhow much time recharge in this month: ");
    scanf("%d", &e1.n);

    vat = e1.amount * (5.0 / 105);

    rebate = e1.amount * (0.5 / 101);

    if (e1.n == 0)
    {
        printf("\n\nkilowatt: ");
        scanf("%d", &e1.kw);
        demand_charge = e1.kw * 48;
        printf("demand charge: %0.2f\n\n", demand_charge);
        printf("Meter rent = 250");
        calculation = e1.amount - meter_rent - demand_charge - vat + rebate;
        printf("\n\nEnergy Cost: %0.2f\n\n\n", calculation);
    }
    else
    {
        printf("Meter rent = 0");
        printf("demand charge: %0.2f\n\n", demand_charge * 0);
        calculation = e1.amount - vat + rebate;
        printf("Energy Cost: %0.2f\n\n\n", calculation);
    }
    energy = calculation / 10.76;
    printf("Energy: %0.2fKwh\n\n", energy);
    printf("vat: %0.2f\n\n", vat);
    printf("revat: -%0.2f\n\n", rebate);
}

void recharge_bill(struct electrycity e1)
{
    int choice;
    char addMore = 'y';
    do
    {

        printf("\n\n\t\t\t1. Home bill \n\n");
        printf("\t\t\t2. Business \n\n");
        printf("\t\t\t3. Exit \n\n");
        printf("\t\t\tEnter a number: ");
        scanf("%d", &choice);

        system("clear");
        switch (choice)
        {

        case 1:
            home(e1);
            break;
        case 2:
            Business(e1);
            break;

        case 3:
            system("clear");
            break;

            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
            break;
        }
    } while (choice != 3);
}