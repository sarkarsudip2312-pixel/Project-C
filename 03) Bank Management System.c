#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100

struct Account {
    int accountNo;
    char name[50];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int count = 0;

/* Function Prototypes */
void loadAccounts();
void saveAccounts();
void createAccount();
void viewAccounts();
void searchAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();

/* Main Function */
int main() {
    int choice;

    loadAccounts();

    while (1) {
        printf("\n====================================\n");
        printf("      BANK MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Check Balance\n");
        printf("7. Save Data\n");
        printf("8. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                viewAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                depositMoney();
                break;

            case 5:
                withdrawMoney();
                break;

            case 6:
                checkBalance();
                break;

            case 7:
                saveAccounts();
                break;

            case 8:
                saveAccounts();
                printf("\nData Saved Successfully.\n");
                printf("Thank You For Using Bank Management System!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

/* Load Accounts from File */
void loadAccounts() {
    FILE *fp = fopen("accounts.txt", "r");

    if (fp == NULL)
        return;

    while (fscanf(fp, "%d|%49[^|]|%f\n",
                  &accounts[count].accountNo,
                  accounts[count].name,
                  &accounts[count].balance) == 3) {
        count++;
    }

    fclose(fp);
}

/* Save Accounts to File */
void saveAccounts() {
    FILE *fp = fopen("accounts.txt", "w");

    if (fp == NULL) {
        printf("File Error!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d|%s|%.2f\n",
                accounts[i].accountNo,
                accounts[i].name,
                accounts[i].balance);
    }

    fclose(fp);

    printf("\nAccounts Saved Successfully!\n");
}

/* Create Account */
void createAccount() {
    if (count >= MAX_ACCOUNTS) {
        printf("Account Limit Reached!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accounts[count].accountNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", accounts[count].name);

    printf("Enter Initial Balance: ");
    scanf("%f", &accounts[count].balance);

    count++;

    printf("\nAccount Created Successfully!\n");
}

/* View Accounts */
void viewAccounts() {
    if (count == 0) {
        printf("\nNo Accounts Found!\n");
        return;
    }

    printf("\n========== ACCOUNT LIST ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nAccount %d\n", i + 1);
        printf("Account No : %d\n", accounts[i].accountNo);
        printf("Name       : %s\n", accounts[i].name);
        printf("Balance    : %.2f\n", accounts[i].balance);
    }
}

/* Search Account */
void searchAccount() {
    int accNo;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNo == accNo) {
            printf("\nAccount Found!\n");
            printf("Account No : %d\n", accounts[i].accountNo);
            printf("Name       : %s\n", accounts[i].name);
            printf("Balance    : %.2f\n", accounts[i].balance);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAccount Not Found!\n");
    }
}

/* Deposit Money */
void depositMoney() {
    int accNo;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNo == accNo) {

            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);

            if (amount > 0) {
                accounts[i].balance += amount;
                printf("\nDeposit Successful!\n");
                printf("New Balance: %.2f\n",
                       accounts[i].balance);
            } else {
                printf("Invalid Amount!\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAccount Not Found!\n");
    }
}

/* Withdraw Money */
void withdrawMoney() {
    int accNo;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNo == accNo) {

            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("Invalid Amount!\n");
            } else if (amount > accounts[i].balance) {
                printf("Insufficient Balance!\n");
            } else {
                accounts[i].balance -= amount;

                printf("\nWithdrawal Successful!\n");
                printf("Remaining Balance: %.2f\n",
                       accounts[i].balance);
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAccount Not Found!\n");
    }
}

/* Check Balance */
void checkBalance() {
    int accNo;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNo == accNo) {

            printf("\nAccount No : %d\n",
                   accounts[i].accountNo);
            printf("Name       : %s\n",
                   accounts[i].name);
            printf("Balance    : %.2f\n",
                   accounts[i].balance);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nAccount Not Found!\n");
    }
}