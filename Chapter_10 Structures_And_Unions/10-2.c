#include <stdio.h>

#define  NAMELENGTH    21
#define  ADDRLENGTH    41
#define  MODLLENGTH    21
#define  NAMEOFBANKLEN 21

typedef struct
{
    float ManufactureerSuggestedRetailPrice;
    float ActualSellingPrice;
    float SalesTax;
    float LicesingFee;
}CashSale;

typedef struct
{
    float ManufactureerSuggestedRetailPrice;
    float ActualSellingPrice;
    float DownPayment;
    float SecurityDeposit;
    float MonthlyPayment;
    int   LeaseTerm;
}Rent;

typedef struct
{
    float ManufactureerSuggestedRetailPrice;
    float ActualSellingPrice;
    float SalesTax;
    float LicesingFee;
    float DownPayment;
    int   LoanDuration;
    float InterestRate;
    float MonthlyPayment;
    char  NameOfBank[NAMEOFBANKLEN];
}LoanSale;

typedef struct
{
    char     CustomerName[NAMELENGTH];
    char     CustomerAddr[ADDRLENGTH];
    char     Model[MODLLENGTH];
    CashSale cashsal;
    Rent     RentSal;
    LoanSale LoanSal;
}SaleRecord;

int main()
{
    return 0;
}
